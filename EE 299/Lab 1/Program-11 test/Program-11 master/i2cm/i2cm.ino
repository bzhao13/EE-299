#include <Wire.h>

int button = 9;
bool ledOn = false;

void setup()
{
  pinMode(button, INPUT);
  Wire.begin(); 				    // join i2c bus (address optional for master)
  Serial.begin(9600); 			// start serial for output
}

void loop()
{
  if (digitalRead(button)) {
     Wire.beginTransmission(4);         // transmit to device #4
     Wire.write(HIGH); 
     Serial.println(HIGH);
     Wire.endTransmission();
     ledOn = true;
  } else {
     Wire.beginTransmission(4);         // transmit to device #4
     Wire.write(LOW); 
     Serial.println(LOW);
     Wire.endTransmission();
     ledOn = false;  
  }
//  delay(300);
  //Wire.beginTransmission(4); 	      // transmit to device #4
  //Wire.write(HIGH);	
  
  //Wire.endTransmission();
  //delay(1000);

  //Wire.beginTransmission(4);
  // Wire.write("LED is off");
  //Wire.write(LOW);
  
  //Wire.endTransmission();
  //delay(1000);
}
