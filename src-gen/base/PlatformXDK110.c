/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2019-05-23 10:33:59
 */


#include <FreeRTOS.h>
#include <AdcCentral.h>
#include <Mcu_Adc.h>
#include <BSP_Adc.h>
#include <semphr.h>
#include <BCDS_Retcode.h>
#include "xdk110Types.h"
#include "MitaExceptions.h"

static uint16_t AdcResultBuffer = 0;
static SemaphoreHandle_t AdcSampleSemaphore = NULL;

static void adcCallback(ADC_T adc, uint16_t* buffer) {
	BCDS_UNUSED(adc);
	BCDS_UNUSED(buffer);

	BaseType_t higherPriorityTaskWoken = pdFALSE;

	if (pdTRUE == xSemaphoreGiveFromISR(AdcSampleSemaphore, &higherPriorityTaskWoken))
	{
		portYIELD_FROM_ISR(higherPriorityTaskWoken);
	}
	else
	{
		/* ignore... semaphore has already been given */
	}
}

AdcCentral_ConfigSingle_T XDK110_powerStatus_ADC = {
	.AcqTime = ADC_ACQ_TIME_64,
	.Appcallback = adcCallback,
	.BufferPtr = &AdcResultBuffer,
	.Channel = ADC_ENABLE_CH7,
	.Reference = ADC_REF_2V5,
	.Resolution = ADC_RESOLUTION_12BIT
};

Retcode_T XDK110_powerStatus_read(PowerStatus* result) {
	uint16_t batteryVoltage = 0;
	uint16_t* batteryVoltagePtr = &batteryVoltage;
	Retcode_T exception = NO_EXCEPTION;
	
	exception = AdcCentral_StartSingle(BSP_Adc_GetHandle(), &XDK110_powerStatus_ADC);
	if(exception != NO_EXCEPTION) return exception;
	if (pdTRUE != xSemaphoreTake(AdcSampleSemaphore, (TickType_t) pdMS_TO_TICKS(100)))
	{
		exception = RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_TIMEOUT);
	}
	else
	{
		*batteryVoltagePtr = AdcResultBuffer * 2500 / 4096;
	}
	
	if(exception != NO_EXCEPTION) return exception;
	
	// 0% is 3V, internal voltage divider -> 1.5V
	batteryVoltage -= 1500;
	
	// experimentally determined threshold
	if(batteryVoltage > 600) {
		result->tag = PowerStatus_Corded_e;
	}
	else {
		result->tag = PowerStatus_Battery_e;
		result->data.Battery = 100 * batteryVoltage / 587.0f;
	}
	return exception;
}

Retcode_T PlatformXDK110_Setup(void)
{
	Retcode_T exception = RETCODE_OK;
	
	exception = AdcCentral_Init();
	if(exception != RETCODE_OK) return exception;
	
	AdcSampleSemaphore = xSemaphoreCreateBinary();
	if(AdcSampleSemaphore == NULL) {
		return RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_SEMAPHORE_ERROR);
	}
	
	return NO_EXCEPTION;
}

Retcode_T PlatformXDK110_Enable(void)
{
	
	return NO_EXCEPTION;
}


