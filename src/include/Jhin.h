#pragma once

#include <iostream>

#include "BrickPi3.h"
#include "Utility.h"

class Jhin
{
  public:
    Jhin();
    void print_info();
    void print_help();
    void test();
    void linerider();

  private:
    BrickPi3 BP;
};
