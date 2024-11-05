/*
    Module: PUSH BUTTON
    File Name: pushButton.h
    Author: Moustafa Ahmed @EOIP

    Description: Header file for PULPINO mcu - PushButton Driver
*/

#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

/*-------------------------Includes Section----------------------------*/
#include "../../LIB/inc/Platform_Types.h"
#include "gpio.h"
/*------------------------------END------------------------------------*/

/*-------------------------Define Section------------------------------*/
#define GPIO_INPUT_PB       3   
#define GPIO_INPUT_PB2      1
/*------------------------------END------------------------------------*/

/*--------------------------ENUM Section-------------------------------*/
/*Description: Enum to hold the PUSH BUTTON state */
typedef enum
{
    PUSH_BUTTON_LOW,
    PUSH_BUTTON_HIGH,
}PUSH_BUTTON_STATE;
/*------------------------------END------------------------------------*/

/*---------------------Global Variables Section------------------------*/

/*------------------------------END------------------------------------*/

/*-------------------Function Decleration Section----------------------*/

/* Description: Inits the  Push Button PIN*/
void INIT_pushButton();

/* Description: Gets the state of the PushButton*/
uint8 PUSH_buttonState();

/* Description: Gets the state of the PushButton*/
uint8 PUSH_buttonState2();
/*------------------------------END------------------------------------*/

#endif