/*
 * engine.h
 *
 *  Created on: 15 ago. 2022
 *      Author: Carlos
 */

#ifndef ENGINE_H_
#define ENGINE_H_
#include "main.h"
#define size_timetable 100

typedef struct temporizacion{
	uint8_t hora;
	uint8_t minuto;
	uint8_t segundo;
	uint8_t pista;
	uint8_t full;//flag que indica si es un registro lleno o no
}temporizacion;
temporizacion time_table[size_timetable];
RTC_TimeTypeDef GetTime;
void execute_cmd(uint8_t cmd);
uint8_t scheduling_track(RTC_TimeTypeDef Time_current,RTC_DateTypeDef Date_current,temporizacion *time_prog,uint8_t size_prog);//Puntero de temporizacion hacia la lista de tiempos
//Lo suyo es que RTC llame a su IT cada vez que haya un cambio y que asi se vaya actualizando
void sheduling_prog(temporizacion *time_prog,uint8_t hora,uint8_t minuto,uint8_t segundo,uint8_t track,uint8_t size_prog);
void sheduling_table_init(temporizacion *time_prog,uint8_t size_prog);
void exec(temporizacion *time_prog,RTC_HandleTypeDef hrtc);
#endif /* ENGINE_H_ */
