#include "Wammus.h"

#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

#include "MotorControl.h"
#include "Utility.h"

namespace Wammus
{
Wammus::Wammus()
{
}

Wammus::Wammus(MotorControl *ctrl)
{
    Ctrl = ctrl;
}

int Wammus::run_file(const char *path)
{
    return 0;
}

void Wammus::prompt()
{
    print_banner();

    std::string input;
    while (true)
    {
        std::cout << "> ";

        if (getline(std::cin, input))
        {
            execute(input);
        }
    }
}

void Wammus::print_banner()
{
    std::cout << " __          __\n"
              << " \\ \\        / /\n"
              << "  \\ \\  /\\  / /_ _ _ __ ___  _ __ ___  _   _ ___ \n"
              << "   \\ \\/  \\/ / _` | '_ ` _ \\| '_ ` _ \\| | | / __|\n"
              << "    \\  /\\  / (_| | | | | | | | | | | | |_| \\__ \\\n"
              << "     \\/  \\/ \\__,_|_| |_| |_|_| |_| |_|\\__,_|___/\n"
              << "\n"
              << "Jhin v" << xstr(jhin_VERSION) << std::endl;
}

int Wammus::execute(std::string line)
{
    if (line.empty())
        return 0;

    // Define variables used inside the switch statement
    int x, y;

    // Split input on spaces
    std::istringstream iss(line);
    std::vector<std::string> cmd(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>());

    // Do stuff with cmd
    switch (hash(cmd[0].c_str()))
    {
    case hash("version"):
        std::cout << "Jhin v" << xstr(jhin_VERSION) << std::endl;
        break;
    case hash("exit"):
    case hash("quit"):
        exit(0);
    case hash("roll"):
    case hash("move"):
        if (cmd.size() < 3)
        {
            std::cout << "Not enough arguments!" << std::endl;
            return 1;
        }

        if (cmd[1] == "~")
            x = 0;
        else
            x = std::stoi(cmd[1]);

        if (cmd[2] == "~")
            y = 0;
        else
            y = std::stoi(cmd[2]);

        Ctrl->move(x, y);
        break;
    case hash("set"):
        break;
    case hash("pen"):
        break;
    case hash("get"):
        break;
    case hash("reset"):
        Ctrl->reset_position();
        break;
    case hash("setsize"):
        if (cmd.size() < 3)
        {
            std::cout << "Not enough arguments!" << std::endl;
            return 1;
        }

        x = std::stoi(cmd[1]);
        y = std::stoi(cmd[2]);
        Ctrl->set_size(x, y);
        std::cout << "Set canvas size to " << x << ", " << y << std::endl;
        break;
    case hash("echo"):
        for (int i = 1; i < cmd.size(); i++)
            std::cout << cmd[i] << " ";
        std::cout << std::endl;
        break;
    default:
        std::cout << "Unknown command! Type help to see all commands." << std::endl;
        break;
    }

    return 0;
}
} // namespace Wammus
