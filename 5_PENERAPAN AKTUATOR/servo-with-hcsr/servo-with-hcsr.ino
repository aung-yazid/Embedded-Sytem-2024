#include <Servo.h>

Servo myServo;

const int trig = A0;
const int echo = A1;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myServo.attach(6);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  long durasi = pulseIn(echo, HIGH);
  float cm = durasi*0.034/2;
  
  Serial.print("Jarak Sensor : ");
  Serial.print(cm);
  delay(500);
  
  if(cm > 10) {
    myServo.write(90);
  } else {
    myServo.write(0);
  }
}
