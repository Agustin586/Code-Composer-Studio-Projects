#ifndef INCLUDE_ADC_H_
#define INCLUDE_ADC_H_

#include "driverlib.h"
#include "device.h"

#define ADC_BUFFER_SIZE 10

typedef struct {
    float buffer[ADC_BUFFER_SIZE];
    float adc_read;
    uint8_t index;
} Adc_t;

__interrupt void INT_ADC_Sine_1_ISR ();

#endif
