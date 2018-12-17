#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7, 8); // bus 1

#define SCREEN_LENGTH 16
String wheelDisplay = "100|200|300|400|500|600|700|800|900|1000|1100|1200|1300|1400|1500|";
#define BUZZER 10  // one of the physical buzzer is broken, remember to check

int state = 0;
int wheelVal = 0;
int strength = 0;
int player = 0;
int score = 0;
int p1Total = 0;
int p2Total = 0;
String guessWord = "";

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  lcd.begin(16, 2);
  lcd.display();
}

void loop() {
  if (state == 0) {
    state = readWheelInput();
  } else if (state == 1) {
    spinWheel(wheelVal, strength);
    state = 2;
  } else if (state == 2) {
    state = readInfo();
  } else if (state == 3) {
    printInfo(player, score);
    delay(500);
    state = 0;
  }
}

int readWheelInput() {
   if (Serial.available() == 4) { // 2 times 2 bytes
      wheelVal = readInt();
      strength = readInt();
      return 1;
   } else {
      return 0;
   }
}

int readInfo() {
   if (Serial.available() == 4) {
      player = readInt();
      score  = readInt();
      return 3;
   } else {
      return 2;
   }
}
void spinWheel(int num, int strength) {
  strength = 2;
  String number = String(num);
  String printStr = "";
  int i = 0;
  int count = 0;
  while (printStr.substring(0, number.length()) != number || strength > count) {
    printStr = dispalyWheelPos(i);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(printStr);
    lcd.setCursor(0, 1);
    lcd.print('^');
    delay(70 / strength);
    i++;
    if (i == wheelDisplay.length()) {
      i = 0;
      count += 1;
    }
  }
  tone(BUZZER, 261);
  delay(100);
  noTone(BUZZER); 
}

String dispalyWheelPos(int num) {
  if (num + SCREEN_LENGTH < wheelDisplay.length()) {
    return wheelDisplay.substring(num, num + SCREEN_LENGTH);
  } else {
    return wheelDisplay.substring(num, wheelDisplay.length()) + wheelDisplay.substring(0, SCREEN_LENGTH);
  }
}

void printInfo(int player, int score) {
  lcd.setCursor(0, 1);
  lcd.print("P");
  lcd.print(player);
  lcd.print(": Score $");
  lcd.print(score);
}

int readInt() {
  byte b1 = Serial.read();
  byte b2 = Serial.read();
  int number = b1 | b2 << 8;
  return number;
}
