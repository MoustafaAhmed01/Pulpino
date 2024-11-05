/*
    Project: LED Test
    Made by: Moustafa Ahmed @EOIP
    Date   : 10/24/2024

    Illustration:
    - This Project used to test GPIO driver on PULPINO MCU
    - This Project will include LED driver, Push Button and GPIO Driver
*/

/*-------------------------Includes Section----------------------------*/
#include "gpio.h"
#include <string.h>
#include "utils.h"
#include "uart.h"
#include "event.h"
#include "int.h"
#include "bench.h"
#include "HAL/inc/led.h"
#include "HAL/inc/pushButton.h"
#include "LIB/inc/Platform_Types.h"
#include "LIB/inc/delay.h"

/*------------------------------END------------------------------------*/

/*-------------------------Define Section------------------------------*/

/*------------------------------END------------------------------------*/

/*---------------------Global Variables Section------------------------*/
volatile uint8 g_GPIO_FLAG = FALSE;
/*------------------------------END------------------------------------*/

/*-------------------Function Decleration Section----------------------*/

/* Description: Init all drivers in the system */
void system_init();

/*------------------------------END------------------------------------*/

/*-------------------------Interrupt Section---------------------------*/
void ISR_GPIO(void)
{
    ICP = (1 << 25);
    g_GPIO_FLAG = TRUE;
}
/*------------------------------END------------------------------------*/

/*---------------------------Main Section------------------------------*/
int main()
{
    /* Initializing the system */
    system_init();
    /*----------------------Local Variables Section------------------------*/
    uint8 l_ledStatus = FALSE;
    /*------------------------------END------------------------------------*/

    while (1)
    {
        /* Check on the Push Button */
        if (g_GPIO_FLAG == TRUE)
        {

            LED_CONTROL(LED_HIGH);
            delay_ms(30);
            LED_CONTROL(LED_LOW);
            delay_ms(30);
            LED_CONTROL(LED_HIGH);
            delay_ms(30);
            LED_CONTROL(LED_LOW);
            delay_ms(30);
            LED_CONTROL(LED_HIGH);
            delay_ms(30);
            LED_CONTROL(LED_LOW);
            delay_ms(30);
            LED_CONTROL(LED_HIGH);
            delay_ms(30);
            LED_CONTROL(LED_LOW);
            delay_ms(30);
            LED_CONTROL(LED_HIGH);
            delay_ms(30);
            LED_CONTROL(LED_LOW);

            /* Reset the FLAG again */
            g_GPIO_FLAG = FALSE;
        }
        else if (PUSH_buttonState2() == PUSH_BUTTON_HIGH)
        {
            LED_CONTROL(LED_HIGH);
            delay_ms(8);
            LED_CONTROL(LED_LOW);
            delay_ms(8);
            LED_CONTROL(LED_HIGH);
            delay_ms(8);
            LED_CONTROL(LED_LOW);

            while (PUSH_buttonState2() == PUSH_BUTTON_HIGH)
            {
                /* Do Nothing until the user removes his hand from the push button*/
            }
        }
        else
        {
            /* Do Nothing */
        }
    }

    return 0;
}
/*------------------------------END------------------------------------*/

/*-------------------Function Definition Section-----------------------*/

/* Description: Init all drivers in the system */
void system_init()
{
    /* Enable interrupts */
    int_enable();
    EER = 0x02000000; // enable all timer events;
    IER = 0x02000000; // enable all timer interrupts

    /* Initializing LED */
    INIT_led();

    /* Initializing Push Button */
    INIT_pushButton();
}

/*------------------------------END------------------------------------*/
