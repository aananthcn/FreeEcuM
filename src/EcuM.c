/*
 * Created on Sun Aug 21 2022 12:46:21 PM
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
#include <Mcu.h>
#include <osek.h>
#include <stddef.h>

// include system generated file
#include <sg_appmodes.h>

// temp. workaround for pr_log() API
#include <os_api.h>

#include <EcuM.h>
#include <EcuM_Externals.h>


#include <zephyr/logging/log.h> // for LOG_DBG()

// Global variables
LOG_MODULE_REGISTER(EcuM, LOG_LEVEL_DBG);



TASK(EcuM_StartupTwo) {
        pr_log("Info: EcuM_StartupTwo() is invoked by Os!\n");
}



void EcuM_Init(void) {
        const EcuM_ConfigType* ecum_cfg;

        EcuM_AL_SetProgrammableInterrupts();

        // GetCoreID(CoreIdType)
        EcuM_AL_DriverInitZero();

        ecum_cfg = EcuM_DeterminePbConfiguration();
        if (ecum_cfg != NULL) {
                // do data consistency check
                // EcuM_ErrorHook(ECUM_E_CONFIGURATION_DATA_INCONSISTENT);
        }
        else {
                LOG_DBG("Error: EcuM_DeterminePbConfiguration() returned NULL pointer\n");
        }

        EcuM_AL_DriverInitOne();
        // Mcu_GetResetReason(Mcu_ResetType);
        // Update the reset reason variables

        // EcuM_SelectShutdownTarget(Std_ReturnType, EcuM_ShutdownTargetType, EcuM_ShutdownModeType)

        EcuM_LoopDetection();

        //for each core: StartCore(CoreIdType, StatusType**)
}



void EcuM_SetWakeupEvent(EcuM_WakeupSourceType sources) {

}

void EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType sources) {

}