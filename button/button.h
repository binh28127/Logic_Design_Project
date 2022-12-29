#ifndef BUTTON_H
#define	BUTTON_H

#include <p18f4620.h>

#define PORT_BUTTON		PORTC
#define TRIS_BUTTON		TRISC
#define	MAX_COL			4
#define MAX_ROW			4

extern unsigned int key_code[16];

void init_key_matrix();
void init_key_matrix_with_uart();
void scan_key_matrix();
void scan_key_matrix_with_uart();
void button_process();
void button_delay_ms(int value);
unsigned int is_button_pressed(unsigned int button);

#endif	/* BUTTON_H */

