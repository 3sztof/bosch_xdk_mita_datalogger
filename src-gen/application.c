/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2019-05-31 11:05:36
 */


#include <XdkSensorHandle.h>
#include <BCDS_Environmental.h>
#include <bma2x2.h>
#include <string.h>
#include <inttypes.h>
#include <stdio.h>
#include <BCDS_Basics.h>
#include <BCDS_Retcode.h>
#include <stdint.h>
#include <stdbool.h>
#include "SensorEnvironment.h"
#include "SensorAccelerometer.h"
#include "PlatformXDK110.h"
#include "xdk110Types.h"
#include "InputOutputSDCardSd.h"
#include "ConnectivityLEDLed.h"
#include "MitaExceptions.h"
#include "MitaGeneratedTypes.h"
#include "application.h"

#ifndef BCDS_MODULE_ID
#define BCDS_MODULE_ID 0xCAFE
#endif

bool inactive = 0;
// buffer for cycle
uint8_t data_cycle_9[2];
// var cycle: array<uint8_t>
array_uint8_t cycle = {
	.data = data_cycle_9,
	.length = 2
};
uint32_t cycleTime = 0;
uint8_t cycleNum = 0;
bool orangeBlink = 0;
bool orangeOn = false;
uint8_t orangeBlinksRequested = 0;
int32_t blinkCounter = 0;
int32_t accelerationX = 0;
int32_t accelerationY = 0;
int32_t accelerationZ = 0;
uint32_t pressure = 0;

Retcode_T initGlobalVariables_application() {
	Retcode_T exception = RETCODE_OK;
	
	if(exception != NO_EXCEPTION) return exception;
	
	if(exception != NO_EXCEPTION) return exception;
	
	if(exception != NO_EXCEPTION) return exception;
	
	if(exception != NO_EXCEPTION) return exception;
	
	if(exception != NO_EXCEPTION) return exception;
	
	if(exception != NO_EXCEPTION) return exception;
	
	if(exception != NO_EXCEPTION) return exception;
	
	if(exception != NO_EXCEPTION) return exception;
	
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
	// buffer for init
	uint8_t data_init_2[2] = {0, 0};
	// var init: array<uint8_t>
	array_uint8_t init = {
		.data = data_init_2,
		.length = 2
	};
	
	
	array_uint8_t _newInputOutputSDCardSd_CycleInit_2 = init;
	exception = InputOutputSDCardSd_CycleInit_Write(&_newInputOutputSDCardSd_CycleInit_2);
	if(exception != NO_EXCEPTION) return exception;
	char result1253358510_buf[29] = {0};
	char *result1253358510 = result1253358510_buf;
	
	char mainHandleEveryXDK110Startup11Result1253358510_3_buf[29] = {0};
	snprintf(mainHandleEveryXDK110Startup11Result1253358510_3_buf, sizeof(mainHandleEveryXDK110Startup11Result1253358510_3_buf), "Status: ,Powered on \n \n \n");
	memcpy(result1253358510, mainHandleEveryXDK110Startup11Result1253358510_3_buf, sizeof(mainHandleEveryXDK110Startup11Result1253358510_3_buf));
	
	char* _newInputOutputSDCardSd_Writer_3 = result1253358510;
	exception = InputOutputSDCardSd_Writer_Write(&_newInputOutputSDCardSd_Writer_3);
	if(exception != NO_EXCEPTION) return exception;
	inactive = true;


	return NO_EXCEPTION;
}

