#include "include/filtro.h"

extern void FIR_Init(FIRFilter_t* filter, const float* coeffs)
{
    uint8_t i;

    // Limpia el buffer
    for (i = 0; i < FILTER_ORDER; i++) {
        filter->coefficients[i] = coeffs[i];
        filter->buffer[i] = 0.0f;
    }

    filter->index = 0;

    return;
}

extern float FIR_Update(FIRFilter_t* filter, float input)
{
    // Inserta nueva muestra en el buffer circular
    filter->buffer[filter->index] = input;

    // Calcula la salida
    float output = 0.0f;
    uint8_t buf_index = filter->index;
    uint8_t i;

    for (i = 0; i < FILTER_ORDER; i++) {
        // Aplica el filtro a cada elemento del buffer
        output += filter->coefficients[i] * filter->buffer[buf_index];

        // Reinicia el indice del buffer
        if (buf_index == 0)
            buf_index = FILTER_ORDER-1;
        else
            buf_index--;
    }

    // Avanza el indice del buffer
    filter->index++;

    if (filter->index >= FILTER_ORDER)
        filter->index = 0;

    return output;
}
