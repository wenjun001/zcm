// THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
// BY HAND!!
//
// Generated by zcm-gen

#include <string.h>
#include "prim1.h"

static int __prim1_hash_computed;
static uint64_t __prim1_hash;

uint64_t __prim1_hash_recursive(const __zcm_hash_ptr *p)
{
    const __zcm_hash_ptr *fp;
    for (fp = p; fp != NULL; fp = fp->parent)
        if (fp->v == __prim1_get_hash)
            return 0;

    __zcm_hash_ptr cp;
    cp.parent =  p;
    cp.v = (void*)__prim1_get_hash;
    (void) cp;

    uint64_t hash = (uint64_t)0x0c7cd031e3f10c81LL
         + __int8_t_hash_recursive(&cp)
         + __int16_t_hash_recursive(&cp)
         + __int32_t_hash_recursive(&cp)
         + __int64_t_hash_recursive(&cp)
         + __float_hash_recursive(&cp)
         + __double_hash_recursive(&cp)
         + __string_hash_recursive(&cp)
         + __boolean_hash_recursive(&cp)
         + __byte_hash_recursive(&cp)
        ;

    return (hash<<1) + ((hash>>63)&1);
}

int64_t __prim1_get_hash(void)
{
    if (!__prim1_hash_computed) {
        __prim1_hash = (int64_t)__prim1_hash_recursive(NULL);
        __prim1_hash_computed = 1;
    }

    return __prim1_hash;
}

