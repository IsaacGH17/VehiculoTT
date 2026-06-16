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

/* Porcentaje PWM actual (0-100) */
extern volatile uint16_t percentage_pulse;

/* Estado de acople del par 1 de ruedas (A / Cerrado_Pin) */
extern volatile uint8_t ruedas_abiertas;

/* Estado de acople del par 2 de ruedas (A1 / Cerrado1_Pin) */
extern volatile uint8_t ruedas1_abiertas;

/* Handle de event flags para la tarea semiautomática */
extern osEventFlagsId_t semiAutoEvtHandle;

/* Flags de evento */
#define EVT_OBSTACULO1   (1U << 0)
#define EVT_OBSTACULO2   (1U << 1)
#define EVT_STOP_SEMI    (1U << 2)
#define EVT_START_SEMI   (1U << 3)

#endif /* INC_GLOBALS_H_ */
