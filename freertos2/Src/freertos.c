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
osThreadId ClignotementLedHandle;
osThreadId SuspendLedTaskHandle;
osThreadId GestionConpteurHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void ClignotementLedTask(void const * argument);
void SuspendTask(void const * argument);
void CompteurLed(void const * argument);

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
  /* definition and creation of ClignotementLed */
  osThreadDef(ClignotementLed, ClignotementLedTask, osPriorityNormal, 0, 128);
  ClignotementLedHandle = osThreadCreate(osThread(ClignotementLed), NULL);

  /* definition and creation of SuspendLedTask */
  osThreadDef(SuspendLedTask, SuspendTask, osPriorityHigh, 0, 128);
  SuspendLedTaskHandle = osThreadCreate(osThread(SuspendLedTask), NULL);

  /* definition and creation of GestionConpteur */
  osThreadDef(GestionConpteur, CompteurLed, osPriorityHigh, 0, 128);
  GestionConpteurHandle = osThreadCreate(osThread(GestionConpteur), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_ClignotementLedTask */
/**
  * @brief  Function implementing the ClignotementLed thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_ClignotementLedTask */
void ClignotementLedTask(void const * argument)
{

  /* USER CODE BEGIN ClignotementLedTask */
  /* Infinite loop */
  for(;;)
  {
	  HAL_GPIO_WritePin(LD3_GPIO_Port, LD1_Pin, 1);
	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 1);
	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD3_Pin, 1);
	  for(int i=0; i<cpt_led; i++)
	  {
		  HAL_GPIO_WritePin(LD3_GPIO_Port, LD1_Pin, 1);
		  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 1);
		  HAL_GPIO_WritePin(LD2_GPIO_Port, LD3_Pin, 1);
		  osDelay(250);
		  HAL_GPIO_WritePin(LD3_GPIO_Port, LD1_Pin, 0);
		  HAL_GPIO_WritePin(LD3_GPIO_Port, LD2_Pin, 0);
		  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 0);
		  osDelay(250);
	  }
	  osDelay(1000);
  }
  /* USER CODE END ClignotementLedTask */
}

/* USER CODE BEGIN Header_SuspendTask */
/**
* @brief Function implementing the SuspendLedTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_SuspendTask */
void SuspendTask(void const * argument)
{
  /* USER CODE BEGIN SuspendTask */
  /* Infinite loop */
  for(;;)
  {
	  if(appui_tactile == TOUCHE_MI_GAUCHE)
	  {
		  osThreadSuspend(ClignotementLedHandle);
		  HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, 1);
		  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 1);
		  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, 1);
	  }
	  if(appui_tactile == TOUCHE_MI_DROITE)
	  {
		  osThreadResume(ClignotementLedHandle);
	  }
    osDelay(1);
  }
  /* USER CODE END SuspendTask */
}

/* USER CODE BEGIN Header_CompteurLed */
/**
* @brief Function implementing the GestionConpteur thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_CompteurLed */
void CompteurLed(void const * argument)
{
  /* USER CODE BEGIN CompteurLed */
  /* Infinite loop */
  for(;;)
  {
	  if(appui_btn_led == 1 || appui_tactile == TOUCHE_DROITE)
	  {
		  cpt_led ++;
		  HAL_Delay(TEMPS_REBOND_BOUTON);
		  appui_btn_led = 0;
		  appui_tactile = 0;
	  }
	  if(appui_tactile == TOUCHE_GAUCHE)
	  {
		  cpt_led = 0;
		  appui_tactile = 0;
	  }
      osDelay(1);
  }
  /* USER CODE END CompteurLed */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
