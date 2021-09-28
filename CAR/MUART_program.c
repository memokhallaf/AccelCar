/*
 *	Name : MUART_program.c
 *  Author: mohamed khallaf
 * 	Discreption : This file contains main program of UART module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/*************************************************/
/*					INCLUDES					*/
/***********************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MUART_privet.h"
#include "MUART_interface.h"
#include "MUART_config.h"

/**********************************************/
/*				FUN DIFFINETION			 	 */
/********************************************/

void(*FunToSet_0)(void)=0;
//void(*FunToSet_1)(void)=0;


void muart_init(void)
{
	/*ENABLE RXC INTERRUPT*/
	SET_BIT(UCSRB,7);
	/*ENABLE UDRE INTERRUPT*/
	//SET_BIT(UCSRB,5);
	/*SET AS SLAVE (RECIEVER)*/
	SET_BIT(UCSRB,4);
	/*FRAME SIZE --> 8-BIT*/
	CLEAR_BIT(UCSRB,2);
	/*SELLECT UCSRC REGISTER*/
	SET_BIT(UCSRC,7);
	/*SLLECT ASYCH MODE*/
	CLEAR_BIT(UCSRC,6);
	/*SISABLED PARITY MODE*/
	CLEAR_BIT(UCSRC,5);
	CLEAR_BIT(UCSRC,4);
	/*STOP BIT ---> 1-BIT*/
	CLEAR_BIT(UCSRC,3);
	/*FRAME SIZE --> 8-BIT*/
	SET_BIT(UCSRC,2);
	SET_BIT(UCSRC,1);
	/*set the b*/
	UBRRL = BAUD_RATE_VALUE;
	/*CLEAR FE, DOR & PE WITH MASTER MODE */
	//CLEAR_BIT(UCSRA,4);
	//CLEAR_BIT(UCSRA,3);
	//CLEAR_BIT(UCSRA,2);

	return;
}



void muart_CallBack_0(void(*func)(void))
{
	FunToSet_0 = func;
	return;
}

/*void muart_CallBack_1(void(*func)(void))
{
	FunToSet_1 = func;
	return;
}*/

void __vector_13 (void)
{
	if( FunToSet_0 != 0)
		FunToSet_0();
}

/*void __vector_14 (void)
{
	if( FunToSet_1 != 0)
		FunToSet_1();
}*/
