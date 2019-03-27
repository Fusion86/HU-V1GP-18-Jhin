#include "Jhin.h"

Jhin::Jhin()
{
    BP = BrickPi3();
    BP.detect();
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
    // Left wheel = M B
    // Right wheel = M C

    sensor_light_t light;
    BP.set_sensor_type(PORT_3, SENSOR_TYPE_NXT_LIGHT_ON);

    while (true)
    {
        BP.get_sensor(PORT_3, light);

        if (light.reflected >= 2200)
        {
            // Robot is still on the line
            BP.set_sensor_type(PORT_1, SENSOR_TYPE_NXT_COLOR_BLUE);
        }
        else
        {
            // Robot lost the line, need to find it again
            BP.set_sensor_type(PORT_1, SENSOR_TYPE_NXT_COLOR_RED);
        }

        std::cout << "Ambient: " << light.ambient << std::endl;
        std::cout << "Reflected: " << light.reflected << std::endl;
    }
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
