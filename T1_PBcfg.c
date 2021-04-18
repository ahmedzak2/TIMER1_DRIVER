/*
 * ADC_PBcfg.c
 *
 *  Created on: Mar 31, 2021
 *      Author: Ahmed
 */

#include "t1.h"

const timerConfig_type T1_config =
{
		Normal,
		set_output_high,
		rising_edge,
		no_prscaling,
		caputre,
		0,
		0,
		0,
		Caputre_PIN
};
