#include"STD_TYPES.h"
#include"Utils.h"
#include"GPIO_DRV.h"
#include"RegMap.h"
#include"UART.h"

void UART_Init(UART_N0_t uart, f32 baud_rate)
{
    f32 clk_uart = 1000000 / baud_rate;
    uint16 clk_int = (uint16) clk_uart;
    uint8 clk_frac = ((clk_uart - clk_int) * 64) + .5;
    switch (uart)
    {

    case UART0:
//enable clk for specific uart
        SET_BIT(UART_RCGC, 0);
//ENABLE CLK FOR GPIO_Port
        SET_BIT(GPIO_RCGC, 0);

//DISABLE UART
        CLR_BIT(UART0_CTL, 0);

//INTEGER ,FRACTIONAL GPIO_PortION OF BAUDRATE 9600
        UART0_IBRD = clk_int;
        UART0_FBRD = clk_frac;

//SYS CLOCK INTENAL
        UART0_CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
        UART0_LCRH = 0X60;

//ENABLE RX , TX
        SET_BIT(UART0_CTL, 8);
        SET_BIT(UART0_CTL, 9);

//ENABLE UART
        SET_BIT(UART0_CTL, 0);

//COINFIGURE GPIO
        GPIO_PortADEN = 0X03;
        GPIO_PortAAFSEL = 0X03; //ALternate fn. for these pins
        GPIO_PortAPCTL = 0X000222211; //THE Fn. IS UART
        break;

    case UART1:
//enable clk for specific uart
        SET_BIT(UART_RCGC, 1);
//ENABLE CLK FOR GPIO_Port
        SET_BIT(GPIO_RCGC, 1);

//DISABLE UART
        CLR_BIT(UART1_CTL, 0);

//INTEGER ,FRACTIONAL GPIO_PortION OF BAUDRATE 9600
        UART1_IBRD = clk_int;
        UART1_FBRD = clk_frac;

//SYS CLOCK INTENAL
        UART1_CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
        UART1_LCRH = 0X60;

//ENABLE RX , TX
        SET_BIT(UART1_CTL, 8);
        SET_BIT(UART1_CTL, 9);

//ENABLE UART
        SET_BIT(UART1_CTL, 0);

//COINFIGURE GPIO
        GPIO_PortBDEN = 0X03;
        GPIO_PortBAFSEL = 0X03; //ALternate fn. for these pins
        GPIO_PortBPCTL = 0X3311; //THE Fn. IS UART
        break;

    case UART2:
//enable clk for specific uart
        SET_BIT(UART_RCGC, 2);
//ENABLE CLK FOR GPIO_Port
        SET_BIT(GPIO_RCGC, 3);

//DISABLE UART
        CLR_BIT(UART2_CTL, 0);

//INTEGER ,FRACTIONAL GPIO_PortION OF BAUDRATE 9600
        UART2_IBRD = clk_int;
        UART2_FBRD = clk_frac;

//SYS CLOCK INTENAL
        UART2_CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
        UART2_LCRH = 0X60;

//ENABLE RX , TX
        SET_BIT(UART2_CTL, 8);
        SET_BIT(UART2_CTL, 9);

//ENABLE UART
        SET_BIT(UART2_CTL, 0);

//COINFIGURE GPIO
        GPIO_PortDDEN = 0XC0;
        GPIO_PortDAFSEL = 0XC0; //ALternate fn. for these pins
        GPIO_PortDPCTL = 0X11000000; //THE Fn. IS UART
        break;

    case UART3:
//enable clk for specific uart
        SET_BIT(UART_RCGC, 3);
//ENABLE CLK FOR GPIO_Port
        SET_BIT(GPIO_RCGC, 2);

//DISABLE UART
        CLR_BIT(UART3_CTL, 0);

//INTEGER ,FRACTIONAL GPIO_PortION OF BAUDRATE 9600
        UART3_IBRD = clk_int;
        UART3_FBRD = clk_frac;

//SYS CLOCK INTENAL
        UART3_CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
        UART3_LCRH = 0X60;

//ENABLE RX , TX
        SET_BIT(UART3_CTL, 8);
        SET_BIT(UART3_CTL, 9);

//ENABLE UART
        SET_BIT(UART3_CTL, 0);

//COINFIGURE GPIO
        GPIO_PortCDEN = 0XFF;
        GPIO_PortCAFSEL = 0XCF; //ALternate fn. for these pins
        GPIO_PortCPCTL = 0X11000111; //THE Fn. IS UART
        break;

    case UART4:
//enable clk for specific uart
        SET_BIT(UART_RCGC, 4);
//ENABLE CLK FOR GPIO_Port
        SET_BIT(GPIO_RCGC, 2);

//DISABLE UART
        CLR_BIT(UART4_CTL, 0);

//INTEGER ,FRACTIONAL GPIO_PortION OF BAUDRATE 9600
        UART4_IBRD = clk_int;
        UART4_FBRD = clk_frac;

//SYS CLOCK INTENAL
        UART4_CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
        UART4_LCRH = 0X60;

//ENABLE RX , TX
        SET_BIT(UART4_CTL, 8);
        SET_BIT(UART4_CTL, 9);

//ENABLE UART
        SET_BIT(UART4_CTL, 0);

//COINFIGURE GPIO
        GPIO_PortCDEN = 0XFF;
        GPIO_PortCAFSEL = 0X3F; //ALternate fn. for these pins
        GPIO_PortCPCTL = 0X00110111; //THE Fn. IS UART
        break;

    case UART5:
//enable clk for specific uart
        SET_BIT(UART_RCGC, 5);
//ENABLE CLK FOR GPIO_Port
        SET_BIT(GPIO_RCGC, 4);

//DISABLE UART
        CLR_BIT(UART5_CTL, 0);

//INTEGER ,FRACTIONAL GPIO_PortION OF BAUDRATE 9600
        UART5_IBRD = clk_int;
        UART5_FBRD = clk_frac;

//SYS CLOCK INTENAL
        UART5_CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
        UART5_LCRH = 0X60;

//ENABLE RX , TX
        SET_BIT(UART5_CTL, 8);
        SET_BIT(UART5_CTL, 9);

//ENABLE UART
        SET_BIT(UART5_CTL, 0);

//COINFIGURE GPIO
        GPIO_PortEDEN = 0X30;
        GPIO_PortEAFSEL = 0X30; //ALternate fn. for these pins
        GPIO_PortEPCTL = 0X00110000; //THE Fn. IS UART
        break;

    case UART6:
//enable clk for specific uart
        SET_BIT(UART_RCGC, 6);
//ENABLE CLK FOR GPIO_Port
        SET_BIT(GPIO_RCGC, 3);

//DISABLE UART
        CLR_BIT(UART6_CTL, 0);

//INTEGER ,FRACTIONAL GPIO_PortION OF BAUDRATE 9600
        UART6_IBRD = clk_int;
        UART6_FBRD = clk_frac;

//SYS CLOCK INTENAL
        UART6_CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
        UART6_LCRH = 0X60;

//ENABLE RX , TX
        SET_BIT(UART6_CTL, 8);
        SET_BIT(UART6_CTL, 9);

//ENABLE UART
        SET_BIT(UART6_CTL, 0);

//COINFIGURE GPIO
        GPIO_PortDDEN = 0X30;
        GPIO_PortDAFSEL = 0X30; //ALternate fn. for these pins
        GPIO_PortDPCTL = 0X00110000; //THE Fn. IS UART
        break;

    case UART7:
//enable clk for specific uart
        SET_BIT(UART_RCGC, 7);
//ENABLE CLK FOR GPIO_Port
        SET_BIT(GPIO_RCGC, 4);

//DISABLE UART
        CLR_BIT(UART7_CTL, 0);

//INTEGER ,FRACTIONAL GPIO_PortION OF BAUDRATE 9600
        UART7_IBRD = clk_int;
        UART7_FBRD = clk_frac;

//SYS CLOCK INTENAL
        UART7_CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
        UART7_LCRH = 0X60;

//ENABLE RX , TX
        SET_BIT(UART7_CTL, 8);
        SET_BIT(UART7_CTL, 9);

//ENABLE UART
        SET_BIT(UART7_CTL, 0);

//COINFIGURE GPIO
        GPIO_PortEDEN = 0X03;
        GPIO_PortEAFSEL = 0X03; //ALternate fn. for these pins
        GPIO_PortEPCTL = 0X11; //THE Fn. IS UART
        break;
    }
}

