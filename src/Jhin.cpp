#include "Jhin.h"

Jhin::Jhin()
{
    BP = BrickPi3();
    BP.detect();

    Car = CarKit(BP);
    Car.Config.LeftWheel = PORT_B;
    Car.Config.RightWheel = PORT_C;
}

void Jhin::print_info()
{
    char str[33]; // Room for the 32-character serial number string plus the NULL terminator.

    BP.get_manufacturer(str);
    printf("Manufacturer    : %s\n", str);

    BP.get_board(str);
    printf("Board           : %s\n", str);

    BP.get_id(str);
    printf("Serial Number   : %s\n", str);

    BP.get_version_hardware(str);
    printf("Hardware version: %s\n", str);

    BP.get_version_firmware(str);
    printf("Firmware version: %s\n", str);

    printf("Battery voltage : %.3f\n", BP.get_voltage_battery());
    printf("9v voltage      : %.3f\n", BP.get_voltage_9v());
    printf("5v voltage      : %.3f\n", BP.get_voltage_5v());
    printf("3.3v voltage    : %.3f\n", BP.get_voltage_3v3());
}

void Jhin::print_help()
{
    std::cout << "Jhin v" << xstr(jhin_VERSION)
              << "\n\n"
              << "COMMANDS:\n"
              << "  help - print this help page\n"
              << "  info - print info about device (serial/voltage/etc)\n"
              << "  test - execute test code\n"
              << "  linerider - follow line\n"
              << "  police - do a wee-ooo wee-ooo\n"
              << std::endl;
}

void Jhin::test()
{
    BP.set_motor_dps(PORT_A, 90);
    sleep(2);
    BP.set_motor_power(PORT_A, 0);
}

void Jhin::linerider()
{
    int timeout;
    sensor_light_t light;
    sensor_ultrasonic_t sonic; // Gotta go fast
    BP.set_sensor_type(PORT_3, SENSOR_TYPE_NXT_LIGHT_ON);
    BP.set_sensor_type(PORT_2, SENSOR_TYPE_NXT_ULTRASONIC);
    Car.turn_right();
//    while (true)
//    {
//        timeout = 0;
//        BP.get_sensor(PORT_2, sonic);
//        BP.get_sensor(PORT_3, light);
//
//        // Detect if there is an obstacle on the path
//        if (sonic.cm < LINERIDER_OBJECT_DISTANCE)
//        {
//            BP.set_sensor_type(PORT_1, SENSOR_TYPE_NXT_COLOR_RED);
//
//            Car.turn_right();
//            timeout = 500;
//        }
//        else if (light.reflected >= LINERIDER_REFLECTED_LIGHT)
//        {
//            // Robot is still on the line
//            BP.set_sensor_type(PORT_1, SENSOR_TYPE_NXT_COLOR_GREEN);
//            Car.set_left_dps(LINERIDER_SPEED);
//            Car.set_right_dps(0);
//        }
//        else
//        {
//            // Robot lost the line, need to find it again
//            BP.set_sensor_type(PORT_1, SENSOR_TYPE_NXT_COLOR_GREEN);
//            Car.set_left_dps(0);
//            Car.set_right_dps(LINERIDER_SPEED);
//        }
//
//        std::cout << "Ambient: " << light.ambient << std::endl;
//        std::cout << "Reflected: " << light.reflected << std::endl;
//        std::cout << "Centimeters: " << sonic.cm << std::endl;
//        std::cout << "Timeout: " << timeout << std::endl;
//        usleep(timeout);
//    }
}

void Jhin::reset()
{
    BP.reset_all(); // Reset everything so there are no run-away motors
}

void Jhin::police()
{
    while (true)
    {
        BP.set_sensor_type(PORT_4, SENSOR_TYPE_NXT_COLOR_RED);
        sleep(1);
        BP.set_sensor_type(PORT_4, SENSOR_TYPE_NXT_COLOR_BLUE);
        sleep(1);
    }
}
