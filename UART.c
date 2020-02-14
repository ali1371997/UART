#include"STD_TYPES.h"
#include"Utils.h"
#include"GPIO_DRV.h"
#include"MEM_MAP.h"
#include"UART.h"

void UART_Init(UART_N0_t uart, f32 baud_rate)
{
    f32 clk_uart=1000000/baud_rate;
        uint16 clk_int=(uint16)clk_uart;
        uint8 clk_frac=((clk_uart- clk_int)*64)+.5;
 switch (uart)
    {

    case UART0:
//enable clk for specific uart
        SET_BIT(RCGCUART, 0);
//ENABLE CLK FOR PORT
        SET_BIT(RCGCGPIO, 0);

//DISABLE UART
        CLR_BIT(UART0CTL, 0);

//INTEGER ,FRACTIONAL PORTION OF BAUDRATE 9600
        UART0IBRD = clk_int;
        UART0FBRD = clk_frac;

//SYS CLOCK INTENAL
        UART0CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
        UART0LCRH = 0X60;

//ENABLE RX , TX
        SET_BIT(UART0CTL, 8);
        SET_BIT(UART0CTL, 9);

//ENABLE UART
        SET_BIT(UART0CTL, 0);

//COINFIGURE GPIO
        PORTADEN = 0X03;
        PORTAAFSEL = 0X03; //ALternate fn. for these pins
        PORTAPCTL = 0X11; //THE Fn. IS UART
        break;

    case UART1:
//enable clk for specific uart
        SET_BIT(RCGCUART, 1);
//ENABLE CLK FOR PORT
        SET_BIT(RCGCGPIO, 1);

//DISABLE UART
        CLR_BIT(UART1CTL, 0);

//INTEGER ,FRACTIONAL PORTION OF BAUDRATE 9600
        UART1IBRD = clk_int;
        UART1FBRD = clk_frac;

//SYS CLOCK INTENAL
        UART1CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
        UART1LCRH = 0X60;

//ENABLE RX , TX
        SET_BIT(UART1CTL, 8);
        SET_BIT(UART1CTL, 9);

//ENABLE UART
        SET_BIT(UART1CTL, 0);

//COINFIGURE GPIO
        PORTBDEN = 0X03;
        PORTBAFSEL = 0X03; //ALternate fn. for these pins
        PORTBPCTL = 0X11; //THE Fn. IS UART
        break;


    case UART2:
//enable clk for specific uart
        SET_BIT(RCGCUART, 2);
//ENABLE CLK FOR PORT
        SET_BIT(RCGCGPIO, 3);

//DISABLE UART
        CLR_BIT(UART2CTL, 0);

//INTEGER ,FRACTIONAL PORTION OF BAUDRATE 9600
        UART2IBRD = clk_int;
        UART2FBRD = clk_frac;

//SYS CLOCK INTENAL
        UART2CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
        UART2LCRH = 0X60;

//ENABLE RX , TX
        SET_BIT(UART2CTL, 8);
        SET_BIT(UART2CTL, 9);

//ENABLE UART
        SET_BIT(UART2CTL, 0);

//COINFIGURE GPIO
        PORTDDEN = 0XC0;
        PORTDAFSEL = 0XC0; //ALternate fn. for these pins
        PORTDPCTL = 0X11000000; //THE Fn. IS UART
        break;


    case UART3:
//enable clk for specific uart
        SET_BIT(RCGCUART, 3);
//ENABLE CLK FOR PORT
        SET_BIT(RCGCGPIO, 2);

//DISABLE UART
        CLR_BIT(UART3CTL, 0);

//INTEGER ,FRACTIONAL PORTION OF BAUDRATE 9600
        UART3IBRD = clk_int;
        UART3FBRD = clk_frac;

//SYS CLOCK INTENAL
        UART3CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
        UART3LCRH = 0X60;

//ENABLE RX , TX
        SET_BIT(UART3CTL, 8);
        SET_BIT(UART3CTL, 9);

//ENABLE UART
        SET_BIT(UART3CTL, 0);

//COINFIGURE GPIO
        PORTCDEN = 0XFF;
        PORTCAFSEL = 0XCF; //ALternate fn. for these pins
        PORTCPCTL = 0X11000111; //THE Fn. IS UART
        break;


    case UART4:
//enable clk for specific uart
        SET_BIT(RCGCUART, 4);
//ENABLE CLK FOR PORT
        SET_BIT(RCGCGPIO, 2);

//DISABLE UART
        CLR_BIT(UART4CTL, 0);

//INTEGER ,FRACTIONAL PORTION OF BAUDRATE 9600
        UART4IBRD = clk_int;
        UART4FBRD = clk_frac;

//SYS CLOCK INTENAL
        UART4CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
        UART4LCRH = 0X60;

//ENABLE RX , TX
        SET_BIT(UART4CTL, 8);
        SET_BIT(UART4CTL, 9);

//ENABLE UART
        SET_BIT(UART4CTL, 0);

//COINFIGURE GPIO
        PORTCDEN = 0XFF;
        PORTCAFSEL = 0X3F; //ALternate fn. for these pins
        PORTCPCTL = 0X00110111; //THE Fn. IS UART
        break;


   case UART5:
//enable clk for specific uart
        SET_BIT(RCGCUART, 5);
//ENABLE CLK FOR PORT
        SET_BIT(RCGCGPIO, 4);

//DISABLE UART
        CLR_BIT(UART5CTL, 0);

//INTEGER ,FRACTIONAL PORTION OF BAUDRATE 9600
        UART5IBRD = clk_int;
        UART5FBRD = clk_frac;

//SYS CLOCK INTENAL
        UART5CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
        UART5LCRH = 0X60;

//ENABLE RX , TX
        SET_BIT(UART5CTL, 8);
        SET_BIT(UART5CTL, 9);

//ENABLE UART
        SET_BIT(UART5CTL, 0);

//COINFIGURE GPIO
        PORTEDEN = 0X30;
        PORTEAFSEL = 0X30; //ALternate fn. for these pins
        PORTEPCTL = 0X00110000; //THE Fn. IS UART
        break;

   case UART6:
//enable clk for specific uart
       SET_BIT(RCGCUART, 6);
//ENABLE CLK FOR PORT
       SET_BIT(RCGCGPIO, 3);

//DISABLE UART
       CLR_BIT(UART6CTL, 0);

//INTEGER ,FRACTIONAL PORTION OF BAUDRATE 9600
       UART6IBRD = clk_int;
       UART6FBRD = clk_frac;

//SYS CLOCK INTENAL
       UART6CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
       UART6LCRH = 0X60;

//ENABLE RX , TX
       SET_BIT(UART6CTL, 8);
       SET_BIT(UART6CTL, 9);

//ENABLE UART
       SET_BIT(UART6CTL, 0);

//COINFIGURE GPIO
       PORTDDEN = 0X30;
       PORTDAFSEL = 0X30; //ALternate fn. for these pins
       PORTDPCTL = 0X00110000; //THE Fn. IS UART
       break;




    case UART7:
//enable clk for specific uart
        SET_BIT(RCGCUART, 7);
//ENABLE CLK FOR PORT
        SET_BIT(RCGCGPIO, 4);

//DISABLE UART
        CLR_BIT(UART7CTL, 0);

//INTEGER ,FRACTIONAL PORTION OF BAUDRATE 9600
        UART7IBRD = clk_int;
        UART7FBRD = clk_frac;

//SYS CLOCK INTENAL
        UART7CC = 0X0;

//CONFIGURATION UART NO PARITY 1 STOPBIT NO INTERRUAPT 8BITS DATA
        UART7LCRH = 0X60;

//ENABLE RX , TX
        SET_BIT(UART7CTL, 8);
        SET_BIT(UART7CTL, 9);

//ENABLE UART
        SET_BIT(UART7CTL, 0);

//COINFIGURE GPIO
        PORTEDEN = 0X03;
        PORTEAFSEL = 0X03; //ALternate fn. for these pins
        PORTEPCTL = 0X11; //THE Fn. IS UART
        break;
    }
}

