/**
 * Generated by Eclipse Mita 0.1.0.
 * @date 2019-05-23 19:47:53
 */


#ifndef MITA_EXCEPTIONS_H
#define MITA_EXCEPTIONS_H

#include <BCDS_Retcode.h>

#ifndef BCDS_MODULE_ID
#define BCDS_MODULE_ID 0xCAFE
#endif

#define NO_EXCEPTION RETCODE_OK

#define EXCEPTION_EXCEPTION RETCODE(RETCODE_SEVERITY_ERROR, UINT32_C(2118808545))
#define EXCEPTION_INDEXOUTOFBOUNDSEXCEPTION RETCODE(RETCODE_SEVERITY_ERROR, UINT32_C(590273687))
#define EXCEPTION_INVALIDRANGEEXCEPTION RETCODE(RETCODE_SEVERITY_ERROR, UINT32_C(930165447))
#define EXCEPTION_NOSUCHELEMENTEXCEPTION RETCODE(RETCODE_SEVERITY_ERROR, UINT32_C(82503061))
#define EXCEPTION_TIMEOUTEXCEPTION RETCODE(RETCODE_SEVERITY_ERROR, UINT32_C(987555358))
#define EXCEPTION_NOVALUEEXCEPTION RETCODE(RETCODE_SEVERITY_ERROR, UINT32_C(604791793))
#define EXCEPTION_NODEVICECONNECTEDEXCEPTION RETCODE(RETCODE_SEVERITY_ERROR, UINT32_C(95110413))
#define EXCEPTION_MQTTEXCEPTION RETCODE(RETCODE_SEVERITY_ERROR, UINT32_C(1176493701))
#define EXCEPTION_HTTPREQUESTNOTOKEXCEPTION RETCODE(RETCODE_SEVERITY_ERROR, UINT32_C(1070981591))
#define EXCEPTION_ENDOFFILEEXCEPTION RETCODE(RETCODE_SEVERITY_ERROR, UINT32_C(1635684785))

#endif
