/*
 *	Name : MADC_programe.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains main programe of ADC module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */

/******************************************/
/*				INCLUDES		           */
/*******************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MADC_private.h"
#include "MADC_interface.h"
/******************************************/
/*				FUNCTIONS DIFINITIONS		*/
/*******************************************/

void madc_init(void)
{
	/*REFERENCE SELECTION BITS */
	/*SETTING BIT 7 TO HIGH AND CLEAR BIT 6 TO RESERVED*/
	SET_BIT(ADMUX, 6);
	CLEAR_BIT(ADMUX, 7);
	/*ADC LEFT ADJUST RESULT BIT (ADLAR)*/
	/*CLEAR BIT 5 FOR RIGHT ADJUSTED */
	CLEAR_BIT(ADMUX, 5);
	/*Differential Mode [ADC0 & ADC1]*/
	SET_BIT(ADMUX, 4);
	CLEAR_BIT(ADMUX, 3);
	CLEAR_BIT(ADMUX, 2);
	CLEAR_BIT(ADMUX, 1);
	CLEAR_BIT(ADMUX, 0);

	/*ADC PRESCALER SELECT BITS*/
	/*SETTING THA DIVISION FACTOR EQUAL 128 */
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);


	/*ADC ENABLE BIT*/
	SET_BIT(ADCSRA, 7);



	return;
}

u16_t madc_ReadAnalogPolling_1(void)
{

	u16_t au16_Result = 0;

	/**/
	SET_BIT(ADCSRA,6);
	/**/
	while(GET_BIT(ADCSRA,4) == 0);
	/**/
	SET_BIT(ADCSRA,4);

	au16_Result = ADCL + ADCH ;
	return au16_Result;
}

