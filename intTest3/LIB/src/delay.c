/*
    Module: delay
    File Name: delay.c
    Author: Moustafa Ahmed @EOIP

    Description: Source file for PULPINO mcu - Delay Driver
*/


/*-------------------------Includes Section----------------------------*/
#include "../inc/delay.h"
/*------------------------------END------------------------------------*/

/*-------------------------Define Section------------------------------*/

/*------------------------------END------------------------------------*/

/*---------------------Global Variables Section------------------------*/

/*------------------------------END------------------------------------*/

/*-------------------Function Definition Section-----------------------*/
void delay_ms(uint64 milliseconds) {
    volatile uint64 count;
    uint64 iterations = 50000;  // 50,000 cycles per millisecond for 50 MHz

    while (milliseconds--) {
        for (count = 0; count < iterations; count++) {
            // No operation, just looping to create the delay
            //asm volatile("nop");
        }
    }
}

/*------------------------------END------------------------------------*/
