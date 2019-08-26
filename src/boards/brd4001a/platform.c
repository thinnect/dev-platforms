/*
 * SiLabs Wireless Starter Kit Mainboard BRD4001A platform setup
 * for Series1 boards.
 * Supported radio boards:
 *                         - (BRD4161A)
 *                         - BRD4162A
 *                         - (BRD4304A)
 *
 * Copyright Thinnect Inc. 2019
 * @license MIT
 * @author Madis Uusjärv, Raido Pahtma
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

#include "bsp.h" // Make use of GPIO mappings already defined by SiLabs

uint32_t PLATFORM_Init() {
	volatile uint32_t i;
	uint32_t resetCause;

	EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;
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

	EMU_DCDCInit(&dcdcInit);
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
	GPIO_PinModeSet(BSP_LED0_PORT, BSP_LED0_PIN, gpioModePushPull, 0);
	GPIO_PinModeSet(BSP_LED1_PORT, BSP_LED1_PIN, gpioModePushPull, 0);
}

void setLed0()
{
	GPIO_PinOutSet(BSP_LED0_PORT, BSP_LED0_PIN);
}

void clearLed0()
{
	GPIO_PinOutClear(BSP_LED0_PORT, BSP_LED0_PIN);
}

void setLed1()
{
	GPIO_PinOutSet(BSP_LED1_PORT, BSP_LED1_PIN);
}

void clearLed1()
{
	GPIO_PinOutClear(BSP_LED1_PORT, BSP_LED1_PIN);
}

void PLATFORM_LedsSet(uint8_t leds)
{
	if (leds & 1)
	{
		setLed0();
	}
	else
	{
		clearLed0();
	}
	if (leds & 2)
	{
		setLed1();
	}
	else
	{
		clearLed1();
	}
}
