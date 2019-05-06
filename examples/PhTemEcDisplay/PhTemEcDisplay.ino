#include <KnowFlow.h>
#include <LiquidCrystal_I2C.h>

#define SENSOR_COUNT 3

LiquidCrystal_I2C lcd(0x3f,2,1,0,4,5,6,7,3, POSITIVE);

GravityTemperature myTemp(TEMPPIN);
GravityEc myEc(&myTemp);
GravityPh myPh;


void setup() {
  lcd.begin (16,2);
  
  lcd.setBacklight(HIGH);
  myEc.setup();
  
}

void loop() {
  
  myTemp.update();
  myEc.update();
  myPh.update();
  
  double runningTemp = myTemp.getValue();  
  double runningEc   = myEc.getValue();
  double runningPh   = myPh.getValue();
  
  lcd.setCursor(0,0);
  lcd.print("T = ");
  lcd.print(runningTemp);

  lcd.setCursor(0,1);
  lcd.print("Ec= ");
  lcd.print(runningEc);

  lcd.setCursor(9,1);
  lcd.print("Ph=");
  lcd.print(runningPh);
  
  delay(1000);
}
