#include "BrickPi3.h"

class Jhin
{
public:
  Jhin();
  void reset();
  void print_help();
  void print_info();
  void run();

private:
  BrickPi3 BP;
};
