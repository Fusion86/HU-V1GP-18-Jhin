/***********************************************************************
 * AUTHOR: Wouter Visser <Fusion86>
 *   FILE: .//BrickPi3.cpp
 *   DATE: Wed Apr 03 11:16:15 2019
 *  DESCR: 
 ***********************************************************************/
#include "BrickPi3.h"

/***********************************************************************
 *  Method: BrickPi3::BrickPi3
 *  Params: uint8_t addr
 * Effects: 
 ***********************************************************************/
BrickPi3::BrickPi3(uint8_t addr)
{
}


/***********************************************************************
 *  Method: BrickPi3::detect
 *  Params: bool critical
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::detect(bool critical)
{
}


/***********************************************************************
 *  Method: BrickPi3::get_manufacturer
 *  Params: char *str
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::get_manufacturer(char *str)
{
}


/***********************************************************************
 *  Method: BrickPi3::get_board
 *  Params: char *str
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::get_board(char *str)
{
}


/***********************************************************************
 *  Method: BrickPi3::get_version_hardware
 *  Params: char *str
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::get_version_hardware(char *str)
{
}


/***********************************************************************
 *  Method: BrickPi3::get_version_firmware
 *  Params: char *str
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::get_version_firmware(char *str)
{
}


/***********************************************************************
 *  Method: BrickPi3::get_id
 *  Params: char *str
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::get_id(char *str)
{
}


/***********************************************************************
 *  Method: BrickPi3::set_led
 *  Params: uint8_t value
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::set_led(uint8_t value)
{
}


/***********************************************************************
 *  Method: BrickPi3::get_voltage_3v3
 *  Params: 
 * Returns: float
 * Effects: 
 ***********************************************************************/
float
BrickPi3::get_voltage_3v3()
{
}


/***********************************************************************
 *  Method: BrickPi3::get_voltage_5v
 *  Params: 
 * Returns: float
 * Effects: 
 ***********************************************************************/
float
BrickPi3::get_voltage_5v()
{
}


/***********************************************************************
 *  Method: BrickPi3::get_voltage_9v
 *  Params: 
 * Returns: float
 * Effects: 
 ***********************************************************************/
float
BrickPi3::get_voltage_9v()
{
}


/***********************************************************************
 *  Method: BrickPi3::get_voltage_battery
 *  Params: 
 * Returns: float
 * Effects: 
 ***********************************************************************/
float
BrickPi3::get_voltage_battery()
{
}


/***********************************************************************
 *  Method: BrickPi3::get_voltage_3v3
 *  Params: float &voltage
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::get_voltage_3v3(float &voltage)
{
}


/***********************************************************************
 *  Method: BrickPi3::get_voltage_5v
 *  Params: float &voltage
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::get_voltage_5v(float &voltage)
{
}


/***********************************************************************
 *  Method: BrickPi3::get_voltage_9v
 *  Params: float &voltage
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::get_voltage_9v(float &voltage)
{
}


/***********************************************************************
 *  Method: BrickPi3::get_voltage_battery
 *  Params: float &voltage
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::get_voltage_battery(float &voltage)
{
}


/***********************************************************************
 *  Method: BrickPi3::set_sensor_type
 *  Params: uint8_t port, uint8_t type, uint16_t flags, i2c_struct_t *i2c_struct
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::set_sensor_type(uint8_t port, uint8_t type, uint16_t flags, i2c_struct_t *i2c_struct)
{
}


/***********************************************************************
 *  Method: BrickPi3::transact_i2c
 *  Params: uint8_t port, i2c_struct_t *i2c_struct
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::transact_i2c(uint8_t port, i2c_struct_t *i2c_struct)
{
}


/***********************************************************************
 *  Method: BrickPi3::get_sensor
 *  Params: uint8_t port, sensor_val_struct_t &sensor_val_struct
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::get_sensor(uint8_t port, sensor_val_struct_t &sensor_val_struct)
{
}


/***********************************************************************
 *  Method: BrickPi3::set_motor_power
 *  Params: uint8_t port, int8_t power
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::set_motor_power(uint8_t port, int8_t power)
{
}


/***********************************************************************
 *  Method: BrickPi3::set_motor_position
 *  Params: uint8_t port, int32_t position
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::set_motor_position(uint8_t port, int32_t position)
{
}


/***********************************************************************
 *  Method: BrickPi3::set_motor_position_relative
 *  Params: uint8_t port, int32_t position
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::set_motor_position_relative(uint8_t port, int32_t position)
{
}


/***********************************************************************
 *  Method: BrickPi3::set_motor_dps
 *  Params: uint8_t port, int16_t dps
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::set_motor_dps(uint8_t port, int16_t dps)
{
}


/***********************************************************************
 *  Method: BrickPi3::set_motor_limits
 *  Params: uint8_t port, uint8_t power, uint16_t dps
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::set_motor_limits(uint8_t port, uint8_t power, uint16_t dps)
{
}


/***********************************************************************
 *  Method: BrickPi3::get_motor_status
 *  Params: uint8_t port, uint8_t &state, int8_t &power, int32_t &position, int16_t &dps
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::get_motor_status(uint8_t port, uint8_t &state, int8_t &power, int32_t &position, int16_t &dps)
{
}


/***********************************************************************
 *  Method: BrickPi3::offset_motor_encoder
 *  Params: uint8_t port, int32_t position
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::offset_motor_encoder(uint8_t port, int32_t position)
{
}


/***********************************************************************
 *  Method: BrickPi3::reset_motor_encoder
 *  Params: uint8_t port, int32_t &value
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::reset_motor_encoder(uint8_t port, int32_t &value)
{
}


/***********************************************************************
 *  Method: BrickPi3::reset_motor_encoder
 *  Params: uint8_t port
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::reset_motor_encoder(uint8_t port)
{
}


/***********************************************************************
 *  Method: BrickPi3::set_motor_encoder
 *  Params: uint8_t port, int32_t value
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::set_motor_encoder(uint8_t port, int32_t value)
{
}


/***********************************************************************
 *  Method: BrickPi3::get_motor_encoder
 *  Params: uint8_t port, int32_t &value
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::get_motor_encoder(uint8_t port, int32_t &value)
{
}


/***********************************************************************
 *  Method: BrickPi3::get_motor_encoder
 *  Params: uint8_t port
 * Returns: int32_t
 * Effects: 
 ***********************************************************************/
int32_t
BrickPi3::get_motor_encoder(uint8_t port)
{
}


/***********************************************************************
 *  Method: BrickPi3::reset_all
 *  Params: 
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::reset_all()
{
}


/***********************************************************************
 *  Method: BrickPi3::spi_write_8
 *  Params: uint8_t msg_type, uint8_t value
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::spi_write_8(uint8_t msg_type, uint8_t value)
{
}


/***********************************************************************
 *  Method: BrickPi3::spi_read_16
 *  Params: uint8_t msg_type, uint16_t &value
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::spi_read_16(uint8_t msg_type, uint16_t &value)
{
}


/***********************************************************************
 *  Method: BrickPi3::spi_read_32
 *  Params: uint8_t msg_type, uint32_t &value
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::spi_read_32(uint8_t msg_type, uint32_t &value)
{
}


/***********************************************************************
 *  Method: BrickPi3::spi_read_string
 *  Params: uint8_t msg_type, char *str, uint8_t chars
 * Returns: int
 * Effects: 
 ***********************************************************************/
int
BrickPi3::spi_read_string(uint8_t msg_type, char *str, uint8_t chars)
{
}


