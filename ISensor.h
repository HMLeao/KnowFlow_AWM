/*********************************************************************
* ISensor.h
*
* Copyright (C)    2017   [DFRobot](http://www.dfrobot.com),
* GitHub Link :https://github.com/DFRobot/watermonitor
* This Library is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Description:
*
* author  :  Jason(jason.ling@dfrobot.com)
* version :  V1.0
* date    :  2017-04-06
**********************************************************************/
#pragma once
#include "Config.h"
#include "Arduino.h"

/**
 * @file ISensor.h
 * @brief This class represents a generic sensor.
 * @author Jason(jason.ling@dfrobot.com)
 * @date 2017-04-06
 */ 

class ISensor
{
public:

	/**
	 * This function starts the sensor. All the initial configurations must be done here
	 */ 
	virtual void begin()		= 0;

	/**
	 * This function updates the sensor value and stores the value, so that it's ready to return data
	 */ 
	virtual void update()		= 0;

	/**
	 * This function must return the sensor data. You should run update() just before getValue() 
	 * to return a recent and valid data.
	 */ 
	virtual double getValue()	= 0;
};