//#############################################################################
//
// FILE:   empty_driverlib_main.c
//
// TITLE:  Empty Project
//
// Empty Project Example
//
// This example is an empty project setup for Driverlib development.
//
//#############################################################################
//
//
// $Copyright:
// Copyright (C) 2013-2024 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//
// #include "F28x_Project.h"  // Incluye todos los headers necesarios
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"

// Includes:
#include "include/SignalManager.h"

SignalManager_t* Signal;

// Private
static void Blink();

//
// Main
//
void main(void)
{

    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Disable pin locks and enable internal pull-ups.
    //
    Device_initGPIO();

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    //
    // PinMux and Peripheral Initialization
    //
    Board_init();

    //
    // C2000Ware Library initialization
    //
    C2000Ware_libraries_init();

    //
    // Enable the temperature sensor and give it 500 us to power up
    //
    ASysCtl_enableTemperatureSensor();
    DEVICE_DELAY_US(500);

    //
    // Enable ADC interrupt
    //
    Interrupt_enable(INT_ADCA1);

    //
    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    //
    EINT;
    ERTM;

    // Configuracion de la señal
    SignalManager_Init(Signal);
    SignalManager_ConfigFir(Signal);

    while(1)
    {
        //Blink();
        // SignalManager_TestSinePwm(Signal);
        SignalManager_TestSineNoisePwm(Signal);
        // SignalManager_TestSineWithNoise(Signal);
        // DEVICE_DELAY_US(100);
    }
}

static void Blink()
{
    GPIO_togglePin(Led_Blink);
    DEVICE_DELAY_US(500000);

    return;
}

//
// End of File
//
