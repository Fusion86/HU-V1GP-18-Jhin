#include <iostream>

#include <signal.h> // for catching exit signals

#include "Jhin.h"

Jhin j;

void exit_signal_handler(int signo);

int main(int argc, char **argv)
{
    signal(SIGINT, exit_signal_handler); // register the exit function for Ctrl+C

    if (argc < 2)
    {
        std::cerr << "No argument given \n"
                  << std::endl;
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
    else if (strcmp(argv[1], "run") == 0)
    {
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
