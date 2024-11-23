/*
*
*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  STEPPER_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*   Author:Mariem Ossama
*   Layer:HAL
*   SWC:STEPPER
*
*/
#ifndef   STEPPER_PROGRAM_C_
#define   STEPPER_PROGRAM_C_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "STEPPER_private.h"
#include "STEPPER_interface.h"
#include "STEPPER_config.h"
#include <util/delay.h>

#define STEPS_PER_REVOLUTION 512

void STEPPER_voidInit()
{
    DIO_enumSetPinDirection(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_OUTPUT);
    DIO_enumSetPinDirection(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_OUTPUT);
    DIO_enumSetPinDirection(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_OUTPUT);
    DIO_enumSetPinDirection(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_OUTPUT);

    STEPPER_voidOFF();
}

void STEPPER_voidOFF()
{
    DIO_enumSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
    DIO_enumSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
    DIO_enumSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
    DIO_enumSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
}

void STEPPER_voidRotateCounterClockwise(u16 Copy_u16Degree, u16 Copy_u16Speed)
{
    // Calculate the number of iterations required
    u16 Copy_u16Iterations = (u16)(((Copy_u16Degree * STEPS_PER_REVOLUTION) / 360) + 0.5);

    for (u16 LOC_u16Iterator = 0; LOC_u16Iterator < Copy_u16Iterations; LOC_u16Iterator++)
    {
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_HIGH);

        _delay_ms(Copy_u16Speed);

        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);

        _delay_ms(Copy_u16Speed);

        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);

        _delay_ms(Copy_u16Speed);

        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);

        _delay_ms(Copy_u16Speed);
    }
}

void STEPPER_voidRotateClockwise(u16 Copy_u16Degree, u16 Copy_u16Speed)
{
    // Calculate the number of iterations required
    u16 Copy_u16Iterations = (u16)(((Copy_u16Degree * STEPS_PER_REVOLUTION) / 360) + 0.5);

    for (u16 LOC_u16Iterator = 0; LOC_u16Iterator < Copy_u16Iterations; LOC_u16Iterator++)
    {
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);

        _delay_ms(Copy_u16Speed);

        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);

        _delay_ms(Copy_u16Speed);

        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);

        _delay_ms(Copy_u16Speed);

        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
        DIO_enumSetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);

        _delay_ms(Copy_u16Speed);
    }
}

#endif
