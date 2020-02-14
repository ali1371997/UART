
/**
 * main.c
 */
#include"STD_TYPES.h"
#include"GPIO_DRV.h"
#include"UART.h"

void _delay_ms(uint32 n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < 3180; j++)
        {
        } /* do nothing for 1 ms */
}



int main(void)
{

    UART_Init(UART1,9600);

    while(1){

    UART_Transmit(UART1,'b');
_delay_ms(1000);



    }

	return 0;
}
