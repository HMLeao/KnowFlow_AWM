/*********************************************************************
* @file GravityPh.h
*
* Copyright (C)    2017   [DFRobot](http://www.dfrobot.com),
* GitHub Link :https://github.com/DFRobot/watermonitor
* This Library is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Description:Monitoring water quality parameters ph
*
* Product Links：http://www.dfrobot.com.cn/goods-812.html
*
* Sensor driver pin：A2 
*
* author  :  Jason(jason.ling@dfrobot.com)
* version :  V1.0
* date    :  2017-04-07
**********************************************************************/

#pragma once
#include <Arduino.h>
#include "ISensor.h"
class GravityPh:public ISensor
{
public:
	// ph sensor pin
	int phSensorPin;


	// Take the sample interval
	int samplingInterval;
private:

	static const int arrayLength = 5;
	unsigned int pHArray [arrayLength];    // stores the average value of the sensor return data
	double pHValue, voltage;
	double averageVoltage;
	double sum;
	double referenceVoltage = 5.0;


	#ifdef USING_DYNAMIC_CAL
	/* Calibration member variables */
	// y-axis intercept
	double yAxis = -0.014;
	// slope
	double slope = 4.411;
	#endif

public:
	GravityPh();
	~GravityPh() {};
	// initialization
	void begin();

	void begin(double defSlope, double defYaxis);

	// update the sensor data
	void  update ();

	// Get the sensor data
	double getValue();

	#ifdef USING_DYNAMIC_CAL
	/**
	 * defines the Y-Axis intercept parameter for calibration
	 *@param[in]  newYAxis is the new Y-Axis intercept
	 */
	void setYAxis(double newYAxis);

	/**
	 * defines the newSlope parameter for calibration
	 *@param[in]  Slope is the new slope value
	 */
	void setSlope(double newSlope);
	#endif
};

