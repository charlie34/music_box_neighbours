/*
 * frame_decoder.h
 *
 *  Created on: 13 ago. 2022
 *      Author: Carlos
 */
#include "main.h"
#ifndef FRAME_DECODER_H_
#define FRAME_DECODER_H_
uint8_t checksum_tmp;
uint8_t buffer_tmp[14];
 uint8_t hora;
uint8_t minuto;
uint8_t segundo;
uint8_t track;
uint8_t cmd;
uint16_t *data_dec;
uint16_t data;
void decoder(uint8_t symbol);
uint8_t checksum_calc(uint8_t *payload);
uint8_t error_frame();
uint8_t horas();
uint8_t minutos();
uint8_t segundos();
uint8_t tracks();
uint16_t datas();



#endif /* FRAME_DECODER_H_ */
