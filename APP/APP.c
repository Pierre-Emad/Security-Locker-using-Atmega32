/*
 * APP.c
 *
 *  Created on: 8 Sep 2023
 *      Author: Pierre Emad
 */
#include "APP.h"

u8 pass[4];

void APP_Init(void)
{
	LCD_voidInit();
	KEYPAD_Init();
	ALARM_Init();
	UART_voidInit();
	DIO_voidSetPinDirection(GPIOD, greenLED, OUTPUT);
	DIO_voidSetPinValue(GPIOD, greenLED, LOW);
}

void APP_WelcomeMessage(void)
{
	LCD_voidSendCommand(LCD_HOME_ADDRESS);
	u8 wel[] = "Welcome to Safe";
	for (int i = 0; i < 15; i++)
	{
		LCD_voidSendChar(wel[i]);
		_delay_ms(50);
	}
	_delay_ms(2000);
}

void APP_SetPassword(void)
{
	LCD_Clear();
	LCD_voidSendString("Set new password: ");
	LCD_voidSendCommand(LCD_NEW_LINE);
	u8 count = 0;
	while(count < 4)
	{
		u8 key = NOT_PRESSED;

		do
		{
			key = GET_PRESSED_KEY();
		} while(key == NOT_PRESSED);

		/* auto show/hide password as the user is typing */
		pass[count] = key;
		LCD_voidSendChar(key);
		_delay_ms(1000);
		count++;
		LCD_voidSetCursor(2, count);
		LCD_voidSendChar('*');
	}

	/* write the password in the internal EEPROM */
	eeprom_write_byte(PASS_LOC1, pass[0]);
	eeprom_write_byte(PASS_LOC2, pass[1]);
	eeprom_write_byte(PASS_LOC3, pass[2]);
	eeprom_write_byte(PASS_LOC4, pass[3]);
	eeprom_write_byte(STATUS_LOC, 0x00); // a password exist
}

u8 APP_EnterPassword(void)
{
	LCD_Clear();
	LCD_voidSendString("Enter password:");
	LCD_voidSendCommand(LCD_NEW_LINE);
	u8 count = 0;
	while(count < 4)
	{
		u8 key = NOT_PRESSED;

		do
		{
			key = GET_PRESSED_KEY();
		} while(key == NOT_PRESSED);

		/* auto show/hide password as the user is typing */
		pass[count] = key;
		LCD_voidSendChar(key);
		_delay_ms(1000);
		count++;
		LCD_voidSetCursor(2, count);
		LCD_voidSendChar('*');
	}

	/* check if the password is correct or not */
	return APP_CheckPassword();
}

void APP_WrongPassword(void)
{
	LCD_Clear();
	LCD_voidSendString("Wrong password");
}

void APP_CorrectPassword(void)
{
	LCD_Clear();
	LCD_voidSendString("Correct password");
	LED_ON(GPIOD, greenLED); 
	_delay_ms(1500);

	/* Send notification to the owner via bluetooth and UART */
	LCD_Clear();
	u8 notification[] = "Safe opened!";
	UART_voidSendString(notification);
}

void APP_TryAgain(u8 tries)
{
	if (tries == MAX_TRIES)
	{
		/* Send notification to the owner via bluetooth and UART */
		u8 notification1[] = "WATCHOUT! IT IS A THIEF!";
		UART_voidSendString(notification1);

		LCD_Clear();
		LCD_voidSendString("THIEF");
		_delay_ms(3000);
		while(1)
		{
			ALARM_ON();
		}
	}
	else
	{
		/* show the number of tries left */
		LCD_voidSendCommand(LCD_NEW_LINE);
		LCD_voidSendNum(MAX_TRIES - tries);
		LCD_voidSendString(" tries left");
		_delay_ms(1500);
	}
}

u8 APP_CheckPassword()
{
	if (eeprom_read_byte(PASS_LOC1) != pass[0])
		return WRONG;
	if (eeprom_read_byte(PASS_LOC2) != pass[1])
		return WRONG;
	if (eeprom_read_byte(PASS_LOC3) != pass[2])
		return WRONG;
	if (eeprom_read_byte(PASS_LOC4) != pass[3])
		return WRONG;

	return CORRECT;
}

void APP_ResetPassword()
{
	LCD_Clear();
	LCD_voidSendString("Press 1 to");
	LCD_voidSendCommand(LCD_NEW_LINE);
	LCD_voidSendString("change password");
	u8 key = NOT_PRESSED;
	do
	{
		key = GET_PRESSED_KEY();
	} while(key == NOT_PRESSED);
	LED_OFF(GPIOD, greenLED); 
	if (key != '1')
	{
		return;
	}
	APP_SetPassword();
}
