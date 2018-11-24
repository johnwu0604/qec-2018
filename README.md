# Quebec Engineering Competition (QEC) 2018

This repository holds the source code for a garbage collector vehicle that is controlled using an arduino.

It was built in a 12 hour period during the provincial Quebec engineering competition.


# Writing To Serial Port Using NPM Package

1) Install serialport node module

```
npm install -g serialport
```

2) List the serial ports

```
serialport-list
```

3) Open up the serial port terminal

```
serialport-term -p <PORT NAME> -b <BAUD RATE> --echo
```
