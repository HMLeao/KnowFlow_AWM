#pragma once

#include <Arduino.h>
#include <SD.h>
#include "KnowFlow.h"

class SensorLog
{
public:

	SensorLog();
	~SensorLog();

	void createFile(String fileName);
	void storeLine();
	
private:

	FILE logFile;
	String lineToStore;
	String fileText;
};