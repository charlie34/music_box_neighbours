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
	  char header[4]={'H','E','L','O'};
	  for(int i=0;i<4;i++){
		  if (header[i]==*(buffer_uart+i)){
			  state_machine++;
		  }
	  }
    if (state_machine==4){
    	for (int j=4;j<13;j++){
    		buffer_tmp[j-4]=*(buffer_uart+j);
    	}
    	state_machine=0;
    }

}
uint8_t checksum_calc(uint8_t *payload){
    uint8_t tmp=0;
	for(int i=0;i<7;i++){
    	   tmp+=*(payload+i);

       }
	tmp=-tmp;
	return tmp;
}
uint8_t error_frame(){
	uint8_t checksum_calc=checksum(buffer_tmp);
	uint8_t error;
	if (checksum_calc==checksum_tmp){
		error=0;
	}else{
		error=-1;
	}
	return error;
}
uint8_t horas(){
	return hora;
}
uint8_t minutos(){
	return minuto;
}
uint8_t segundos(){
	return segundo;
}
uint8_t tracks(){
	return track;
}
uint16_t datas(){
	return data;
}
