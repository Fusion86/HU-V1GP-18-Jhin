#include "BrickPi3.h"

#define PORT_PEN PORT_A
#define PORT_X PORT_B
#define PORT_Y PORT_C

#define X_RAIL_LENGTH 344
#define Y_RAIL_LENGTH 3820
#define X_MOTOR_SPEED 30
#define Y_MOTOR_SPEED 60

class Jhin
{
public:
  Jhin();
  void reset();
  void print_help();
  void print_info();
  void motor_status();
  void run(); // Temp for development

private:
  BrickPi3 BP;
};
