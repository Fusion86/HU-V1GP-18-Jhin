#include "Jhin.h"

#include <iostream>

#include <stdio.h>

#include "BrickPi3.h"
#include "Utility.h"

Jhin::Jhin()
{
    BP = BrickPi3();
    BP.detect();
}

void Jhin::reset()
{
    BP.reset_all(); // Reset everything so there are no run-away motors
}

void Jhin::print_help()
{
    std::cout << "Jhin v" << xstr(jhin_VERSION)
              << "\n\n"
              << "COMMANDS:\n"
              << "  help - print this help page\n"
              << "  info - print info about device (serial/voltage/etc)\n"
              << "  status - print motor status (rotation/power/etc)\n"
              << "\nDRAW COMMANDS:\n"
              << "  line - draw line\n"
              << "  rect - draw rectangle\n"
              << "  vector - load vector from disk and draw\n"
              << std::flush;
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

void Jhin::motor_status()
{
    uint8_t pen_state = 0;
    int8_t pen_power = 0;
    int32_t pen_pos = 0;
    int16_t pen_dps = 0;
    BP.get_motor_status(PORT_PEN, pen_state, pen_power, pen_pos, pen_dps);
}
