#pragma once

#include <string>

#include "MotorControl.h"

namespace Wammus
{
class Wammus
{
  public:
    Wammus();
    Wammus(MotorControl *ctrl);
    int run_file(const char *path);
    void prompt();
    int execute(std::string);

  private:
    MotorControl *Ctrl;

    void print_banner();
};
} // namespace Wammus
