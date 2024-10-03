/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_host.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "pro_headder.h"
#include <stdint.h>
#include <stdlib.h> //random function


uint8_t guess_phase = 1; // the first half of the game is the guess phase. When true, still guessing. When false, memory phase.
uint8_t seed = 7; // This is the global seed. The number you start with does not matter because it will be changed based on player delay
uint8_t answers[4] = {};//0green, 1orange, 2red, 3 blue  : this stores the 4 random numbers
uint8_t memory_check = 0; // this manages the memory phase of the game.
uint8_t repeat_intro = 0; // if true, the intro repeats. if false, the intro does not repeat

int game = 0; // if you played the game once this updates

uint8_t green = 1; //this enables the led's in the loop function and helps count score
uint8_t orange = 1; //this enables the led's in the loop function and helps count score
uint8_t red = 1; //this enables the led's in the loop function and helps count score
uint8_t blue = 1; //this enables the led's in the loop function and helps count score

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
I2C_HandleTypeDef hi2c1;

I2S_HandleTypeDef hi2s3;

SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2S3_Init(void);
static void MX_SPI1_Init(void);
void MX_USB_HOST_Process(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_I2S3_Init();
  MX_SPI1_Init();
  MX_USB_HOST_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */


intro();

while (1){ // main loop checks for new intro, initializes count down, generates a new pesudo random seed, checks for memory phase,
	if(repeat_intro){
		intro();
		repeat_intro = 0;
	}
	uint8_t count_down = green + orange + red + blue;
	seed = seed + rand();
	srand(seed);
	//enable = 1;
	if(!count_down){
		guess_phase = 0; // the guess phase is over and you can begin the answer phase
		green = 1;
		orange = 1;
		red = 1;
		blue = 1;
	}

	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)){ //this loop is for the first button press. the rest of the game is in the interrupt

		if (game == 0){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
		def_delay(500);
		}

		if (game == 0){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
		def_delay(500);
		}

		if (game == 0){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
		def_delay(500);
		}

		if (game == 0){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		def_delay(500);
		}

		game = 0;
	}



	/* USER CODE END WHILE */
	MX_USB_HOST_Process();

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2S3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2S3_Init(void)
{

  /* USER CODE BEGIN I2S3_Init 0 */

  /* USER CODE END I2S3_Init 0 */

  /* USER CODE BEGIN I2S3_Init 1 */

  /* USER CODE END I2S3_Init 1 */
  hi2s3.Instance = SPI3;
  hi2s3.Init.Mode = I2S_MODE_MASTER_TX;
  hi2s3.Init.Standard = I2S_STANDARD_PHILIPS;
  hi2s3.Init.DataFormat = I2S_DATAFORMAT_16B;
  hi2s3.Init.MCLKOutput = I2S_MCLKOUTPUT_ENABLE;
  hi2s3.Init.AudioFreq = I2S_AUDIOFREQ_96K;
  hi2s3.Init.CPOL = I2S_CPOL_LOW;
  hi2s3.Init.ClockSource = I2S_CLOCK_PLL;
  hi2s3.Init.FullDuplexMode = I2S_FULLDUPLEXMODE_DISABLE;
  if (HAL_I2S_Init(&hi2s3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2S3_Init 2 */

  /* USER CODE END I2S3_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_11|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OTG_FS_PowerSwitchOn_GPIO_Port, OTG_FS_PowerSwitchOn_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10|GPIO_PIN_12|GPIO_PIN_14, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin
                          |Audio_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PE2 PE3 PE4 PE5
                           PE6 PE7 PE11 PE13
                           PE0 PE1 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_11|GPIO_PIN_13
                          |GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : OTG_FS_PowerSwitchOn_Pin */
  GPIO_InitStruct.Pin = OTG_FS_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OTG_FS_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PDM_OUT_Pin */
  GPIO_InitStruct.Pin = PDM_OUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(PDM_OUT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB2 */
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PE8 PE10 PE12 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : PE14 */
  GPIO_InitStruct.Pin = GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB12 PB14 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_12|GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : LD4_Pin LD3_Pin LD5_Pin LD6_Pin
                           Audio_RST_Pin */
  GPIO_InitStruct.Pin = LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin
                          |Audio_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : OTG_FS_OverCurrent_Pin */
  GPIO_InitStruct.Pin = OTG_FS_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(OTG_FS_OverCurrent_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

}

/* USER CODE BEGIN 4 */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	def_delay(100); // delay to wait for button to stabilize
	uint8_t rand_num = rand() % 10; // this makes a random number between 0 to 9

	if(GPIO_Pin == GPIO_PIN_0){// put all of your interrupt code for A0 here
		uint8_t light_blink = 0;
		// this is the guess phase. you have unlimited guesses at the light that you exited the loop on.
		while((!HAL_GPIO_ReadPin(GPIOA, GPIO_Pin)) & (guess_phase)){

			if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_12) & green){
				light_blink = 1;
			}
			else if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_13) & orange){
				light_blink = 2;
			}
			else if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_14) & red){
				light_blink = 3;
			}
			else if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_15) & blue){
				light_blink = 4;
			}
			led_blink(100, 1, light_blink, green, orange, red, blue);
			int8_t user_input = KEY_SEG(0);

			if(user_input == -1){ // the default value of KEY_SEG is -1 and this filters that output
				HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_RESET);
			}
			else if(user_input == 14){ // if the star is pressed, the rand_num is displayed
				SEVSEG(rand_num);
			}
			else if(user_input == 15){ // if the pound sign is pushed, the lights blink
				HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_SET);
				def_delay(250);
				HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_SET);
				def_delay(250);
				HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_RESET);
			}
			else if(user_input == rand_num){ // if the user number is equal to the random number, the lights do a little party
				if(light_blink == 1){
					HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
					answers[0] = rand_num;
					green = 0;
					led_score(green, orange, red, blue);
				}
				if(light_blink == 2){
					HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
					answers[1] = rand_num;
					orange = 0;
					led_score(green, orange, red, blue);
				}
				if(light_blink == 3){
					HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
					answers[2] = rand_num;
					red = 0;
					led_score(green, orange, red, blue);
				}
				if(light_blink == 4){
					HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
					answers[3] = rand_num;
					blue = 0;
					led_score(green, orange, red, blue);
				}
				light_blink = 0;
				//enable = 0;
				game++;
/*
				for(uint8_t i=0;i<10;i++){
					HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_SET);
					def_delay(250-25*i);
					HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_SET);
					def_delay(250-25*i);
					HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_RESET);
				}
				HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_SET);
				def_delay(250);
				HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_RESET);

*/
				return;
			}
			else if(user_input < rand_num){ // if the random number is larger than the user input, the red light turns on
				HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_SET);
				def_delay(250);
				SEVSEG(-1);
				HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_RESET);
			}
			else if(user_input > rand_num){// if the random number is less than the user input, the green light turns on
				HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_SET);
				def_delay(250);
				SEVSEG(-1);
				HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_RESET);
			}
		}

		if((!HAL_GPIO_ReadPin(GPIOA, GPIO_Pin)) & (!guess_phase)){
			repeat_intro = 1;
			for(uint8_t i = 1; i<5; i++){

				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
				led_blink(200, 3, i, green, orange, red, blue);
				SEVSEG(-1);
				uint8_t user_input = KEY_SEG(1);
				if(answers[i-1] == user_input){
					memory_check++;
				}
			}
			if(memory_check == 4){ //do light party
				//led_circle(uint32_t delay, uint32_t blink_num, uint8_t enable, uint8_t clockwise, uint8_t green,uint8_t orange, uint8_t red, blue);
				for(uint8_t i=0;i<10;i++){
					HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_SET);
					def_delay(250-25*i);
					HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_SET);
					def_delay(250-25*i);
					HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_RESET);
				}
				HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_SET);
				def_delay(250);
				HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_RESET);
			}

			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);

			guess_phase = 1;
			seed = seed + rand();
			for(uint8_t i = 0; i<4;i++){
				answers[i] = 11;
			}
			//reset all memory to begin new game
			memory_check = 0;
			//enable = 1;
			game = 1; // if you played the game once this updates
			green = 1; //this enables the led's in the loop function
			orange = 1; //this enables the led's in the loop function
			red = 1; //this enables the led's in the loop function
			blue = 1; //this enables the led's in the loop function
		}

	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
