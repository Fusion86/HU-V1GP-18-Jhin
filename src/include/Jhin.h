#pragma once

#include <iostream>

#include <stdio.h>  // for printf
#include <unistd.h> // for sleep
#include <signal.h> // for catching exit signals

#include "BrickPi3.h"
#include "Utility.h"
#include "CarKit.h"

#define LINERIDER_SPEED 200            // Speed
#define LINERIDER_OBJECT_DISTANCE 15   // Distance at which objects will be detected
#define LINERIDER_REFLECTED_LIGHT 2200 // If the reflected light count is larger than this number the robot is on the line, if the reflected light count is lower then it is NOT on the line

class Jhin
{
public:
  Jhin();
  void print_info();
  void print_help();
  void test();
  void linerider();
  void reset();
  void police();
//  void remote_control();
  CarKit Car;

private:
  BrickPi3 BP;
};
