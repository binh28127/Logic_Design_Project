#include "button.h"

unsigned int key_code[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

unsigned int key_reg[2][16] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

unsigned char arrayMaskOutputOfKey [4] = {0x10,0x20,0x40,0x80};
unsigned char arrayMaskInputOfKey [4] = {0x01,0x02,0x04,0x08};
unsigned char arrayMaskInputOfButton [8] = {0x01,0x02,0x04,0x08,
                                            0x10,0x20,0x40,0x80};

void init_key_matrix()
{
	TRIS_BUTTON = 0x0f; 
	PORT_BUTTON = 0xff;
}

void init_key_matrix_with_uart()
{
    TRIS_BUTTON = TRIS_BUTTON & 0xcf; //RC5 & RC4 Output
	PORT_BUTTON = 0xff;
}

void scan_key_matrix()
{
	int i,j;
	for(i=0;i<MAX_ROW;i++)     
	{
		PORT_BUTTON = ~arrayMaskOutputOfKey[i];
		for(j=0;j<MAX_COL;j++)
		{             
			if((PORT_BUTTON & arrayMaskInputOfKey[j]) == 0)  
				key_code[i*MAX_ROW+j] = key_code[i*MAX_ROW+j] + 1;
			else
				key_code[i*MAX_ROW+j] = 0;
		}
	}
}

void scan_key_matrix_with_uart()
{
	int i,j;
	for(i=0;i<2;i++)
	{
		PORT_BUTTON = PORT_BUTTON & ~arrayMaskOutputOfKey[i];
        PORT_BUTTON = PORT_BUTTON | 0x0f;
		for(j=0;j<MAX_COL;j++)
		{
			if((PORT_BUTTON & arrayMaskInputOfKey[j]) == 0)
				key_code[i*MAX_ROW+j] = key_code[i*MAX_ROW+j] + 1;
			else
				key_code[i*MAX_ROW+j] = 0;
		}
	}
}

void button_delay_ms(int value)
{
	int i,j;
	for(i=0;i<value;i++)
		for(j=0;j<238;j++);
}

unsigned int is_button_pressed(unsigned int button)
{
    if (key_code[button]) {
        key_code[button] = 0;
        button_delay_ms(100);
        return 1;
    }
    else return 0;
}