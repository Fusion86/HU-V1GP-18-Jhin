#include "Jhin.h"

#include <iostream>

#include <stdio.h>
#include <unistd.h>

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

void Jhin::run()
{
    BP.set_motor_limits(PORT_X, X_MOTOR_SPEED, 0);
    BP.set_motor_limits(PORT_Y, Y_MOTOR_SPEED, 0);

    uint32_t rotate = 0;

    uint32_t x_move = 0;
    uint32_t x_pos = 0;

    uint32_t y_move = 0;
    uint32_t y_pos = 0;

    std::string input;

    std::cout << "Calibrate pen\n"
              << "Rotate pen with q and e, press shift to rotate faster.\n"
              << "Press [enter] to confirm and continue."
              << std::endl;

    while (true)
    {
        std::getline(std::cin, input);
        if (input[0] == 'q')
        {
            rotate += 15;
        }
        else if (input[0] == 'e')
        {
            rotate -= 15;
        }
        else if (input[0] == 'w')
        {
            x_move += X_RAIL_LENGTH;
        }
        else if (input[0] == 's')
        {
            x_move -= X_RAIL_LENGTH;
        }
        else if (input[0] == 'a')
        {
            y_move += Y_RAIL_LENGTH;
        }
        else if (input[0] == 'd')
        {
            y_move -= Y_RAIL_LENGTH;
        }
        else if (input.empty())
        {
            break;
        }

        BP.set_motor_position_relative(PORT_PEN, rotate);

        if (x_pos + x_move <= X_RAIL_LENGTH) {
            BP.set_motor_position_relative(PORT_X, x_move);
            x_pos += x_move;
        }

        if (y_pos + y_move <= Y_RAIL_LENGTH) {
            BP.set_motor_position_relative(PORT_Y, y_move);
            y_pos += y_move;
        }

        rotate = 0;
        x_move = 0;
        y_move = 0;
    }
}
