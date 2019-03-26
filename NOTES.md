## Light sensor

TYPE_SENSOR_LIGHT_<OFF, ON> is for the NXT light sensor (not the NXT color sensor), in one of two modes (ambient, or reflected).

TYPE_SENSOR_RCX_LIGHT is for using a Lego RCX light sensor (with an NXT <> RCX adapter cable).

TYPE_SENSOR_COLOR_<FULL, RED, GREEN, BLUE, NONE> is for a Lego NXT color sensor, in one of 5 modes.

In mode TYPE_SENSOR_COLOR_FULL, the color number will be stored in BrickPi.Sensor[port] (where port is PORT_<1, 2, 3, 4>), and the raw ADC values for the 4 measurements will be stored in BrickPi.SensorArray[port][index] (where index is INDEX_<RED, GREEN, BLUE, BLANK>.

In modes TYPE_SENSOR_COLOR_<RED, GREEN, BLUE, NONE> (not FULL), the LED will light according to the color specified (red, green, blue, or off), and the raw ADC value of the sensor will be stored in BrickPi.Sensor[port].

For motor encoder values, you can read the variable BrickPi.Encoder[port], where the port is PORT_<A, B, C, D>.

You can add to or subtract from the encoder value using the variable BrickPi.EncoderOffset[port]. If you want to reset the encoder value to 0, you can use something like this BrickPi.EncoderOffset[port] = BrickPi.Encoder[port];

https://forum.dexterindustries.com/t/nxt-light-sensor-intensity-value/111/5