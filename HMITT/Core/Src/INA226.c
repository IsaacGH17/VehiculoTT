/*
 * INA226.c
 *
 *  Created on: Mar 17, 2026
 *      Author: USER
 */
#include "INA226.h"
#include <stdbool.h>
bool _reset = 0;
uint16_t _cal = 1024;
float _shuntResistance = 0.01;          // Shunt en Ohms (10mΩ)
// Con _cal=1024 y R_shunt=0.01Ω:
//   Current_LSB = 0.00512 / (1024 * 0.01) = 0.5mA/bit
float _currentResolution = 0.0005;      // 0.5mA/bit  (AJUSTADO a _cal)
float _voltageResolutionBus = 1.25e-3;  // 1.25mV/bit (fijo en INA226)
float _voltageResolutionShunt = 2.5e-6; // 2.5µV/bit  (fijo en INA226)


void updateConfiguration(AVG_t _average, ConvTime_t _time, MeasureId_t _measure)
{
	uint16_t reg = 0x0000;
	reg |= (_reset   << 15);
	reg |= (_average << 9);
	reg |= (_time    << 6);	// Bus conversion time
	reg |= (_time    << 3);	// Shunt conversion time
	reg |= _measure;

	// ESCRIBIR al registro de configuracion del INA226
	uint8_t data[2] = {(reg >> 8) & 0xFF, reg & 0xFF};
	HAL_I2C_Mem_Write(&hi2c1, INA226_ADDR, CONFIG_REG, I2C_MEMADD_SIZE_8BIT, data, 2, 200);

	calibrateDevice();
}

float getShuntVol()
{
	uint8_t data[2] = {0x00, 0x00};
	HAL_I2C_Mem_Read(&hi2c1, INA226_ADDR, SHUNTVOL_REG, I2C_MEMADD_SIZE_8BIT, data, 2, 200);
	return (float)((int16_t)((data[0] << 8) + data[1]) * _voltageResolutionShunt);
}

float getBusVol()
{
	uint8_t data[2] = {0x00, 0x00};
	HAL_I2C_Mem_Read(&hi2c1, INA226_ADDR, BUSVOL_REG, I2C_MEMADD_SIZE_8BIT, data, 2, 200);
	return (float)(((data[0] << 8) + data[1]) * _voltageResolutionBus);
}

float getPower()
{
	uint8_t data[2] = {0x00, 0x00};
	HAL_I2C_Mem_Read(&hi2c1, INA226_ADDR, POWER_REG, I2C_MEMADD_SIZE_8BIT, data, 2, 200);
	return (float)(((data[0] << 8) + data[1]) * 25 * _currentResolution);
}

float getCurrent()
{
	uint8_t data[2] = {0x00, 0x00};
	HAL_I2C_Mem_Read(&hi2c1, INA226_ADDR, CURRENT_REG, I2C_MEMADD_SIZE_8BIT, data, 2, 200);
	return (float)(((data[0] << 8) + data[1]) * _currentResolution);
}

void calibrateDevice()
{
	uint8_t data[2] = {(_cal >> 8) & 0xFF, _cal & 0xFF};
	// Enviar 2 bytes (registro de 16 bits)
	HAL_I2C_Mem_Write(&hi2c1, INA226_ADDR, CALIB_REG, I2C_MEMADD_SIZE_8BIT, data, 2, 200);
}

