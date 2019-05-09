/*
 * Wtitten by Henrique Martins in 2019-05-09
 * 
 * Linear Sensor Calibration for the KnowFlow library
 * 
 * Initially, the values readen from the probes are a little wrong.
 * This is because probes differ from each other when measuring the same solution.
 * To fix it, you have to set the calibration parameters for the KnowFlow library to work with more accuracy.
 * 
 * Probes like the Ph  and EC give us a linear response, which means that they can be dicribed by the well known y=mx+b linear function. So, the only parameters we need to calculate
 * are the slope (which is represented by 'm') and the the y-axis intercept (which is 'b'). This procedure is called "two-point calibration".
 *
 * To calculate that parameters follow these simple steps:
 *  -1st: Run this sketch and open the Serial Monitor. Put the probe into the lower buffer solution (which will give you a true and known value), and annotate the correspondent analog value for that solution, it is our X1 value
 *  and the lower buffer value will be the y1 value.
 *  
 *  -2nd: Now put the probe into the higher buffer solution to get the value of X2 and, again, the buffer solution will be the Y2.
 *  
 *  -3rd: Calculate the slope (m) using the equation: m=(Y2-Y1)/(X2-X1). Annotate its value.
 *   
 *  -4th: Calculate the y-intercept (b) using b=y-(m*X)
 *  
 *  -5th: That's it! you have the equation that describe your probe's responses. Take the 'm' and 'b' parameters an put at the #define statement below!
 *  
 *  -6th: Recompile and run this sketch again and see the correct value on the serial monitor
 * 
 */

#define SLOPE         4.411   // m=(Y2-Y1)/(X2-X1)
#define Y_INTERCEPT  -0.014  // b=Y-(m*X)


void setup() {
    Serial.begin(9600);

}

double sensorValue(double m, double b, double v);

void loop() {
  unsigned int adcValue = analogRead(2);
  double analogValue = (double)adcValue*5.0 / 1024;

  double m=SLOPE, b=Y_INTERCEPT; // m=> coneficiente angular; b=> coeficiente linear

  double ph =  sensorValue(m,b,analogValue);
  
  Serial.println("|------------------------|");
  Serial.print("  Analog Value: ");
  Serial.println(analogValue);
  Serial.print("  m=");
  Serial.print(m);
  Serial.print(", b=");
  Serial.println(b);
  
  

  Serial.print("  Sensor Value: ");
  Serial.println(ph);
  
  delay(1000);
}


double sensorValue(double m, double b, double analogValue) 
{
  double sensor = m*analogValue + b;
  return sensor;
}
