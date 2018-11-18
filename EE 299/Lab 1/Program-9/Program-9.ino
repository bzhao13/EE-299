/*
 * Lab 1 Program 9
 * Feifan Qiao, Mitchell Szeto, Bert Zhao
 * 
 * This program allows two buttons to move the cursor
 * on the display left or right. Scrolls display right
 * or left when the cursor hits the ends
 *  
  LiquidCrystal Library - display() and noDisplay()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 display() and noDisplay() functions to turn on and off
 the display.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal lcd(2, 3, 4, 5, 6, 7, 8);

const int minColumn = 0, maxColumns = 16;
int button1 = 10, button2 = 9;
int lastButton1State = LOW, lastButton2State = LOW;
int column = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(maxColumns, 2);
  // Print a message to the LCD.
  lcd.print("X");
}

void loop() {
  int read1 = digitalRead(button1);
  int read2 = digitalRead(button2);
  Serial.println(read2);
  if (read1 == HIGH && read1 != lastButton1State) {
    lastButton1State = read1;
    if (column < maxColumns - 1) {
      lcd.scrollDisplayRight();
      column++;
    }
  } else if (read1 == LOW) {
    lastButton1State = read1;
  }

  if (read2 == HIGH && read2 != lastButton2State) {
    lastButton2State = read2;
    if (column > minColumn) {
      lcd.scrollDisplayLeft();
      column--;
    }
  } else if (read2 == LOW) {
    lastButton2State = read2;
  }
  
}
