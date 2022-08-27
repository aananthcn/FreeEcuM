/*
 * Created on Sat Aug 27 2022 10:10:21 PM
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
#ifndef ECUM_EXTERNALS_H
#define ECUM_EXTERNALS_H


// Callouts - Generic
void EcuM_ErrorHook(uint16 reason);

// Callouts - STARTUP Phase
void EcuM_AL_SetProgrammableInterrupts(void);
void EcuM_AL_DriverInitZero(void);
const EcuM_ConfigType* EcuM_DeterminePbConfiguration(void);
void EcuM_AL_DriverInitOne(void);
void EcuM_LoopDetection(void);

// Callouts - SHUTDOWN Phase
void EcuM_OnGoOffOne(void);
void EcuM_OnGoOffTwo(void);
void EcuM_AL_SwitchOff(void);
void EcuM_AL_Reset(EcuM_ResetType reset);

// Callouts - SLEEP Phase
void EcuM_EnableWakeupSources(EcuM_WakeupSourceType wakeupSource);
void EcuM_GenerateRamHash(void);
void EcuM_SleepActivity(void);
void EcuM_StartCheckWakeup(EcuM_WakeupSourceType WakeupSource);
void EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource);
void EcuM_EndCheckWakeup(EcuM_WakeupSourceType WakeupSource);
uint8 EcuM_CheckRamHash(void);
void EcuM_DisableWakeupSources(EcuM_WakeupSourceType wakeupSource);
void EcuM_AL_DriverRestart(void);

// Callouts
void EcuM_StartWakeupSources(EcuM_WakeupSourceType wakeupSource);
void EcuM_CheckValidation(EcuM_WakeupSourceType wakeupSource);
void EcuM_StopWakeupSources(EcuM_WakeupSourceType wakeupSource);

#endif