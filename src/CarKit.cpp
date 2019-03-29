#include "CarKit.h"
#include <unistd.h>

CarKit::CarKit() {
};

CarKit::CarKit(BrickPi3 bp)
{
    BP = bp;
    Config.Speed = 300;
}

void CarKit::set_left_dps(int dps)
{
    BP.set_motor_dps(Config.LeftWheel, dps);
}

void CarKit::set_right_dps(int dps)
{
    BP.set_motor_dps(Config.RightWheel, dps);
}

void CarKit::stop()
{
    set_left_dps(0);
    set_right_dps(0);
}

void CarKit::turn_right()
{
    set_right_dps(0);
    set_left_dps(0);

    BP.set_motor_position_relative(PORT_B, 390);
    sleep(1);
}

void CarKit::turn_left()
{
    set_left_dps(0);
    set_right_dps(0);

    BP.set_motor_position_relative(PORT_C, 380);
    sleep(1);
}

void CarKit::move_forward(float seconds)
{
    int sleepTime = static_cast<int>(seconds * 1000000);
    set_left_dps(Config.Speed);
    set_right_dps(Config.Speed);
    usleep(static_cast<__useconds_t>(sleepTime));

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
