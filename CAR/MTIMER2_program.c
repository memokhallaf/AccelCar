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
#include "MTIMER2_private.h"
#include "MTIMER2_interface.h"

/******************************************/
/*				FUNCTIONS DIFINITIONS		*/
/*******************************************/
void mtimer2_init(void)
{
	/*setting timer2 mode at PWM_PHASE_CORRECT MODE [D3,D6]-->[01]*/
	CLEAR_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);
	/*setting OC2 PIN at inverting mode [D5,D4]-->[11]*/
	SET_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);
	/*setting clock selector at (clk/64) [D2,D1,D0]-->[011]*/
	SET_BIT(TCCR2,0);
	SET_BIT(TCCR2,1);
	CLEAR_BIT(TCCR2,2);
	/*setting compare match value*/
	//OCR2 =  OCR_VAL;
	return;
}

void mtimer2_widthControl(u8_t au8_OCR_Value)
{
	/*setting compare match value*/
		OCR2 =  au8_OCR_Value;
}
