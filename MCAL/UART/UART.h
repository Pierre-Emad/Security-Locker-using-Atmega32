/*
 *  * UART.h
 *
 *  Created on: ??�/??�/????
 *      Author: HELAL
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_
#include "../../LIB/STD_TYPES/STD_TYPES.h"

void UART_voidInit();
void UART_voidSendData(u8 data);
u8   UART_u8RecieveData(void);
void UART_voidSendString(u8 *ptr);
void UART_voidRecieveString(u8 *ptr);


#endif /* MCAL_UART_UART_H_ */
