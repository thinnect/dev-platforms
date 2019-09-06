/*
 * SiLabs Wireless Starter Kit Mainboard leds setup.
 * Also works for Thunderboards.
 *
 * Copyright Thinnect Inc. 2019
 * @license MIT
 * @author Madis Uusjärv, Raido Pahtma
 */
#include "platform.h"
#include <stdint.h>
#include "em_cmu.h"
#include "em_gpio.h"

#include "bsp.h" // Make use of GPIO mappings already defined by SiLabs

void PLATFORM_LedsInit()
{
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

uint8_t PLATFORM_LedsGet()
{
	return (GPIO_PinOutGet(BSP_LED0_PORT, BSP_LED0_PIN) << 0)
	      |(GPIO_PinOutGet(BSP_LED1_PORT, BSP_LED1_PIN) << 1);
}
