/*
 * UART.c
 *
 *  Created on: ??�/??�/????
 *      Author: HELAL
 */

#include "../../LIB/STD_TYPES/STD_TYPES.h"
#include "../../LIB/BIT_MATH/BIT_MATH.h"
#include "UART.h"

#include <avr/io.h>

void UART_voidInit()
{
	// Set the baud rate
	UBRRL = 51;
	UBRRH = 0;

	// Normal Speed OF SAMPLE
	CLR_BIT(UCSRA, U2X);

	// Asynchronous Mode
	CLR_BIT(UCSRC, 6);

    // 8 bits Data
	CLR_BIT(UCSRB, 2);
	SET_BIT(UCSRC, 1);
	SET_BIT(UCSRC, 2);

	// 1 stop bit
	CLR_BIT(UCSRC, 3);

	// no parity check
	CLR_BIT(UCSRC, 4);
	CLR_BIT(UCSRC, 5);

	// Enable transmitter and receiver
	SET_BIT(UCSRB, 3);
	SET_BIT(UCSRB, 4);
}
void UART_voidSendData(u8 data)
{
	/* check if transmission is complete */
	while(GET_BIT(UCSRA, 5) == 0);
	UDR = data;
}

u8 UART_u8RecieveData(void)
{
	/* check if receiving is complete */
	while(GET_BIT(UCSRA, 7) == 0);
	return UDR;
}

void UART_voidSendString(u8 *ptr)
{
	u8 i = 0;

	while(ptr[i] != '\0')
	{
		UART_voidSendData(ptr[i]);
		i++;
	}
	UART_voidSendData(ptr[i]);
}

void UART_voidRecieveString(u8 *ptr)
{
	u8 i = 0;

	while(ptr[i] !='\0')
	{
		i++;
		ptr[i]=UART_u8RecieveData();
	}
	ptr[i]='\0';
}


