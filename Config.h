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
 * Set here your voltage reference value
 */
#define V_REFERENCE 3.853

/**
 * Define whether you are using dynamic calibaration or not
 *
 */
#define USING_DYNAMIC_CAL

/**
 * @file Config.h
 * @defgroup PIN_SETTINGS Sensor pin settings
 * @brief set here the Arduino pins on which the sensors are connected
 * @{
 */ 
/** Gravity dissolved oxygen pin*/
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
#define ECKVALUE 0.985	
#define ECOFFSET 0

/**
 * Set the gain of the signal conditioning circuit fot the EC
 */
#define EC_GAIN 5.46


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
/**ORP offset is set by disconnecting the sensor from the BNC, then pressing the calibration button.
 * The value readen must be set on this define below*/
#define ORP_OFFSET	-0.2
/**@}*/


/**
 * @defgroup ARRAY_DEFS Array definitions
 * @brief definitions for ISensor array manipulations
 * @{
 */ 
/**The maximum number of sensors*/
#define SENSORCOUNT 5
/** PH sensor index */
#define PH_INDEX	0
/** Temperature sensor index*/
#define TEMP_INDEX	1
/** Dissolved oxygen index*/
#define DO_INDEX	2
/** Conductivity sensor index*/
#define EC_INDEX	3
/** TDS index*/
#define TDS_INDEX	3
/** ORP sensor index*/
#define ORP_INDEX	4

/**
 * @}
 */ 
//The sensor corresponds to the array number, ph=0, temperature=1..., the maximum number is SENSORCOUNT-1
enum SensorNumber
{
	phSensor = 0,
	temperatureSensor,
	doSensor,
	ecSensor,
	tdsSensor = 3,
	orpSensor
};
