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
#include "HAL/inc/led.h"
#include "HAL/inc/pushButton.h"
#include "LIB/inc/Platform_Types.h"
#include "LIB/inc/delay.h"

/*------------------------------END------------------------------------*/

/*-------------------------Define Section------------------------------*/

/*------------------------------END------------------------------------*/

/*---------------------Global Variables Section------------------------*/

/*------------------------------END------------------------------------*/

/*-------------------Function Decleration Section----------------------*/

/* Description: Init all drivers in the system */
void system_init();

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
        if (PUSH_buttonState() == PUSH_BUTTON_HIGH)
        {

            LED_CONTROL(LED_HIGH);
            delay_ms(110);
            LED_CONTROL(LED_LOW);
            delay_ms(110);
            LED_CONTROL(LED_HIGH);
            delay_ms(110);
            LED_CONTROL(LED_LOW);
            delay_ms(110);
            LED_CONTROL(LED_HIGH);
            delay_ms(110);
            LED_CONTROL(LED_LOW);

            while (PUSH_buttonState() == PUSH_BUTTON_HIGH)
            {
                /* Do Nothing until the user removes his hand from the push button*/
            }
        }
        else if (PUSH_buttonState2() == PUSH_BUTTON_HIGH)
        {
            if (l_ledStatus == TRUE)
            {
                l_ledStatus = FALSE;
                LED_CONTROL(LED_LOW);
            }
            else
            {
                l_ledStatus = TRUE;
                LED_CONTROL(LED_HIGH);
            }
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
    /* Initializing LED */
    INIT_led();

    /* Initializing Push Button */
    INIT_pushButton();
}

/*------------------------------END------------------------------------*/
