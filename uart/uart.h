#ifndef UART_H
#define	UART_H

#include <p18f4620.h>

extern unsigned char dataReceive;

void init_uart();
void uart_putchar(unsigned char data);
void uart_send_str(const char *str);
void UartSendString(const rom char *str);
void uart_isr();

#endif	/* UART_H */

