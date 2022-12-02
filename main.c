#include "main.h"

void init_system(void);
void delay_ms(int value);
void get_adc(void);

void main(void)
{
    init_system();
    lcd_print_str("Hello");
    delay_ms(1000);
    
    while(1)
    {
        while(!flag_timer3);
        lcd_clearS();
        flag_timer3 = 0;
        get_adc();
        lcd_display_screen();
    }
}

void init_system(void) 
{
    TRISB = 0x00;		//setup PORTB is output
    lcd_init();
    lcd_clear();
    lcd_clearS();
    delay_ms(500);
    init_interrupt();
    init_adc();
    init_timer3(46950); //dinh thoi 10ms
	SetTimer3_ms(50);   //Chu ky thuc hien viec xu ly input,proccess,output
}

void delay_ms(int value) 
{
    int i, j;
    
	for(i = 0; i < value; i++)
		for(j = 0; j < 238; j++);
}

void get_adc(void)
{
    unsigned int adcValue;
    adcValue = get_adc_value(0);
    lcd_print_numS(0, 0, adcValue);
}
