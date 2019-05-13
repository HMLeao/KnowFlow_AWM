#include <KnowFlow.h>
#include <LiquidCrystal_I2C.h>

GravityOrp myOrp;
GravityTemperature myTemp(TEMPPIN);

LiquidCrystal_I2C lcd(0x3f,2,1,0,4,5,6,7,3, POSITIVE);

void setup() {
  lcd.begin (16,2);
  lcd.setBacklight(HIGH);
  myOrp.begin();
}

void loop() {
  myOrp.update();
  myTemp.update();

  double runningTemp = myTemp.getValue();
  double runningOrp = myOrp.getValue();

  lcd.setCursor(0,1);
  lcd.print("Orp =");
  lcd.print(runningOrp);
  lcd.print("mV");

  lcd.setCursor(0,0);
  lcd.print("T =");
  lcd.print(runningTemp);
  lcd.print("oC");

  delay(1000);

}
