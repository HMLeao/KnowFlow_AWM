/*********************************************************************************************
* SensorDo.cpp
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
* author  :  Jason(jason.ling@dfrobot.com)
* version :  V1.0
* date    :  2017-04-19
*********************************************************************************************/

#include "SensorDo.h"

SensorDo::SensorDo()
{
	this->inputStream = &Serial;
}


//********************************************************************************************
// Overloading the constructor function. 
// Function Description: Initializes the sensor, and gives it a Stream already instantiated and 
// 	with the baud rate set to 9600 baud.
//********************************************************************************************
SensorDo::SensorDo(Stream& st)
{
	//this->inputStream = &st;
	begin(st);
}

SensorDo::~SensorDo()
{
}


//********************************************************************************************
// function name: begin ()
// Function Description: Initializes the sensor
//********************************************************************************************
void SensorDo::begin()
{
	sensorstring.reserve(30);
	Serial.begin(9600);
}

//********************************************************************************************
// Overloading begin for define the input Stream. That Stream must have been initialized, 
// that is, you need to pass it with the baud rate set to 9600 baud beforhands.	
// NOTE: not all pins on the Mega can be used as RX. Please use one of the following pins for RX:
// 	-> 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68 or 69.
//********************************************************************************************
void SensorDo::begin(Stream& st)
{
	sensorstring.reserve(30);
	this->inputStream = &st;
}


//********************************************************************************************
// function name: update ()
// Function Description: Update the sensor value
//********************************************************************************************
void SensorDo::update()
{
	inputStream->listen();
	delay(100);
	if (inputStream->isListening())
	{
		static boolean sensorStringComplete = false;
		if (inputStream->available() > 0)
		{
			while(inputStream->available()>0){			
				char inchar = (char)inputStream->read();
				this->sensorstring += inchar;
				if (inchar == '\r'){
					sensorStringComplete = true;
					break;
				}
			}
			inputStream->flush();		
		}
		if (sensorStringComplete == true)
		{
			if (isdigit(this->sensorstring[0]))
				doValue = this->sensorstring.toFloat();
			this->sensorstring = "";
			sensorStringComplete = false;
		}
	}
	else
	{
		inputStream->flush();
		return;
	}
	
}

//********************************************************************************************
// function name: getValue ()
// Function Description: Returns the sensor data
//********************************************************************************************
double SensorDo::getValue()
{
	return doValue;
}

//
//void serialEvent() {                                  //if the hardware serial port_0 receives a char
//	inputstring = Serial.readStringUntil(13);           //read the string until we see a <CR>
//	input_string_complete = true;                       //set the flag used to tell if we have received a completed string from the PC 
//}

void SensorDo::print(String msg)
{
	inputStream->print(msg);
	inputStream->println(msg);
}