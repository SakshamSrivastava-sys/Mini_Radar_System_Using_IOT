#include <Servo.h>

Servo myServo;
int trigPin = 9;
int echoPin = 10;
long duration;
int distance;

void setup() {
  myServo.attach(6);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  for(int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);
    delay(30);

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" Distance: ");
    Serial.println(distance);
  }

  for(int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    delay(30);
  }
}
