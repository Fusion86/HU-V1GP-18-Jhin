#include "BrickPi3.h"

typedef struct CarKitConfig
{
    int LeftWheel;
    int RightWheel;
};

class CarKit
{
  public:
    int Speed = 200;
    CarKitConfig Config = {};

    CarKit();
    CarKit(BrickPi3 bp);

    void set_left_dps(int dps);
    void set_right_dps(int dps);

  private:
    BrickPi3 BP;
};
