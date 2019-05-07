#include <KnowFlow.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,2,1,0,4,5,6,7,3, POSITIVE);

GravityTemperature myTemp(TEMPPIN);
GravityEc myEc(&myTemp);

void begin() {
  lcd.begin (16,2);
  lcd.setBacklight(HIGH);
  myEc.begin();
}

void loop() {
  
  myTemp.update();
  myEc.update();
  
  double runningTemp = myTemp.getValue();  
  double runningEc = myEc.getValue();
  
  lcd.setCursor(0,0);
  lcd.print("T = ");
  lcd.print(runningTemp);

  lcd.setCursor(0,1);
  lcd.print("Ec= ");
  lcd.print(runningEc);
  
  delay(1000);
}
