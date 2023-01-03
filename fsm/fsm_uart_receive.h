#ifndef FSM_UART_RECEIVE_H
#define	FSM_UART_RECEIVE_H

#include <p18f4620.h>

extern unsigned char statusReceive;
extern unsigned char flagOfDataReceiveComplete;
extern unsigned char dataReceive[50];

void uart_isr_simulate_machine(void);
void uart_display(void);

#endif	/* FSM_UART_RECEIVE_H */

