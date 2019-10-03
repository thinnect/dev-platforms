/*
 * Thinnect TestSystemBoard platform.
 *
 * Copyright Thinnect Inc.
 * @license MIT
 * @author Raido Pahtma
 */
#include "platform.h"
#include <stdio.h>
#include <stdint.h>
#include "em_chip.h"
#include "em_rmu.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_msc.h"

#define PLATFORM_LED0_PORT gpioPortB
#define PLATFORM_LED0_PIN 12
#define PLATFORM_LED1_PORT gpioPortB
#define PLATFORM_LED1_PIN 11
#define PLATFORM_LED2_PORT gpioPortA
#define PLATFORM_LED2_PIN 5

#define PLATFORM_PIN1_PORT gpioPortA
#define PLATFORM_PIN1_PIN 0
#define PLATFORM_PIN2_PORT gpioPortA
#define PLATFORM_PIN2_PIN 1
#define PLATFORM_PIN3_PORT gpioPortA
#define PLATFORM_PIN3_PIN 2
#define PLATFORM_PIN4_PORT gpioPortA
#define PLATFORM_PIN4_PIN 3

uint32_t PLATFORM_Init() {
	volatile uint32_t i;
	uint32_t resetCause;

	//EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;
	CMU_HFXOInit_TypeDef hfxoInit = CMU_HFXOINIT_DEFAULT;
	CMU_LFXOInit_TypeDef lfxoInit = CMU_LFXOINIT_DEFAULT;

	// Set the vector table to the start location
	SCB->VTOR = (uint32_t)VTOR_START_LOCATION;

	resetCause = RMU_ResetCauseGet();
	RMU_ResetCauseClear();

	for(i = 0; i < 3000000; i++)__asm__("nop");

	if(resetCause & RMU_RSTCAUSE_EM4RST){
		EMU->CMD = EMU_CMD_EM4UNLATCH;
	}

	CHIP_Init();

	//EMU_DCDCInit(&dcdcInit); // DCDC does not work correctly on tsb
	CMU_OscillatorEnable(cmuOsc_HFRCO, 1, 1);
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFRCO);
	CMU_HFXOInit(&hfxoInit);
	CMU_LFXOInit(&lfxoInit);
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);
	CMU_OscillatorEnable(cmuOsc_HFRCO, 0, 0);
	SystemCoreClockUpdate();

	MSC_Init();

	return resetCause;
}

void PLATFORM_RadioInit() {
	// Nothing to do
}

void PLATFORM_LedsInit() {
	CMU_ClockEnable(cmuClock_GPIO, true);
	GPIO_PinModeSet(PLATFORM_LED0_PORT, PLATFORM_LED0_PIN, gpioModePushPull, 0);
	GPIO_PinModeSet(PLATFORM_LED1_PORT, PLATFORM_LED1_PIN, gpioModePushPull, 0);
	GPIO_PinModeSet(PLATFORM_LED2_PORT, PLATFORM_LED2_PIN, gpioModePushPull, 0);
}

void PLATFORM_LedsSet(uint8_t leds) {
	if(leds & 1) {
		GPIO_PinOutSet(PLATFORM_LED0_PORT, PLATFORM_LED0_PIN);
	}
	else {
		GPIO_PinOutClear(PLATFORM_LED0_PORT, PLATFORM_LED0_PIN);
	}
	if(leds & 2) {
		GPIO_PinOutSet(PLATFORM_LED1_PORT, PLATFORM_LED1_PIN);
	}
	else {
		GPIO_PinOutClear(PLATFORM_LED1_PORT, PLATFORM_LED1_PIN);
	}
	if(leds & 4) {
		GPIO_PinOutSet(PLATFORM_LED2_PORT, PLATFORM_LED2_PIN);
	}
	else {
		GPIO_PinOutClear(PLATFORM_LED2_PORT, PLATFORM_LED2_PIN);
	}
}

uint8_t PLATFORM_LedsGet() {
	return (GPIO_PinOutGet(PLATFORM_LED0_PORT, PLATFORM_LED0_PIN) << 0)
	      |(GPIO_PinOutGet(PLATFORM_LED1_PORT, PLATFORM_LED1_PIN) << 1)
	      |(GPIO_PinOutGet(PLATFORM_LED2_PORT, PLATFORM_LED2_PIN) << 2);
}

/******************************************************************************
 * Enable TSB JP1 - PIN1..PIN4
 *****************************************************************************/
void PLATFORM_GpioPinInit()
{
	CMU_ClockEnable(cmuClock_GPIO, true);
    GPIO_PinModeSet(PLATFORM_PIN1_PORT, PLATFORM_PIN1_PIN, gpioModePushPull, 0);
    GPIO_PinModeSet(PLATFORM_PIN2_PORT, PLATFORM_PIN2_PIN, gpioModePushPull, 0);
    GPIO_PinModeSet(PLATFORM_PIN3_PORT, PLATFORM_PIN3_PIN, gpioModePushPull, 0);
    GPIO_PinModeSet(PLATFORM_PIN4_PORT, PLATFORM_PIN4_PIN, gpioModePushPull, 0);
}

