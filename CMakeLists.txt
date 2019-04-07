cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 11)

project(jhin VERSION 0.2.0)
add_definitions(-D jhin_VERSION="${jhin_VERSION}")

find_package(Curses REQUIRED)
include_directories(include ${CURSES_INCLUDE_DIR})

file(GLOB sources "src/*.cpp")
set(jhin_SRC ${sources})

if(FAKE_BRICKPI)
    message(STATUS "Building with fake BrickPi3")
    add_definitions(-D FAKE_BRICKPI)
    list(REMOVE_ITEM jhin_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/BrickPi3.cpp)
    message(STATUS ${jhin_SRC})
else()
    message(STATUS "Building with real BrickPi3")
    list(REMOVE_ITEM jhin_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/BrickPi3Fake.cpp)
endif(FAKE_BRICKPI)

add_executable(jhin ${jhin_SRC})
target_link_libraries(jhin ${CURSES_LIBRARIES})
