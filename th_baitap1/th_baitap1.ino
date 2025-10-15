int led[] = {1,2,3,4,5,6,7,8,9,10};

void setup() {
  
  for (int i = 0; i < sizeof(led); i++){
    pinMode(led[i], OUTPUT);
  }

}

void loop() {

  for (int i = 0; i < sizeof(led); i++){
    if (random(1,11) % 2 != 0){
      digitalWrite(led[i],HIGH);
    } else {
      digitalWrite(led[i],LOW);
    }
  }
  delay(1000);
}
