/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2019-05-31 09:54:04
 */


#ifndef MITA_EVENTS_H
#define MITA_EVENTS_H

#include <BCDS_Basics.h>
#include <BCDS_Retcode.h>
#include <BCDS_CmdProcessor.h>


extern CmdProcessor_T Mita_EventQueue;

Retcode_T HandleEveryXDK110Startup1(void* userParameter1, uint32_t userParameter2);

Retcode_T HandleEveryButton_onePressed1(void* userParameter1, uint32_t userParameter2);

Retcode_T HandleEveryButton_twoPressed1(void* userParameter1, uint32_t userParameter2);

Retcode_T HandleEvery20Millisecond1(void* userParameter1, uint32_t userParameter2);

Retcode_T HandleEvery250Millisecond1(void* userParameter1, uint32_t userParameter2);


#endif
