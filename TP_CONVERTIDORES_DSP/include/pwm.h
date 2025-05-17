#ifndef INCLUDE_PWM_H
#define INCLUDE_PWM_H

#include "stdint.h"

typedef struct {
    // Private
    float frequency;
    uint16_t duty;
}PwmObject_t;

// Publics:
extern void pwmInit(PwmObject_t* this);
extern void pwmDuty(PwmObject_t* this);
extern void pwmSetFreq(PwmObject_t* this);

#endif
