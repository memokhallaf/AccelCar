/*
 *	Name : MUART_interface.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains interfacing information of UART module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/* Header file guard */
#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_
/******************************************/
/*				FUNCTIONS PROTOTYPES		*/
/*******************************************/
/*UART INITIALIZATION AS MASTER*/
void muart_init(void);
/*THIS FUN IS USED TO TRANSMIT DATA*/
//void muart_transmit(u8_t au8_Data);
/*USED TO CALLBACK FUNCTION 0*/
void muart_CallBack_0(void(*func)(void));
/*USED TO CALLBACK FUNCTION 1*/
//void muart_CallBack_1(void(*func)(void));

#endif /* MUART_INTERFACE_H_ */
