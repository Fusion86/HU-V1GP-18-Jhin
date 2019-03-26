cmake_minimum_required(VERSION 3.0.0)

# Project
project(jhin VERSION 0.1.1)
add_definitions(-D jhin_VERSION="${jhin_VERSION}")

add_executable(jhin main.cpp BrickPi3.cpp Jhin.cpp)
include_directories(include)
