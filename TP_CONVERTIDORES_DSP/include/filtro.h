#ifndef FILTRO_FIR_H
#define FILTRO_FIR_H

#include "driverlib.h"

#define FILTER_ORDER    50

typedef struct {
    float coefficients[FILTER_ORDER];
    float buffer[FILTER_ORDER];
    uint8_t index;
} FIRFilter_t;

// Public:
/**
    @brief Inicialización del filtro FIR
    @param filter Objeto de tipo filtro
    @param coeffs Buffer de coeficientes del filtro de orden 50
*/
extern void FIR_Init(FIRFilter_t* filter, const float* coeffs);
/**
    @brief Actualización del filtro FIR
    @param filter Objeto de tipo filtro
    @param input Entrada del valor actual
*/
extern float FIR_Update(FIRFilter_t* filter, float input);

#endif
