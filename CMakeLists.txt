cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 11)

project(jhin VERSION 0.2.0)
add_definitions(-D jhin_VERSION="${jhin_VERSION}")

include_directories(include)

file(GLOB jhin_SRC "src/*.cpp")
add_executable(jhin ${jhin_SRC})
