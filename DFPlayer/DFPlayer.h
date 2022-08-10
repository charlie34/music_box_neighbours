/*
 * DFPlayer.h
 *
 *  Created on: 9 ago. 2022
 *      Author: Carlos Martín
 */

#ifndef DFPLAYER_H_
#define DFPLAYER_H_
#include "main.h"
void initialization(UART_HandleTypeDef huart);
void mp3_set_reply (uint8_t state);
void mp3_play_physical_num (uint16_t num);
void mp3_play_physical ();
void mp3_next ();
void mp3_prev ();
void mp3_set_volume (uint16_t volume);
void mp3_set_EQ (uint16_t eq);
void mp3_set_device (uint16_t device);
void mp3_sleep ();
void mp3_reset ();
void mp3_play ();
void mp3_pause ();
void mp3_stop ();
void mp3_play_num (uint16_t num);
void mp3_get_state ();
void mp3_get_volume ();
void mp3_get_u_sum ();
void mp3_get_tf_sum ();
void mp3_get_flash_sum ();
void mp3_get_tf_current ();
void mp3_get_u_current ();
void mp3_get_flash_current ();
void mp3_single_loop (uint8_t state);
void mp3_single_play (uint16_t num);
void mp3_DAC (uint8_t state);
void mp3_random_play ();
//Aqui va el private
uint8_t send_buf[10];
uint8_t recv_buf[10];
uint8_t is_reply;
static void fill_uint16_bigend (uint8_t *thebuf, uint16_t data);
uint16_t mp3_get_checksum (uint8_t *thebuf);
UART_HandleTypeDef huart_tmp;
void mp3_fill_checksum ();
void send_func ();
void mp3_send_cmd_arg (uint8_t cmd, uint16_t arg);
void mp3_send_cmd (uint8_t cmd);
#endif /* DFPLAYER_H_ */
