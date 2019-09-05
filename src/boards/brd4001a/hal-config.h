/**
 * Fallback hal-config.h to include hal-config-board.h which may exist
 * (predefined in SiLabs SDK) for some radioboard + mainboard combinations.
 *
 * For more complex situations, Simplicity Studio can be used to generate
 * a proper hal-config using the Hardware Config Generator.
 *
 * Copyright Thinnect Inc. 2019
 */
#ifndef HAL_CONFIG_H
#define HAL_CONFIG_H

#pragma message "Using hal-config-board.h for hal-config.h"
#include "hal-config-board.h"

#endif//HAL_CONFIG_H
