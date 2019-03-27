#include "CarKit.h"

#include <unistd.h>

CarKit::CarKit()
{
}

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
    BP.set_right_dps(0);

    BP.set_left_dps(500);
    sleep(10);
    BP.set_left_dps(0);
}

void CarKit::turn_left()
{
    BP.set_left_dps(0);

    BP.set_right_dps(500);
    sleep(1);
    BP.set_right_dps(0);
}

void CarKit::move_forward()
{
    BP.set_left_dps(500);
    BP.set_right_dps(500);
    sleep(1);
    BP.set_left_dps(0);
    BP.set_right_dps(0);
}
