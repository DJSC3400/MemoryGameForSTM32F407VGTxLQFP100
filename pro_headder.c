/*
 * pro_headder.c
 *
 *  Created on: Apr 4, 2023
 *      Author: crawfordd1
 */

#include "pro_headder.h"
#include "main.h"
#include <stdint.h>

void def_delay(uint32_t delay){
	for(uint32_t i = 0; i < delay*10000; i++){}
}

void SEVSEG(uint8_t num){ //LED masks for a seven segment display
	switch(num+1){
	case 1: // number 0
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_SET);
		break;
	case 2: // number 1
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_SET);
		break;
	case 3: // number 2
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_SET); //
		break;
	case 4: // number 3
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_SET); //
		break;
	case 5: // number 4
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_SET); //
		break;
	case 6: // number 5
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_SET); //
		break;
	case 7: // number 6
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_SET); //
		break;
	case 8: // number 7
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_RESET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_RESET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_RESET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_SET);
		break;
	case 9: // number 8
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_SET); //
		break;
	case 10: // number 9
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_RESET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_SET); //
		break;
	case 11: // letter A
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_RESET);
		break;
	case 12: // letter b
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_RESET);
		break;
	case 13: // letter C problem
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_SET); //
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_RESET);
		break;
	case 14: // letter d
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_SET);//
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_SET);//
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_RESET);
		break;
	case 15: // Asterisk "*"
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_RESET);
		break;
	case 16: // hashtag "#"
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_RESET);
		break;
	default:
		HAL_GPIO_WritePin(SEG_GPIO, SEG_A, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_B, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_C, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_D, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_E, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_F, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_G, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_GPIO, SEG_DP, GPIO_PIN_SET);
		break;
	}
}

