/*
 *	Name : MTIMER0_private.h
 *  Author: mohamed khallaf
 * 	Discreption : This file contains private information of TIMER0 module
 *  Version : v1.0
 *  Created on: Aug 16, 2021
 *
 */
/* Header file guard */
#ifndef MTIMER0_PRIVATE_H_
#define MTIMER0_PRIVATE_H_

/******************************************/
/*					TIMER0 Register		  */
/*******************************************/
#define TCCR0 	(*(volatile u8_t*)(0x53))
#define TCNT0 	(*(volatile u8_t*)(0x52))
#define TIMSK 	(*(volatile u8_t*)(0x59))
#define TIFR 	(*(volatile u8_t*)(0x58))
#define OCR0 	(*(volatile u8_t*)(0x5C))

#endif /* MTIMER0_PRIVATE_H_ */
