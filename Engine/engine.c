/*
 * engine.c
 *
 *  Created on: 15 ago. 2022
 *      Author: Carlos
 */
#include "engine.h"
#include "main.h"
uint8_t scheduling_track(RTC_TimeTypeDef Time_current,RTC_DateTypeDef Date_current,temporizacion *time_prog,uint8_t size_prog){
	uint8_t track_tmp;
	for (int i=0;i<size_prog;i++){
	        	  if((time_prog[i].hora==Time_current.Hours) && (time_prog[i].minuto==Time_current.Minutes)&&(Time_current.Seconds==0)){
	        		  track_tmp=time_prog[i].pista;
	        	  }
	          }
	return track_tmp;
//Puntero de temporizacion hacia la lista de tiempos
}
void sheduling_prog(temporizacion *time_prog,uint8_t hora,uint8_t minuto,uint8_t segundo,uint8_t track,uint8_t size_prog){
	int i;
	for(i=0;i<size_prog;i++){
		if((time_prog+i)->full==0){ //Busca en la lista cual es el primer registro que esta vacío
			break;
		}
	}
	(time_prog+i)->hora=hora;
	(time_prog+i)->minuto=minuto;
	(time_prog+i)->segundo=segundo;
	(time_prog+i)->pista=track;
	(time_prog+i)->full=1;

}

void sheduling_table_init(temporizacion *time_prog,uint8_t size_prog){
	for (int i=0;i<size_prog;i++){
	(time_prog+i)->hora=0;
	(time_prog+i)->minuto=0;
		(time_prog+i)->segundo=0;
		(time_prog+i)->pista=0;
		(time_prog+i)->full=0;
	}
}
void exec(temporizacion *time_prog,RTC_HandleTypeDef hrtc){
	RTC_TimeTypeDef GetTime;
	HAL_RTC_GetTime(&hrtc, &GetTime, RTC_FORMAT_BIN);//Get time
		      /* Get the RTC current Date */
		    //  HAL_RTC_GetDate(&hrtc, &GetData, RTC_FORMAT_BIN);//get date
	          int i=0;
	          while(time_prog[i].full==1){
	        	  if((time_prog[i].hora==GetTime.Hours) && (time_prog[i].minuto==GetTime.Minutes)&&(GetTime.Seconds==0)){
	        		  mp3_play_physical_num(time_prog[i].pista);
	        	  }
	        	  i++;
	          }
}