int8_t KEY_SEG(int8_t loop){
	int8_t val = -1;
	if(loop){
		while(val == -1){
			  HAL_GPIO_WritePin(GPIOB, PIN_ROW0, GPIO_PIN_SET);
			  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL0)){
				  SEVSEG(1);
				  val = 1;
			  }
			  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL1)){
				  SEVSEG(2);
				 val = 2;
			  }
			  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL2)){
				  SEVSEG(3);
				  val = 3;
			  }

			  //if(HAL_GPIO_ReadPin(GPIOB, PIN_COL3)){SEVSEG(4);}

			  HAL_GPIO_WritePin(GPIOB, PIN_ROW0, GPIO_PIN_RESET);

			  HAL_GPIO_WritePin(GPIOB, PIN_ROW1, GPIO_PIN_SET);
			  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL0)){
				  SEVSEG(4);
				  val = 4;
			  }
			  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL1)){
				  SEVSEG(5);
				  val = 5;
			  }
			  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL2)){
				  SEVSEG(6);
				  val = 6;
			  }

			  //if(HAL_GPIO_ReadPin(GPIOB, PIN_COL3)){SEVSEG(8);}

			  HAL_GPIO_WritePin(GPIOB, PIN_ROW1, GPIO_PIN_RESET);

			  HAL_GPIO_WritePin(GPIOB, PIN_ROW2, GPIO_PIN_SET);
			  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL0)){
				  SEVSEG(7);
				  val = 7;
			  }
			  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL1)){
				  SEVSEG(8);
				  val = 8;
			  }
			  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL2)){
				  SEVSEG(9);
				  val = 9;
			  }

			 //if(HAL_GPIO_ReadPin(GPIOB, PIN_COL3)){SEVSEG(12);}

			  HAL_GPIO_WritePin(GPIOB, PIN_ROW2, GPIO_PIN_RESET);

			  HAL_GPIO_WritePin(GPIOE, PIN_ROW3, GPIO_PIN_SET);
			  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL0)){
				  SEVSEG(14); //"*"
				  val = 14;
			  }
			  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL1)){
				  SEVSEG(0);
				  val = 0;
			  }
			  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL2)){
				  SEVSEG(15); //"#"
				  val = 15;
			  }

			  //if(HAL_GPIO_ReadPin(GPIOB, PIN_COL3)){SEVSEG(16);}

			  HAL_GPIO_WritePin(GPIOE, PIN_ROW3, GPIO_PIN_RESET);
		}
		return val;
	}
	else{
		  HAL_GPIO_WritePin(GPIOB, PIN_ROW0, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL0)){
			  SEVSEG(1);
			  val = 1;
		  }
		  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL1)){
			  SEVSEG(2);
			 val = 2;
		  }
		  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL2)){
			  SEVSEG(3);
			  val = 3;
		  }

		  //if(HAL_GPIO_ReadPin(GPIOB, PIN_COL3)){SEVSEG(4);}

		  HAL_GPIO_WritePin(GPIOB, PIN_ROW0, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOB, PIN_ROW1, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL0)){
			  SEVSEG(4);
			  val = 4;
		  }
		  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL1)){
			  SEVSEG(5);
			  val = 5;
		  }
		  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL2)){
			  SEVSEG(6);
			  val = 6;
		  }

		  //if(HAL_GPIO_ReadPin(GPIOB, PIN_COL3)){SEVSEG(8);}

		  HAL_GPIO_WritePin(GPIOB, PIN_ROW1, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOB, PIN_ROW2, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL0)){
			  SEVSEG(7);
			  val = 7;
		  }
		  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL1)){
			  SEVSEG(8);
			  val = 8;
		  }
		  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL2)){
			  SEVSEG(9);
			  val = 9;
		  }

		 //if(HAL_GPIO_ReadPin(GPIOB, PIN_COL3)){SEVSEG(12);}

		  HAL_GPIO_WritePin(GPIOB, PIN_ROW2, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOE, PIN_ROW3, GPIO_PIN_SET);
		  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL0)){
			  SEVSEG(14); //"*"
			  val = 14;
		  }
		  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL1)){
			  SEVSEG(0);
			  val = 0;
		  }
		  if(HAL_GPIO_ReadPin(GPIOE, PIN_COL2)){
			  SEVSEG(15); //"#"
			  val = 15;
		  }

		  //if(HAL_GPIO_ReadPin(GPIOB, PIN_COL3)){SEVSEG(16);}

		  HAL_GPIO_WritePin(GPIOE, PIN_ROW3, GPIO_PIN_RESET);
		  return val;
	}

}

void intro(){ // quickly turns on every light and turns off every light.
	  for(uint8_t i = 0; i < 2; i++){
	  		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
	  	//	HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_SET);
	  		HAL_Delay(250);
	  		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	  	//	HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_RESET);

	  		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
	  	//	HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_SET);
	  		HAL_Delay(250);
	  		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	  		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
	  	//	HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_RESET);
	  	}
	  	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
	  	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	  	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	  	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
	  	HAL_GPIO_WritePin(GPIO_LED, RED_LED_PIN, GPIO_PIN_RESET);
	  	HAL_GPIO_WritePin(GPIO_LED, GRN_LED_PIN, GPIO_PIN_RESET);

	  	SEVSEG(100);
}


void led_blink(uint32_t delay, uint32_t blink_num, uint16_t color, uint8_t green, uint8_t orange, uint8_t red, uint8_t blue){ //1 is green, 2 is orange, 3 is red, 4 is blue.
	for(uint32_t i = 0; i<blink_num; i++){
		if(green & (color == 1)){
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
			def_delay(delay);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
			def_delay(delay);
		}
		if(orange & (color == 2)){
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
			def_delay(delay);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			def_delay(delay);
		}
		if(red & (color == 3)){
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
			def_delay(delay);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
			def_delay(delay);
		}
		if(blue & (color == 4)){
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
			def_delay(delay);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
			def_delay(delay);
		}
	}
}

void led_score(uint8_t green, uint8_t orange, uint8_t red, uint8_t blue){
	if(green == 0){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
	}

	if(orange == 0){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
	}

	if(red == 0){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
	}

	if(blue == 0){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
	}
}
