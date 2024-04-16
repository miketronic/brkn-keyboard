// Copyright 2024 
// miketronic@github sepultor@discord -- Mike B <mxb540@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

#include_next <halconf.h>

#undef HAL_USE_SPI
#define HAL_USE_SPI TRUE


//#undef HAL_USE_PIO
//#define HAL_USE_PIO FALSE

//#undef HAL_USE_PWM
//#define HAL_USE_PWM FALSE

#include_next "halconf.h"
