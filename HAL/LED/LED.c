/*
 * LED.c
 *
 *  Created on: Sep 8, 2023
 *      Author: m
 */
#include "LED.h"

void LED_Init(u8 port, u8 pin)
{
	DIO_voidSetPinDirection(port, pin, OUTPUT);
}
void LED_ON (u8 port, u8 pin)
{
	DIO_voidSetPinValue(port, pin, HIGH);
}
void LED_OFF (u8 port, u8 pin)
{
	DIO_voidSetPinValue(port, pin, LOW);
}
void LED_TOGGLE (u8 port, u8 pin)
{
	TOGGLE_BIT(port, pin);
}
