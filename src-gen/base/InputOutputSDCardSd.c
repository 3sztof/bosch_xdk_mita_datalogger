/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2019-05-31 11:05:36
 */

#include <BCDS_Basics.h>
#include <BCDS_Retcode.h>
#include <FreeRTOS.h>
#include <stdint.h>
#include <inttypes.h>
#include <BCDS_SDCard_Driver.h>
#include <ff.h>
#include <XdkCommonInfo.h>
#include <string.h>
#include <task.h>
#include "MitaGeneratedTypes.h"
#include "MitaExceptions.h"

static FATFS StorageSDCardFatFSObject; /** File system specific objects */
/**< Macro to define default logical drive */
#define STORAGE_DEFAULT_LOGICAL_DRIVE ""

/**< Macro to define force mount */
#define STORAGE_SDCARD_FORCE_MOUNT UINT8_C(1)

/**< SD Card Drive 0 location */
#define STORAGE_SDCARD_DRIVE_NUMBER UINT8_C(0)

Retcode_T InputOutputSDCardSd_Setup(void)
{

	return NO_EXCEPTION;
}

Retcode_T InputOutputSDCardSd_Enable(void)
{
	Retcode_T retcode = RETCODE_OK;
	retcode = SDCardDriver_Initialize();
	if (RETCODE_OK == retcode)
	{
		if (SDCARD_INSERTED != SDCardDriver_GetDetectStatus())
		{
			printf("[ERROR, %s:%d] SD card was not detected for Storage\n", __FILE__, __LINE__);
			retcode = RETCODE(RETCODE_SEVERITY_WARNING, RETCODE_STORAGE_SDCARD_NOT_AVAILABLE);
		}
	}
	if (RETCODE_OK == retcode)
	{
		retcode = SDCardDriver_DiskInitialize(STORAGE_SDCARD_DRIVE_NUMBER); /* Initialize SD card */
	}
	if (RETCODE_OK == retcode)
	{
		/* Initialize file system */
		if (FR_OK != f_mount(&StorageSDCardFatFSObject, STORAGE_DEFAULT_LOGICAL_DRIVE, STORAGE_SDCARD_FORCE_MOUNT))
		{
			retcode = RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_STORAGE_SDCARD_MOUNT_FAILED);
		}
	}
	return retcode;

	return NO_EXCEPTION;
}

/**
 * Provides read access to the writer signal.
 */
Retcode_T InputOutputSDCardSd_Writer_Read(char **result)
{
	BCDS_UNUSED(result);
	return RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_FAILURE);

	return NO_EXCEPTION;
}

/**
 * Provides write access to the writer signal.
 */
Retcode_T InputOutputSDCardSd_Writer_Write(char **value)
{
	Retcode_T retcode = RETCODE_OK;
	FRESULT sdCardReturn = FR_OK, fileOpenReturn = FR_OK;
	FIL fileWriteHandle;
	UINT bytesWritten;
	FILINFO sdCardFileInfo;
#if _USE_LFN
	sdCardFileInfo.lfname = NULL;
#endif
	uint32_t writerFilePosition;
	fileOpenReturn = f_open(&fileWriteHandle, "CollectedData.csv", FA_WRITE | FA_OPEN_ALWAYS);
	if ((FR_OK == sdCardReturn) && (FR_OK == fileOpenReturn))
	{
		sdCardReturn = f_stat("CollectedData.csv", &sdCardFileInfo);
		writerFilePosition = sdCardFileInfo.fsize;
	}
	if ((FR_OK == sdCardReturn) && (FR_OK == fileOpenReturn))
	{
		sdCardReturn = f_lseek(&fileWriteHandle, writerFilePosition);
	}
	if ((FR_OK == sdCardReturn) && (FR_OK == fileOpenReturn))
	{
		sdCardReturn = f_write(&fileWriteHandle, *value, strlen(*value), &bytesWritten); /* Write it to the destination file */
	}
	if (FR_OK == fileOpenReturn)
	{
		sdCardReturn = f_close(&fileWriteHandle);
	}
	if ((FR_OK != sdCardReturn) || (FR_OK != fileOpenReturn))
	{
		retcode = RETCODE(RETCODE_SEVERITY_WARNING, RETCODE_STORAGE_ERROR_IN_FILE_WRITE);
	}
	return retcode;

	return NO_EXCEPTION;
}

/**
 * Provides read access to the cycleInit signal.
 */
Retcode_T InputOutputSDCardSd_CycleInit_Read(array_uint8_t *result)
{
	BCDS_UNUSED(result);
	return RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_FAILURE);

	return NO_EXCEPTION;
}

/**
 * Provides write access to the cycleInit signal.
 */
