/*
 * bit_math.h
 *
 * Created: 10/7/2022 7:17:20 PM
 *  Author: Thomas Medhat Mounir Botros
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/************************************************************************/
/*                         bit                                          */
#define SET_BIT(REG, BITNO)  (REG) |= (1 << (BITNO))
#define CLR_BIT(REG, BITNO)  (REG) &= (~(1 << (BITNO)))
#define TOG_BIT(REG, BITNO)  (REG) ^= (1 << (BITNO))
#define GET_BIT(REG, BITNO)  (((REG) >> (BITNO)) & 0x01)
/************************************************************************/



#endif /* BIT_MATH_H_ */