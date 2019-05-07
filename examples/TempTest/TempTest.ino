#include <KnowFlow.h>


GravityTemperature myTemp(TEMPPIN);

void begin()
{
    Serial.begin(9600);
}


void loop()
{
    myTemp.update();
    double tempValue = myTemp.getValue();
    Serial.print("Temperature value: ");
    Serial.println(tempValue);
    _delay_ms(2000);
}
