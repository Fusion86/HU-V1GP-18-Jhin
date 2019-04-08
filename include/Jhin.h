#include "BrickPi3.h"
#include "MotorControl.h"
#include "Wammus.h"

#define PORT_PEN PORT_A
#define PORT_X PORT_B
#define PORT_Y PORT_C

#define X_RAIL_LENGTH 760
#define Y_RAIL_LENGTH 6970
#define X_MOTOR_SPEED 30
#define Y_MOTOR_SPEED 60

#define PEN_ROT_MAX 140
#define STEP_SIZE 40

class Jhin
{
  public:
    Wammus::Wammus Wammus;

    Jhin();
    void reset();
    void print_help();
    void print_info();
    void motor_status();
    void manual_control();

  private:
    BrickPi3 BP;
    MotorControl Ctrl;
};
