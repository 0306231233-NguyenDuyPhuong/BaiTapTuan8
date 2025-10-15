#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int btn_tat = 6;
int btn_trai = 7;
int btn_phai = 8;

int btn_pre_tat = LOW;
int btn_pre_trai = LOW;
int btn_pre_phai = LOW;

String hienThi = "HELLO";

int viTri = 0;
void setup() {
  lcd.begin(16,2);
  pinMode(btn_trai,INPUT);
  pinMode(btn_phai,INPUT);
  pinMode(btn_tat,INPUT);  
  lcd.setCursor(0,0);
  lcd.print(hienThi);
}

void loop() {

  int btn_tt_tat = digitalRead(btn_tat);
  int btn_tt_trai = digitalRead(btn_trai);
  int btn_tt_phai = digitalRead(btn_phai);

  if(btn_tt_tat == HIGH && btn_pre_tat == LOW){
    lcd.setCursor(0,0);
    lcd.print("Ô");
  }
  if(btn_tt_phai == HIGH && btn_pre_phai == LOW){
    viTri++;
    if(viTri > 16-hienThi.length()) viTri = 16-hienThi.length();
    lcd.clear();
    lcd.setCursor(viTri, 0);
    lcd.print(hienThi);
  }
  if(btn_tt_trai == HIGH && btn_pre_trai == LOW){
    viTri--;
    if(viTri < 0) viTri = 0;
    lcd.clear();
    lcd.setCursor(viTri, 0);
    lcd.print(hienThi);
  }

  
  btn_pre_tat = btn_tt_tat;
  btn_pre_trai = btn_tt_trai;
  btn_pre_phai = btn_tt_phai;
}
