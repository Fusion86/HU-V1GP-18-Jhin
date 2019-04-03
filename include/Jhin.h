#include "BrickPi3.h"

#define PORT_WHEELS PORT_A
#define PORT_AXIS PORT_B
#define PORT_PEN PORT_C

class Jhin
{
public:
  Jhin();
  void reset();
  void print_help();
  void print_info();
  void motor_status();

private:
  BrickPi3 BP;
};
