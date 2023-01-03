#include "fsm_display.h"
#include "fsm_mode.h"
#include "../button/button.h"
#include "../lcd/lcd.h"
#include "../fsm/fsm_uart_receive.h"

unsigned int pH_value = 750;
unsigned int SS_value = 3500;
unsigned int COD_value = 12000;
unsigned int TMP_value = 3000;
unsigned int NH4_value = 400;
unsigned int NO3_value = 400;
unsigned int FLOW_value = 20000;

unsigned int pH_value_min = 690;
unsigned int pH_value_max = 780;
unsigned int SS_value_min = 2800;
unsigned int SS_value_max = 4500;
unsigned int COD_value_min = 9000;
unsigned int COD_value_max = 18000;
unsigned int TMP_value_min = 2500;
unsigned int TMP_value_max = 3300;
unsigned int NH4_value_min = 210;
unsigned int NH4_value_max = 540;
unsigned int NO3_value_min = 150;
unsigned int NO3_value_max = 550;
unsigned int FLOW_value_min = 16000;
unsigned int FLOW_value_max = 25000;

void fsm_pH_run(void);

void fsm_display_run(void)
{
    // FSM for DISPLAY MODE
    switch (mode){    
//---------------------------------------------------------------- DISPLAY_pH //
        case DISPLAY_pH:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_SS;
                lcd_clearS();
                lcd_print_stringS(0, 0, "SS =   .  mg/L");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_pH_min;
                lcd_print_stringS(1, 0, "min");
                lcd_display_screen();
            }
            else {
                lcd_print_stringS(0, 5, "  .  ");
                
                if (pH_value > 999) {
                    lcd_print_numS(0, 5, pH_value / 100);
                }
                else {
                    lcd_print_numS(0, 6, pH_value / 100);
                }
                lcd_print_numS(0, 8, pH_value % 100);
                lcd_display_screen();
            }
            break;

//---------------------------------------------------------------- DISPLAY_SS //
        case DISPLAY_SS:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_COD;
                lcd_clearS();
                lcd_print_stringS(0, 0, "COD =    .  mg/L");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_SS_min;
                lcd_print_stringS(1, 0, "min");
                lcd_display_screen();
            }
            else {
                lcd_print_stringS(0, 5, "  .  ");
                
                if (SS_value > 999) {
                    lcd_print_numS(0, 5, SS_value / 100);
                }
                else {
                    lcd_print_numS(0, 6, SS_value / 100);
                }
                lcd_print_numS(0, 8, SS_value % 100);
                lcd_display_screen();
            }
            break;
            
//---------------------------------------------------------------- DISPLAY_COD //
        case DISPLAY_COD:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_TMP;
                lcd_clearS();
                lcd_print_stringS(0, 0, "TMP =   .  C");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_COD_min;
                lcd_print_stringS(1, 0, "min");
                lcd_display_screen();
            }
            else {
                lcd_print_stringS(0, 6, "   .  ");
                
                if (COD_value > 9999) {
                    lcd_print_numS(0, 6, COD_value / 100);
                }
                else {
                    lcd_print_numS(0, 7, COD_value / 100);
                }
                lcd_print_numS(0, 10, COD_value % 100);
                lcd_display_screen();
            }
            break;
            
//---------------------------------------------------------------- DISPLAY_TMP //
        case DISPLAY_TMP:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_NH4;
                lcd_clearS();
                lcd_print_stringS(0, 0, "NH4 =   .  mg/L");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(5)) {
                mode = SET_TMP_min;
                lcd_print_stringS(1, 0, "min");
                lcd_display_screen();
            }
            else {
                lcd_print_stringS(0, 6, "  .  ");
                
                if (TMP_value > 999) {
                    lcd_print_numS(0, 6, TMP_value / 100);
                }
                else {
                    lcd_print_numS(0, 7, TMP_value / 100);
                }
                lcd_print_numS(0, 9, TMP_value % 100);
                lcd_display_screen();
            }
            break;
            
