/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2019-05-24 10:40:01
 */


#include <BCDS_Basics.h>
#include <BCDS_Retcode.h>
#include <XdkSensorHandle.h>
#include <BCDS_Environmental.h>
#include "MitaExceptions.h"


Retcode_T SensorEnvironment_Setup(void)
{
	Retcode_T exception = RETCODE_OK;
	
	exception = Environmental_init(xdkEnvironmental_BME280_Handle);
	if(exception != NO_EXCEPTION) return exception;
	
	exception = Environmental_setPowerMode(xdkEnvironmental_BME280_Handle, ENVIRONMENTAL_BME280_POWERMODE_NORMAL);
	if(exception != NO_EXCEPTION) return exception;
	
	exception = Environmental_setStandbyDuration(xdkEnvironmental_BME280_Handle, ENVIRONMENTAL_BME280_STANDBY_TIME_1000_MS);
	if(exception != NO_EXCEPTION) return exception;
	
	exception = Environmental_setOverSamplingPressure(xdkEnvironmental_BME280_Handle, ENVIRONMENTAL_BME280_OVERSAMP_2X);
	if(exception != NO_EXCEPTION) return exception;
	
	return NO_EXCEPTION;
}

Retcode_T SensorEnvironment_Enable(void)
{
	
	return NO_EXCEPTION;
}


