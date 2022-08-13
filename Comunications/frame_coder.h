/*
 * frame_coder.h
 *
 *  Created on: 11 ago. 2022
 *      Author: Carlos
 */
#include "main.h"
#ifndef FRAME_CODER_H_
#define FRAME_CODER_H_
UART_HandleTypeDef huart_tmp;
uint8_t buffer_output[14];
void init(UART_HandleTypeDef huart); //Definir la trama, de inicio y de final
void checksum();
void put_hora(uint8_t hora);
void put_minuto(uint8_t min);
void put_segundo(uint8_t seg);
void put_cancion(uint8_t track);
void put_command(uint8_t cmd);
void put_data(uint16_t data);
void send_frame(uint8_t* buffer,uint8_t size);
void send_frame_complete();


#endif /* FRAME_CODER_H_ */
