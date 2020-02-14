
/**
 * main.c
 */
#include"STD_TYPES.h"
#include"GPIO_DRV.h"
#include"LCD.h"
#include"UART.h"



int main(void)
{

    UART_Init(UART1,9600);

    while(1){

    UART_Transmit(UART1,'b');
_delay_ms(1000);



    }

	return 0;
}
