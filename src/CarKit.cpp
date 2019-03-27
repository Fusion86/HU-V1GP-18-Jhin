#include "CarKit.h"

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
    BP.set_motor_dps(Config.LeftWheel, 0);

    BP.set_motor_dps(Config.RightWheel, 200);
    usleep(1000);
    BP.set_motor_dps(Config.RightWheel, 0);
}
