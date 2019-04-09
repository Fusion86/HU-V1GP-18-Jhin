#pragma once

#include "BrickPi3.h"
#include "Config.h"

class MotorControl
{
  public:
    MotorControl();
    MotorControl(BrickPi3 bp);

    // Move to relative position
    void move(int x, int y, bool blocking = true);

    // Set absolute position
    void set_pos(int x, int y, bool blocking = true);

    // Toggle pen up/down
    void toggle_pen();

    // Set speed limit
    void set_limits(int x_speed = X_MOTOR_SPEED, int y_speed = Y_MOTOR_SPEED);

    // Set canvas size
    void set_size(int x, int y);

    // Reset position
    void reset_position();

    int get_x();
    int get_y();
    int get_pen();
    int get_x_max();
    int get_y_max();

    // Block till motors have finished moving
    void wait_for(uint8_t port);
    void wait_for_all();

  private:
    BrickPi3 BP;
    int x = 0;
    int y = 0;
    int pen = 0;
    int x_max = 0;
    int y_max = 0;
};
