/*
 * Lab 1 Program 11
 * Mitchell Szeto, Feifan Qiao, Bert Zhao
 * 
 * 
 */

#include <Wire.h>
void setup()
{
  Wire.begin(4); 				// join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600); 			// start serial for output

  pinMode(8, OUTPUT);
}
void loop()
{
  delay(100);
}
// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
//  while(1 <Wire.available()) 	// loop through all but the last
//  {
//    char c =Wire.read(); 		// receive byte as a character
//    Serial.print(c); 			// print the character
//  }
  
  int x = Wire.read(); 			// receive byte as an integer
  //if (x)
  //{
    digitalWrite(8, x);  
//  } else
//  {
//    digitalWrite(LED_BUILTIN, LOW);  
//  }
  //Serial.println(x); 			// print the integer
}
