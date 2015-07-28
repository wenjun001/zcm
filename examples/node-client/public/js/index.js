onload = function(){
    var z = zcm.create()
    z.subscribe('EXAMPLE', function(channel, msg) {
        console.log('Got EXAMPLE: ', msg);
        z.publish('FOOBAR', {
            timestamp: 0,
            position: [2, 4, 6],
            orientation: [0, 2, 4, 6],
            num_ranges: 2,
            ranges: [7, 6],
            name: 'foobar string',
            enabled: false,
        });
    });
}