/*
 * KEYPAD.h
 *
 *  Created on: 9 Sep 2023
 *      Author: Pierre Emad
 */

#ifndef HAL_KEY_PAD_KEY_PAD_H_
#define HAL_KEY_PAD_KEY_PAD_H_

#define KEYPAD_PORT GPIOC
#define NOT_PRESSED 0xff

void KEYPAD_Init(void);
u8   GET_PRESSED_KEY();

#endif /* HAL_KEY_PAD_KEY_PAD_H_ */
