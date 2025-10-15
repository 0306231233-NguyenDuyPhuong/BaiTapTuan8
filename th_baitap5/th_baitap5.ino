#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int led = 9;
int btn = 6;
int btnS = LOW;
int state = 0;
void setup() {
  lcd.begin (16,2);
  lcd.print("HELLO!");
  pinMode(led,OUTPUT);
  pinMode(btn,INPUT);
}

void loop() {
  if (btnS == LOW && digitalRead(btn) == HIGH){
    btnS = digitalRead(btn);
    state++;
  }
  btnS = digitalRead(btn);
  switch(state)
    {
      case 1: {
        lcd.noDisplay();
        digitalWrite (led, HIGH);
      } break;
      case 2: {
        lcd.display();
        digitalWrite(led,LOW);
      } break;
      default: {state = 0;} 
    }
}
