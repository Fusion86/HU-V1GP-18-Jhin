#include "BrickPi3.h"

struct CarKitConfig
{
    int Speed;
    int LeftWheel;
    int RightWheel;
};

class CarKit
{
  public:
    CarKitConfig Config = {};

    CarKit();
    CarKit(BrickPi3 bp);

    void set_left_dps(int dps);
    void set_right_dps(int dps);
    void turn_right();
    void turn_left();
    void move_forward();
    void move_backward();

  private:
    BrickPi3 BP;
};
