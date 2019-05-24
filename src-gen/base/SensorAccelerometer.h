/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2019-05-24 10:40:00
 */


#ifndef SENSORACCELEROMETER_ACCELEROMETER_H
#define SENSORACCELEROMETER_ACCELEROMETER_H

#include <bma2x2.h>
#include <BCDS_Retcode.h>


/**
 * Sets up the accelerometer.
 */
Retcode_T SensorAccelerometer_Setup(void);

/**
 * Enables the accelerometer sensor.
 */
Retcode_T SensorAccelerometer_Enable(void);


Retcode_T SensorAccelerometer_ReadXYZ(struct bma2x2_accel_data* result);

#endif
