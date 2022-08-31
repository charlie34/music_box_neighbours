/*
 * frame_parser.h
 *
 *  Created on: 15 ago. 2022
 *      Author: Carlos
 */

#ifndef FRAME_PARSER_H_
#define FRAME_PARSER_H_
#include "engine.h"
#include "frame_decoder.h"
void command(UART_HandleTypeDef huart,uint8_t cmd,temporizacion *time_temp,uint8_t hora,uint8_t minuto,uint8_t segundo,uint8_t track);


#endif /* FRAME_PARSER_H_ */