//---------------------------------------------------------------- DISPLAY_NH4 //
        case DISPLAY_NH4:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_NO3;
                lcd_clearS();
                lcd_print_stringS(0, 0, "NO3 =   .  mg/L");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_NH4_min;
                lcd_print_stringS(1, 0, "min");
                lcd_display_screen();
            }
            else {
                lcd_print_stringS(0, 6, "  .  ");
                
                if (NH4_value > 999) {
                    lcd_print_numS(0, 6, NH4_value / 100);
                }
                else {
                    lcd_print_numS(0, 7, NH4_value / 100);
                }
                lcd_print_numS(0, 9, NH4_value % 100);
                lcd_display_screen();
            }
            break;
            
//---------------------------------------------------------------- DISPLAY_NO3 //
        case DISPLAY_NO3:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_FLOW;
                lcd_clearS();
                lcd_print_stringS(0, 0, "FLOW =    m3/h");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_NO3_min;
                lcd_print_stringS(1, 0, "min");
                lcd_display_screen();
            }
            else {
                lcd_print_stringS(0, 6, "  .  ");
                
                if (NO3_value > 999) {
                    lcd_print_numS(0, 6, NO3_value / 100);
                }
                else {
                    lcd_print_numS(0, 7, NO3_value / 100);
                }
                lcd_print_numS(0, 9, NO3_value % 100);
                lcd_display_screen();
            }
            break;
            
//---------------------------------------------------------------- DISPLAY_FLOW //
        case DISPLAY_FLOW:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_pH;
                lcd_clearS();
                lcd_print_stringS(0, 0, "pH =   .");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_FLOW_min;
                lcd_print_stringS(1, 0, "min");
                lcd_display_screen();
            }
            else {
                lcd_print_stringS(0, 7, "   ");
                
                if (FLOW_value > 9999) {
                    lcd_print_numS(0, 7, FLOW_value / 100);
                }
                else {
                    lcd_print_numS(0, 8, FLOW_value / 100);
                }
                lcd_display_screen();
            }
            break;
            
        default:
            break;
    }
}

void fsm_pH_run(void)
{
//------------------------------------------------------- SETTING pH THRESHOLDS //
    switch(mode){
        case SET_pH_min:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_SS;
                lcd_clearS();
                lcd_print_stringS(0, 0, "SS =   .");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_pH_max;
                lcd_print_stringS(1, 0, "max");
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_A)) {
                if (pH_value_min <= 1390) {
                    pH_value_min += 10;
                }
            }
            else if (is_button_pressed(BUTTON_B)) {
                if (pH_value_min >= 10) {
                    pH_value_min -= 10;
                }
            }
            else {
                lcd_print_stringS(0, 5, "  .  ");
                
                if (pH_value_min > 999) {
                    lcd_print_numS(0, 5, pH_value_min / 100);
                }
                else {
                    lcd_print_numS(0, 6, pH_value_min / 100);
                }
                lcd_print_numS(0, 8, pH_value_min % 100);
                lcd_display_screen();
            }
            break;
            
        case SET_pH_max:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_SS;
                lcd_clearS();
                lcd_print_stringS(0, 0, "SS =   .  mg/L");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_pH_min;
                lcd_print_stringS(1, 0, "min");
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_A)) {
                if (pH_value_max <= 1390) {
                    pH_value_max += 10;
                }
            }
            else if (is_button_pressed(BUTTON_B)) {
                if (pH_value_max >= 10) {
                    pH_value_max -= 10;
                }
            }
            else {
                lcd_print_stringS(0, 5, "  .  ");
                
                if (pH_value_max > 999) {
                    lcd_print_numS(0, 5, pH_value_max / 100);
                }
                else {
                    lcd_print_numS(0, 6, pH_value_max / 100);
                }
                lcd_print_numS(0, 8, pH_value_max % 100);
                lcd_display_screen();
            }
            break;
            
        default:
            break;
    }
}

