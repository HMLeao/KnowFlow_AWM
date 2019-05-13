#include <SoftwareSerial.h>
#include <KnowFlow.h>
#include <LiquidCrystal_I2C.h>


SensorDo myDo;

LiquidCrystal_I2C lcd(0x3f,2,1,0,4,5,6,7,3, POSITIVE);



void setup() 
{
  SoftwareSerial myStream(10,11);
  myStream.begin(9600);
  lcd.begin(16,2);
  lcd.setBacklight(HIGH);
  myDo.begin(myStream);
}

void loop() 
{ 
  lcd.setCursor(0,0);
  lcd.print("Do = ");
  lcd.print(readSensor(myDo));
  lcd.print("mg/L");
  delay(2000);
}


double readSensor(ISensor& mySensor){
  mySensor.update();
  delay(200);
  double valorLido = mySensor.getValue();
  return valorLido;
 }
