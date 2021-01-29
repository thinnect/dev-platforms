/*
 * Thinnect TestSystemBoard0 platform.
 *
 * Copyright Thinnect Inc. 2019
 * @license MIT
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

uint32_t PLATFORM_Init ()
{
	volatile uint32_t i;
	uint32_t resetCause;

	//EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;
	CMU_HFXOInit_TypeDef hfxoInit = CMU_HFXOINIT_DEFAULT;
	//CMU_LFXOInit_TypeDef lfxoInit = CMU_LFXOINIT_DEFAULT;

	// Set the vector table to the start location
	SCB->VTOR = (uint32_t)VTOR_START_LOCATION;

	resetCause = RMU_ResetCauseGet();
	RMU_ResetCauseClear();

	for(i = 0; i < 3000000; i++)__asm__("nop");

	if(resetCause & RMU_RSTCAUSE_EM4RST)
	{
		EMU->CMD = EMU_CMD_EM4UNLATCH;
	}

	CHIP_Init();

	//EMU_DCDCInit(&dcdcInit); // DCDC does not work on tsb
	CMU_OscillatorEnable(cmuOsc_HFRCO, 1, 1);
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFRCO);
	CMU_HFXOInit(&hfxoInit);
	//CMU_LFXOInit(&lfxoInit); // LFXO not present on TSB0
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);
	CMU_OscillatorEnable(cmuOsc_HFRCO, 0, 0);
	SystemCoreClockUpdate();

	MSC_Init();

	return resetCause;
}

void PLATFORM_RadioInit ()
{
	// Nothing to do
}

void PLATFORM_HardReset ()
{
	NVIC_SystemReset(); // TODO investigate if the MCU supports hard-reset
}
