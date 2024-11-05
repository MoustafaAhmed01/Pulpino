/*
    Module: PUSH BUTTON
    File Name: pushButton.c
    Author: Moustafa Ahmed @EOIP

    Description: Source file for PULPINO mcu - PushButton Driver
*/


/*-------------------------Includes Section----------------------------*/
#include "../inc/pushButton.h"
/*------------------------------END------------------------------------*/

/*-------------------------Define Section------------------------------*/

/*------------------------------END------------------------------------*/

/*---------------------Global Variables Section------------------------*/

/*------------------------------END------------------------------------*/

/*-------------------Function Definition Section-----------------------*/
/* Description: Inits the  Push Button PIN*/
void INIT_pushButton()
{
    /* Set the direction as INPUT */
    set_gpio_pin_direction(GPIO_INPUT_PB,DIR_IN);

    /* Set the second GPIO PIN as input */
    set_gpio_pin_direction(GPIO_INPUT_PB2,DIR_IN);
}

/* Description: Gets the state of the PushButton*/
uint8 PUSH_buttonState()
{
    return get_gpio_pin_value(GPIO_INPUT_PB);
}

/* Description: Gets the state of the PushButton*/
uint8 PUSH_buttonState2()
{
    return get_gpio_pin_value(GPIO_INPUT_PB2);
}
/*------------------------------END------------------------------------*/
