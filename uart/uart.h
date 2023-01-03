#ifndef UART_H
#define	UART_H

#include <p18f4620.h>

void init_uart();
void uart_putchar(unsigned char data);
void uart_send_str(const char *str);
void uart_send_string(const rom char *str);
void uart_send_num(long num);
void uart_send_num_percent(long num);
void uart_isr();

#endif	/* UART_H */

