/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2019-05-23 10:33:59
 */


#include <bma2x2.h>
#include <string.h>
#include <inttypes.h>
#include <stdio.h>
#include <BCDS_Basics.h>
#include <BCDS_Retcode.h>
#include <stdint.h>
#include <stdbool.h>
#include "SensorAccelerometer.h"
#include "PlatformXDK110.h"
#include "xdk110Types.h"
#include "InputOutputSDCardSd.h"
#include "ConnectivityLEDLed.h"
#include "MitaExceptions.h"
#include "application.h"

#ifndef BCDS_MODULE_ID
#define BCDS_MODULE_ID 0xCAFE
#endif

bool inactive = true;
int32_t accelerationX = 0;
int32_t accelerationY = 0;
int32_t accelerationZ = 0;

Retcode_T initGlobalVariables_application() {
	Retcode_T exception = RETCODE_OK;
	
	if(exception != NO_EXCEPTION) return exception;
	
	if(exception != NO_EXCEPTION) return exception;
	
	if(exception != NO_EXCEPTION) return exception;
	
	if(exception != NO_EXCEPTION) return exception;
	
	return exception;
}

Retcode_T HandleEveryXDK110Startup1(void* userParameter1, uint32_t userParameter2)
{
	
	BCDS_UNUSED(userParameter1);
	BCDS_UNUSED(userParameter2);

	Retcode_T exception = NO_EXCEPTION;
	
	
	bool _newConnectivityLEDLed_Red_1 = true;
	exception = ConnectivityLEDLed_Red_Write(&_newConnectivityLEDLed_Red_1);
	if(exception != NO_EXCEPTION) return exception;
	char result586156517_buf[21] = {0};
	char *result586156517 = result586156517_buf;
	
	char mainHandleEveryXDK110Startup11Result586156517_2_buf[21] = {0};
	snprintf(mainHandleEveryXDK110Startup11Result586156517_2_buf, sizeof(mainHandleEveryXDK110Startup11Result586156517_2_buf), "Application start \n");
	memcpy(result586156517, mainHandleEveryXDK110Startup11Result586156517_2_buf, sizeof(mainHandleEveryXDK110Startup11Result586156517_2_buf));
	
	char* _newInputOutputSDCardSd_Writer_2 = result586156517;
	exception = InputOutputSDCardSd_Writer_Write(&_newInputOutputSDCardSd_Writer_2);
	if(exception != NO_EXCEPTION) return exception;


	return NO_EXCEPTION;
}

Retcode_T HandleEveryButton_onePressed1(void* userParameter1, uint32_t userParameter2)
{
	
	BCDS_UNUSED(userParameter1);
	BCDS_UNUSED(userParameter2);

	Retcode_T exception = NO_EXCEPTION;
	
	
	if(inactive)
	{
		inactive = false;
		printf("Starting data acquisition \n\n");
		char result1943790415_buf[60] = {0};
		char *result1943790415 = result1943790415_buf;
		
		char IfStatement1Result1943790415_2_buf[60] = {0};
		snprintf(IfStatement1Result1943790415_2_buf, sizeof(IfStatement1Result1943790415_2_buf), "Data acquisition started: accelerometer data (X ; Y ; Z) \n");
		memcpy(result1943790415, IfStatement1Result1943790415_2_buf, sizeof(IfStatement1Result1943790415_2_buf));
		
		char* _newInputOutputSDCardSd_Writer_1 = result1943790415;
		exception = InputOutputSDCardSd_Writer_Write(&_newInputOutputSDCardSd_Writer_1);
		if(exception != NO_EXCEPTION) return exception;
		PowerStatus platformXDK110ModalityPreparation_1;
		exception = XDK110_powerStatus_read(&platformXDK110ModalityPreparation_1);
		if(exception != NO_EXCEPTION) return exception;
		
		PowerStatus ps;
		ps = platformXDK110ModalityPreparation_1;
		switch(ps.tag) {
			case PowerStatus_Battery_e: {
				float level = ps.data.Battery;
				
					char result1440147321_buf[42] = {0};
					char *result1440147321 = result1440147321_buf;
					
					char IsDeconstructionCase0Result1440147321_4_buf[42] = {0};
					snprintf(IsDeconstructionCase0Result1440147321_4_buf, sizeof(IsDeconstructionCase0Result1440147321_4_buf), "Battery level: approx. %.6g%% \n", level);
					memcpy(result1440147321, IsDeconstructionCase0Result1440147321_4_buf, sizeof(IsDeconstructionCase0Result1440147321_4_buf));
					
					char* _newInputOutputSDCardSd_Writer_2 = result1440147321;
					exception = InputOutputSDCardSd_Writer_Write(&_newInputOutputSDCardSd_Writer_2);
					if(exception != NO_EXCEPTION) return exception;
				
				break;
			}
		}
		
		bool _newConnectivityLEDLed_Red_3 = false;
		exception = ConnectivityLEDLed_Red_Write(&_newConnectivityLEDLed_Red_3);
		if(exception != NO_EXCEPTION) return exception;
		bool _newConnectivityLEDLed_Yellow_4 = true;
		exception = ConnectivityLEDLed_Yellow_Write(&_newConnectivityLEDLed_Yellow_4);
		if(exception != NO_EXCEPTION) return exception;
	}
	else
	{
		inactive = true;
		printf("Stopping data acquisition \n\n");
		char result1500234529_buf[28] = {0};
		char *result1500234529 = result1500234529_buf;
		
		char IfStatement54Result1500234529_6_buf[28] = {0};
		snprintf(IfStatement54Result1500234529_6_buf, sizeof(IfStatement54Result1500234529_6_buf), "Data acquisition stopped \n");
		memcpy(result1500234529, IfStatement54Result1500234529_6_buf, sizeof(IfStatement54Result1500234529_6_buf));
		
		char* _newInputOutputSDCardSd_Writer_5 = result1500234529;
		exception = InputOutputSDCardSd_Writer_Write(&_newInputOutputSDCardSd_Writer_5);
		if(exception != NO_EXCEPTION) return exception;
		bool _newConnectivityLEDLed_Red_6 = true;
		exception = ConnectivityLEDLed_Red_Write(&_newConnectivityLEDLed_Red_6);
		if(exception != NO_EXCEPTION) return exception;
		bool _newConnectivityLEDLed_Yellow_7 = false;
		exception = ConnectivityLEDLed_Yellow_Write(&_newConnectivityLEDLed_Yellow_7);
		if(exception != NO_EXCEPTION) return exception;
	}


	return NO_EXCEPTION;
}

