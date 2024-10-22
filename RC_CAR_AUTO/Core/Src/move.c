/*
 * move.c
 *
 *  Created on: Jul 14, 2024
 *      Author: user
 */


#include "move.h"

void go()
{
	TIM3->CCR1 = 700;
	TIM3->CCR2 = 700;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
	backflag=0;
}

void back()
{
  	TIM3->CCR1 = 700;
  	TIM3->CCR2 = 700;
  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
  	backflag=1;
}

void left()
{
  	TIM3->CCR1 = 1000;
  	TIM3->CCR2 = 1000;
  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
  	backflag=0;
}

void right()
{
  	TIM3->CCR1 = 1000;
  	TIM3->CCR2 = 1000;
  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);
  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
  	backflag=0;
}

void stop()
{
  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);
  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
  	backflag=0;
}

void goright()
{
  	TIM3->CCR1 = 1000;
  	TIM3->CCR2 = 500;
  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);
  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
  	backflag=0;
}

void goleft()
{
  	TIM3->CCR2 = 1000;
  	TIM3->CCR1 = 500;
  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);
  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
  	backflag=0;
}

void backright()
{
  	TIM3->CCR1 = 1000;
  	TIM3->CCR2 = 500;
  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
  	backflag=1;
}

void backleft()
{
  	TIM3->CCR2 = 1000;
  	TIM3->CCR1 = 500;
  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
  	backflag=1;
}

void autocar()
{

	HC_SR04();
	if(distance2 < 30){
		if(distance1<distance3){
			right();
			HAL_Delay(10);
		}
		else if(distance3<distance1){
			left();
			HAL_Delay(10);
		}
	}
	else if (distance1 < 8) {right(); HAL_Delay(10);}
	else if (distance3 < 8) {left(); HAL_Delay(10);}
	else go();
}

