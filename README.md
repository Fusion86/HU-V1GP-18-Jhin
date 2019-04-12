# Jhin

- [JhinV2](https://github.com/Fusion86/V1GP-18-Jhin/tree/v2) is the drawing robot
- [Stormrazor](https://github.com/Fusion86/V1GP-18-Jhin/tree/stormrazor) is a SVG -> WMS (drawing script) converter
- [Wammus](https://github.com/Fusion86/V1GP-18-Jhin/blob/v2/src/Wammus.cpp#L75) is the scriptengine that powers JhinV2


## How to compile

```sh
./build.sh
```


## How to connect the motors

The prefixed M stands for motor (probably).
Ports 1-4 should be connected to the **S**1-4 ports on the BrickPi.

* MA = Pen motor
* MB = X-axis motor
* MC = Y-axis motor
* MD = Y-axis motor
* PORT_1 = Unused
* PORT_2 = Unused
* PORT_3 = Unused
* PORT_4 = Unused