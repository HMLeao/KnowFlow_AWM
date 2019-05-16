/**
 * @file Config.h
 * 
 */ 
#pragma once

/**Serial print switch*/
#define DEBUG_AVR
//#define DEBUG_M0

//!The maximum length of the sensor filter array
#define ARRAYLENGTH 10

//!SD card update data time, 60,000 is 1 minute
#define SDUPDATEDATATIME 60000

//!EC sensor is selected by default, comment this line to use TDS sensor
#define SELECTEC 

/**
 * @file Config.h
 * @defgroup PIN_SETTINGS Sensor pin settings
 * @brief set here the Arduino pins on which the sensors are connected
 * @{
 */ 
/** Gravoty dissolved oxygen pin*/
#define DOPIN  A0
/** Electric conductivity pin*/
#define ECPIN  A1
/** TDS pin*/
#define TDSPIN A1
/** Gravity PH sensor pin*/
#define PHPIN  A2
/** Gravity ORP sensor pin*/
#define ORPPIN A3
/** Temperature sensor pin (must be digital for OneWire interface)*/
#define TEMPPIN 5
/**@}  */


/**Set sensor offset (calibration data)*/
#define PHOFFSET 0.12	
#define ECKVALUE 0.6	

/**The maximum number of sensors*/
#define SENSORCOUNT 5


/**
 * @file Config.h
 * @defgroup CAL_COEFF calibration coefficients
 * @brief calibration values for the linear sensors
 * @{
 */

/** PH slope */
#define PH_M_COEFF	4.411
/** PH Y-intercept */
#define	PH_B_COEFF	-0.014
/**ORP offset is set my disconnecting the sensor from the BNC, then pressing the calibration button.
 * The value readen must be set on this define below*/
#define ORP_OFFSET	8.79

/**@}*/


///The sensor corresponds to the array number, ph=0, temperature=1..., the maximum number is SENSORCOUNT-1
enum SensorNumber
{
	phSensor = 0,
	temperatureSensor,
	doSensor,
	ecSensor,
	tdsSensor = 3,
	orpSensor
};
