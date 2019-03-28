#include "Jhin.h"

#include "BluetoothSocket.h"

Jhin::Jhin()
{
    BP = BrickPi3();
    BP.detect();

    Car = CarKit(BP);
    Car.Config.LeftWheel = PORT_B;
    Car.Config.RightWheel = PORT_C;
}

void Jhin::print_info()
{
    char str[33]; // Room for the 32-character serial number string plus the NULL terminator.

    BP.get_manufacturer(str);
    printf("Manufacturer    : %s\n", str);

    BP.get_board(str);
    printf("Board           : %s\n", str);

    BP.get_id(str);
    printf("Serial Number   : %s\n", str);

    BP.get_version_hardware(str);
    printf("Hardware version: %s\n", str);

    BP.get_version_firmware(str);
    printf("Firmware version: %s\n", str);

    printf("Battery voltage : %.3f\n", BP.get_voltage_battery());
    printf("9v voltage      : %.3f\n", BP.get_voltage_9v());
    printf("5v voltage      : %.3f\n", BP.get_voltage_5v());
    printf("3.3v voltage    : %.3f\n", BP.get_voltage_3v3());
}

void Jhin::print_help()
{
    std::cout << "Jhin v" << xstr(jhin_VERSION)
              << "\n\n"
              << "COMMANDS:\n"
              << "  help - print this help page\n"
              << "  info - print info about device (serial/voltage/etc)\n"
              << "  test - execute test code\n"
              << "  linerider - follow line\n"
              << "  police - do a wee-ooo wee-ooo\n"
              << "  remote - remote control with bluetooth app\n"
              << std::endl;
}

void Jhin::test()
{
    Car.set_right_dps(90);
    Car.set_left_dps(-90);
    sleep(2);
    Car.set_right_dps(0);
    Car.set_left_dps(0);
}

void Jhin::linerider()
{
    int timeout;
    sensor_light_t light{};
    sensor_ultrasonic_t sonic{}; // Gotta go fast
    sensor_touch_t touch{};
    BP.set_sensor_type(PORT_2, SENSOR_TYPE_NXT_ULTRASONIC);
    BP.set_sensor_type(PORT_3, SENSOR_TYPE_NXT_LIGHT_ON);
    BP.set_sensor_type(PORT_4, SENSOR_TYPE_TOUCH);

    std::cout << "Calibration: " << std::endl;

    std::cout << "Calibrate light surface: " << std::endl;
    do {
        BP.get_sensor(PORT_4, touch);
    }
    while (!touch.pressed);

    sleep(2);

    BP.get_sensor(PORT_3, light);
    int lightSurface = light.reflected;

    std::cout << "Light surface calibrated." << std::endl;

    std::cout << "Calibrate dark surface: " << std::endl;
    do {
        BP.get_sensor(PORT_4, touch);
    }
    while (!touch.pressed);

    BP.get_sensor(PORT_3, light);
    int darkSurface = light.reflected;

    std::cout << "Dark surface calibrated." << std::endl;

    std::cout << "Light surface: " << lightSurface << std::endl;
    std::cout << "Dark surface: " << darkSurface << std::endl;

    while (true)
    {
        timeout = 0;
        BP.get_sensor(PORT_2, sonic);
        BP.get_sensor(PORT_3, light);

        while (sonic.cm > LINERIDER_OBJECT_DISTANCE)
        {
            // Following line
            Car.set_left_dps(LINERIDER_SPEED * 1);
            BP.set_sensor_type(PORT_1, SENSOR_TYPE_NXT_COLOR_GREEN);
            Car.set_right_dps(0);

            // Robot lost the line, need to find it again
            BP.set_sensor_type(PORT_1, SENSOR_TYPE_NXT_COLOR_GREEN);
            Car.set_left_dps(0);
            Car.set_right_dps(LINERIDER_SPEED);

            // Evading obstacle
            BP.set_sensor_type(PORT_1, SENSOR_TYPE_NXT_COLOR_RED);

            Car.turn_right();
            timeout = 500;
        }

        std::cout << "Ambient: " << light.ambient << std::endl;
        std::cout << "Reflected: " << light.reflected << std::endl;
        std::cout << "Centimeters: " << sonic.cm << std::endl;
        std::cout << "Timeout: " << timeout << std::endl;
        usleep(timeout);
    }
}

void Jhin::reset()
{
    BP.reset_all(); // Reset everything so there are no run-away motors
}

void Jhin::police()
{
    while (true)
    {
        BP.set_sensor_type(PORT_4, SENSOR_TYPE_NXT_COLOR_RED);
        sleep(1);
        BP.set_sensor_type(PORT_4, SENSOR_TYPE_NXT_COLOR_BLUE);
        sleep(1);
    }
}

//void Jhin::remote_control()
//{
//    BluetoothServerSocket serversock(2, 1); // Channel 2
//    std::cout << "listening" << std::endl;
//    while (true)
//    {
//        bool colorToggle;
//        BluetoothSocket *clientsock = serversock.accept();
//        std::cout << "accepted from " << clientsock->getForeignAddress().getAddress() << std::endl;
//        MessageBox &mb = clientsock->getMessageBox();
//
//        std::string input;
//        while (mb.isRunning())
//        {
//            input = mb.readMessage(); // Non-blocking
//            if (input != "")
//                std::cout << std::endl
//                     << input << std::endl;
//
//            if (input == "UP") {
//                Car.set_left_dps(500);
//                Car.set_right_dps(500);
//                sleep(1);
//                Car.set_left_dps(0);
//                Car.set_right_dps(0);
//            } else if (input == "DOWN") {
//                Car.set_left_dps(-500);
//                Car.set_right_dps(-500);
//                sleep(1);
//                Car.set_left_dps(0);
//                Car.set_right_dps(0);
//            } else if (input == "LEFT") {
//                Car.set_left_dps(500);
//                sleep(1);
//                Car.set_left_dps(0);
//            } else if (input == "RIGHT") {
//                Car.set_right_dps(500);
//                sleep(1);
//                Car.set_right_dps(0);
//            } else if (input == "FIRE") {
//                if (colorToggle)
//                    BP.set_sensor_type(PORT_1, SENSOR_TYPE_NXT_COLOR_RED);
//                else
//                    BP.set_sensor_type(PORT_1, SENSOR_TYPE_NXT_COLOR_BLUE);
//
//                colorToggle = !colorToggle;
//            } else if (input == "A") {
//            } else if (input == "B") {
//            } else if (input == "C") {
//            }
//
//            std::cout << ".";
//            std::cout.flush();
//            usleep(500000); // Wait 500 ms
//        }
//
//        clientsock->close();
//    }
//}