int __prim1_encode_array(void *buf, int offset, int maxlen, const prim1 *p, int elements)
{
    int pos = 0, element;
    int thislen;

    for (element = 0; element < elements; element++) {

        thislen = __int8_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].i8), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int16_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].i16), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].i32), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].i64), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __float_encode_array(buf, offset + pos, maxlen - pos, &(p[element].f), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __double_encode_array(buf, offset + pos, maxlen - pos, &(p[element].d), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __string_encode_array(buf, offset + pos, maxlen - pos, &(p[element].s), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __boolean_encode_array(buf, offset + pos, maxlen - pos, &(p[element].bl), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __byte_encode_array(buf, offset + pos, maxlen - pos, &(p[element].b), 1);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int prim1_encode(void *buf, int offset, int maxlen, const prim1 *p)
{
    int pos = 0, thislen;
    int64_t hash = __prim1_get_hash();

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    thislen = __prim1_encode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int __prim1_encoded_array_size(const prim1 *p, int elements)
{
    int size = 0, element;
    for (element = 0; element < elements; element++) {

        size += __int8_t_encoded_array_size(&(p[element].i8), 1);

        size += __int16_t_encoded_array_size(&(p[element].i16), 1);

        size += __int32_t_encoded_array_size(&(p[element].i32), 1);

        size += __int64_t_encoded_array_size(&(p[element].i64), 1);

        size += __float_encoded_array_size(&(p[element].f), 1);

        size += __double_encoded_array_size(&(p[element].d), 1);

        size += __string_encoded_array_size(&(p[element].s), 1);

        size += __boolean_encoded_array_size(&(p[element].bl), 1);

        size += __byte_encoded_array_size(&(p[element].b), 1);

    }
    return size;
}

int prim1_encoded_size(const prim1 *p)
{
    return 8 + __prim1_encoded_array_size(p, 1);
}

int __prim1_decode_array(const void *buf, int offset, int maxlen, prim1 *p, int elements)
{
    int pos = 0, thislen, element;

    for (element = 0; element < elements; element++) {

        thislen = __int8_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].i8), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int16_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].i16), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].i32), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].i64), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __float_decode_array(buf, offset + pos, maxlen - pos, &(p[element].f), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __double_decode_array(buf, offset + pos, maxlen - pos, &(p[element].d), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __string_decode_array(buf, offset + pos, maxlen - pos, &(p[element].s), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __boolean_decode_array(buf, offset + pos, maxlen - pos, &(p[element].bl), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __byte_decode_array(buf, offset + pos, maxlen - pos, &(p[element].b), 1);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int __prim1_decode_array_cleanup(prim1 *p, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int8_t_decode_array_cleanup(&(p[element].i8), 1);

        __int16_t_decode_array_cleanup(&(p[element].i16), 1);

        __int32_t_decode_array_cleanup(&(p[element].i32), 1);

        __int64_t_decode_array_cleanup(&(p[element].i64), 1);

        __float_decode_array_cleanup(&(p[element].f), 1);

        __double_decode_array_cleanup(&(p[element].d), 1);

        __string_decode_array_cleanup(&(p[element].s), 1);

        __boolean_decode_array_cleanup(&(p[element].bl), 1);

        __byte_decode_array_cleanup(&(p[element].b), 1);

    }
    return 0;
}

int prim1_decode(const void *buf, int offset, int maxlen, prim1 *p)
{
    int pos = 0, thislen;
    int64_t hash = __prim1_get_hash();

    int64_t this_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (this_hash != hash) return -1;

    thislen = __prim1_decode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int prim1_decode_cleanup(prim1 *p)
{
    return __prim1_decode_array_cleanup(p, 1);
}

int __prim1_clone_array(const prim1 *p, prim1 *q, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int8_t_clone_array(&(p[element].i8), &(q[element].i8), 1);

        __int16_t_clone_array(&(p[element].i16), &(q[element].i16), 1);

        __int32_t_clone_array(&(p[element].i32), &(q[element].i32), 1);

        __int64_t_clone_array(&(p[element].i64), &(q[element].i64), 1);

        __float_clone_array(&(p[element].f), &(q[element].f), 1);

        __double_clone_array(&(p[element].d), &(q[element].d), 1);

        __string_clone_array(&(p[element].s), &(q[element].s), 1);

        __boolean_clone_array(&(p[element].bl), &(q[element].bl), 1);

        __byte_clone_array(&(p[element].b), &(q[element].b), 1);

    }
    return 0;
}

prim1 *prim1_copy(const prim1 *p)
{
    prim1 *q = (prim1*) malloc(sizeof(prim1));
    __prim1_clone_array(p, q, 1);
    return q;
}

void prim1_destroy(prim1 *p)
{
    __prim1_decode_array_cleanup(p, 1);
    free(p);
}

int prim1_publish(zcm_t *lc, const char *channel, const prim1 *p)
{
      int max_data_size = prim1_encoded_size (p);
      uint8_t *buf = (uint8_t*) malloc (max_data_size);
      if (!buf) return -1;
      int data_size = prim1_encode (buf, 0, max_data_size, p);
      if (data_size < 0) {
          free (buf);
          return data_size;
      }
      int status = zcm_publish (lc, channel, (char *)buf, (size_t)data_size);
      free (buf);
      return status;
}

struct _prim1_subscription_t {
    prim1_handler_t user_handler;
    void *userdata;
    zcm_sub_t *z_sub;
};
static
void prim1_handler_stub (const zcm_recv_buf_t *rbuf,
                            const char *channel, void *userdata)
{
    int status;
    prim1 p;
    memset(&p, 0, sizeof(prim1));
    status = prim1_decode (rbuf->data, 0, rbuf->data_size, &p);
    if (status < 0) {
        fprintf (stderr, "error %d decoding prim1!!!\n", status);
        return;
    }

    prim1_subscription_t *h = (prim1_subscription_t*) userdata;
    h->user_handler (rbuf, channel, &p, h->userdata);

    prim1_decode_cleanup (&p);
}

prim1_subscription_t* prim1_subscribe (zcm_t *zcm,
                    const char *channel,
                    prim1_handler_t f, void *userdata)
{
    prim1_subscription_t *n = (prim1_subscription_t*)
                       malloc(sizeof(prim1_subscription_t));
    n->user_handler = f;
    n->userdata = userdata;
    n->z_sub = zcm_subscribe (zcm, channel,
                              prim1_handler_stub, n);
    if (n->z_sub == NULL) {
        fprintf (stderr,"couldn't reg prim1 ZCM handler!\n");
        free (n);
        return NULL;
    }
    return n;
}

int prim1_unsubscribe(zcm_t *zcm, prim1_subscription_t* hid)
{
    int status = zcm_unsubscribe (zcm, hid->z_sub);
    if (0 != status) {
        fprintf(stderr,
           "couldn't unsubscribe prim1_handler %p!\n", hid);
        return -1;
    }
    free (hid);
    return 0;
}