void fsm_SS_run(void)
{
//------------------------------------------------------- SETTING SS THRESHOLDS //
    switch(mode){
        case SET_SS_min:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_COD;
                lcd_clearS();
                lcd_print_stringS(0, 0, "COD =    .  mg/L");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_SS_max;
                lcd_print_stringS(1, 0, "max");
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_A)) {
                if (SS_value_min <= 9800) {
                    SS_value_min += 100;
                }
            }
            else if (is_button_pressed(BUTTON_B)) {
                if (SS_value_min >= 100) {
                    SS_value_min -= 100;
                }
            }
            else {
                lcd_print_stringS(0, 5, "  .  ");
                
                if (SS_value_min > 999) {
                    lcd_print_numS(0, 5, SS_value_min / 100);
                }
                else {
                    lcd_print_numS(0, 6, SS_value_min / 100);
                }
                lcd_print_numS(0, 8, SS_value_min % 100);
                lcd_display_screen();
            }
            break;
            
        case SET_SS_max:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_COD;
                lcd_clearS();
                lcd_print_stringS(0, 0, "COD =    .  mg/L");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_SS_min;
                lcd_print_stringS(1, 0, "min");
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_A)) {
                if (SS_value_max <= 9800) {
                    SS_value_max += 100;
                }
            }
            else if (is_button_pressed(BUTTON_B)) {
                if (SS_value_max >= 100) {
                    SS_value_max -= 100;
                }
            }
            else {
                lcd_print_stringS(0, 5, "  .  ");
                
                if (SS_value_max > 999) {
                    lcd_print_numS(0, 5, SS_value_max / 100);
                }
                else {
                    lcd_print_numS(0, 6, SS_value_max / 100);
                }
                lcd_print_numS(0, 8, SS_value_max % 100);
                lcd_display_screen();
            }
            break;
            
        default:
            break;
    }
}

void fsm_COD_run(void)
{
//------------------------------------------------------- SETTING COD THRESHOLDS //
    switch(mode){
        case SET_COD_min:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_TMP;
                lcd_clearS();
                lcd_print_stringS(0, 0, "TMP =   .  C");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_COD_max;
                lcd_print_stringS(1, 0, "max");
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_A)) {
                if (COD_value_min <= 99800) {
                    COD_value_min += 100;
                }
            }
            else if (is_button_pressed(BUTTON_B)) {
                if (COD_value_min >= 1100) {
                    COD_value_min -= 100;
                }
            }
            else {
                lcd_print_stringS(0, 6, "   .  ");
                
                if (COD_value_min > 9999) {
                    lcd_print_numS(0, 6, COD_value_min / 100);
                }
                else {
                    lcd_print_numS(0, 7, COD_value_min / 100);
                }
                lcd_print_numS(0, 10, COD_value_min % 100);
                lcd_display_screen();
            }
            break;
            
        case SET_COD_max:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_TMP;
                lcd_clearS();
                lcd_print_stringS(0, 0, "TMP =   .  C");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_COD_min;
                lcd_print_stringS(1, 0, "min");
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_A)) {
                if (COD_value_max <= 99800) {
                    COD_value_max += 100;
                }
            }
            else if (is_button_pressed(BUTTON_B)) {
                if (COD_value_max >= 1100) {
                    COD_value_max -= 100;
                }
            }
            else {
                lcd_print_stringS(0, 6, "   .  ");
                
                if (COD_value_max > 9999) {
                    lcd_print_numS(0, 6, COD_value_max / 100);
                }
                else {
                    lcd_print_numS(0, 7, COD_value_max / 100);
                }
                lcd_print_numS(0, 10, COD_value_max % 100);
                lcd_display_screen();
            }
            break;
            
        default:
            break;
    }
}

