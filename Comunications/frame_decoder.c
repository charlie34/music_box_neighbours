/*
 * frame_decoder.c
 *
 *  Created on: 13 ago. 2022
 *      Author: Carlos
 */
#include "frame_decoder.h"
#include "main.h"
void decoder(uint8_t *buffer_uart){
	 static uint8_t state_machine=0;
	 static uint8_t data_byte_pos=0;

	 // char buffer[20];
	  char header[5]={'H','E','L','L','O'};
	  for(int i=0;i<5;i++){
		  if (header[i]==*(buffer_uart+i)){
			  state_machine++;
		  }
	  }
    if (state_machine==5){
    	for (int j=5;j<14;j++){
    		buffer_tmp[j-5]=*(buffer_uart+j);
    	}
    	state_machine=0;
    }

}
uint8_t checksum_calc(uint8_t *payload){
    uint8_t tmp=0;
	for(int i=0;i<7;i++){
    	   tmp+=*(payload+i);

       }

	return tmp;
}
uint8_t error_frame(){
	uint8_t checksum_real;
	checksum_real=checksum_calc(buffer_tmp);
	uint8_t error;
	if (checksum_real==buffer_tmp[7]){
		error=0;
	}else{
		error=-1;
	}
	return error;
}
uint8_t horas(){
	return buffer_tmp[0];
}
uint8_t minutos(){
	return buffer_tmp[1];
}
uint8_t segundos(){
	return buffer_tmp[2];
}
uint8_t tracks(){
	return buffer_tmp[3];
}
uint8_t cmd_get(){
	return buffer_tmp[4];
}
uint16_t datas(){
	uint8_t data_tmp[2];
	data_tmp[0]=buffer_tmp[5];
	data_tmp[1]=buffer_tmp[6];
	return (uint16_t)data_tmp;
}
