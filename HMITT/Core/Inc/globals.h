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
extern volatile uint8_t selected_actuator;
extern volatile float roll;
extern volatile float pitch;
extern volatile uint8_t flag_paro_e;
extern volatile char act[3];
extern volatile uint32_t last_telemetry_time;
#endif /* INC_GLOBALS_H_ */
