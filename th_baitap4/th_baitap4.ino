int Rled = 11;
int Yled = 10;
int btn = 3;
int btnS = LOW;
int state = 0;
void setup() {
  pinMode(Rled,OUTPUT);
  pinMode(Yled,OUTPUT);
  pinMode(btn,INPUT);
}

void loop() {

  if (btnS == LOW && digitalRead(btn) == HIGH){
    btnS = digitalRead(btn);
    state++;
  }
  btnS = digitalRead(btn);

  switch(state){
    case 1: {
      digitalWrite(Yled,HIGH);
      digitalWrite(Rled,HIGH);
    }break;
    case 2: {
      digitalWrite(Yled,LOW);
      digitalWrite(Rled,LOW);
    }break;
    case 3: {
      digitalWrite(Yled,HIGH);
      digitalWrite(Rled,LOW);
    }break;
    case 4: {
      digitalWrite(Yled,LOW);
      digitalWrite(Rled,HIGH);
    }break;
    default: {
      state = 0; 
      digitalWrite(Yled,LOW);
      digitalWrite(Rled,LOW);
    }
  }

}
