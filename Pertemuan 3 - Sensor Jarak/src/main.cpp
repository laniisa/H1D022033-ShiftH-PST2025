#include <Arduino.h>

int trigPin = D0; //mengeluarkn gelombang
int echoPin = D1; //menangkap
int Led = D2;

long duration;
long distance;

void setup() {
  pinMode(Led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * duration / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance <= 10){
    digitalWrite(Led, HIGH);
  }else {
    digitalWrite(Led, LOW);
  }
  delay(1000);
}