Retcode_T HandleEveryButton_onePressed1(void* userParameter1, uint32_t userParameter2)
{
	
	BCDS_UNUSED(userParameter1);
	BCDS_UNUSED(userParameter2);

	Retcode_T exception = NO_EXCEPTION;
	
	
	if(inactive)
	{
		// buffer for result312364948
		uint8_t data_result312364948_2[2];
		// var result312364948: array<uint8_t>
		array_uint8_t result312364948 = {
			.data = data_result312364948_2,
			.length = 2
		};
		
		exception = InputOutputSDCardSd_CycleReader_Read(&result312364948);
		if(exception != NO_EXCEPTION) return exception;
		
		// cycle = result312364948
		memcpy(cycle.data, result312364948.data, sizeof(uint8_t) * cycle.length);
		if((cycle.data[0] == 0) && (cycle.data[1] == 0))
		{
			cycleNum = 0;
		}
		else
		{
			cycleNum = (cycle.data[0] * 10) + cycle.data[1];
		}
		
		cycleNum += 1;
		cycle.data[1] = cycleNum - ((cycleNum / 10) * 10);
		cycle.data[0] = cycleNum / 10;
		array_uint8_t _newInputOutputSDCardSd_CycleWriter_2 = cycle;
		exception = InputOutputSDCardSd_CycleWriter_Write(&_newInputOutputSDCardSd_CycleWriter_2);
		if(exception != NO_EXCEPTION) return exception;
		char result782576828_buf[33] = {0};
		char *result782576828 = result782576828_buf;
		
		char IfStatement1Result782576828_3_buf[33] = {0};
		snprintf(IfStatement1Result782576828_3_buf, sizeof(IfStatement1Result782576828_3_buf), "Data acquisition cycle: , %" PRIu8 " \n", cycleNum);
		memcpy(result782576828, IfStatement1Result782576828_3_buf, sizeof(IfStatement1Result782576828_3_buf));
		
		char* _newInputOutputSDCardSd_Writer_3 = result782576828;
		exception = InputOutputSDCardSd_Writer_Write(&_newInputOutputSDCardSd_Writer_3);
		if(exception != NO_EXCEPTION) return exception;
		PowerStatus platformXDK110ModalityPreparation_1;
		exception = XDK110_powerStatus_read(&platformXDK110ModalityPreparation_1);
		if(exception != NO_EXCEPTION) return exception;
		
		PowerStatus ps;
		ps = platformXDK110ModalityPreparation_1;
		switch(ps.tag) {
			case PowerStatus_Battery_e: {
				float level = ps.data.Battery;
				
					char result344236287_buf[43] = {0};
					char *result344236287 = result344236287_buf;
					
					char IsDeconstructionCase0Result344236287_5_buf[43] = {0};
					snprintf(IsDeconstructionCase0Result344236287_5_buf, sizeof(IsDeconstructionCase0Result344236287_5_buf), "Battery level: ,Approx. %.6g%% \n", level);
					memcpy(result344236287, IsDeconstructionCase0Result344236287_5_buf, sizeof(IsDeconstructionCase0Result344236287_5_buf));
					
					char* _newInputOutputSDCardSd_Writer_4 = result344236287;
					exception = InputOutputSDCardSd_Writer_Write(&_newInputOutputSDCardSd_Writer_4);
					if(exception != NO_EXCEPTION) return exception;
				
				break;
			}
			case PowerStatus_Corded_e: {
				
					char result2093286154_buf[28] = {0};
					char *result2093286154 = result2093286154_buf;
					
					char IsTypeMatchCase0Result2093286154_7_buf[28] = {0};
					snprintf(IsTypeMatchCase0Result2093286154_7_buf, sizeof(IsTypeMatchCase0Result2093286154_7_buf), "Battery level: ,Charging \n");
					memcpy(result2093286154, IsTypeMatchCase0Result2093286154_7_buf, sizeof(IsTypeMatchCase0Result2093286154_7_buf));
					
					char* _newInputOutputSDCardSd_Writer_5 = result2093286154;
					exception = InputOutputSDCardSd_Writer_Write(&_newInputOutputSDCardSd_Writer_5);
					if(exception != NO_EXCEPTION) return exception;
				
				break;
			}
		}
		
		char result196421421_buf[107] = {0};
		char *result196421421 = result196421421_buf;
		
		char IfStatement1Result196421421_8_buf[107] = {0};
		snprintf(IfStatement1Result196421421_8_buf, sizeof(IfStatement1Result196421421_8_buf), "Acceleration: X [raw] , Acceleration: Y [raw] , Acceleration: Z [raw] , Pressure [raw] , Cycle time [s] \n");
		memcpy(result196421421, IfStatement1Result196421421_8_buf, sizeof(IfStatement1Result196421421_8_buf));
		
		char* _newInputOutputSDCardSd_Writer_6 = result196421421;
		exception = InputOutputSDCardSd_Writer_Write(&_newInputOutputSDCardSd_Writer_6);
		if(exception != NO_EXCEPTION) return exception;
		bool _newConnectivityLEDLed_Red_7 = false;
		exception = ConnectivityLEDLed_Red_Write(&_newConnectivityLEDLed_Red_7);
		if(exception != NO_EXCEPTION) return exception;
		bool _newConnectivityLEDLed_Yellow_8 = true;
		exception = ConnectivityLEDLed_Yellow_Write(&_newConnectivityLEDLed_Yellow_8);
		if(exception != NO_EXCEPTION) return exception;
		inactive = false;
	}
	else
	{
		char result981986812_buf[70] = {0};
		char *result981986812 = result981986812_buf;
		
		char IfStatement160Result981986812_9_buf[70] = {0};
		snprintf(IfStatement160Result981986812_9_buf, sizeof(IfStatement160Result981986812_9_buf), "\nStatus: ,Data acquisition cycle %" PRIu8 " stopped by the user \n \n \n \n", cycleNum);
		memcpy(result981986812, IfStatement160Result981986812_9_buf, sizeof(IfStatement160Result981986812_9_buf));
		
		char* _newInputOutputSDCardSd_Writer_9 = result981986812;
		exception = InputOutputSDCardSd_Writer_Write(&_newInputOutputSDCardSd_Writer_9);
		if(exception != NO_EXCEPTION) return exception;
		bool _newConnectivityLEDLed_Red_10 = true;
		exception = ConnectivityLEDLed_Red_Write(&_newConnectivityLEDLed_Red_10);
		if(exception != NO_EXCEPTION) return exception;
		bool _newConnectivityLEDLed_Yellow_11 = false;
		exception = ConnectivityLEDLed_Yellow_Write(&_newConnectivityLEDLed_Yellow_11);
		if(exception != NO_EXCEPTION) return exception;
		inactive = true;
		cycleTime = 0;
	}


	return NO_EXCEPTION;
}

