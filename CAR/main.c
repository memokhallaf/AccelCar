#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MUART_privet.h"
#include "MUART_interface.h"
#include "MGIE_interface.h"
#include "MTIMER0_interface.h"
#include "MTIMER2_interface.h"
/*PROTOTYPE OF ISR FUN*/
void func(void);

/**/
u16_t gu16_DataReceived ;
int main(void)
{
	/*select UART receive pin [RXD] */
	mdio_setPinstatus(PORTD,PIN0,INPUT_FLOAT);
	/*SELECT PWM PIN [OC0]*/
	mdio_setPinstatus(PORTB,PIN3,OUTPUT);
	/*select A_IN_1 & A_IN_2*/
	mdio_setPinstatus(PORTB, PIN4,OUTPUT);
	mdio_setPinstatus(PORTB, PIN5,OUTPUT);
	/*select B_IN_1 & B_IN_2*/
	mdio_setPinstatus(PORTD, PIN6,OUTPUT);
	mdio_setPinstatus(PORTD, PIN5,OUTPUT);
	/*SELECT STBY PIN*/
	mdio_setPinstatus(PORTC,PIN0,OUTPUT);

	/*INITIALIZE UART MODULE*/
	muart_init();
	muart_CallBack_0(func);
	mGIE_EnableGie();

	/*INITIALIZE TIMER0 MODULE*/
	mtimer0_init();
	/*INITIALIZE TIMER2 MODULE*/
	mtimer2_init();
	/*SET STBY PIN TO HIGH*/
	mdio_setPinValue(PORTC,PIN0,HIGH);
	while(1)
	{
		switch (gu16_DataReceived)
			 {
				 case (0X66):

					/*Forward with low speed*/
					/**/
					mdio_setPinValue(PORTB, PIN4,HIGH);
				 	mdio_setPinValue(PORTB, PIN5,LOW);
				 	mtimer0_widthControl(LOW_SPEED);
				 	/**/
				 	mdio_setPinValue(PORTD, PIN5,HIGH);
				 	mdio_setPinValue(PORTD, PIN6,LOW);
				 	mtimer2_widthControl(LOW_SPEED);
					/*break from this case*/
					break;
				 case (0XCD):


					/*Forward WITH HIGH SPEED*/
					/**/
					mdio_setPinValue(PORTB, PIN4,HIGH);
					mdio_setPinValue(PORTB, PIN5,LOW);
					mtimer0_widthControl(HIGH_SPEED);
					/**/
					mdio_setPinValue(PORTD, PIN5,HIGH);
					mdio_setPinValue(PORTD, PIN6,LOW);
					mtimer2_widthControl(HIGH_SPEED	);
					/*break from this case*/
					break;
				 case (0X00):


					/*BACKWARD*/
					/**/
					mdio_setPinValue(PORTB, PIN4,LOW);
					mdio_setPinValue(PORTB, PIN5,HIGH);
					mtimer0_widthControl(HIGH_SPEED);
					/**/
					mdio_setPinValue(PORTD, PIN5,LOW);
					mdio_setPinValue(PORTD, PIN6,HIGH);
					mtimer2_widthControl(HIGH_SPEED);
					/*break from this case*/
					break;
				 case (0X9B):


					/*Forward AND RIGHT with low speed*/
					/**/
					mdio_setPinValue(PORTB, PIN4,HIGH);
					mdio_setPinValue(PORTB, PIN5,LOW);
					mtimer0_widthControl(LOW_SPEED);
					/**/
					mdio_setPinValue(PORTD, PIN5,LOW);
					mdio_setPinValue(PORTD, PIN6,HIGH);
					mtimer2_widthControl(LOW_SPEED);
					/*break from this case*/
					break;
				 case (0X02):


					/*Forward AND RIGHT with HIGH speed*/
					/**/
					mdio_setPinValue(PORTB, PIN4,HIGH);
					mdio_setPinValue(PORTB, PIN5,LOW);
					mtimer0_widthControl(HIGH_SPEED);
					/**/
					mdio_setPinValue(PORTD, PIN5,LOW);
					mdio_setPinValue(PORTD, PIN6,HIGH);
					mtimer2_widthControl(HIGH_SPEED);
					/*break from this case*/
					break;
				 case (0X68):


					/*Forward AND LEFT with low speed*/
					/**/
					mdio_setPinValue(PORTB, PIN4,LOW);
					mdio_setPinValue(PORTB, PIN5,HIGH);
					mtimer0_widthControl(LOW_SPEED);
					/**/
					mdio_setPinValue(PORTD, PIN5,HIGH);
					mdio_setPinValue(PORTD, PIN6,LOW);
					mtimer2_widthControl(LOW_SPEED);
					/*break from this case*/
					break;
				 case (0XCF):


					/*Forward AND LEFT with HIGH speed*/
					/**/
					mdio_setPinValue(PORTB, PIN4,LOW);
					mdio_setPinValue(PORTB, PIN5,HIGH);
					mtimer0_widthControl(HIGH_SPEED);
					/**/
					mdio_setPinValue(PORTD, PIN5,HIGH);
					mdio_setPinValue(PORTD, PIN6,LOW);
					mtimer2_widthControl(HIGH_SPEED);
					/*break from this case*/
					break;
				 default:
					/*break from default*/
					break;

			 }
	}
	return 0;
}
/*DIFINITION OF ISR FUN*/
void func(void)
{

	gu16_DataReceived  = UDR;

	return;
}
