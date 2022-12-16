#ifndef LCD_H
#define	LCD_H

#include <p18f4620.h>

#define LCD_RS			2 		//define MCU pin connected to LCD RS (RB2)
#define LCD_E			3		//define MCU pin connected to LCD E  (RB3)
#define LCD_D4			4		//define MCU pin connected to LCD D4 (RB4)
#define LCD_D5			5		//define MCU pin connected to LCD D5 (RB5)
#define LCD_D6			6		//define MCU pin connected to LCD D6 (RB6)
#define LCD_D7			7		//define MCU pin connected to LCD D7 (RB7)

#define FALSE   0
#define TRUE    1
#define CLR     0
#define SET     1

#define DAT     1       // data mode
#define CMD     0       // command mode
#define READ    1       // read mode
#define WRITE   0       // write mode

#define LCD_DATA_4BIT_HIGH	1   // 4BIT_HIGHT is true
#define LCD_PORT 	PORTB
#define LCD_DDR 	TRISB

#define RS(x)	((x) ? (LCD_PORT |= (1<<LCD_RS)) : (LCD_PORT &= ~(1<<LCD_RS)))
#define EN(x)	((x) ? (LCD_PORT |= (1<<LCD_E)) : (LCD_PORT &= ~(1<<LCD_E)))

#define LCD_DATA_OUT(x)     LCD_PORT &= 0x0F; LCD_PORT |= (x);
#define LCD_DATA_IN         LCD_PORT & 0x0F;
#define LCD_DIR_IN          LCD_PORT |= 0x0F;

void init_lcd(void);
void lcd_send_command(unsigned char cmd);
unsigned long lcd_power_of(int A, int x);
void lcd_delay(unsigned long time);
void lcd_write_4bits(unsigned char dat);
void lcd_write_data(unsigned char data);
void lcd_write_cmd(unsigned char cmd);
void lcd_set_cursor (unsigned char row, unsigned char column);
void lcd_print_char(char c);
void lcd_print_charS(unsigned char c);
void lcd_print_str(const rom unsigned char *string);
void lcd_print_numS(unsigned char x, unsigned char y, long num);
void lcd_display_screen(void);
void lcd_clear (void);
void lcd_clearS(void);

#endif	/* LCD_H */

