/*********************************************************************************************
* @file SensorDo.h
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
* Sensor driver pin：Serial,Rx(0),Tx(1)
*
* @author  :  Jason(jason.ling@dfrobot.com)
* @version :  V1.0
* @date    :  2017-04-19
*********************************************************************************************/
#pragma once
#include "ISensor.h"
#include "Arduino.h"
/**
 * This class controls the <a target="_blank" rel="noopener noreferer" href="https://www.atlas-scientific.com/product_pages/kits/do_kit.html">Atlas Scientific DO Sensor</a> via uart serial interface.
 * It takes Dissolved Oxigen readings from the <a target="_blank" rel="noopener noreferer" href="https://www.atlas-scientific.com/_files/_datasheets/_circuit/DO_EZO_Datasheet.pdf?">EZO</a> circuit and stores 
 * it's current value.
 */ 
class SensorDo: public ISensor
{
public:
	/**
 	* Default constructor. Sets the instantiated HardwareSerial Serial as the Stream for the sensor.
 	*/ 
	SensorDo();
	/** 
	* Initialize the Do Sensor with a given Stream. 
	* @param[in] st	The Stream for comunicate with the sensor via serial interface.
	*/
	SensorDo(Stream& st);
	~SensorDo();

public:
	/**
	 * Initializes the default Serial instance
	 */
	void  begin ();
	/**
	 * Initializes the DO sensor  with a given Stream
	 * @param[in] st The Stream for comunicating with the sensor via serial interface.
	 */ 
	void  begin(Stream& st);

	/**
	 * Reads the sensor value and stores it's value.
	 */ 
	void  update ();

	/**
	 * Read the stored value.
	 * @return The value os the sensor.
	 */ 
	double getValue();

private:

	String sensorstring = "";

	Stream *inputStream;
	// do the data
	double doValue;

};

