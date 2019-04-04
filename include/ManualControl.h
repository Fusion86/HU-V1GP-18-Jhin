#include "Jhin.h"

#include "BrickPi3.h"

class ManualControl
{
	public:
	    ManualControl(BrickPi3 bp);
		void x_forward();
		void x_backward();
		void y_forward();
		void y_backward();
		void pen_down();
		void pen_up();
    private:
		BrickPi3 BP;
}