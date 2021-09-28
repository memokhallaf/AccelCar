/*
 *	Name : MUART_private.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains private information of UART module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/* Header file guard */
#ifndef MUART_PRIVET_H_
#define MUART_PRIVET_H_
/******************************************/
/*					UART Register			*/
/*******************************************/
/*DATA REGISTER*/
#define UDR   (*(volatile u8_t *)(0x2C))
/*BOAD RATR REGIDTER*/
#define UBRRL   (*(volatile u8_t *)(0x29))
/*UART CONTROL STATUS REGISTER --> A*/
#define UCSRA   (*(volatile u8_t *)(0x2B))
/*UART CONTROL STATUS REGISTER --> B*/
#define UCSRB   (*(volatile u8_t *)(0x2A))
/*UART CONTROL STATUS REGISTER --> C*/
#define UCSRC   (*(volatile u8_t *)(0x40))



/*USED TO set vector of USART, Rx Complete */
//void __vector_13 (void) __attribute__((signal));
/*USED TO set vector of USART Data Register Empty*/
void __vector_14 (void) __attribute__((signal));
#endif /* MUART_PRIVET_H_ */
