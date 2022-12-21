#include "fsm_mode.h"
#include "../button/button.h"
#include "../lcd/lcd.h"

unsigned int mode = MODE_INIT;

void fsm_mode_run(void)
{
    // FSM to choose MODE
    switch(mode){
        case MODE_INIT:
            mode = WARNING_MODE;
            lcd_clearS();
            lcd_print_stringS(0, 0, "WARNING MODE");
            lcd_display_screen();
            delay_ms(200);
            break;
            
        case WARNING_MODE:
            if (is_button_pressed(BUTTON_1)) {
                mode = DISPLAY_MODE;
            }
            // Check if all parameters are in safe threshold
            
            break;
            
        case DISPLAY_MODE:            
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }        
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_pH;
                lcd_clearS();
                lcd_print_stringS(0, 0, "pH =   .");
                lcd_display_screen();
            }
            else {
                lcd_clearS();
                lcd_print_stringS(0, 0, "DISPLAY MODE");
                lcd_display_screen();
            }
            break;
            
        default:
            break;
    }    
}
