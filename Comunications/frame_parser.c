/*
 * frame_parser.c
 *
 *  Created on: 15 ago. 2022
 *      Author: Carlos
 */
#include "frame_parser.h"
#include "engine.h"
#include "main.h"
void command(UART_HandleTypeDef *huart,uint8_t cmd,temporizacion *time_temp,uint8_t hora,uint8_t minuto,uint8_t segundo,uint8_t track){
  	switch(cmd){
  	case 0x01:{
  		sheduling_prog(time_temp,hora,minuto,segundo,track);
  		 char buffer[14]={'H','E','L','L','O',0,0,0,0,0x01,0,0,0x01,0xEF};
  		HAL_UART_Transmit(&huart, buffer, sizeof(buffer), 100);
  	}
  	}
}
