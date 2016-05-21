var SerialPortLib = require('serialport');
var request = require('request');

var SerialPort = SerialPortLib.SerialPort;
var port = new SerialPort("/dev/ttyACM0", {
    parser: SerialPortLib.parsers.readline('\n'),
    baudrate: 9600
});

port.on('open', function () {
        port.on('data', function (data) {
                data = data/100;
                console.log("data: " + data);

                request.post(
                    '192.168.0.138:3000',
                    { id: '123-123-123', value: data },
                    function (error, response, body) {
                        if (!error && response.statusCode == 200) {
                            console.log("OK");
                        }
                    }
                );
        });
});