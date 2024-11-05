/*
    Module: LED
    File Name: led.c
    Author: Moustafa Ahmed @EOIP

    Description: Source file for PULPINO mcu - LED Driver
*/

/*-------------------------Includes Section----------------------------*/
#include "../inc/led.h"
/*------------------------------END------------------------------------*/

/*-------------------------Define Section------------------------------*/

/*------------------------------END------------------------------------*/

/*---------------------Global Variables Section------------------------*/

/*------------------------------END------------------------------------*/

/*-------------------Function Definition Section-----------------------*/
/* Description: Init the LED pin */
void INIT_led()
{
    /* Set the direction as OUTPUT */
    set_gpio_pin_direction(GPIO_OUTPUT_LED, DIR_OUT);
}

/* Description: LED Control */
void LED_CONTROL(uint8 ledState)
{
    if (ledState == LED_HIGH)
    {
        set_gpio_pin_value(GPIO_OUTPUT_LED, LED_HIGH);
    }
    else if (ledState == LED_LOW)
    {
        set_gpio_pin_value(GPIO_OUTPUT_LED, LED_LOW);
    }
    else
    {
        /* Do NOTHING*/
    }
}
/*------------------------------END------------------------------------*/
