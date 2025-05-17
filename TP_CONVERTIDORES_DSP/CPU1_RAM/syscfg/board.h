/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// EPWM1 -> Pwm_FPB Pinmux
//
//
// EPWM1A - GPIO Settings
//
#define GPIO_PIN_EPWM1A 0
#define Pwm_FPB_EPWMA_GPIO 0
#define Pwm_FPB_EPWMA_PIN_CONFIG GPIO_0_EPWM1A
//
// EPWM1B - GPIO Settings
//
#define GPIO_PIN_EPWM1B 1
#define Pwm_FPB_EPWMB_GPIO 1
#define Pwm_FPB_EPWMB_PIN_CONFIG GPIO_1_EPWM1B
//
// GPIO31 - GPIO Settings
//
#define Led_Blink_GPIO_PIN_CONFIG GPIO_31_GPIO31

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define Pwm_FPB_BASE EPWM1_BASE
#define Pwm_FPB_TBPRD 2500
#define Pwm_FPB_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define Pwm_FPB_TBPHS 0
#define Pwm_FPB_CMPA 1250
#define Pwm_FPB_CMPB 0
#define Pwm_FPB_CMPC 0
#define Pwm_FPB_CMPD 0
#define Pwm_FPB_DBRED 0
#define Pwm_FPB_DBFED 0
#define Pwm_FPB_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define Pwm_FPB_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define Pwm_FPB_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define Led_Blink 31
void Led_Blink_init();

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	EPWM_init();
void	GPIO_init();
void	SYNC_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
