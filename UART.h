/*
 * UART.h
 *
 *  Created on: Nov 26, 2019
 *      Author: ali zewail
 */

#ifndef UART_H_
#define UART_H_


typedef enum{
 UART0,
 UART1,
 UART2,
 UART3,
 UART4,
 UART5,
 UART6,
 UART7
}UART_N0_t;

typedef enum{
Parity_1,
Parity_0
}PARITY_t;


typedef enum{
data_5_bits,
data_6_bits,
data_7_bits,
data_8_bits
}DATA_LEN_t;


void UART_Transmit(UART_N0_t uart,uint8 data);
void UART_Init(UART_N0_t uart,f32 baud_rate);
uint8 UART_Receive(UART_N0_t uart);
void UART_TransmitString(UART_N0_t uart,uint8 *data);


#endif /* UART_H_ */
