#ifndef ADC_H
#define	ADC_H

#include <p18f4620.h>

#define ADC_CHANNEL 	13

void init_adc(void);
int get_adc_value(unsigned char channel);

#endif	/* ADC_H */