Retcode_T HandleEveryButton_twoPressed1(void* userParameter1, uint32_t userParameter2)
{
	
	BCDS_UNUSED(userParameter1);
	BCDS_UNUSED(userParameter2);

	Retcode_T exception = NO_EXCEPTION;
	
	
	PowerStatus platformXDK110ModalityPreparation_1;
	exception = XDK110_powerStatus_read(&platformXDK110ModalityPreparation_1);
	if(exception != NO_EXCEPTION) return exception;
	
	PowerStatus ps;
	ps = platformXDK110ModalityPreparation_1;
	switch(ps.tag) {
		case PowerStatus_Battery_e: {
			float level = ps.data.Battery;
			
				printf("Battery level: approx. %.6g%%\n", level);
				if(inactive)
				{
					char result1971753688_buf[59] = {0};
					char *result1971753688 = result1971753688_buf;
					
					char IfStatement1Result1971753688_3_buf[59] = {0};
					snprintf(IfStatement1Result1971753688_3_buf, sizeof(IfStatement1Result1971753688_3_buf), "Battery level checked by the user: approx. %.6g%%", level);
					memcpy(result1971753688, IfStatement1Result1971753688_3_buf, sizeof(IfStatement1Result1971753688_3_buf));
					
					char* _newInputOutputSDCardSd_Writer_1 = result1971753688;
					exception = InputOutputSDCardSd_Writer_Write(&_newInputOutputSDCardSd_Writer_1);
					if(exception != NO_EXCEPTION) return exception;
				}
			
			break;
		}
		case PowerStatus_Corded_e: {
			
				printf("%s\n", "Charged");
			
			break;
		}
	}


	return NO_EXCEPTION;
}

Retcode_T HandleEvery10Millisecond1(void* userParameter1, uint32_t userParameter2)
{
	
	BCDS_UNUSED(userParameter1);
	BCDS_UNUSED(userParameter2);

	Retcode_T exception = NO_EXCEPTION;
	
	
	if(!inactive)
	{
		struct bma2x2_accel_data sensorAccelerometerModalityPreparation_1;
		exception = SensorAccelerometer_ReadXYZ(&sensorAccelerometerModalityPreparation_1);
		if(exception != NO_EXCEPTION) return exception;
		
		accelerationX = sensorAccelerometerModalityPreparation_1.x;
		accelerationY = sensorAccelerometerModalityPreparation_1.y;
		accelerationZ = sensorAccelerometerModalityPreparation_1.z;
		char result1579328734_buf[43] = {0};
		char *result1579328734 = result1579328734_buf;
		
		char IfStatement2Result1579328734_2_buf[43] = {0};
		snprintf(IfStatement2Result1579328734_2_buf, sizeof(IfStatement2Result1579328734_2_buf), "%" PRId32 " ; %" PRId32 " ; %" PRId32 " \n", accelerationX, accelerationY, accelerationZ);
		memcpy(result1579328734, IfStatement2Result1579328734_2_buf, sizeof(IfStatement2Result1579328734_2_buf));
		
		char* _newInputOutputSDCardSd_Writer_1 = result1579328734;
		exception = InputOutputSDCardSd_Writer_Write(&_newInputOutputSDCardSd_Writer_1);
		if(exception != NO_EXCEPTION) return exception;
		printf("X: %" PRId32 " Y: %" PRId32 " Z: %" PRId32 "\n", accelerationX, accelerationY, accelerationZ);
	}


	return NO_EXCEPTION;
}

