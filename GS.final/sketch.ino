#include <Servo.h>

#define servoPin 10
#define ledR 13
#define trigger 8
#define echo 7

int dist = 0;
Servo myservo;

void setup() {
  Serial.begin(9600);
  pinMode(ledR, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  myservo.attach(servoPin);
}

void loop() {
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  //Função para pegar o valor em ECHO
  dist = pulseIn(echo, HIGH);

  //convertendo o valor em cm
  dist = dist / 58;

  if(dist < 20){
    Serial.println("risco de alagamento na Rua[...]");
    digitalWrite(ledR, HIGH);
    myservo.write(45);
  }else{
      digitalWrite(ledR, LOW);
      myservo.write(0);
  }
}