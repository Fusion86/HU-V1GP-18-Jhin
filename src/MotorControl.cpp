#include "MotorControl.h"

#include <algorithm>

#include "Jhin.h"

MotorControl::MotorControl()
{
}

MotorControl::MotorControl(BrickPi3 bp)
{
    BP = bp;
}

void MotorControl::move(int x, int y)
{
    if (x != 0)
    {
        int rel_move = std::min(x, X_RAIL_LENGTH - this->x);

        if (this->x + rel_move < 0)
            rel_move = this->x * -1;

        this->x += rel_move;
        BP.set_motor_position_relative(PORT_X, rel_move);
    }

    if (y != 0)
    {
        int rel_move = std::min(y, Y_RAIL_LENGTH - this->y);

        if (this->y + rel_move < 0)
            rel_move = this->y * -1;

        this->y += rel_move;
        BP.set_motor_position_relative(PORT_Y, rel_move);
    }
}

void MotorControl::set_pos(int x, int y)
{
    move(x - this->x, y - this->y);
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
