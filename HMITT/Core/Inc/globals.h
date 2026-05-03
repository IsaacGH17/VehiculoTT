/*
 * globals.h
 *
 *  Created on: Mar 17, 2026
 *      Author: USER
 */

#ifndef INC_GLOBALS_H_
#define INC_GLOBALS_H_
#include <stdint.h>
extern volatile float vbat;
extern volatile int pwm;
extern volatile int dist_mm;
extern volatile uint8_t selected_actuator;  /* 0=none, 1=Pinzas, 2=Ruedas, 3=Cremallera */
#endif /* INC_GLOBALS_H_ */
