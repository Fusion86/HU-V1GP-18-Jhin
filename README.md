# Jhin

### <p align="center"> **_"Four."_**</p>

Text etc


## How to compile

```sh
./build.sh
```


## How to connect the motors

The prefixed M stands for motor (probably).  
Ports 1-4 should be connected to the **S**1-4 ports on the BrickPi.

* MA = Unused
* MB = Left wheel
* MC = Right wheel
* MD = Unused
* PORT_1 = Unused
* PORT_2 = Unused
* PORT_3 = Light sensor
* PORT_4 = RGB light sensor


## Coding guidelines

The user is expected to close the program with Ctrl-C. This means that if your main code runs in a `while(true)` loop you don't have to include a `break`, the program will automatically stop all running motors on exit. All other sensors will remain in their latest state (aka won't be reset).
