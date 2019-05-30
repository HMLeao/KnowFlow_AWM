/*********************************************************************
* GravityRtc.h
*
* Copyright (C)    2017   [DFRobot](http://www.dfrobot.com),
* GitHub Link :https://github.com/DFRobot/Gravity-I2C-SD2405-RTC-Module/
* This Library is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Description:Get real-time clock data
*
* Product Links：https://www.dfrobot.com/wiki/index.php/Gravity:_I2C_SD2405_RTC_Module_SKU:_DFR0469
*
* Sensor driver pin：I2C
*
* author  :  Jason(jason.ling@dfrobot.com)
* version :  V1.0
* date    :  2017-04-18
**********************************************************************/

#pragma once
#include <Arduino.h>

#define RTC_Address   0x32  //RTC_Address 

/**
 * This class controls the Real Time data from the RTC device 
 */ 
class GravityRtc
{
public:
	GravityRtc() {};
	~GravityRtc() {};

public:

	
	/**
	 * Initialize RTC time to set the corresponding year, month, day, Weekday, Hour, Minute and Second
	 * @param[in] date The date string 
	 * @param[in] time The time string
	 */ 
	void adjustRtc(const __FlashStringHelper* date, const __FlashStringHelper* time);
	
	/**
	 * Initialize RTC time to set the corresponding year, month, day, Weekday, Hour, Minute and Second as separated integer values
	 * @param [in] year the year value
	 * @param[in] month the month value
	 * @param[in] day the day value
	 * @param[in] week the weekday value
	 * @param[in] hour the hor value
	 * @param[in] minute the minute valuee
	 * @param[in] second the seconds value
	 */ 
	void adjustRtc(uint16_t year,uint8_t month,uint8_t day,uint8_t week,
            	uint8_t hour,uint8_t minute,uint8_t second);

	/**
	 * Initializes the I2C interface through the Arduino Wire library
	 */ 
	void setup();

	/**
	 * Reads, processes and stores the current time data
	 */ 
	void read();
	
	//getters for encapsulating time parameters
	/**@return the year value*/
	uint16_t	getYear()	{return this->year;};
	/**@return the month value*/
	uint8_t 	getMonth()	{return this->month;};
	/**@return the day value*/
	uint8_t 	getDay()	{return this->day;};		
	/**@return the weeday value*/
	uint8_t 	getWeek()	{return this->week;};
	/**@return the hour value*/
	uint8_t 	getHour()	{return this->hour;};
	/**@return the minute value*/
	uint8_t 	getMinute()	{return this->minute;};
	/**@return the seconds value*/
	uint8_t 	getSecond()	{return this->second;};

private:
	uint8_t date[7];

	//Read RTC Time
	void readRtc();

	//Analysis RTC Time
	void processRtc();

	//Decimal turn to BCD
	uint8_t decTobcd(uint8_t num);
	void WriteTimeOn(void);
	void WriteTimeOff(void);
	unsigned long timeUpdate;

	//adjust RTC
	uint8_t dayOfTheWeek();
	// number of days since 2000/01/01, valid for 2001..2099
 	uint16_t date2days(uint16_t y, uint8_t m, uint8_t d);
	
	uint8_t conv2d(const char* p);


private:
		//Year Month Day Weekday Minute Second
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t week;
	uint8_t hour;
	uint8_t minute;
	uint8_t second;

};