/******************************************************************************
 * Clear GPIO pin
 * @param pin_nr - TSB pin number (1..4) in JP1 header
 *****************************************************************************/
void PLATFORM_ClearGpioPin (uint8_t pin_nr)
{
    switch (pin_nr)
    {
        case 1:
            GPIO_PinOutClear(PLATFORM_PIN1_PORT, PLATFORM_PIN1_PIN);
        break;

        case 2:
            GPIO_PinOutClear(PLATFORM_PIN2_PORT, PLATFORM_PIN2_PIN);
        break;

        case 3:
            GPIO_PinOutClear(PLATFORM_PIN3_PORT, PLATFORM_PIN3_PIN);
        break;

        case 4:
            GPIO_PinOutClear(PLATFORM_PIN4_PORT, PLATFORM_PIN4_PIN);
        break;
    }
}

/******************************************************************************
 * Set GPIO pin
 * @param pin_nr - TSB pin number (1..4) in JP1 header
 *****************************************************************************/
void PLATFORM_SetGpioPin (uint8_t pin_nr)
{
    switch (pin_nr)
    {
        case 1:
            GPIO_PinOutSet(PLATFORM_PIN1_PORT, PLATFORM_PIN1_PIN);
        break;

        case 2:
            GPIO_PinOutSet(PLATFORM_PIN2_PORT, PLATFORM_PIN2_PIN);
        break;

        case 3:
            GPIO_PinOutSet(PLATFORM_PIN3_PORT, PLATFORM_PIN3_PIN);
        break;

        case 4:
            GPIO_PinOutSet(PLATFORM_PIN4_PORT, PLATFORM_PIN4_PIN);
        break;
    }
}

/******************************************************************************
 * Get GPIO pin
 * @param pin_nr - TSB pin number (1..4) in JP1 header
 *****************************************************************************/
void PLATFORM_GetGpioPin (uint8_t pin_nr)
{
    switch (pin_nr)
    {
        case 1:
            GPIO_PinOutGet(PLATFORM_PIN1_PORT, PLATFORM_PIN1_PIN);
        break;

        case 2:
            GPIO_PinOutGet(PLATFORM_PIN2_PORT, PLATFORM_PIN2_PIN);
        break;

        case 3:
            GPIO_PinOutGet(PLATFORM_PIN3_PORT, PLATFORM_PIN3_PIN);
        break;

        case 4:
            GPIO_PinOutGet(PLATFORM_PIN4_PORT, PLATFORM_PIN4_PIN);
        break;
    }
}

/******************************************************************************
 * Toggle GPIO pin
 * @param pin_nr - TSB pin number (1..4) in JP1 header
 *****************************************************************************/
void PLATFORM_ToggleGpioPin (uint8_t pin_nr)
{
    switch (pin_nr)
    {
        case 1:
            if (GPIO_PinOutGet(PLATFORM_PIN1_PORT, PLATFORM_PIN1_PIN) == 1)
            {
                GPIO_PinOutClear(PLATFORM_PIN1_PORT, PLATFORM_PIN1_PIN);
            }
            else
            {
                GPIO_PinOutSet(PLATFORM_PIN1_PORT, PLATFORM_PIN1_PIN);
            }
        break;

        case 2:
            if (GPIO_PinOutGet(PLATFORM_PIN2_PORT, PLATFORM_PIN2_PIN) == 1)
            {
                GPIO_PinOutClear(PLATFORM_PIN2_PORT, PLATFORM_PIN2_PIN);
            }
            else
            {
                GPIO_PinOutSet(PLATFORM_PIN2_PORT, PLATFORM_PIN2_PIN);
            }
        break;

        case 3:
            if (GPIO_PinOutGet(PLATFORM_PIN3_PORT, PLATFORM_PIN3_PIN) == 1)
            {
                GPIO_PinOutClear(PLATFORM_PIN3_PORT, PLATFORM_PIN3_PIN);
            }
            else
            {
                GPIO_PinOutSet(PLATFORM_PIN3_PORT, PLATFORM_PIN3_PIN);
            }
        break;

        case 4:
            if (GPIO_PinOutGet(PLATFORM_PIN4_PORT, PLATFORM_PIN4_PIN) == 1)
            {
                GPIO_PinOutClear(PLATFORM_PIN4_PORT, PLATFORM_PIN4_PIN);
            }
            else
            {
                GPIO_PinOutSet(PLATFORM_PIN4_PORT, PLATFORM_PIN4_PIN);
            }
        break;
    }
}
