# Jhin

### <p align="center"> **_"Four."_**</p>

Text etc


## How to compile on BrickPi

```sh
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=Debug ../src
```


## How to cross compile

Work in progress...

```sh
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=Debug -D CMAKE_TOOLCHAIN_FILE=../Toolchain-BrickPi.cmake ../src
```
