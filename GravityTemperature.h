/*********************************************************************
* GravityTemperature.h
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
* date    :  2017-04-12
**********************************************************************/

#pragma once
#include "ISensor.h"
#include "OneWire.h"
#define StartConvert 0
#define ReadTemperature 1


/**
 * This class is responsible for taking the temperature values from the sensor, which is done by the implementations of the 
 * one wire protocol bit banged by the OneWire.h Arduino library.
 */ 
class GravityTemperature : public ISensor
{
public:
	// temperature sensor pin
	int temperaturePin;
	double temperature;

public:
/**
 * @param[in] the pin to be used by the OneWire object
 */ 
	GravityTemperature(int pin);
	~GravityTemperature();

/**
 * Initializes the sensor
 */ 
	void  begin ();

/**
 * Updates the temperature value
 */ 
	void  update ();

/**
 * @return The processed temperature data
 */ 
	double getValue();

private:

	OneWire * oneWire;
	unsigned  long tempSampleInterval = 850 ;
	unsigned  long tempSampleTime;

	// Analyze temperature data
	double TempProcess(bool ch);
};

