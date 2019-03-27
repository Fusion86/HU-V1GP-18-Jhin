#pragma once

#include <iostream>

#include <stdio.h>      // for printf
#include <unistd.h>     // for sleep
#include <signal.h>     // for catching exit signals

#include "BrickPi3.h"
#include "Utility.h"

#define LINERIDER_SPEED 200

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

  private:
    BrickPi3 BP;
};
