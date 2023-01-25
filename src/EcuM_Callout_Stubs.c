/*
 * Created on Sat Aug 27 2022 10:35:38 AM
 *
 * The MIT License (MIT)
 * Copyright (c) 2022 Aananth C N
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stddef.h>

#include <Mcu.h>
#include <EcuM.h>
#include <Port.h>
#include <Spi.h>
#include <EthIf.h>
#include <Eth.h>



// Callouts - STARTUP Phase
void EcuM_AL_SetProgrammableInterrupts(void) {

}


void EcuM_AL_DriverInitZero(void) {
        Mcu_Init(&McuConfig);
	Port_Init(&PortConfigs);
	Spi_Init(&SpiConfigs);

	// Ethernet init
	EthIf_Init(&EthIfConfigs);
	Eth_Init(EthConfigs);
}

const EcuM_ConfigType* EcuM_DeterminePbConfiguration(void) {
	EcuM_ConfigType* ecum_cfg = NULL;

	return ecum_cfg;
}

void EcuM_AL_DriverInitOne(void) {

}

void EcuM_LoopDetection(void) {

}
