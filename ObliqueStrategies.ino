#include <LiquidCrystal.h>
#include "frases.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
String fraseLine1 = "Strategy ";
String spaces = "               ";
String fraseLine2 = "";
int i = 0;
int fraseNum = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  SerialUSB.begin(9600);
  randomSeed(analogRead(A1));
  fraseNum =  random(126);
  fraseLine2 = spaces + ob[fraseNum];
}

void loop() {
  SerialUSB.println(analogRead(A1));
  lcd.clear();
  lcd.setCursor(0, 0);
  String line1 = fraseLine1 + (fraseNum+1);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(fraseLine2.substring(i, i + 15));
  lcd.display();
  delay(300);
  i = (i + 1) % (fraseLine2.length());
  if (analogRead(A1) < 1023) {
    fraseNum =  random(126);
    fraseLine2 = spaces + ob[fraseNum];
    lcd.clear();
    delay(1000);
    i = 0;
  }

}



