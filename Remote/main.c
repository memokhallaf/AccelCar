#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MADC_interface.h"
#include "MGIE_interface.h"
#include "MUART_privet.h"
#include "MUART_interface.h"


/*PROTOTYPE OF ISR FUN*/
void func(void);

/**/
u16_t gu16_DataTransmitted ;

/*MAIN FUN*/
int main(void)
{

	/*select ADC PINS [Accelerometer pins]*/
	mdio_setPinstatus(PORTA,PIN0,INPUT_FLOAT);
	mdio_setPinstatus(PORTA,PIN1,INPUT_FLOAT);
	/*Select the UART PIN [TXD] */
	mdio_setPinstatus(PORTD,PIN1,OUTPUT);

	/*INITIALIZE ADC module*/
	madc_init();
	/*INITIALIZE UART module*/
	muart_init();
	muart_CallBack_1(func);
	mGIE_EnableGie();
	while(1)
		{
			gu16_DataTransmitted = madc_ReadAnalogPolling_1();

		}
	return 0;
}



/*DIFINITION OF ISR FUN*/
void func(void)
{
	UDR =  gu16_DataTransmitted;
	return;
}



