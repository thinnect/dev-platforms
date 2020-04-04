/*
 * SiLabs Radio Board BRD4180A platform setup.
 *
 * Copyright Thinnect Inc. 2020
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

uint32_t PLATFORM_Init()
{
	volatile uint32_t i;
	uint32_t resetCause;

	CMU_HFXOInit_TypeDef hfxoInit = CMU_HFXOINIT_DEFAULT;
	CMU_LFXOInit_TypeDef lfxoInit = CMU_LFXOINIT_DEFAULT;

	// Set the vector table to the start location
	SCB->VTOR = (uint32_t)VTOR_START_LOCATION;

	resetCause = RMU_ResetCauseGet();
	RMU_ResetCauseClear();

	for(i = 0; i < 3000000; i++)__asm__("nop");

	if(resetCause & EMU_RSTCAUSE_EM4){
		EMU->CMD = EMU_CMD_EM4UNLATCH;
	}

	CHIP_Init();

    CMU_OscillatorEnable(cmuOsc_FSRCO, 1, 1);
    CMU_ClockSelectSet(cmuClock_SYSCLK, cmuSelect_FSRCO);

    // Init LFXO
    CMU_LFXOInit(&lfxoInit);

    // Init HFXO
    CMU_HFXOInit(&hfxoInit);

    // Set HFXO as source for SYSCLK
    CMU_ClockSelectSet(cmuClock_SYSCLK, cmuSelect_HFXO);

    // Set HFXO as source for timers
    CMU_ClockSelectSet(cmuClock_EM01GRPACLK, cmuSelect_HFXO);

    // Disable FSRCO
    CMU_OscillatorEnable(cmuOsc_FSRCO, 0, 0);

    SystemCoreClockUpdate();

	MSC_Init();

	return resetCause;
}

void PLATFORM_RadioInit()
{

}
