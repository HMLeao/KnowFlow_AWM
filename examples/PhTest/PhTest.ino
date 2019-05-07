#include <KnowFlow.h>

GravityPh myPhMeter;

void begin() {
  Serial.begin(9600);
  myPhMeter.setOffset(0.45);
}

void loop() {
  myPhMeter.update();  
  double phValue = myPhMeter.getValue();
  Serial.print("Ph value: ");
  Serial.println(phValue);
  _delay_ms(2000);
}
