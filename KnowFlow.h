#ifndef KnowFlow_H
#define KnowFlow_H

#include "Config.h"

#ifndef	V_REFERENCE
#error you must define a V_REFERENCE at Config.h
#endif
//calling everybody at once
#include "ISensor.h"
#include "Config.h"
#include "Debug.h"
#include "GravityDo.h"
#include "GravityEc.h"
#include "GravityOrp.h"
#include "GravityPh.h"
#include "GravityRtc.h"
#include "GravitySensorHub.h"
#include "GravityTDS.h"
#include "GravityTemperature.h"
#include "SdService.h"
#include "SensorDo.h"


#endif
