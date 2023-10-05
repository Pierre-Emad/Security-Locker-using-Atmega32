/*
 * ALARM.c
 *
 *  Created on: 9 Sep 2023
 *      Author: Pierre Emad
 */
#include "ALARM.h"

void ALARM_Init()
{
	LED_Init(alarmPORT, redLED);
	BUZZER_voidInit(alarmPORT, BUZZER);
}

void ALARM_ON()
{
	LED_ON(alarmPORT, redLED);
	BUZZER_ON(alarmPORT, BUZZER);
    _delay_ms(500);
    LED_OFF(alarmPORT, redLED);
    BUZZER_OFF(alarmPORT, BUZZER);
    _delay_ms(500);
}
