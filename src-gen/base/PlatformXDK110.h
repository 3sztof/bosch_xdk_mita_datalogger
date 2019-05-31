/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2019-05-31 09:54:04
 */


#ifndef PLATFORMXDK110_XDK110_H
#define PLATFORMXDK110_XDK110_H

#include <BCDS_Retcode.h>
#include "xdk110Types.h"


/**
 * Sets up the XDK110.
 */
Retcode_T PlatformXDK110_Setup(void);

/**
 * Enables the XDK110 sensor.
 */
Retcode_T PlatformXDK110_Enable(void);


Retcode_T XDK110_powerStatus_read(PowerStatus* result);

#endif
