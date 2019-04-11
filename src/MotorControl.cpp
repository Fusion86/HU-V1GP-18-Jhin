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

void MotorControl::move(int x, int y, bool blocking, bool sync)
{
    // Calculate x
    int rel_move_x = std::min(x, x_max - this->x);

    if (this->x + rel_move_x < 0)
        rel_move_x = this->x * -1;

    this->x += rel_move_x;

    // Calculate y
    int rel_move_y = std::min(y, y_max - this->y);

    if (this->y + rel_move_y < 0)
        rel_move_y = this->y * -1;

    this->y += rel_move_y;

    std::cout << "Moving by " << rel_move_x << ", " << rel_move_y << std::endl;

    // Caluclate y speed
    bool reset_limits = false;
    if (sync && rel_move_x != 0 && rel_move_y != 0)
    {
        reset_limits = true;
        int mult = rel_move_y / rel_move_x;

        int y_speed = Y_MOTOR_SPEED;

        if (mult != 0)
            y_speed = Y_MOTOR_SPEED * mult;

        set_limits(X_MOTOR_SPEED, y_speed);
    }

    if (rel_move_x != 0)
    {
        BP.set_motor_position_relative(PORT_X, rel_move_x);
    }

    if (rel_move_y != 0)
    {
        BP.set_motor_position_relative(PORT_Y, rel_move_y);
    }

    // Wait for all motors
    if (blocking)
    {
        wait_for(PORT_X);
        wait_for(PORT_Y);
    }

    // Reset limits
    if (reset_limits)
        set_limits();
}

void MotorControl::set_pos(int x, int y, bool blocking, bool sync)
{
    move(x - this->x, y - this->y, blocking, sync);
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
    wait_for(PORT_PEN);
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
    // Speed is limited to 90 (see BrickPi.h set_motor_limits)
    if (x_speed > 90)
        x_speed = 90;

    if (y_speed > 90)
        y_speed = 90;

    BP.set_motor_limits(PORT_X, x_speed, 0);
    BP.set_motor_limits(PORT_Y, y_speed, 0);
    std::cout << "Set limits to " << x_speed << ", " << y_speed << std::endl;
}

void MotorControl::set_size(int x, int y)
{
    x_max = x;
    y_max = y;
    std::cout << "Set canvas size to " << x_max << ", " << y_max << std::endl;
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
    set_limits(90, 90);
    set_pos(0, 0, false);

    if (pen != 0)
        toggle_pen();

    wait_for_all();
    set_limits();
}

void MotorControl::reset_brickpi()
{
    BP.reset_all();
}