Retcode_T InputOutputSDCardSd_CycleInit_Write(array_uint8_t *value)
{
	Retcode_T retcode = RETCODE_OK;
	FRESULT sdCardReturn = FR_OK, fileOpenReturn = FR_OK;
	FIL fileWriteHandle;
	UINT bytesWritten;
	FILINFO sdCardFileInfo;
#if _USE_LFN
	sdCardFileInfo.lfname = NULL;
#endif
	uint16_t cycleInitFilePosition;
	fileOpenReturn = f_open(&fileWriteHandle, ".cycle.xdk", FA_WRITE | FA_OPEN_ALWAYS);
	if ((FR_OK == sdCardReturn) && (FR_OK == fileOpenReturn))
	{
		sdCardReturn = f_stat(".cycle.xdk", &sdCardFileInfo);
		cycleInitFilePosition = sdCardFileInfo.fsize;
	}
	if ((FR_OK == sdCardReturn) && (FR_OK == fileOpenReturn))
	{
		sdCardReturn = f_lseek(&fileWriteHandle, cycleInitFilePosition);
	}
	if ((FR_OK == sdCardReturn) && (FR_OK == fileOpenReturn))
	{
		sdCardReturn = f_write(&fileWriteHandle, value->data, value->length, &bytesWritten); /* Write it to the destination file */
	}
	if (FR_OK == fileOpenReturn)
	{
		sdCardReturn = f_close(&fileWriteHandle);
	}
	if ((FR_OK != sdCardReturn) || (FR_OK != fileOpenReturn))
	{
		retcode = RETCODE(RETCODE_SEVERITY_WARNING, RETCODE_STORAGE_ERROR_IN_FILE_WRITE);
	}
	return retcode;

	return NO_EXCEPTION;
}

/**
 * Provides read access to the cycleWriter signal.
 */
Retcode_T InputOutputSDCardSd_CycleWriter_Read(array_uint8_t *result)
{
	BCDS_UNUSED(result);
	return RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_FAILURE);

	return NO_EXCEPTION;
}

/**
 * Provides write access to the cycleWriter signal.
 */
Retcode_T InputOutputSDCardSd_CycleWriter_Write(array_uint8_t *value)
{
	Retcode_T retcode = RETCODE_OK;
	FRESULT sdCardReturn = FR_OK, fileOpenReturn = FR_OK;
	FIL fileWriteHandle;
	UINT bytesWritten;
	fileOpenReturn = f_open(&fileWriteHandle, ".cycle.xdk", FA_WRITE | FA_CREATE_ALWAYS);
	if ((FR_OK == sdCardReturn) && (FR_OK == fileOpenReturn))
	{
		sdCardReturn = f_lseek(&fileWriteHandle, 0);
	}
	if ((FR_OK == sdCardReturn) && (FR_OK == fileOpenReturn))
	{
		sdCardReturn = f_write(&fileWriteHandle, value->data, value->length, &bytesWritten); /* Write it to the destination file */
	}
	if (FR_OK == fileOpenReturn)
	{
		sdCardReturn = f_close(&fileWriteHandle);
	}
	if ((FR_OK != sdCardReturn) || (FR_OK != fileOpenReturn))
	{
		retcode = RETCODE(RETCODE_SEVERITY_WARNING, RETCODE_STORAGE_ERROR_IN_FILE_WRITE);
	}
	return retcode;

	return NO_EXCEPTION;
}

/**
 * Provides read access to the cycleReader signal.
 */
Retcode_T InputOutputSDCardSd_CycleReader_Read(array_uint8_t *result)
{
	Retcode_T retcode = RETCODE_OK;
	FRESULT sdCardReturn = FR_OK, fileOpenReturn = FR_OK;
	FILINFO sdCardFileInfo;
#if _USE_LFN
	sdCardFileInfo.lfname = NULL;
#endif
	FIL fileReadHandle;
	UINT bytesRead;

	sdCardReturn = f_stat(".cycle.xdk", &sdCardFileInfo);
	if (FR_OK == sdCardReturn)
	{
		if (0 >= sdCardFileInfo.fsize)
		{
			return EXCEPTION_ENDOFFILEEXCEPTION;
		}
		else
		{
			fileOpenReturn = f_open(&fileReadHandle, ".cycle.xdk", FA_OPEN_EXISTING | FA_READ);
		}
	}
	if ((FR_OK == sdCardReturn) && (FR_OK == fileOpenReturn))
	{
		sdCardReturn = f_lseek(&fileReadHandle, 0);
	}
	if ((FR_OK == sdCardReturn) && (FR_OK == fileOpenReturn))
	{
		sdCardReturn = f_read(&fileReadHandle, result->data, 2, &bytesRead); /* Read a chunk of source file */
	}
	if ((FR_OK == sdCardReturn) && (FR_OK == fileOpenReturn))
	{
	}
	if (FR_OK == fileOpenReturn)
	{
		sdCardReturn = f_close(&fileReadHandle);
	}
	if ((FR_OK != sdCardReturn) || (FR_OK != fileOpenReturn))
	{
		retcode = RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_STORAGE_SDCARD_READ_FAILED);
	}
	return retcode;

	return NO_EXCEPTION;
}

/**
 * Provides write access to the cycleReader signal.
 */
Retcode_T InputOutputSDCardSd_CycleReader_Write(array_uint8_t *value)
{
	BCDS_UNUSED(value);
	return RETCODE(RETCODE_SEVERITY_ERROR, RETCODE_FAILURE);

	return NO_EXCEPTION;
}