void fsm_TMP_run(void)
{
//------------------------------------------------------- SETTING TMP THRESHOLDS //
    switch(mode){
        case SET_TMP_min:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_NH4;
                lcd_clearS();
                lcd_print_stringS(0, 0, "NH4 =   .  mg/L");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_TMP_max;
                lcd_print_stringS(1, 0, "max");
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_A)) {
                if (TMP_value_min <= 9800) {
                    TMP_value_min += 100;
                }
            }
            else if (is_button_pressed(BUTTON_B)) {
                if (TMP_value_min >= 100) {
                    TMP_value_min -= 100;
                }
            }
            else {
                lcd_print_stringS(0, 6, "  .  ");
                
                if (TMP_value_min > 999) {
                    lcd_print_numS(0, 6, TMP_value_min / 100);
                }
                else {
                    lcd_print_numS(0, 7, TMP_value_min / 100);
                }
                lcd_print_numS(0, 9, TMP_value_min % 100);
                lcd_display_screen();
            }
            break;
            
        case SET_TMP_max:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_NH4;
                lcd_clearS();
                lcd_print_stringS(0, 0, "NH4 =   .  mg/L");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_TMP_min;
                lcd_print_stringS(1, 0, "min");
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_A)) {
                if (TMP_value_max <= 9800) {
                    TMP_value_max += 100;
                }
            }
            else if (is_button_pressed(BUTTON_B)) {
                if (TMP_value_max >= 100) {
                    TMP_value_max -= 100;
                }
            }
            else {
                lcd_print_stringS(0, 6, "  .  ");
                
                if (TMP_value_min > 999) {
                    lcd_print_numS(0, 6, TMP_value_max / 100);
                }
                else {
                    lcd_print_numS(0, 7, TMP_value_max / 100);
                }
                lcd_print_numS(0, 9, TMP_value_max % 100);
                lcd_display_screen();
            }
            break;
            
        default:
            break;
    }
}

void fsm_NH4_run(void)
{
//------------------------------------------------------- SETTING NH4 THRESHOLDS //
    switch(mode){
        case SET_NH4_min:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_NO3;
                lcd_clearS();
                lcd_print_stringS(0, 0, "NO3 =   .  mg/L");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_NH4_max;
                lcd_print_stringS(1, 0, "max");
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_A)) {
                if (NH4_value_min <= 1990) {
                    NH4_value_min += 10;
                }
            }
            else if (is_button_pressed(BUTTON_B)) {
                if (NH4_value_min >= 10) {
                    NH4_value_min -= 10;
                }
            }
            else {
                lcd_print_stringS(0, 6, "  .  ");
                
                if (NH4_value_min > 999) {
                    lcd_print_numS(0, 6, NH4_value_min / 100);
                }
                else {
                    lcd_print_numS(0, 7, NH4_value_min / 100);
                }
                lcd_print_numS(0, 9, NH4_value_min % 100);
                lcd_display_screen();
            }
            break;
            
        case SET_NH4_max:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_NO3;
                lcd_clearS();
                lcd_print_stringS(0, 0, "NO3 =   .  mg/L");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_NH4_min;
                lcd_print_stringS(1, 0, "min");
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_A)) {
                if (NH4_value_max <= 1990) {
                    NH4_value_max += 10;
                }
            }
            else if (is_button_pressed(BUTTON_B)) {
                if (NH4_value_max >= 10) {
                    NH4_value_max -= 10;
                }
            }
            else {
                lcd_print_stringS(0, 6, "  .  ");
                
                if (NH4_value_max > 999) {
                    lcd_print_numS(0, 6, NH4_value_max / 100);
                }
                else {
                    lcd_print_numS(0, 7, NH4_value_max / 100);
                }
                lcd_print_numS(0, 9, NH4_value_max % 100);
                lcd_display_screen();
            }
            break;
            
        default:
            break;
    }
}

