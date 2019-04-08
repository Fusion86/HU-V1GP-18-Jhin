#pragma once

class Jhin; // Forward declare

namespace Wammus
{
class Wammus
{
  public:
    Wammus();
    Wammus(Jhin *parent);
    int run_file(const char *path);
    void prompt();

  private:
    Jhin *J;

    void print_banner();
};
} // namespace Wammus