uint8 UART_Receive(UART_N0_t uart)
{
    uint8 data = 0;
    if(uart==UART0){
        while (GET_BIT(UART0FR,4) == 1);
        data = UART0DR;
    }else if(uart==UART1){
        while (GET_BIT(UART1FR,4) == 1);
        data = UART1DR;
    }else if(uart==UART2){
        while (GET_BIT(UART2FR,4) == 1);
        data = UART2DR;
    }else if(uart==UART3){
        while (GET_BIT(UART3FR,4) == 1);
        data = UART3DR;
    }else if(uart==UART4){
        while (GET_BIT(UART4FR,4) == 1);
        data = UART4DR;
    }else if(uart==UART5){
        while (GET_BIT(UART5FR,4) == 1);
        data = UART5DR;
    }else if(uart==UART6){
        while (GET_BIT(UART6FR,4) == 1);
        data = UART6DR;
    }else{
        while (GET_BIT(UART7FR,4) == 1);
            data = UART7DR;
    }
    return data;
}

void UART_Transmit(UART_N0_t uart,uint8 data){

    if(uart==UART0){
        while (GET_BIT(UART0FR,5) == 1);//wait utill buffer is not full
            UART0DR=data;
     }else if(uart==UART1){
         while (GET_BIT(UART1FR,5) == 1);//wait utill buffer is not full
             UART1DR=data;
     }else if(uart==UART2){

         while (GET_BIT(UART2FR,5)==1);//wait utill buffer is not full
         UART2DR=data;
     }else if(uart==UART3){
         while (GET_BIT(UART3FR,5) == 1);//wait utill buffer is not full
             UART3DR=data;
     }else if(uart==UART4){
         while (GET_BIT(UART4FR,5) == 1);//wait utill buffer is not full
             UART4DR=data;
     }else if(uart==UART5){
         while (GET_BIT(UART5FR,5) == 1);//wait utill buffer is not full
             UART5DR=data;
     }else if(uart==UART6){
         while (GET_BIT(UART6FR,5) == 1);//wait utill buffer is not full
             UART6DR=data;
     }else{
         while (GET_BIT(UART7FR,5) == 1);//wait utill buffer is not full
             UART7DR=data;
 }

}
