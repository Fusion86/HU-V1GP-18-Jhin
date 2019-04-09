#include "BrickPi3.h"
#include "Config.h"
#include "MotorControl.h"
#include "Wammus.h"

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
    void calibrate();

  private:
    BrickPi3 BP;
    MotorControl Ctrl;
};
