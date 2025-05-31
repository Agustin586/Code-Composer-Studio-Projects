#include "include/pwm.h"
#include "board.h"

extern void pwmInit(PwmObject_t* this)
{
    // No utilizada dado que tenemos el sysconfig
    
    return;
}

extern void pwmDuty(PwmObject_t* this)
{
    EPWM_setCounterCompareValue(Pwm_FPB_BASE, EPWM_COUNTER_COMPARE_A, this->duty);

    return;
}

extern void pwmDutyB(PwmObject_t* this)
{
    EPWM_setCounterCompareValue(Pwm_FPB_BASE, EPWM_COUNTER_COMPARE_B, this->duty);

    return;
}

extern void pwmSetFreq(PwmObject_t* this)
{

    return;
}
