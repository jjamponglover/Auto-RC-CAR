/*
 * song.c
 *
 *  Created on: Jul 14, 2024
 *      Author: user
 */
#include "song.h"

uint16_t elise[] = {Mii, Miib, Mii, Miib, Mii, Si, Ree, Doo, Ra, Do, Mi, Ra, Si, Mi, Rab, Si, Doo,
	  	  	  	  	  	Mi, Mii, Miib, Mii, Miib, Mii, Si, Ree, Doo, Ra, Do, Mi, Ra, Si, Re, Doo, Si, Ra};
uint16_t elisetime[] = {hNote, hNote, hNote, hNote, hNote, hNote, hNote, hNote, pNote,
						hNote, hNote, hNote, pNote, hNote, hNote, hNote, pNote,
						hNote, hNote, hNote, hNote, hNote, hNote, hNote, hNote, hNote, pNote,
						hNote, hNote, hNote, pNote, hNote, hNote, hNote, dNote};
uint16_t domisol[] = {Do, Mi, Sol};
uint16_t domisoltime[] = {pNote, pNote, pNote};

void backsong()
{
	while(backflag==1){
		int i = 0;
		for(i = 0; i < 35; i++)
		{
		TIM5->CCR2 = 500;
		TIM5->PSC = elise[i];
		HAL_Delay(elisetime[i]);
		TIM5->CCR2 = 0;
		HAL_Delay(5);
		if(backflag==0)break;
		}
	}
};
