/*
 * Created on Sun Aug 21 2022 12:43:35 PM
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
#ifndef ECUM_H
#define ECUM_H

#include <Std_Types.h>
#include <Rte_EcuM_Type.h>


/*/ 
A structure to hold post-build configuration parameters for the ECU Manager
module, as well as ConfigType structures of modules that are intiialized by
ECU manger module
/*/
typedef struct {
        uint64 hash; // to be filled by the tool
} EcuM_ConfigType;



#define ECUM_RUNSTATUS_UNKNOWN       0 /* Unknown status. Init Value */
#define ECUM_RUNSTATUS_REQUESTED     1 /* Status requested from EcuM */
#define ECUM_RUNSTATUS_RELEASED      2 /* Status released from EcuM  */

typedef uint8 EcuM_RunStatusType;



#define ECUM_WKSOURCE_POWER           0x01
#define ECUM_WKSOURCE_RESET           0x02 /* default */
#define ECUM_WKSOURCE_INTERNAL_RESET  0x04
#define ECUM_WKSOURCE_INTERNAL_WDG    0x08
#define ECUM_WKSOURCE_EXTERNAL_WDG    0x10

typedef uint32 EcuM_WakeupSourceType;



#define ECUM_WKSTATUS_NONE        0 /* No pending wakeup event was detected */
#define ECUM_WKSTATUS_PENDING     1 /* The wakeup event was detected but not yet validated */
#define ECUM_WKSTATUS_VALIDATED   2 /* The wakeup event is valid */
#define ECUM_WKSTATUS_EXPIRED     3 /* The wakeup event has not been validated and has expired therefore */

typedef uint8 EcuM_WakeupStatusType;



#define ECUM_RESET_MCU          0 /* Microcontroller reset via Mcu_PerformReset */
#define ECUM_RESET_WDG          1 /* Watchdog reset via WdgM_PerformReset */
#define ECUM_RESET_IO           2 /* Reset by toggeling an I/O line. */

typedef uint8 EcuM_ResetType;



#define ECUM_SUBSTATE_MASK      0x0f
#define ECUM_STATE_STARTUP      0x10
#define ECUM_STATE_RUN          0x32
#define ECUM_STATE_POST_RUN     0x33
#define ECUM_STATE_SHUTDOWN     0x40
#define ECUM_STATE_SLEEP        0x50

typedef uint8 EcuM_StateType;



/*/
Globals
/*/
extern uint64 EcuMConfigConsistencyHash; // this is used for post-build cfg only.



/*/
Functions
/*/
// General
void EcuM_GetVersionInfo(Std_VersionInfoType* versioninfo);

// Initialization and Shutdown Sequences
Std_ReturnType EcuM_GoDownHaltPoll(EcuM_UserType UserID);
void EcuM_Init(void);
void EcuM_StartupTwo(void);
void EcuM_Shutdown(void);

// State Management
void EcuM_SetState(EcuM_StateType state);
Std_ReturnType EcuM_RequestRUN(EcuM_UserType user);
Std_ReturnType EcuM_ReleaseRUN(EcuM_UserType user);
Std_ReturnType EcuM_RequestPOST_RUN(EcuM_UserType user);
Std_ReturnType EcuM_ReleasePOST_RUN(EcuM_UserType user);

// Shutdown Management
Std_ReturnType EcuM_SelectShutdownTarget(EcuM_ShutdownTargetType shutdownTarget,
        EcuM_ShutdownModeType shutdownMode);
Std_ReturnType EcuM_GetShutdownTarget(EcuM_ShutdownTargetType* shutdownTarget,
        EcuM_ShutdownModeType* shutdownMode);
Std_ReturnType EcuM_GetLastShutdownTarget(EcuM_ShutdownTargetType* shutdownTarget,
        EcuM_ShutdownModeType* shutdownMode);
Std_ReturnType EcuM_SelectShutdownCause(EcuM_ShutdownCauseType target);
Std_ReturnType EcuM_GetShutdownCause(EcuM_ShutdownCauseType* shutdownCause);

// Wakeup Handling
EcuM_WakeupSourceType EcuM_GetPendingWakeupEvents(void);
void EcuM_ClearWakeupEvent(EcuM_WakeupSourceType sources);
EcuM_WakeupSourceType EcuM_GetValidatedWakeupEvents(void);
EcuM_WakeupSourceType EcuM_GetExpiredWakeupEvents(void);

// Alarm Clock
Std_ReturnType EcuM_SetRelWakeupAlarm(EcuM_UserType user, EcuM_TimeType time);
Std_ReturnType EcuM_SetAbsWakeupAlarm(EcuM_UserType user, EcuM_TimeType time);
Std_ReturnType EcuM_AbortWakeupAlarm(EcuM_UserType user);
Std_ReturnType EcuM_GetCurrentTime(EcuM_TimeType* time);
Std_ReturnType EcuM_GetWakeupTime(EcuM_TimeType* time);
Std_ReturnType EcuM_SetClock(EcuM_UserType user, EcuM_TimeType time);

// Miscellaneous
Std_ReturnType EcuM_SelectBootTarget(EcuM_BootTargetType target);
Std_ReturnType EcuM_GetBootTarget(EcuM_BootTargetType * target);


// Callback
void EcuM_SetWakeupEvent(EcuM_WakeupSourceType sources);
void EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType sources);


#endif