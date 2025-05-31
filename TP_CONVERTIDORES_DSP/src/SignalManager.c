#include "include/SignalManager.h"

#include "math.h"
#include <stdlib.h>

#define PWM_TBCLK   2500
#define PWM_CMPA_DUTY_50_PORCENT 1250

#define FIR_TAP_NUM 51  // Número de coeficientes

const float firCoeffs[FIR_TAP_NUM] = {
    0.00052097592152740822,
    0.00097062603087293381,
    0.0015691444172991305,
    0.0023344891336893833,
    0.0032819973623196279,
    0.0044234758130805981,
    0.0057663457716163498,
    0.0073128848288522537,
    0.0090596056281137469,
    0.01099680821284829,
    0.013108336839713554,
    0.015371564637910005,
    0.017757620545056904,
    0.020231862918316405,
    0.022754593561380303,
    0.025281995124539738,
    0.027767264448961736,
    0.03016190495448021,
    0.032417133096720452,
    0.034485347669247032,
    0.036321606642281921,
    0.037885054552260496,
    0.039140244311022504,
    0.040058300690627754,
    0.040617878534767789,
    0.040805876704986817,
    0.040617878534767789,
    0.040058300690627754,
    0.039140244311022504,
    0.037885054552260496,
    0.036321606642281921,
    0.034485347669247032,
    0.032417133096720452,
    0.03016190495448021,
    0.027767264448961736,
    0.025281995124539738,
    0.022754593561380303,
    0.020231862918316405,
    0.017757620545056904,
    0.015371564637910005,
    0.013108336839713554,
    0.01099680821284829,
    0.0090596056281137469,
    0.0073128848288522537,
    0.0057663457716163498,
    0.0044234758130805981,
    0.0032819973623196279,
    0.0023344891336893833,
    0.0015691444172991305,
    0.00097062603087293381,
    0.00052097592152740822
};


// Private
#define SINE_TABLE_SIZE 100
#define NOISE_AMPLITUDE 0.5f  // Nivel de ruido máximo

float sine_table[SINE_TABLE_SIZE];
float sineWithNoise_table[SINE_TABLE_SIZE];

static void generateSenoidalTable(void);
static void generateSenoidalWithNoiseTable();

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
    generateSenoidalWithNoiseTable();

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
    FIR_Init(&this->Filtro, firCoeffs);

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
        una frecuencia de actualizacion dado que sino quedaría indenfinido y siempre
        cambiante o nunca cambiaría. La frecuencia de salid  fout = fref/TamañoBuffer = 5000/100 = 50 Hz.
        Cada 1/5000 segundos deberiamos actualizar el pwm para poder obtener 50hz.
    */

    return;
}
extern void SignalManager_TestSineNoisePwm(SignalManager_t* this)
{
    uint8_t i = 0;

    for (i = 0; i < SINE_TABLE_SIZE; i++) {
        // Aplicamos el filtro a la señal con ruido
        float duty_filtered = FIR_Update(&this->Filtro, sineWithNoise_table[i]);
        
        // Aplicamos la señal filtrada
        this->Pwm.duty = PWM_TBCLK*(1-duty_filtered);
        pwmDuty(&this->Pwm);

        // Tiempo necesario entre actualización del ciclo de trabajo
        DEVICE_DELAY_US(100);
    }
}
extern void SignalManager_TestSineWithNoise(SignalManager_t* this)
{
    uint8_t i = 0;

    for (i = 0; i < SINE_TABLE_SIZE; i++) {
        // Aplicamos el filtro a la señal con ruido
        float duty_whitoutfiltered = sineWithNoise_table[i];
        
        // Aplicamos la señal filtrada
        this->Pwm.duty = PWM_TBCLK*(1-duty_whitoutfiltered);
        pwmDuty(&this->Pwm);

        // Tiempo necesario entre actualización del ciclo de trabajo
        DEVICE_DELAY_US(100);
    }
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
static void generateSenoidalWithNoiseTable()
{
    uint8_t i;

    for (i = 0; i < SINE_TABLE_SIZE; i++) {
        float pure = (sinf(2.0f * M_PI * i / SINE_TABLE_SIZE) + 1.0f) * 0.5f;

        // rand() genera un número entre 0 y RAND_MAX
        float noise = ((float)rand() / RAND_MAX) * 2.0f * NOISE_AMPLITUDE - NOISE_AMPLITUDE;

        sineWithNoise_table[i] = pure + noise;

        if (sineWithNoise_table[i] > 1.0)   sineWithNoise_table[i] = 1;
    }

    return;
}
