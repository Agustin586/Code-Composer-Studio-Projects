#include "include/adc.h"
#include "board.h"

int16_t sensorTemp;

__interrupt void INT_ADC_Sine_1_ISR () 
{
    uint16_t adc_read;

    // Lee la conversión
    adc_read = ADC_readResult(ADC_Sine_RESULT_BASE, ADC_Sine_SOC0);

    sensorTemp = ADC_getTemperatureC(adc_read, 3.0f);

    //
    // Check if overflow has occurred
    //
    if(true == ADC_getInterruptOverflowStatus(ADCA_BASE, ADC_INT_NUMBER1))
    {
        ADC_clearInterruptOverflowStatus(ADCA_BASE, ADC_INT_NUMBER1);
        ADC_clearInterruptStatus(ADCA_BASE, ADC_INT_NUMBER1);
    }

    // Limpia la interrupcion
    ADC_clearInterruptStatus(ADC_Sine_BASE, ADC_INT_NUMBER1);

    return;
}
