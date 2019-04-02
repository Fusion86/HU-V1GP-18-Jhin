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

    // Reset terminal to normal "cooked" mode
    system("stty cooked");
}

void Jhin::print_help()
{
    std::cout << "Jhin v" << xstr(jhin_VERSION)
              << "\n\n"
              << "COMMANDS:\n"
              << "  help - print this help page\n"
              << "  info - print info about device (serial/voltage/etc)\n"
              << std::endl;
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

void Jhin::run()
{
    std::string input;

    std::cout << "Calibrate pen\n"
              << "Rotate pen with q and e, press shift to rotate faster.\n"
              << "Press [enter] to confirm and continue."
              << std::endl;

    uint8_t pen_state = 0;
    uint8_t pen_power = 0;
    uint32_t pen_pos = 0;
    uint16_t pen_dps = 0;
    BP.get_motor_status(PORT_PEN, pen_state, pen_power, pen_pos, pen_dps);

    while (true)
    {
        std::getline(std::cin, input);

        if (input[0] == 'q')
        {
            pen_pos = pen_pos + 5 % 360;
        }
        else if (input[0] == 'e')
        {
            if (pen_pos < 5)
                pen_pos = 355;
            else
                pen_pos -= 5;
        }
        else if (input[0] == 'Q')
        {
            pen_pos = pen_pos + 20 % 360;
        }
        else if (input[0] == 'E')
        {
            if (pen_pos < 20)
                pen_pos = 340;
            else
                pen_pos -= 20;
        }
        else if (input.empty())
        {
            break;
        }

        BP.set_motor_position(PORT_PEN, pen_pos);
    }
}
