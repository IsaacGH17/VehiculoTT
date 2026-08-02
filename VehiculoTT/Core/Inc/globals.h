/*
 * globals.h
 *
 *  Created on: Mar 17, 2026
 *      Author: USER
 */

#ifndef INC_GLOBALS_H_
#define INC_GLOBALS_H_
#include <stdint.h>
#include "cmsis_os.h"
extern volatile uint16_t percentage_pulse;
extern volatile uint8_t ruedas_abiertas;
extern volatile uint8_t ruedas1_abiertas;
extern volatile uint8_t dir_acoplar;
extern volatile uint8_t dir_acoplar1;
extern osEventFlagsId_t semiAutoEvtHandle;
#define EVT_OBSTACULO1   (1U << 0)
#define EVT_OBSTACULO2   (1U << 1)
#define EVT_STOP_SEMI    (1U << 2)
#define EVT_START_SEMI   (1U << 3)

#endif /* INC_GLOBALS_H_ */
