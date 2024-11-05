/*
    Module: LED
    File Name: led.h
    Author: Moustafa Ahmed @EOIP

    Description: Header file for PULPINO mcu - LED Driver
*/

#ifndef LED_H
#define LED_H

/*-------------------------Includes Section----------------------------*/
#include "../../LIB/inc/Platform_Types.h"
#include "gpio.h"
/*------------------------------END------------------------------------*/

/*-------------------------Define Section------------------------------*/
#define GPIO_OUTPUT_LED     2
/*------------------------------END------------------------------------*/

/*---------------------Global Variables Section------------------------*/

/*------------------------------END------------------------------------*/

/*--------------------------ENUM Section-------------------------------*/
/*Description: Enum to hold the LED state */
typedef enum
{
    LED_LOW,
    LED_HIGH,
}LED_STATE;
/*------------------------------END------------------------------------*/

/*-------------------------Structure Section---------------------------*/

/*------------------------------END------------------------------------*/


/*-------------------Function Decleration Section----------------------*/
/* Description: Init the LED pin */
void INIT_led();
/* Description: Controls the LED state */
void LED_CONTROL(uint8 ledState);
/*------------------------------END------------------------------------*/

#endif