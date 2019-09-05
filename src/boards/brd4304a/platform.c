/*
 * SiLabs Radio Board BRD4304A platform setup.
 *
 * The BRD4304A has an LNA (Sensitivity -105 dBm) and needs some extra setup in
 * PLATFORM_RadioInit.
 *
 * Copyright Thinnect Inc. 2019
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

void PLATFORM_RadioInit()
{
    CMU_ClockEnable(cmuClock_GPIO, true);
    CMU_ClockEnable(cmuClock_PRS, true);

	// The module has an LNA, which needs PRS setup!
	GPIO_PinModeSet(gpioPortD, 10, gpioModePushPullAlternate, 0);
	GPIO_PinModeSet(gpioPortD, 11, gpioModePushPullAlternate, 0);
	PRS->CH[6].CTRL = PRS_RAC_ACTIVE | PRS_CH_CTRL_ASYNC;
	PRS->CH[5].CTRL = PRS_RAC_LNAEN | PRS_CH_CTRL_ASYNC;
	PRS->CH[6].CTRL = PRS_RAC_PAEN | PRS_CH_CTRL_ASYNC | PRS_CH_CTRL_ORPREV;
	PRS->ROUTELOC1 |= PRS_ROUTELOC1_CH5LOC_LOC0 | PRS_ROUTELOC1_CH6LOC_LOC13;
	BUS_RegBitWrite(&PRS->ROUTEPEN, _PRS_ROUTEPEN_CH6PEN_SHIFT, 1);
	BUS_RegBitWrite(&PRS->ROUTEPEN, _PRS_ROUTEPEN_CH5PEN_SHIFT, 1);
}
