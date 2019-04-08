#pragma once

#include "BrickPi3.h"

class MotorControl
{
  public:
    MotorControl();
    MotorControl(BrickPi3 bp);
    void move(int x, int y);
    void set_pos(int x, int y);
    void toggle_pen();

    int get_x();
    int get_y();
    int get_pen();

  private:
    BrickPi3 BP;
    int x = 0;
    int y = 0;
    int pen = 0;
};
