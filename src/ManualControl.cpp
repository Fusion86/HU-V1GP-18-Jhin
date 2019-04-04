#include "ManualControl.h"

#include "Jhin.h"

ManualControl::ManualControl() {
}

ManualControl::ManualControl(BrickPi3 bp) {
	BP = bp;
}
void ManualControl::x_forward() {
	BP.set_motor_position_relative(PORT_X, X_RAIL_LENGTH);
}

void ManualControl::x_backward() {
	BP.set_motor_position_relative(PORT_X, -X_RAIL_LENGTH);
}

void ManualControl::y_forward() {
	BP.set_motor_position_relative(PORT_Y, Y_RAIL_LENGTH);
}

void ManualControl::y_backward() {
	BP.set_motor_position_relative(PORT_Y, -Y_RAIL_LENGTH);
}

void ManualControl::pen_down() {
	BP.set_motor_position_relative(PORT_PEN, 15);
}

void ManualControl::pen_up() {
	BP.set_motor_position_relative(PORT_PEN, -15);
}
