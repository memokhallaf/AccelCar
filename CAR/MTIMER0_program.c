/*
 *	Name : MTIMER0_program.c
 *  Author: mohamed khallaf
 * 	Discreption : This file contains main program of TIMER0 module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/******************************************/
/*				INCLUDES					*/
/*******************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MTIMER0_private.h"
#include "MTIMER0_interface.h"
#include "TIMER0_config.h"

/******************************************/
/*				FUNCTIONS DIFINITIONS		*/
/*******************************************/
void mtimer0_init(void)
{
	/*setting timer0 mode at PWM_PHASE_CORRECT MODE [D3,D6]-->[01]*/
	CLEAR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	/*setting OC0 PIN at inverting mode [D5,D4]-->[11]*/
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	/*setting clock selector at (clk/64) [D2,D1,D0]-->[011]*/
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	/*setting compare match value*/
	//OCR0 =  OCR_VAL;
	return;
}

void mtimer0_widthControl(u8_t au8_OCR_Value)
{
	/*setting compare match value*/
		OCR0 =  au8_OCR_Value;
}
