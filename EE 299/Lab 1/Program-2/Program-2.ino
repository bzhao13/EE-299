/*
  Lab 1
  Program 2
  Mitchell Szeto, Feifan Qiao, Bert Zhao

  Turns the built in LED on for two 1 second blinks, with a 1 second delay between the two blinks
  then turns the LED on for two 2 second blinks, with a 2 second delay between the two blinks

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(LED_BUILTIN, HIGH);  // turns the LED on
    delay(1000);                      // delays for one second
    digitalWrite(LED_BUILTIN, LOW);   // turns the LED off
    delay(1000);                      // delays for one second
  }
  
  for (int i = 0; i < 2; i++) {
    digitalWrite(LED_BUILTIN, HIGH);  // turns the LED on
    delay(2000);                      // delays for two seconds
    digitalWrite(LED_BUILTIN, LOW);   // turns the LED off
    delay(2000);                      // delays for two seconds
  }
}
