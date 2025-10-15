int led = 10;
int btnup = 7;
int btndwn = 6;
int btnupS = LOW;
int btndwnS = LOW;
int interval = 100;
int ledState = LOW;
unsigned long long preMillis = 0;

void setup() {

  pinMode(led,OUTPUT);
  pinMode(btnup,INPUT);
  pinMode(btndwn,INPUT);

}

void loop() {

  unsigned long long currMillis = millis();
  if (currMillis - preMillis >= interval){
    preMillis = currMillis; 
    ledState = ledState?LOW:HIGH;
    digitalWrite (led,ledState);
  }

  if (btnupS == LOW && digitalRead(btnup) == HIGH){
    btnupS = digitalRead(btnup);
    delay(20);
    interval = (interval-100 <=100) ?100:interval - 100;
  }
  btnupS = digitalRead(btnup);

  if (btndwnS == LOW && digitalRead(btndwn) == HIGH){
    btndwnS = digitalRead(btndwn);
    delay(20);
    interval = (interval+100 >= 2000)?2000:interval + 100;
  }
  btndwnS = digitalRead(btndwn);


}
