/*
 *
 *
 *
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  GIE_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *   Author:Mariem Ossama
 *   Layer:MCAL
 *   SWC:GIE 
 *
 */
#ifndef _GIE_PROGRAM_C_
#define _GIE_PROGRAM_C_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"



void GIE_voidEnable (void)
{
	SET_BIT(SREG,SREG_I);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}


#endif