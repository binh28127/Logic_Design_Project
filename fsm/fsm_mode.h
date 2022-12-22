#ifndef FSM_MODE_H
#define	FSM_MODE_H

#include <p18f4620.h>

#define MODE_INIT           0
#define WARNING_MODE        1
#define DISPLAY_MODE        2

#define DISPLAY_pH          4
#define DISPLAY_SS          5
#define DISPLAY_COD         6
#define DISPLAY_TMP         7
#define DISPLAY_NH4         8
#define DISPLAY_NO3         9
#define DISPLAY_FLOW        10

#define SET_pH_min          16
#define SET_SS_min          17
#define SET_COD_min         18
#define SET_TMP_min         19
#define SET_NH4_min         20
#define SET_NO3_min         21
#define SET_FLOW_min        22

#define SET_pH_max          26
#define SET_SS_max          27
#define SET_COD_max         28
#define SET_TMP_max         29
#define SET_NH4_max         30
#define SET_NO3_max         31
#define SET_FLOW_max        32

#define NORMAL_CONDITION    35
#define WARNING_CONDITION   36

#define BUTTON_1        0
#define BUTTON_2        1
#define BUTTON_3        2
#define BUTTON_A        3
#define BUTTON_B        7

extern unsigned int mode;

void fsm_mode_run(void);

#endif	/* FSM_MODE_H */

