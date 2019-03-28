#include "CarKit.h"

#include <unistd.h>

CarKit::CarKit() = default;

CarKit::CarKit(BrickPi3 bp)
{
    BP = bp;
}

void CarKit::set_left_dps(int dps)
{
    BP.set_motor_dps(Config.LeftWheel, dps);
}

void CarKit::set_right_dps(int dps)
{
    BP.set_motor_dps(Config.RightWheel, dps);
}

void CarKit::turn_right()
{
    set_right_dps(0);

    set_left_dps(500);
    sleep(10);
    set_left_dps(0);
}

void CarKit::turn_left()
{
    set_left_dps(0);

    set_right_dps(500);
    sleep(1);
    set_right_dps(0);
}

void CarKit::move_forward()
{
    set_left_dps(500);
    set_right_dps(500);
    sleep(1);
    set_left_dps(0);
    set_right_dps(0);
}