uint8 UART_Receive(UART_N0_t uart)
{
    uint8 data = 0;
    if (uart == UART0)
    {
        while (GET_BIT(UART0_FR,4) == 1)
            ;
        data = UART0_DR;
    }
    else if (uart == UART1)
    {
        while (GET_BIT(UART1_FR,4) == 1)
            ;
        data = UART1_DR;
    }
    else if (uart == UART2)
    {
        while (GET_BIT(UART2_FR,4) == 1)
            ;
        data = UART2_DR;
    }
    else if (uart == UART3)
    {
        while (GET_BIT(UART3_FR,4) == 1)
            ;
        data = UART3_DR;
    }
    else if (uart == UART4)
    {
        while (GET_BIT(UART4_FR,4) == 1)
            ;
        data = UART4_DR;
    }
    else if (uart == UART5)
    {
        while (GET_BIT(UART5_FR,4) == 1)
            ;
        data = UART5_DR;
    }
    else if (uart == UART6)
    {
        while (GET_BIT(UART6_FR,4) == 1)
            ;
        data = UART6_DR;
    }
    else
    {
        while (GET_BIT(UART7_FR,4) == 1)
            ;
        data = UART7_DR;
    }
    return data;
}

void UART_Transmit(UART_N0_t uart, uint8 data)
{

    if (uart == UART0)
    {
        while (GET_BIT(UART0_FR,5) == 1)
            ; //wait utill buffer is not full
        UART0_DR = data;
    }
    else if (uart == UART1)
    {
        while (GET_BIT(UART1_FR,5) == 1)
            ; //wait utill buffer is not full
        UART1_DR = data;
    }
    else if (uart == UART2)
    {

        while (GET_BIT(UART2_FR,5) == 1)
            ; //wait utill buffer is not full
        UART2_DR = data;
    }
    else if (uart == UART3)
    {
        while (GET_BIT(UART3_FR,5) == 1)
            ; //wait utill buffer is not full
        UART3_DR = data;
    }
    else if (uart == UART4)
    {
        while (GET_BIT(UART4_FR,5) == 1)
            ; //wait utill buffer is not full
        UART4_DR = data;
    }
    else if (uart == UART5)
    {
        while (GET_BIT(UART5_FR,5) == 1)
            ; //wait utill buffer is not full
        UART5_DR = data;
    }
    else if (uart == UART6)
    {
        while (GET_BIT(UART6_FR,5) == 1)
            ; //wait utill buffer is not full
        UART6_DR = data;
    }
    else if (uart == UART7)
    {
        while (GET_BIT(UART7_FR,5) == 1)
            ; //wait utill buffer is not full
        UART7_DR = data;
    }

}

void UART_TransmitString(UART_N0_t uart, uint8 *arr)
{
    uint8 i = 0;

    while (arr[i] != '\0')
    {
        UART_Transmit(uart, arr[i]);
        i++;
    }
}
