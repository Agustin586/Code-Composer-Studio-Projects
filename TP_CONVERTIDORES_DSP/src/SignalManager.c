#include "include/SignalManager.h"

#include "math.h"

#define PWM_TBCLK   2500
#define PWM_CMPA_DUTY_50_PORCENT 1250

// Private
#define SINE_TABLE_SIZE 100

float sine_table[SINE_TABLE_SIZE];


static void generateSenoidalTable(void);

extern void SignalManager_Init(SignalManager_t* this)
{
    // Configuracion de la señal
    SignalManager_ConfigPwm(this, 10000, 0.5);
    SignalManager_ConfigAdc(this);
    SignalManager_ConfigFir(this);

    // Pwm Init
    pwmInit(&this->Pwm);

    // Debug...
    generateSenoidalTable();

    return;
}
extern void SignalManager_ConfigPwm(SignalManager_t* this, float Freq, float duty_init)
{
    this->Pwm.frequency = Freq;

    if (duty_init == 0.5)
        this->Pwm.duty = PWM_CMPA_DUTY_50_PORCENT;
    else
        this->Pwm.duty = PWM_TBCLK*(1-duty_init);

    pwmDuty(&this->Pwm);

    return;
}
extern void SignalManager_ConfigAdc(SignalManager_t* this)
{


    return;
}
extern void SignalManager_ConfigFir(SignalManager_t* this)
{

    return;
}
extern void SignalManager_TestSinePwm(SignalManager_t* this)
{
    uint8_t i = 0;

    for(i = 0; i < SINE_TABLE_SIZE; i++)
    {
        this->Pwm.duty = PWM_TBCLK*(1-sine_table[i]);
        pwmDuty(&this->Pwm);
        DEVICE_DELAY_US(100);   // 1/5000 = 200 us
    }

    /*
        Nota: debemos ir actualizando del ciclo de trabajo. Para esto debemos darle
        una frecuencia de actualizancion dado que sino quedaría indenfinido y siempre
        cambiante o nunca cambiaría. La frecuencia de salid  fout = fref/TamañoBuffer = 5000/100 = 50 Hz.
        Cada 1/5000 segundos deberiamos actualizar el pwm para poder obtener 50hz.
    */

    return;
}


// Private
static void generateSenoidalTable(void)
{
    uint8_t i;

    for (i = 0; i < SINE_TABLE_SIZE; i++) 
    {
        sine_table[i] = (sin(2 * M_PI * i / SINE_TABLE_SIZE) + 1)*0.5;  // 0-1
    }

    return;
}
