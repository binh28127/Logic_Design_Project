#include "main.h"

unsigned int adcValue[7];

unsigned int simulateCnt;

int count = 0;

void init_system(void);
void delay_ms(int value);
void get_adc(void);
void get_sensor(void);
void send_software(void);

void main(void)
{
    init_system();
//    lcd_print_stringS(0, 0, "Hello");
//    lcd_display_screen();
//    delay_ms(1000);
    
    while(1)
    {
        while(!flag_timer3);
//        lcd_clear();
        flag_timer3 = 0;
        get_adc();
        get_sensor();
        send_software();                  
        scan_key_matrix();
        
        fsm_mode_run();
        fsm_display_run();
        fsm_warning_run();
        
        fsm_pH_run();
        fsm_SS_run();
        fsm_COD_run();
        fsm_TMP_run();
        fsm_NH4_run();
        fsm_NO3_run();
        fsm_FLOW_run();
    }
}

void init_system(void) 
{
    TRISB = 0x00;		//setup PORTB is output
    init_lcd();
    lcd_clear();
    lcd_clearS();
    init_interrupt();
    init_adc();
    init_timer3(46950); //dinh thoi 10ms
	SetTimer3_ms(50);   //Chu ky thuc hien viec xu ly input,proccess,output
    init_uart();
    init_key_matrix();
    delay_ms(200);
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
    
    for (i = 0; i < 7; i++) {
        adcValue[i] = get_adc_value(i);
        delay_ms(20);
    }
    
//    lcd_print_numS(0, 4, adcValue[0]);
//    lcd_print_numS(0, 8, adcValue[1]);
//    lcd_print_numS(0, 12, adcValue[2]);
//    lcd_print_numS(1, 0, adcValue[3]);
//    lcd_print_numS(1, 4, adcValue[4]);
//    lcd_print_numS(1, 8, adcValue[5]);
//    lcd_print_numS(1, 12, adcValue[6]);
    
}

void get_sensor(void)
{
    pH_value = (0.0 + (long)adcValue[0] * (14.0 - 0.0) / 1023) * 100;
    SS_value = (0.0 + (long)adcValue[1] * (80.0 - 0.0) / 1023) * 100;
    COD_value = (40.0 + (long)adcValue[2] * (250.0 - 40.0) / 1023) * 100;
    TMP_value = (0.0 + (long)adcValue[3] * (60.0 - 0.0) / 1023) * 100;
    NH4_value = (0.0 + (long)adcValue[4] * (12.0 - 0.0) / 86) * 100;
    NO3_value = (0.0 + (long)adcValue[5] * (12.0 - 0.0) / 1023) * 100;
    FLOW_value = (90.0 + (long)adcValue[6] * (400.0 - 90.0) / 1023) * 100;
}

void send_software(void)
{
    simulateCnt = (simulateCnt + 1) % 4;
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