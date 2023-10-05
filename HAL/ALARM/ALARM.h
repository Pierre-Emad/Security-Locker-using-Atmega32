/*
 * ALARM.h
 *
 *  Created on: 9 Sep 2023
 *      Author: Pierre Emad
 */
#ifndef HAL_ALARM_ALARM_H_
#define HAL_ALARM_ALARM_H_


#include "..\..\LIB\STD_TYPES\STD_TYPES.h"
#include "..\..\MCAL\DIO\DIO.h"
#include "..\BUZZER\BUZZER.h"
#include "..\LED\LED.h"

#include <avr/io.h>
#include <util/delay.h>

#define alarmPORT GPIOD
#define greenLED PIN4
#define redLED PIN3
#define BUZZER PIN2

void ALARM_Init(void);
void ALARM_ON(void);

#endif /* HAL_ALARM_ALARM_H_ */
