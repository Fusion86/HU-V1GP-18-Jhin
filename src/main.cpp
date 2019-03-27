#include <iostream>

#include "Jhin.h"

Jhin j;

void exit_signal_handler(int signo);

int main(int argc, char *argv[])
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
    else if (strcmp(argv[1], "version") == 0)
    {
        std::cout << "Jhin v" << xstr(jhin_VERSION) << std::endl;
    }
    else if (strcmp(argv[1], "info") == 0)
    {
        j.print_info();
    }
    else if (strcmp(argv[1], "test") == 0)
    {
        j.test();
    }
    else if (strcmp(argv[1], "linerider") == 0)
    {
        j.linerider();
    }
    else if (strcmp(argv[1], "police") == 0)
    {
        j.police();
    }
    else if (strcmp(argv[1], "remote") == 0)
    {
        j.remote_control();
    }
    else
    {
        std::cerr << "Invalid argument" << std::endl;
        return 1;
    }

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
