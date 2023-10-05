/*
 * BUZZER.h
 *
 *  Created on: 10 Sep 2023
 *      Author: Pierre Emad
 */
#ifndef HAL_BUZZER_BUZZER_H_
#define HAL_BUZZER_BUZZER_H_

#include "..\..\MCAL\DIO\DIO.h"
#include "..\..\LIB\STD_TYPES\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH\BIT_MATH.h"

void BUZZER_Init(u8 port , u8 pin );
void BUZZER_ON (u8 port, u8 pin);
void BUZZER_OFF (u8 port , u8 pin);
void BUZZER_TOGGLE (u8 port , u8 pin ) ;


#endif /* HAL_BUZZER_BUZZER_H_ */
