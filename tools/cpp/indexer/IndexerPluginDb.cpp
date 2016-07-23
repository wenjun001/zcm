#include "IndexerPluginDb.hpp"
#include "util/SymtabElf.hpp"

#include <algorithm>
#include <memory>
#include <cxxabi.h>
#include <typeinfo>

#define DEBUG(...) do {\
    if (this->debug) printf(__VA_ARGS__);\
  } while(0)

#define ERROR(...) do{\
    fprintf(stderr, "Err: ");\
    fprintf(stderr, __VA_ARGS__);\
  } while(0)

static inline std::string demangle(std::string name)
{
    int status = -4; // some arbitrary value to eliminate the compiler warning

    std::unique_ptr<char, void(*)(void*)> res {
        abi::__cxa_demangle(name.c_str(), NULL, NULL, &status),
        std::free
    };

    return (status==0) ? res.get() : name ;
}

static void *openlib(const string& libname)
{
    // verify the .so library
    size_t len = libname.size();
    if (len < 3 || 0 != strcmp(libname.c_str()+len-3, ".so")) {
        ERROR("bad library name, expected a .so file, not '%s'\n", libname.c_str());
        return NULL;
    }

    // attempt to open the .so
    void *lib = dlopen(libname.c_str(), RTLD_LAZY);
    if (!lib) {
        ERROR("failed to open '%s'\n", libname.c_str());
        ERROR("%s\n", dlerror());
        return NULL;
    }

    return lib;
}

static string method = "::makeIndexerPlugin()";

// find all zcm types by post-processing the symbols
bool IndexerPluginDb::findPlugins(const string& libname)
{
    void *lib = openlib(libname);
    if (lib == NULL) {
        ERROR("failed to open '%s'\n", libname.c_str());
        return false;
    }

    // read the library's symbol table
    SymtabElf stbl{libname};
    if (!stbl.good()) {
        ERROR("ERR: failed to load symbol table for ELF file\n");
        return false;
    }

    // process the symbols
    string s;
    while (stbl.getNext(s)) {
        string demangled = demangle(s);
        //DEBUG("Symbol: %s\n", s.c_str());
        if (!StringUtil::endswith(demangled, method))
            continue;

        IndexerPluginMetadata md;
        md.className = demangled;
        md.makeIndexerPlugin = NULL;

        if (std::find(pluginMeta.begin(), pluginMeta.end(), md) != pluginMeta.end()) continue;

        *(void **) &md.makeIndexerPlugin = dlsym(lib, s.c_str());
        if (md.makeIndexerPlugin == NULL) {
            ERROR("ERR: failed to load %s\n", s.c_str());
            continue;
        }

        pluginMeta.push_back(md);

        DEBUG("Success loading plugin %s\n", demangled.c_str());
    }

    for (auto meta : pluginMeta) {
        plugins.push_back(meta.makeIndexerPlugin());
        constPlugins.push_back(plugins.back());
    }

    DEBUG("Loaded %d plugins from %s\n", (int)plugins.size(), libname.c_str());

    return true;
}

std::vector<const zcm::IndexerPlugin*> IndexerPluginDb::getPlugins() { return constPlugins; }

IndexerPluginDb::IndexerPluginDb(const string& paths, bool debug) : debug(debug)
{
    for (auto& libname : StringUtil::split(paths, ':')) {
        DEBUG("Loading plugins from '%s'\n", libname.c_str());
        if (!findPlugins(libname)) {
            ERROR("failed to find indexer plugins in %s\n", libname.c_str());
            continue;
        }
    }
}

IndexerPluginDb::~IndexerPluginDb() { for (auto p : plugins) delete p; }
