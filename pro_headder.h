/*
 * pro_headder.h
 *
 *  Created on: Apr 4, 2023
 *      Author: crawfordd1
 */

#ifndef INC_PRO_HEADDER_H_
#define INC_PRO_HEADDER_H_



#endif /* INC_PRO_HEADDER_H_ */

#include <stdint.h>

#define DELAY 500000 //about half a second

#define GPIO_LED GPIOE //E for both external led's
#define RED_LED_PIN GPIO_PIN_13 //E13
#define GRN_LED_PIN GPIO_PIN_11 //E11

//COL are input pull down
#define PIN_COL3 GPIO_PIN_2 //B2 ->A
#define PIN_COL2 GPIO_PIN_8 //E8 ->3
#define PIN_COL1 GPIO_PIN_10 //E10 ->2
#define PIN_COL0 GPIO_PIN_12 //E12 ->1

//ROW are output
#define PIN_ROW3 GPIO_PIN_14 //E14 ->D
#define PIN_ROW2 GPIO_PIN_10 //B10 ->C
#define PIN_ROW1 GPIO_PIN_12 //B12 ->B
#define PIN_ROW0 GPIO_PIN_14 //B14 ->A


//7segment
#define SEG_GPIO GPIOE //All seven segment is in E0-E7
#define SEG_A GPIO_PIN_4 //E4
#define SEG_B GPIO_PIN_6 //E6
#define SEG_C GPIO_PIN_5 //E5
#define SEG_D GPIO_PIN_3 //E3
#define SEG_E GPIO_PIN_1 //E1
#define SEG_F GPIO_PIN_2 //E2
#define SEG_G GPIO_PIN_0 //E0
#define SEG_DP GPIO_PIN_7 //E7

void SEVSEG(uint8_t num); // takes a value and returns a mask input number.

int8_t KEY_SEG(int8_t loop); // displays number from pad on seven segment and returns number
uint8_t NUM_PAD(); // returns number on pad
void intro();
void def_delay(uint32_t delay); //a for loop to delay the clock similar to HAL_Delay

void led_blink(uint32_t delay, uint32_t blink_num, uint16_t color, uint8_t green, uint8_t orange, uint8_t red, uint8_t blue); //1 is green, 2 is orange, 3 is red, 4 is blue.

void led_score(uint8_t green, uint8_t orange, uint8_t red, uint8_t blue);
