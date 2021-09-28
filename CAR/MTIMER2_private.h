/*
 *	Name : MTIMER2_private.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains private information of TIMER2 module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */
/* Header file guard */
#ifndef MTIMER2_PRIVATE_H_
#define MTIMER2_PRIVATE_H_
/******************************************/
/*					TIMER2 Register		  */
/*******************************************/
#define TCCR2 	(*(volatile u8_t*)(0x45))
#define TCNT2 	(*(volatile u8_t*)(0x44))
#define TIMSK 	(*(volatile u8_t*)(0x59))
#define TIFR 	(*(volatile u8_t*)(0x58))
#define OCR2	(*(volatile u8_t*)(0x43))

#endif /* MTIMER2_PRIVATE_H_ */
