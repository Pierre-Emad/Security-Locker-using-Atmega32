/*
 * BUZZER.c
 *
 *  Created on: 10 Sep 2023
 *      Author: Pierre Emad
 */
#include "BUZZER.h"

void BUZZER_voidInit(u8 port, u8 pin)
{
	DIO_voidSetPinDirection(port, pin, OUTPUT);
}

void BUZZER_ON(u8 port, u8 pin)
{
	DIO_voidSetPinValue(port, pin, HIGH);
}

void BUZZER_OFF(u8 port, u8 pin)
{
	DIO_voidSetPinValue(port, pin, LOW);
}

void BUZZER_TOGGLE(u8 port, u8 pin )
{
	TOGGLE_BIT(port, pin);
}
