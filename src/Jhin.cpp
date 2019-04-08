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
    Wammus = Wammus::Wammus(this);
}

void Jhin::reset()
{
    BP.reset_all(); // Reset everything so there are no run-away motors
    endwin();
}

void Jhin::print_help()
{
    std::cout << "Jhin v" << xstr(jhin_VERSION)
              << "\n\n"
              << "COMMANDS:\n"
              << "  help - print this help page\n"
              << "  info - print info about device (serial/voltage/etc)\n"
              << "  status - print motor status (rotation/power/etc)\n"
              << "  manual_control - manually control motors\n"
              << "  int - wammus interactive\n"
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

void Jhin::manual_control()
{
    BP.set_motor_limits(PORT_X, X_MOTOR_SPEED, 0);
    BP.set_motor_limits(PORT_Y, Y_MOTOR_SPEED, 0);

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
            Ctrl.move(STEP_SIZE, 0);
            break;
        case 's':
            // x = std::max(x - 10, 0);
            Ctrl.move(-STEP_SIZE, 0);
            break;
        case 'a':
            // y = std::min(y + 10, Y_RAIL_LENGTH);
            Ctrl.move(0, STEP_SIZE);
            break;
        case 'd':
            // y = std::max(y - 10, 0);
            Ctrl.move(0, -STEP_SIZE);
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
    }
}
