#include "Jhin.h"

#include <iostream>

#include <curses.h>
#include <stdio.h>
#include <unistd.h>

#include "BrickPi3.h"
#include "Utility.h"

Jhin::Jhin()
{
    BP = BrickPi3();
    BP.detect();
    Ctrl = MotorControl(BP);
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
              << "  run - temp dev function\n"
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
    // BP.set_motor_limits(PORT_X, X_MOTOR_SPEED, 0);
    // BP.set_motor_limits(PORT_Y, Y_MOTOR_SPEED, 0);

    // uint32_t rotate = 0;

    // uint32_t x_move = 0;
    // uint32_t x_pos = 0;

    // uint32_t y_move = 0;
    // uint32_t y_pos = 0;

    // std::string input;

    // std::cout << "Calibrate pen\n"
    //           << "Rotate pen with q and e, press shift to rotate faster.\n"
    //           << "Press [enter] to confirm and continue."
    //           << std::endl;

    // while (true)
    // {
    //     std::getline(std::cin, input);
    //     if (input[0] == 'q')
    //     {
    //         rotate += 15;
    //     }
    //     else if (input[0] == 'e')
    //     {
    //         rotate -= 15;
    //     }
    //     else if (input[0] == 'w')
    //     {
    //         x_move += X_RAIL_LENGTH;
    //     }
    //     else if (input[0] == 's')
    //     {
    //         x_move -= X_RAIL_LENGTH;
    //     }
    //     else if (input[0] == 'a')
    //     {
    //         y_move += Y_RAIL_LENGTH;
    //     }
    //     else if (input[0] == 'd')
    //     {
    //         y_move -= Y_RAIL_LENGTH;
    //     }
    //     else if (input.empty())
    //     {
    //         break;
    //     }

    //     BP.set_motor_position_relative(PORT_PEN, rotate);

    //     if (x_pos + x_move <= X_RAIL_LENGTH) {
    //         BP.set_motor_position_relative(PORT_X, x_move);
    //         x_pos += x_move;
    //     }

    //     if (y_pos + y_move <= Y_RAIL_LENGTH) {
    //         BP.set_motor_position_relative(PORT_Y, y_move);
    //         y_pos += y_move;
    //     }

    //     rotate = 0;
    //     x_move = 0;
    //     y_move = 0;
    // }

    // Setup state
    int x = 0, y = 0, pen = 0;
    int old_x = 0, old_y = 0, old_pen = 0;

    // Setup curses TUI
    // See http://www.cs.ukzn.ac.za/~hughm/os/notes/ncurses.html#using
    initscr();
    cbreak(); // Disable line buffering (aka get input without pressing enter)
    noecho(); // Don't print pressed characters
    // keypad(stdscr, TRUE); // Allow special keys, eg. arrows, function, enter
    // nodelay(stdscr, TRUE);
    curs_set(0); // Set cursor invisible

    // Print initial UI
    addstr("Manual robot control\n");
    addstr("Move over axis with wasd\n");
    addstr("Move pen up/down with q and e\n");
    addstr("Exit with CTRL-C\n");

    int ch;
    while (true)
    {
        // Clear lines to avoid leftover characters if the new
        // printw string is shorter than the previous one
        // TODO: This actually doesn't do anything (it dont work)
        // see HACK below for the workaround
        // clearline(5);

        // Update UI
        // HACK: The spaces after `Pen: %d` are there to overwrite any leftover characters
        mvprintw(5, 0, "X:  %d    Y: %d    Pen: %d    ",
                 Ctrl.get_x(), Ctrl.get_y(), Ctrl.get_pen());

        ch = getch();
        switch (ch)
        {
        case 'w':
            // x = std::min(x + 10, X_RAIL_LENGTH);
            Ctrl.move(10, 0);
            break;
        case 's':
            // x = std::max(x - 10, 0);
            Ctrl.move(-10, 0);
            break;
        case 'a':
            // y = std::min(y + 10, Y_RAIL_LENGTH);
            Ctrl.move(0, 10);
            break;
        case 'd':
            // y = std::max(y - 10, 0);
            Ctrl.move(0, -10);
            break;
        case 'q':
            // pen += 10;
            Ctrl.toggle_pen();
            break;
        case 'e':
            // pen -= 10;
            Ctrl.toggle_pen();
            break;
        }

        // // Only update motors for wich the position changed
        // if (x != old_x)
        // {
        //     // TODO: Do motor stuff
        //     old_x = x;
        // }
        // if (y != old_y)
        // {
        //     // TODO: Do motor stuff
        //     old_y = y;
        // }
        // if (pen != old_pen)
        // {
        //     // TODO: Do motor stuff
        //     old_pen = pen;
        // }
    }
}
