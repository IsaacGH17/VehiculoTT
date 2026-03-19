/*
 * INA226.h
 *
 *  Created on: Mar 17, 2026
 *      Author: USER
 */

#ifndef INC_INA226_H_
#define INC_INA226_H_
#pragma once
#include <stdint.h>
#include <math.h>
#include "stm32f4xx_hal.h"
#define INA226_ADDR (0x40 << 1)
//All Register Addresses of the INA226, each Register 16 Bits in length
#define CONFIG_REG 0x00		//Config Register
#define SHUNTVOL_REG 0x01	//Shunt Voltage Register
#define BUSVOL_REG 0x02		//Bus Voltage Register
#define POWER_REG 0x03	//Power Register
#define CURRENT_REG 0x04		//Current Register
#define CALIB_REG 0x05	//Calibration Register
#define MASKEN_REG 0x06	//Mask / Enable Register
#define ALERT_REG 0x07		//Alert Register
#define MANUF_REG 0xFE	//Manufacturer ID Register
#define UNQID_REG  0xFF	//Unique ID Register
extern I2C_HandleTypeDef hi2c1;
typedef enum{		//Number of samples to be averaged
    AVERAGE_1       = 0b000,
    AVERAGE_4       = 0b001,
    AVERAGE_16      = 0b010,
    AVERAGE_64      = 0b011,
    AVERAGE_128     = 0b100,
    AVERAGE_256     = 0b101,
    AVERAGE_512     = 0b110,
    AVERAGE_1024    = 0b111
} AVG_t;

typedef enum{		//Conversion Time in us
    CONV_TIME_140   = 0b000,
    CONV_TIME_204   = 0b001,
    CONV_TIME_332   = 0b010,
    CONV_TIME_588   = 0b011,
    CONV_TIME_1100  = 0b100,
    CONV_TIME_2116  = 0b101,
    CONV_TIME_4156  = 0b110,
    CONV_TIME_8244  = 0b111
} ConvTime_t;

typedef enum {	//Measure Modes
    POWER_DOWN      	= 0b000,
    SHUNT_TRIGGERED     = 0b001,
    BUS_TRIGGERED      	= 0b010,
	SHUNTBUS_TRIGGERED	= 0b011,
	SHUNT_CONTINOUS		= 0b101,
	BUS_CONTINOUS		= 0b110,
	SHUNTBUS_CONTINOUS	= 0b111
} MeasureId_t;

void updateConfiguration(AVG_t _average, ConvTime_t _time, MeasureId_t _measure);
void calibrateDevice();
uint16_t readConfiguration();
float getShuntVol();	//Returns the current Shunt Voltage in V
float getBusVol();		//Returns the current Bus 	Voltage	in V
float getPower();		//Returns the current Power			in W
float getCurrent();		//Returns the current Current		in A




#endif /* INC_INA226_H_ */
