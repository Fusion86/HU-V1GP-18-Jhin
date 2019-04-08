#include "Wammus.h"

#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

#include "Jhin.h"
#include "Utility.h"

namespace Wammus
{
Wammus::Wammus()
{
}

Wammus::Wammus(Jhin *parent)
{
    J = parent;
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
            if (input.empty())
                continue;

            // Split input on spaces
            std::istringstream iss(input);
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
                return;
            default:
                std::cout << "Unknown command! Type help to see all commands." << std::endl;
                break;
            }
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
} // namespace Wammus
