#include "fsm_uart_receive.h"
#include "../lcd/lcd.h"
#include "../uart/uart.h"

#define INIT_RECEIVE		0
#define WAIT_HEADER_1		1
#define WAIT_HEADER_2		2
#define RECEIVE_DATA		3
#define END_OF_RECEIVE_1	4
#define END_OF_RECEIVE_2	5

unsigned char statusReceive = INIT_RECEIVE;
unsigned char flagOfDataReceiveComplete = 0;
unsigned char indexOfDataReceive = 0;
unsigned char numberOfDataReceive = 5;
unsigned char dataReceive[50];

void uart_isr_simulate_machine(void)
{
    unsigned char tempReceive;
    tempReceive = RCREG;
    uart_putchar(tempReceive);
    switch(statusReceive)
    {
        case INIT_RECEIVE:
        case WAIT_HEADER_1:
            if (tempReceive == 0xfe)
            {
                indexOfDataReceive = 0;
                statusReceive = WAIT_HEADER_2;
            }
            break;
        case WAIT_HEADER_2:
            if (tempReceive == 0xfe)
                statusReceive = RECEIVE_DATA;
            else
                statusReceive = WAIT_HEADER_1;
            break;
        case RECEIVE_DATA:
            dataReceive[indexOfDataReceive] = tempReceive;
            indexOfDataReceive++;
            if (indexOfDataReceive >= numberOfDataReceive)
                statusReceive = END_OF_RECEIVE_1;

            break;
        case END_OF_RECEIVE_1:
            if (tempReceive == 0xff)
                statusReceive = END_OF_RECEIVE_2;
            else
                statusReceive = WAIT_HEADER_1;
            break;
        case END_OF_RECEIVE_2:
            if (tempReceive == 0xff)
            {
                flagOfDataReceiveComplete = 1;
                statusReceive = INIT_RECEIVE;
            }
            else
                statusReceive = WAIT_HEADER_1;
            break;
        default:
            statusReceive = INIT_RECEIVE;
            break;
    }
}

void uart_display(void)
{
    unsigned char i;
    
    if(flagOfDataReceiveComplete == 1)
    {
        lcd_print_stringS(1, 5, "                ");
        for (i = 0; i < numberOfDataReceive;i++)
            lcd_print_numS(1, 3 * i + 4, dataReceive[i]);
        lcd_print_numS(1,15,statusReceive);
    }
}