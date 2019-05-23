/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2019-05-23 19:47:53
 */


#include <FreeRTOS.h>
#include <BCDS_Basics.h>
#include <BCDS_CmdProcessor.h>
#include <timers.h>
#include <BCDS_Retcode.h>
#include "MitaTime.h"
#include "MitaExceptions.h"
#include "MitaEvents.h"

static TimerHandle_t timerHandleEvery10Millisecond1;
static TimerHandle_t timerHandleEvery200Millisecond1;

static void InternalHandleEvery10Millisecond1(TimerHandle_t xTimer)
{
	BCDS_UNUSED(xTimer);
	CmdProcessor_Enqueue(&Mita_EventQueue, HandleEvery10Millisecond1, NULL, 0);
}

static void InternalHandleEvery200Millisecond1(TimerHandle_t xTimer)
{
	BCDS_UNUSED(xTimer);
	CmdProcessor_Enqueue(&Mita_EventQueue, HandleEvery200Millisecond1, NULL, 0);
}


Retcode_T SetupTime(void)
{
	
	timerHandleEvery10Millisecond1 = xTimerCreate("timerHandleEvery10Millisecond1", UINT32_C(10), pdTRUE, NULL, InternalHandleEvery10Millisecond1);
	
	timerHandleEvery200Millisecond1 = xTimerCreate("timerHandleEvery200Millisecond1", UINT32_C(200), pdTRUE, NULL, InternalHandleEvery200Millisecond1);
	
	if(timerHandleEvery10Millisecond1 == NULL || timerHandleEvery200Millisecond1 == NULL)
	{
		return RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_OUT_OF_RESOURCES);
	}
	
	return NO_EXCEPTION;
}

Retcode_T EnableTime(void)
{
	Retcode_T result = NO_EXCEPTION;

	
	result = EveryHandleEvery10Millisecond1_Enable();
	if(result != NO_EXCEPTION)
	{
		return result;
	}
	
	result = EveryHandleEvery200Millisecond1_Enable();
	if(result != NO_EXCEPTION)
	{
		return result;
	}
	
	return NO_EXCEPTION;
}

Retcode_T EveryHandleEvery10Millisecond1_Enable(void)
{
	xTimerStart(timerHandleEvery10Millisecond1, 0);
	
	return NO_EXCEPTION;
}

Retcode_T EveryHandleEvery200Millisecond1_Enable(void)
{
	xTimerStart(timerHandleEvery200Millisecond1, 0);
	
	return NO_EXCEPTION;
}


