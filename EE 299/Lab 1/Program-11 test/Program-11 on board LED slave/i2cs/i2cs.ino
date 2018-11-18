/*
 * Lab 1 Program 11 slave
 * Mitchell Szeto, Bert Zhao, Feifan Qiao
 * 
 * Turns the Brick LED on slave when the button is pressed on master
 */
 
#include <Wire.h>

void setup()
{
  Wire.begin(4); 				// join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600); 			// start serial for output

  pinMode(9, OUTPUT);
}

void loop()
{
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  int x = Wire.read(); 			// receive byte as an integer
  if (x)
  {
    digitalWrite(9, HIGH);  
  } else
  {
    digitalWrite(9, LOW);  
  }
}
