/*
 * frame_decoder.c
 *
 *  Created on: 13 ago. 2022
 *      Author: Carlos
 */
#include "frame_decoder.h"
#include "main.h"
void decoder(uint8_t symbol){
	 static uint8_t state_machine=0;
	 static uint8_t data_byte_pos=0;
	 uint8_t data_tmp[2];
	 switch(symbol){
	 case 0x48:{
		 if (state_machine==0){
			 state_machine=1;
		 }
		 break;
	 }
	 case 0x45:{
		 if (state_machine==1){
					 state_machine=2;
				 }
				 break;
	 }
	 case 0x4C:{
		 if (state_machine==2){
							 state_machine=3;
						 }
						 break;
	 }

	 case 0x4F:{
	 		 if (state_machine==3){
	 							 state_machine=4;
	 						 }
	 						 break;
	 	 }
	 default:{
		 state_machine=0;
	 }
	 }
	 if (state_machine==4){
		 switch(data_byte_pos){
		 case 0:{
			 hora=symbol;
			 buffer_tmp[data_byte_pos]=symbol;
			 data_byte_pos++;
			 break;
		 }

		 case 1:{
		 			 minuto=symbol;
		 			 buffer_tmp[data_byte_pos]=symbol;
		 			 data_byte_pos++;
		 			 break;
		 		 }
		 case 2:{
		 			 segundo=symbol;
		 			 buffer_tmp[data_byte_pos]=symbol;
		 			 data_byte_pos++;
		 			 break;
		 		 }
		 case 3:{
				 			 track=symbol;
				 			 buffer_tmp[data_byte_pos]=symbol;
				 			 data_byte_pos++;
				 			 break;
				 		 }
		 case 4:{
			                 cmd=symbol;
			                 buffer_tmp[data_byte_pos]=symbol;
				 			 data_byte_pos++;
				 			 break;
				 		 }
		 case 5:{
			 buffer_tmp[data_byte_pos]=symbol;
			 data_tmp[0]=symbol;
			 data_byte_pos++;
			 break;
		 }
		 case 6:{
			 data_tmp[1]=symbol;
			 buffer_tmp[data_byte_pos]=symbol;
					 data_byte_pos++;
					 break;
				 }
		 case 7:{
			 checksum_tmp=symbol;
			 buffer_tmp[data_byte_pos]=symbol;
			 data_byte_pos=0;
			 state_machine=0;
			 break;
		 }
		 }

	 }
	 data_dec=(uint16_t*)data_tmp;
	 data=*data_dec;
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
