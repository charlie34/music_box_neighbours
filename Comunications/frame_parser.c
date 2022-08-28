/*
 * frame_parser.c
 *
 *  Created on: 15 ago. 2022
 *      Author: Carlos
 */
#include "frame_parser.h"
#include "engine.h"
#include "main.h"
void command(UART_HandleTypeDef huart,uint8_t cmd,temporizacion *time_temp,uint8_t hora,uint8_t minuto,uint8_t segundo,uint8_t track){
  	switch(cmd){
  	case 0x01:{
  		sheduling_prog(time_temp,hora,minuto,segundo,track,20);
  		 char buffer[14]={'H','E','L','L','O',0,0,0,0,0x01,0,0,0x01,0xEF};
  		HAL_UART_Transmit(&huart, buffer, sizeof(buffer), 100);
  		break;
  	}
  	case 0x02:{
  		flag_scheduler=1;
  		 char buffer[14]={'H','E','L','L','O',0,0,0,0,0x02,0,0,0x02,0xEF};
  		  		HAL_UART_Transmit(&huart, buffer, sizeof(buffer), 100);
  		  		break;
  	}
  	case 0x03:{
  	  		flag_scheduler=0;
  	  		 char buffer[14]={'H','E','L','L','O',0,0,0,0,0x03,0,0,0x03,0xEF};
  	  		  		HAL_UART_Transmit(&huart, buffer, sizeof(buffer), 100);
  	  		  		break;
  	  	}
  	case 0x04:{
  		 GetTime.Hours=hora;
  		GetTime.Minutes=minuto;
  		GetTime.Seconds=segundo;

  		HAL_RTC_SetTime(&hrtc, &GetTime, RTC_FORMAT_BIN);
  	  	  		 char buffer[14]={'H','E','L','L','O',0,0,0,0,0x03,0,0,0x04,0xEF};
  	  	  		  		HAL_UART_Transmit(&huart, buffer, sizeof(buffer), 100);
  	  	  		  		break;
  	  	  	}
  	}
}
