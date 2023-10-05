/*
 * KEYPAD.c
 *
 *  Created on: 9 Sep 2023
 *      Author: Pierre Emad
 */
#include <avr/io.h>
#include <util/delay.h>
#include "..\..\LIB\STD_TYPES\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH\BIT_MATH.h"
#include "..\..\MCAL\DIO\DIO.h"
#include "KEYPAD.h"

void KEYPAD_Init()
{
    /* first 4 pins OUTPUT, last 4 pins INPUT */
    DIO_voidSetPortDirection(KEYPAD_PORT, 0x0f);

    /* enable pull-up resistors on input pins */
    DIO_voidSetPortValue(KEYPAD_PORT, 0xf0);
}

u8 GET_PRESSED_KEY()
{
    /* keypad map */
    u8 keys[4][4] = {
        {'7','8','9','/'},
        {'4','5','6','*'},
        {'1','2','3','-'},
        {'A','0','=','+'} };

    u8 row, col;
    u8 IS_PRESSED, key = NOT_PRESSED;

    for (row = 0; row < 4; row++)
    {
        /* set all rows */
        DIO_voidSetPortValue(KEYPAD_PORT, 0x0f);
        _delay_ms(50);

        /* clear the current row */
        DIO_voidSetPinValue(KEYPAD_PORT, row, 0);

        for (col = 0; col < 4; col++)
        {
            /* set the key */
            DIO_voidSetPinValue(KEYPAD_PORT, (col+4), 1);

            /* get the state of the key */
            IS_PRESSED = !DIO_u8GetPinValue(KEYPAD_PORT, (col+4));
            if (IS_PRESSED)
            {
                key = keys[row][col];
                break;
            }
        }
        
    }

    return key;
}
