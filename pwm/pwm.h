#ifndef PWM_H
#define	PWM_H

#include <p18f4620.h>

void init_pwm(void);
void pwm_set_speed(unsigned char value);

#endif	/* PWM_H */

