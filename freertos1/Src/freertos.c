/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId FlashBlueTaskHandle;
osThreadId FlashRedTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void BlueTask(void const * argument);
void RedTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];
  
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}                   
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
	HAL_GPIO_WritePin(GPIOB, LD1_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, LD2_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, LD3_Pin, 0);
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
#ifndef observation
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);
#endif

  /* definition and creation of FlashBlueTask */
#if ((observationA2 == 1) || (observationB2 == 1))
#elif  (observationC2 == 1)
  osThreadDef(FlashBlueTask, BlueTask, osPriorityHigh, 0, 128);
  FlashBlueTaskHandle = osThreadCreate(osThread(FlashBlueTask), NULL);
#else
  osThreadDef(FlashBlueTask, BlueTask, osPriorityNormal, 0, 128);
  FlashBlueTaskHandle = osThreadCreate(osThread(FlashBlueTask), NULL);
#endif

  /* definition and creation of FlashRedTask */
#if ((observationA1 == 1) || (observationB1 == 1))
#else
	#if ((observationB1 == 1) || (observationB2 == 1) || (observationB3 == 1))
	  osThreadDef(FlashRedTask, RedTask, osPriorityLow, 0, 128);
	#elif  (observationC3 == 1)
	  osThreadDef(FlashRedTask, RedTask, osPriorityHigh, 0, 128);
	#else
	  osThreadDef(FlashRedTask, RedTask, osPriorityNormal, 0, 128);
	#endif
	  FlashRedTaskHandle = osThreadCreate(osThread(FlashRedTask), NULL);
#endif

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{

  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
//	  if(HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin) == 1)
//	  {
//		  compteur = 0;
//		  drapeau = 0;
//		  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 0);
//#ifdef led_rouge
//		  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 1);
//#else
//		  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 0);
//#endif
//		  HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
//		  while(compteur < 1000000){
//			  compteur ++;
//		  }
//		  compteur = 0;
//		  HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
//		  while(compteur < 1000000){
//			  compteur ++;
//		  }
//		  compteur = 0;
//	  }
//	  else
//	  {
//		  if(drapeau == 0){
//			  //HAL_Delay(500);
//			  while(compteur < 10000000){
//				  compteur ++;
//			  }
//			  drapeau = 1;
//		  }
//		  HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, 0);
//		  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 1);
//#ifdef led_rouge
//		  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 1);
//#else
//		  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 0);
//#endif
//	  }
//    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_BlueTask */
/**
* @brief Function implementing the FlashBlueTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_BlueTask */
void BlueTask(void const * argument)
{
  /* USER CODE BEGIN BlueTask */
	int compteur;
  /* Infinite loop */
  for(;;)
  {
	  compteur = 0;
	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 1);
	  osDelay(2500);
	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 0);
#if observationC1  == 1 || observationC2 == 1 || observationC3 == 1
	  while(compteur++ < 40000000);
#else
	  osDelay(2500);
#endif
  }
  /* USER CODE END BlueTask */
}

/* USER CODE BEGIN Header_RedTask */
/**
* @brief Function implementing the FlashRedTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_RedTask */
void RedTask(void const * argument)
{
  /* USER CODE BEGIN RedTask */
  /* Infinite loop */
  for(;;)
  {
		  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 1);
		  osDelay(50);
		  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 0);
		  osDelay(50);
  }
  /* USER CODE END RedTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
