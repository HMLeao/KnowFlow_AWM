#pragma once

//���ڴ�ӡ����
#define DEBUG_AVR
//#define DEBUG_M0

//�������˲��������󳤶�
#define ARRAYLENGTH 10

//SD���������ݵ�ʱ�䣬60000Ϊ1����
#define SDUPDATEDATATIME 60000

//����������������
#define DOPIN  A0
#define ECPIN  A1
#define PHPIN  A2
#define ORPPIN A3
#define TEMPPIN 5

//���ô�����ƫ������У׼���ݣ�
#define PHOFFSET 0.12
#define ECKVALUE 0.6


//������������
#define SENSORCOUNT 5

//��������Ӧ�����ţ�ph=0��temperature=1...,�����ΪSENSORCOUNT-1
enum SensorNumber
{
	phSensor = 0,
	temperatureSensor,
	doSensor,
	ecSensor,
	orpSensor
};
