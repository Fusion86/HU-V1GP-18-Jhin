#include <iostream>

#include "Jhin.h"

int main(int argc, char *argv[])
{
    Jhin j;

    if (argc < 2)
    {
        std::cerr << "No argument given" << std::endl;
        j.print_help();
        return 1;
    }

    if (strcmp(argv[1], "version") == 0)
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
    else
    {
        std::cerr << "Invalid argument" << std::endl;
        return 1;
    }

    return 0;
}
