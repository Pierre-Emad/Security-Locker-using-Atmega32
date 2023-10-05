/*
 * BIT_MATH.h
 *
 *  Created on: ??�/??�/????
 *      Author: HELAL
 */

#ifndef LIB_BIT_MATH_BIT_MATH_H_
#define LIB_BIT_MATH_BIT_MATH_H_

#define GET_BIT(REG, BIT)  (( REG >> BIT ) & 1)
#define SET_BIT(REG, BIT) (REG |= ( 1 << BIT))
#define TOGGLE_BIT(REG, BIT) (REG ^= ( 1 << BIT))
#define CLR_BIT(REG, BIT) (REG &= ~ (1 <<BIT))

#endif /* LIB_BIT_MATH_BIT_MATH_H_ */
