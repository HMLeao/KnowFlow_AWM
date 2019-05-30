/*********************************************************************
* SdService.h
*
* Copyright (C)    2017   [DFRobot](http://www.dfrobot.com),
* GitHub Link :https://github.com/DFRobot/watermonitor
* This Library is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Description:SD card datalogger,Data write format:
* "Year,Month,Day,Hour,Minues,Second,pH,temp(C),DO(mg/l0,ec(s/m),orp(mv)"
*
* Product Links:http://www.dfrobot.com.cn/goods-1142.html
*
* SD card attached to SPI bus as follows:
* UNO:  MOSI - pin 11, MISO - pin 12, CLK - pin 13, CS - pin 4 (CS pin can be changed)
* and pin #10 (SS) must be an output
* Mega:  MOSI - pin 51, MISO - pin 50, CLK - pin 52, CS - pin 53
* and pin #53 (SS) must be an output
* M0:   Onboard SPI pin,CS - pin 4 (CS pin can be changed)
*
* author  :  Jason(jason.ling@dfrobot.com)
* version :  V1.0
* date    :  2017-04-19
*****************
*****************************************************/



#pragma once

#include "ISensor.h"
#include <SD.h>
#include "string.h"
#include "GravityRtc.h"

/**
 * 
 * This class generates a .csv and stores it at the SD card. The .csv file holds a table with all the data
 *	readen from the sensors, generating a log file. The SdService uses a RTC to get a timestamp
 * 
 */
class SdService
{

public:
	int chipSelect;
public:
/**
 * 	The SdService uses a Rtc to save the timestamp and an ISensor pointer array to get the data
 * @param[in] gravitySensor[] the sensor array containing the data to store onto the sd card
 * @param[in] newRtc reference for the rtc that SdService will work with
 */ 
	SdService(ISensor* gravitySensor[], GravityRtc& newRtc);
	~ SdService ();

/**
 * Initializes the SD card, writes the header on the sensor.csv file if it doesn't exists and starts the 
 * RTC device. 
 */ 
	void  begin ();

/**
 * Takes the sensor values and the timestamp from the RTC and writes a line of data on the file
 * 
 */ 
	void  update ();

private:
	// points to the pointer to the array of sensors
	ISensor** gravitySensor;
	//String dataString;

	bool sdReady = false;

	//String sensorstring;

	GravityRtc rtc;

	// file handle
	File dataFile;
	unsigned long sdDataUpdateTime;

	// Connect the string data
	void connectString(double value);

};

