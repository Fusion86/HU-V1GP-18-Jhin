#include <iostream>

#include <signal.h> // For catching exit signals

#include "ColorMod.h"
#include "Jhin.h"

Jhin j;

void exit_signal_handler(int signo);

int main(int argc, char **argv)
{
    signal(SIGINT, exit_signal_handler); // Register the exit function for Ctrl+C

    if (argc < 2)
    {
        std::cerr << Color::ForegroundRed << "No argument given \n" << Color::Default << std::endl;
        j.print_help();
        return 1;
    }

    if (strcmp(argv[1], "help") == 0)
    {
        j.print_help();
    }
    else if (strcmp(argv[1], "info") == 0)
    {
        j.print_info();
    }
    else if (strcmp(argv[1], "line") == 0)
    {

    }
    else if (strcmp(argv[1], "rect") == 0)
    {
        
    }
    else if (strcmp(argv[1], "vector") == 0)
    {
        if (argc < 3)
        {
            std::cerr << Color::ForegroundRed << "No vector file specified" << Color::Default << std::endl;
            return 1;
        }
    }
    else if (strcmp(argv[1], "status") == 0)
    {
        j.motor_status();
    }
    else if (strcmp(argv[1], "run") == 0)
    {
        // TODO: Split this into multiple functions
        j.run();
    }

    j.reset();
    return 0;
}

void exit_signal_handler(int signo)
{
    if (signo == SIGINT)
    {
        j.reset();
        exit(-2);
    }
}
