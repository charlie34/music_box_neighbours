#include "frame_coder.h"
#include "main.h"
/*


* frame_coder.c
 *
 *  Created on: 11 ago. 2022
 *      Author: Carlos
 */
/* Funcion de inicializacion para el frame es donde se inicializa el frame y el
 *
*
*
*/
void init(UART_HandleTypeDef huart){
	buffer_output[0]=0x48;
	buffer_output[1]=0x45;
	buffer_output[2]=0x4C;
	buffer_output[3]=0x4C;
	buffer_output[4]=0x4F;
	buffer_output[13]=0xEF;
	huart_tmp=huart;
}
void send_frame(uint8_t* buffer,uint8_t size){
	HAL_UART_Transmit(&huart_tmp, (uint8_t*)buffer, size, HAL_MAX_DELAY);
}
void checksum(){
	uint8_t tmp=0;
	for(int i=5;i<sizeof(buffer_output)-2;i++){

		tmp+=buffer_output[i];
	}
	buffer_output[12]=tmp;
}
void put_hora(uint8_t hora){
	buffer_output[6]=hora;
}
void put_minuto(uint8_t min){
	buffer_output[7]=min;
}
void put_segundo(uint8_t seg){
	buffer_output[8]=seg;
}
void put_cancion(uint8_t track){
	buffer_output[9]=track;
}
void put_command(uint8_t cmd){
	buffer_output[5]=cmd;
}
void put_data(uint16_t data){
	uint8_t *tmp=(uint8_t*)data;
	buffer_output[10]=tmp[0];
	buffer_output[11]=tmp[1];

}
void send_frame_complete(){
	checksum();
	send_frame(buffer_output,sizeof(buffer_output));

}