Retcode_T HandleEveryButton_twoPressed1(void* userParameter1, uint32_t userParameter2)
{
	
	BCDS_UNUSED(userParameter1);
	BCDS_UNUSED(userParameter2);

	Retcode_T exception = NO_EXCEPTION;
	
	
	if(!inactive)
	{
		orangeBlinksRequested = cycleNum;
		orangeBlink = true;
	}


	return NO_EXCEPTION;
}

Retcode_T HandleEvery20Millisecond1(void* userParameter1, uint32_t userParameter2)
{
	
	BCDS_UNUSED(userParameter1);
	BCDS_UNUSED(userParameter2);

	Retcode_T exception = NO_EXCEPTION;
	
	
	if(!inactive)
	{
		cycleTime += 1;
		struct bma2x2_accel_data sensorAccelerometerModalityPreparation_1;
		exception = SensorAccelerometer_ReadXYZ(&sensorAccelerometerModalityPreparation_1);
		if(exception != NO_EXCEPTION) return exception;
		
		accelerationX = sensorAccelerometerModalityPreparation_1.x;
		accelerationY = sensorAccelerometerModalityPreparation_1.y;
		accelerationZ = sensorAccelerometerModalityPreparation_1.z;
		Environmental_Data_T sensorEnvironmentModalityPreparation_2;
		exception = Environmental_readData(xdkEnvironmental_BME280_Handle, &sensorEnvironmentModalityPreparation_2);
		if(exception != NO_EXCEPTION) return exception;
		
		pressure = sensorEnvironmentModalityPreparation_2.pressure;
		double realCycleTime = (cycleTime * 20) / 1000;
		char result99040402_buf[73] = {0};
		char *result99040402 = result99040402_buf;
		
		char IfStatement2Result99040402_3_buf[73] = {0};
		snprintf(IfStatement2Result99040402_3_buf, sizeof(IfStatement2Result99040402_3_buf), "%" PRId32 " , %" PRId32 " , %" PRId32 " , %" PRIu32 " , %.6g \n", accelerationX, accelerationY, accelerationZ, pressure, realCycleTime);
		memcpy(result99040402, IfStatement2Result99040402_3_buf, sizeof(IfStatement2Result99040402_3_buf));
		
		char* _newInputOutputSDCardSd_Writer_1 = result99040402;
		exception = InputOutputSDCardSd_Writer_Write(&_newInputOutputSDCardSd_Writer_1);
		if(exception != NO_EXCEPTION) return exception;
	}


	return NO_EXCEPTION;
}

Retcode_T HandleEvery250Millisecond1(void* userParameter1, uint32_t userParameter2)
{
	
	BCDS_UNUSED(userParameter1);
	BCDS_UNUSED(userParameter2);

	Retcode_T exception = NO_EXCEPTION;
	
	
	if(!inactive)
	{
		if(orangeBlink)
		{
			if(orangeBlinksRequested > blinkCounter)
			{
				if(!orangeOn)
				{
					bool _newConnectivityLEDLed_Orange_1 = true;
					exception = ConnectivityLEDLed_Orange_Write(&_newConnectivityLEDLed_Orange_1);
					if(exception != NO_EXCEPTION) return exception;
					orangeOn = true;
				}
				else
				{
					bool _newConnectivityLEDLed_Orange_2 = false;
					exception = ConnectivityLEDLed_Orange_Write(&_newConnectivityLEDLed_Orange_2);
					if(exception != NO_EXCEPTION) return exception;
					orangeOn = false;
					blinkCounter += 1;
				}
			}
			else
			{
				blinkCounter = 0;
				orangeBlink = false;
				orangeBlinksRequested = 0;
			}
		}
	}


	return NO_EXCEPTION;
}


