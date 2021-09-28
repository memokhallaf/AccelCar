/*
 *	Name : MTIMER2_interface.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains INTERFACE information of TIMER2 module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */
/* Header file guard */
#ifndef MTIMER2_INTERFACE_H_
#define MTIMER2_INTERFACE_H_
/******************************************/
/*			INTERFACING MACROS				*/
/*******************************************/
#define HIGH_SPEED (64)
#define LOW_SPEED (191)

/******************************************/
/*				FUNCTIONS PROTOTYPES		*/
/*******************************************/
/*INITIALIZE FUN FOR TIMER0*/
void mtimer2_init(void);
/*SELECT THE WIDTH OF THE PWM */
void mtimer2_widthControl(u8_t au8_OCR_Value);


#endif /* MTIMER2_INTERFACE_H_ */
