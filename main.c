#include "main.h"

unsigned int adcValue[6];

unsigned int pH_value;
unsigned int SS_value;
unsigned int COD_value;
unsigned int NH4_value;
unsigned int NO3_value;
unsigned int FLOW_value;
unsigned int TMP_value;

unsigned int simulateCnt;

void init_system(void);
void delay_ms(int value);
void get_adc(void);
void get_sensor(void);
void send_software(void);

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
        get_sensor();
        send_software();
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
    init_uart();
}

void delay_ms(int value) 
{
    int i, j;
    
	for(i = 0; i < value; i++)
		for(j = 0; j < 238; j++);
}

void get_adc(void)
{
    int i;
    
    for (i = 0; i < 2; i++) {
        adcValue[i] = get_adc_value(i);
        delay_ms(20);
    }
    
    lcd_print_numS(0, 0, adcValue[0]);
    lcd_print_numS(0, 6, adcValue[1]);
//    lcd_print_numS(0, 12, adcValue[2]);
//    lcd_print_numS(1, 0, adcValue[3]);
//    lcd_print_numS(1, 6, adcValue[4]);
//    lcd_print_numS(1, 12, adcValue[5]);
    
}

void get_sensor(void)
{
//    pH_value = adcValue[0];
//    SS_value = adcValue[1];
//    COD_value = adcValue[2];
//    NH4_value = adcValue[3];
//    NO3_value = adcValue[4];
//    FLOW_value = adcValue[5];
        pH_value = 443;
        SS_value = adcValue[1];
        COD_value = 3075;
        NH4_value = 27;
        NO3_value = 12;
        TMP_value = adcValue[0];
        FLOW_value = 5120;
}

void send_software(void)
{
    simulateCnt = (simulateCnt + 1) % 40;
    if (simulateCnt) return;
    
    uart_send_string("20.04.16 09:12:07  pH=  ");
    uart_send_num_percent(pH_value);
    
    uart_send_string(" pH SS= ");
    uart_send_num_percent(SS_value);
    
    uart_send_string(" mg/l CSB= ");
    uart_send_num_percent(COD_value);
    
    uart_send_string(" mg/l TMP= ");
    uart_send_num_percent(TMP_value);
    
    uart_send_string(" C NH4= ");
    uart_send_num_percent(NH4_value);
    
    uart_send_string(" mg/l NO3= ");
    uart_send_num_percent(NO3_value);
    
    uart_send_string(" mg/l FLOW= ");
    uart_send_num_percent(FLOW_value);
    
    uart_send_string(" m3/h \r\n");
}