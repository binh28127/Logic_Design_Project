#include "fsm_warning.h"
#include "fsm_mode.h"
#include "../lcd/lcd.h"
#include "../button/button.h"
#include "fsm_display.h"
#include "../pwm/pwm.h"

#define pH          0
#define SS          1
#define COD         2
#define TMP         3
#define NH4         4
#define NO3         5
#define FLOW        6

unsigned int warning_arr[7] = { 0, 0, 0, 0, 0, 0, 0 };
unsigned int current_r = 0;
unsigned int current_c = 0;
unsigned int idx = 0;
unsigned int delay_count = 0;

unsigned int check_parameters(void);
void warning_display(void);

void fsm_warning_run(void)
{
    switch(mode) {
        case NORMAL_CONDITION:
            if (is_button_pressed(BUTTON_1)) {
                mode = DISPLAY_MODE;
            }
            if (check_parameters()) {
                mode = WARNING_CONDITION;
            }
            else {
                pwm_set_speed(0);
                lcd_clearS();
                lcd_print_stringS(0, 0, "ALL PARAMETERS  ARE NORMAL");
                lcd_display_screen();
            }
            break;
            
        case WARNING_CONDITION:
            if (is_button_pressed(BUTTON_1)) {
                mode = DISPLAY_MODE;
            }
            if (!check_parameters()) {
                mode = NORMAL_CONDITION;
                current_c = 0;
                current_r = 0;
            }
            pwm_set_speed(25);
            if (check_parameters() == 1 || check_parameters() == 3) {
                lcd_clearS();
                lcd_print_stringS(0, 0, "HIGH: ");
                current_c = 6;
                current_r = 0;
                for (idx = 0; idx < 7; idx++) {
                    if (warning_arr[idx] == 1) {
                        warning_display();
                    }
                }
                lcd_display_screen();
//                delay_ms(1000);
                for (delay_count = 0; delay_count < 238 * 3000; delay_count++) {
                    if (is_button_pressed(BUTTON_1)) {
                        mode = DISPLAY_MODE;
                        break;
                    }
                }
            }
            if (check_parameters() == 2 || check_parameters() == 3) {
                lcd_clearS();
                lcd_print_stringS(0, 0, "LOW: ");
                current_c = 5;
                current_r = 0;
                for (idx = 0; idx < 7; idx++) {
                    if (warning_arr[idx] == 2) {
                        warning_display();
                    }
                }
                lcd_display_screen();
//                delay_ms(1000);
                for (delay_count = 0; delay_count < 238 * 3000; delay_count++) {
                    if (is_button_pressed(BUTTON_1)) {
                        mode = DISPLAY_MODE;
                        break;
                    }
                }
            }
            break;
            
        default:
            break;
    }
}

unsigned int check_parameters(void)
{    
    unsigned int warning_type = 0;
    
    if (pH_value > pH_value_max) warning_arr[pH] = 1;
    else if (pH_value < pH_value_min) warning_arr[pH] = 2;
    else warning_arr[pH] = 0;
    
    if (SS_value > SS_value_max) warning_arr[SS] = 1;
    else if (SS_value < SS_value_min) warning_arr[SS] = 2;
    else warning_arr[SS] = 0;
    
    if (COD_value > COD_value_max) warning_arr[COD] = 1;
    else if (COD_value < COD_value_min) warning_arr[COD] = 2;
    else warning_arr[COD] = 0;
    
    if (TMP_value > TMP_value_max) warning_arr[TMP] = 1;
    else if (TMP_value < TMP_value_min) warning_arr[TMP] = 2;
    else warning_arr[TMP] = 0;
    
    if (NH4_value > NH4_value_max) warning_arr[NH4] = 1;
    else if (NH4_value < NH4_value_min) warning_arr[NH4] = 2;
    else warning_arr[NH4] = 0;
    
    if (NO3_value > NO3_value_max) warning_arr[NO3] = 1;
    else if (NO3_value < NO3_value_min) warning_arr[NO3] = 2;
    else warning_arr[NO3] = 0;
    
    if (FLOW_value > FLOW_value_max) warning_arr[FLOW] = 1;
    else if (FLOW_value < FLOW_value_min) warning_arr[FLOW] = 2;
    else warning_arr[FLOW] = 0;
    
    for (idx = 0; idx < 7; idx++) {
        if (warning_arr[idx] == 1 && warning_type == 0) {
            warning_type = 1;
        }
        else if (warning_arr[idx] == 1 && warning_type == 2) {
            warning_type = 3;
        }
        else if (warning_arr[idx] == 2 && warning_type == 0) {
            warning_type = 2;
        }
        else if (warning_arr[idx] == 2 && warning_type == 1) {
            warning_type = 3;
        }
    }
    return warning_type;
}

void warning_display(void)
{
    switch(idx) {
        case pH:
            lcd_print_stringS(current_r, current_c, "pH");
            current_c += 3;
            break;
        case SS:
            lcd_print_stringS(current_r, current_c, "SS");
            current_c += 3;
            break;
        case COD:
            lcd_print_stringS(current_r, current_c, "COD");
            current_c += 4;
            break;
        case TMP:
            lcd_print_stringS(current_r, current_c, "TMP");
            current_c += 4;
            break;
        case NH4:
            lcd_print_stringS(current_r, current_c, "NH4");
            current_c += 4;
            break;
        case NO3:
            lcd_print_stringS(current_r, current_c, "NO3");
            current_c += 4;
            break;
        case FLOW:
            lcd_print_stringS(current_r, current_c, "FLOW");
            current_c += 5;
            break;
        default:
            break;
    }
    if (current_c > 15) {
        current_r = 1;
    }
    else current_r = 0;
}
