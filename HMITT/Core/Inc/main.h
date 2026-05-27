/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Verde_Pin GPIO_PIN_13
#define Verde_GPIO_Port GPIOC
#define PWM_DEC_Pin GPIO_PIN_14
#define PWM_DEC_GPIO_Port GPIOC
#define PWM_DEC_EXTI_IRQn EXTI15_10_IRQn
#define Amarillo_Pin GPIO_PIN_15
#define Amarillo_GPIO_Port GPIOC
#define Rojo_Pin GPIO_PIN_0
#define Rojo_GPIO_Port GPIOA
#define RESET_Pin GPIO_PIN_2
#define RESET_GPIO_Port GPIOA
#define DC_Pin GPIO_PIN_3
#define DC_GPIO_Port GPIOA
#define SPI1_NSS_Pin GPIO_PIN_4
#define SPI1_NSS_GPIO_Port GPIOA
#define Paro_Pin GPIO_PIN_0
#define Paro_GPIO_Port GPIOB
#define Paro_EXTI_IRQn EXTI0_IRQn
#define Cremallera_Pin GPIO_PIN_1
#define Cremallera_GPIO_Port GPIOB
#define Cremallera_EXTI_IRQn EXTI1_IRQn
#define Reset_Pin GPIO_PIN_2
#define Reset_GPIO_Port GPIOB
#define Reset_EXTI_IRQn EXTI2_IRQn
#define PWM_INC_Pin GPIO_PIN_12
#define PWM_INC_GPIO_Port GPIOB
#define PWM_INC_EXTI_IRQn EXTI15_10_IRQn
#define ParoE_Pin GPIO_PIN_13
#define ParoE_GPIO_Port GPIOB
#define ParoE_EXTI_IRQn EXTI15_10_IRQn
#define T_IRQ_Pin GPIO_PIN_8
#define T_IRQ_GPIO_Port GPIOA
#define T_IRQ_EXTI_IRQn EXTI9_5_IRQn
#define T_CS_Pin GPIO_PIN_9
#define T_CS_GPIO_Port GPIOA
#define Pinzas_Pin GPIO_PIN_10
#define Pinzas_GPIO_Port GPIOA
#define Pinzas_EXTI_IRQn EXTI15_10_IRQn
#define Ruedas_Pin GPIO_PIN_11
#define Ruedas_GPIO_Port GPIOA
#define Ruedas_EXTI_IRQn EXTI15_10_IRQn
#define Cerrar_Pin GPIO_PIN_3
#define Cerrar_GPIO_Port GPIOB
#define Cerrar_EXTI_IRQn EXTI3_IRQn
#define Abrir_Pin GPIO_PIN_4
#define Abrir_GPIO_Port GPIOB
#define Abrir_EXTI_IRQn EXTI4_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
