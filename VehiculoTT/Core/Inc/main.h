/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Abierto_Pin GPIO_PIN_14
#define Abierto_GPIO_Port GPIOC
#define Cerrado_Pin GPIO_PIN_15
#define Cerrado_GPIO_Port GPIOC
#define ADC_tension_Pin GPIO_PIN_0
#define ADC_tension_GPIO_Port GPIOA
#define Servo2_Pin GPIO_PIN_1
#define Servo2_GPIO_Port GPIOA
#define Servo1_Pin GPIO_PIN_5
#define Servo1_GPIO_Port GPIOA
#define Direccion1_Pin GPIO_PIN_7
#define Direccion1_GPIO_Port GPIOA
#define Direccion2_Pin GPIO_PIN_0
#define Direccion2_GPIO_Port GPIOB
#define Motor1_Pin GPIO_PIN_8
#define Motor1_GPIO_Port GPIOA
#define Motor2_Pin GPIO_PIN_9
#define Motor2_GPIO_Port GPIOA
#define Motor3_Pin GPIO_PIN_10
#define Motor3_GPIO_Port GPIOA
#define Motor4_Pin GPIO_PIN_11
#define Motor4_GPIO_Port GPIOA
#define Direccion3_Pin GPIO_PIN_12
#define Direccion3_GPIO_Port GPIOA
#define Direccion4_Pin GPIO_PIN_15
#define Direccion4_GPIO_Port GPIOA
#define A_Dir_Pin GPIO_PIN_4
#define A_Dir_GPIO_Port GPIOB
#define Acople_Pin GPIO_PIN_5
#define Acople_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