void fsm_NO3_run(void)
{
//------------------------------------------------------- SETTING NO3 THRESHOLDS //
    switch(mode){
        case SET_NO3_min:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_FLOW;
                lcd_clearS();
                lcd_print_stringS(0, 0, "FLOW =     m3/h");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_NO3_max;
                lcd_print_stringS(1, 0, "max");
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_A)) {
                if (NO3_value_min <= 1990) {
                    NO3_value_min += 10;
                }
            }
            else if (is_button_pressed(BUTTON_B)) {
                if (NO3_value_min >= 10) {
                    NO3_value_min -= 10;
                }
            }
            else {
                lcd_print_stringS(0, 6, "  .  ");
                
                if (NO3_value_min > 999) {
                    lcd_print_numS(0, 6, NO3_value_min / 100);
                }
                else {
                    lcd_print_numS(0, 7, NO3_value_min / 100);
                }
                lcd_print_numS(0, 9, NO3_value_min % 100);
                lcd_display_screen();
            }
            break;
            
        case SET_NO3_max:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_FLOW;
                lcd_clearS();
                lcd_print_stringS(0, 0, "FLOW =     m3/h");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_NO3_min;
                lcd_print_stringS(1, 0, "min");
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_A)) {
                if (NO3_value_max <= 1990) {
                    NO3_value_max += 10;
                }
            }
            else if (is_button_pressed(BUTTON_B)) {
                if (NO3_value_max >= 10) {
                    NO3_value_max -= 10;
                }
            }
            else {
                lcd_print_stringS(0, 6, "  .  ");
                
                if (NO3_value_max > 999) {
                    lcd_print_numS(0, 6, NO3_value_max / 100);
                }
                else {
                    lcd_print_numS(0, 7, NO3_value_max / 100);
                }
                lcd_print_numS(0, 9, NO3_value_max % 100);
                lcd_display_screen();
            }
            break;
            
        default:
            break;
    }
}

void fsm_FLOW_run(void)
{
//------------------------------------------------------- SETTING FLOW THRESHOLDS //
    switch(mode){
        case SET_FLOW_min:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_pH;
                lcd_clearS();
                lcd_print_stringS(0, 0, "pH =   .");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_FLOW_max;
                lcd_print_stringS(1, 0, "max");
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_A)) {
                if (FLOW_value_min <= 99800) {
                    FLOW_value_min += 100;
                }
            }
            else if (is_button_pressed(BUTTON_B)) {
                if (FLOW_value_min >= 1100) {
                    FLOW_value_min -= 100;
                }
            }
            else {
                lcd_print_stringS(0, 7, "   ");
                
                if (FLOW_value_min > 9999) {
                    lcd_print_numS(0, 7, FLOW_value_min / 100);
                }
                else {
                    lcd_print_numS(0, 8, FLOW_value_min / 100);
                }
                lcd_display_screen();
            }
            break;
            
        case SET_FLOW_max:
            if (is_button_pressed(BUTTON_1)) {
                mode = WARNING_MODE;
                lcd_clearS();
                lcd_print_stringS(0, 0, "WARNING MODE");
                lcd_display_screen();
                delay_ms(200);
            }
            else if (is_button_pressed(BUTTON_2)) {
                mode = DISPLAY_pH;
                lcd_clearS();
                lcd_print_stringS(0, 0, "pH =   .");
                uart_display();
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_5)) {
                mode = SET_FLOW_min;
                lcd_print_stringS(1, 0, "min");
                lcd_display_screen();
            }
            else if (is_button_pressed(BUTTON_A)) {
                if (FLOW_value_max <= 99800) {
                    FLOW_value_max += 100;
                }
            }
            else if (is_button_pressed(BUTTON_B)) {
                if (FLOW_value_max >= 1100) {
                    FLOW_value_max -= 100;
                }
            }
            else {
                lcd_print_stringS(0, 7, "   ");
                
                if (FLOW_value_max > 9999) {
                    lcd_print_numS(0, 7, FLOW_value_max / 100);
                }
                else {
                    lcd_print_numS(0, 8, FLOW_value_max / 100);
                }
                lcd_display_screen();
            }
            break;
            
        default:
            break;
    }
}