#include "CarKit.h"

#include <unistd.h>

CarKit::CarKit() {
    Config.Speed = 200;
};

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

    set_left_dps(Config.Speed);
    sleep(10);
    set_left_dps(0);
}

void CarKit::turn_left()
{
    set_left_dps(0);

    set_right_dps(Config.Speed);
    sleep(1);
    set_right_dps(0);
}

void CarKit::move_forward()
{
    set_left_dps(Config.Speed);
    set_right_dps(Config.Speed);
    sleep(1);
    set_left_dps(0);
    set_right_dps(0);
}

void CarKit::move_backward()
{
    set_left_dps(-Config.Speed);
    set_right_dps(-Config.Speed);
    sleep(1);
    set_left_dps(0);
    set_right_dps(0);
}
