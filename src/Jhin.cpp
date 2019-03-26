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

    std::cout << "Press s to stop" << std::endl;

    sensor_light_t light;
    BP.set_sensor_type(PORT_3, SENSOR_TYPE_NXT_LIGHT_ON);

    while (true)
    {
        BP.get_sensor(PORT_3, light);

        if (light.reflected >= 40) {
            BP.set_motor_dps(PORT_B, 500 * 1.02);
        } else if (light.reflected < 40) {
            BP.set_motor_dps(PORT_C, 500);
        }
        int ch = std::cin.get();

        if (ch == 115) // If cc == 's'
            break;
    }

    BP.set_motor_power(PORT_B, 0);
    BP.set_motor_power(PORT_C, 0);
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
