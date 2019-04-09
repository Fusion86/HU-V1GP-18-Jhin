#include "MotorControl.h"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include "Jhin.h"

MotorControl::MotorControl()
{
}

MotorControl::MotorControl(BrickPi3 bp)
{
    BP = bp;

    // // Reset all encoders
    // BP.reset_motor_encoder(PORT_A);
    // BP.reset_motor_encoder(PORT_B);
    // BP.reset_motor_encoder(PORT_C);
    // BP.reset_motor_encoder(PORT_D);
}

void MotorControl::move(int x, int y, bool blocking)
{
    if (x != 0)
    {
        int rel_move = std::min(x, x_max - this->x);

        if (this->x + rel_move < 0)
            rel_move = this->x * -1;

        this->x += rel_move;
        BP.set_motor_position_relative(PORT_X, rel_move);
    }

    if (y != 0)
    {
        int rel_move = std::min(y, y_max - this->y);

        if (this->y + rel_move < 0)
            rel_move = this->y * -1;

        this->y += rel_move;
        BP.set_motor_position_relative(PORT_Y, rel_move);
    }

    // Wait for all motors
    if (blocking)
        wait_for_all();
}

void MotorControl::set_pos(int x, int y, bool blocking)
{
    move(x - this->x, y - this->y, blocking);
}

void MotorControl::toggle_pen()
{
    if (pen == 0)
    {
        BP.set_motor_position_relative(PORT_PEN, PEN_ROT_MAX);
        pen = PEN_ROT_MAX;
    }
    else
    {
        BP.set_motor_position_relative(PORT_PEN, -PEN_ROT_MAX);
        pen = 0;
    }
    wait_for_all();
}

int MotorControl::get_x()
{
    return x;
}

int MotorControl::get_y()
{
    return y;
}

int MotorControl::get_pen()
{
    return pen;
}

int MotorControl::get_x_max()
{
    return x_max;
}

int MotorControl::get_y_max()
{
    return y_max;
}

void MotorControl::set_limits(int x_speed, int y_speed)
{
    BP.set_motor_limits(PORT_X, x_speed, 0);
    BP.set_motor_limits(PORT_Y, y_speed, 0);
}

void MotorControl::set_size(int x, int y)
{
    x_max = x;
    y_max = y;
}

void MotorControl::wait_for(uint8_t port)
{
    uint8_t state;
    int8_t power;
    int32_t pos;
    int16_t dps;
    int32_t old_pos = INT32_MIN;

    while (true)
    {
        BP.get_motor_status(port, state, power, pos, dps);

        if (pos == old_pos)
            return;

        old_pos = pos;

        // std::cout << "port:" << std::to_string(port) << "    state: " << std::to_string(state) << "    power: " << std::to_string(power) << "    pos: " << pos << "    dps: " << dps << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void MotorControl::wait_for_all()
{
    wait_for(PORT_A);
    wait_for(PORT_B);
    wait_for(PORT_C);
    // wait_for(PORT_D); // Port D is unused
}

void MotorControl::reset_position()
{
    set_pos(0, 0, false);

    if (pen != 0)
        toggle_pen();

    wait_for_all();
}
