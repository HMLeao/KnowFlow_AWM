#pragma once

//Serial print switch
#define DEBUG_AVR
//#define DEBUG_M0

//The maximum length of the sensor filter array
#define ARRAYLENGTH 10

//SD card update data time, 60,000 is 1 minute
#define SDUPDATEDATATIME 60000

//EC sensor is selected by default, comment this line to use TDS sensor
#define SELECTEC 

//Sensor pin settings
#define DOPIN  A0
#define ECPIN  A1
#define TDSPIN A1
#define PHPIN  A2
#define ORPPIN A3
#define TEMPPIN 5


///Set sensor offset (calibration data)
#define PHOFFSET 0.12	//offset for the Ph sensor
#define ECKVALUE 0.6	//K constant value for the EC sensor

///The maximum number of sensors
#define SENSORCOUNT 5

///calibration coefficients (slope and y-axis intercept) to give more accurate values for the sensors
#define PH_M_COEFF	4.411
#define	PH_B_COEFF	-0.014

#define ORP_OFFSET	8.79


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
