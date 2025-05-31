#ifndef INCLUDE_SIGNAL_MANAGER_H
#define INCLUDE_SIGNAL_MANAGER_H

#include "include/pwm.h"
#include "include/filtro.h"
#include "driverlib.h"
#include "device.h"
#include "stdint.h"

typedef struct{
    // Public:
    PwmObject_t Pwm;
    FIRFilter_t Filtro;
} SignalManager_t;

// Public:
extern void SignalManager_Init(SignalManager_t* this);
extern void SignalManager_ConfigPwm(SignalManager_t* this, float Freq, float duty_init);
extern void SignalManager_ConfigAdc(SignalManager_t* this);
extern void SignalManager_ConfigFir(SignalManager_t* this);
extern void SignalManager_TestSinePwm(SignalManager_t* this);
extern void SignalManager_TestSineNoisePwm(SignalManager_t* this);
extern void SignalManager_TestSineWithNoise(SignalManager_t* this);

#endif
