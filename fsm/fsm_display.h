#ifndef FSM_DISPLAY_H
#define	FSM_DISPLAY_H

#include <p18f4620.h>

extern unsigned int pH_value;
extern unsigned int SS_value;
extern unsigned int COD_value;
extern unsigned int TMP_value;
extern unsigned int NH4_value;
extern unsigned int NO3_value;
extern unsigned int FLOW_value;

extern unsigned int pH_value_min;
extern unsigned int pH_value_max;
extern unsigned int SS_value_min;
extern unsigned int SS_value_max;
extern unsigned int COD_value_min;
extern unsigned int COD_value_max;
extern unsigned int TMP_value_min;
extern unsigned int TMP_value_max;
extern unsigned int NH4_value_min;
extern unsigned int NH4_value_max;
extern unsigned int NO3_value_min;
extern unsigned int NO3_value_max;
extern unsigned int FLOW_value_min;
extern unsigned int FLOW_value_max;

void fsm_display_run(void);
void fsm_pH_run(void);
void fsm_SS_run(void);
void fsm_COD_run(void);
void fsm_TMP_run(void);
void fsm_NH4_run(void);
void fsm_NO3_run(void);
void fsm_FLOW_run(void);

#endif	/* FSM_DISPLAY_H */

