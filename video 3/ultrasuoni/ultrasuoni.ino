#include <L298N.h>

const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

L298N MotoreDestra(IN3, IN4);
L298N MotoreSinistra(IN1, IN2);

const int Trig = 6;
const int Echo = 7;
long durata;
int distanza;


void setup() {
  // put your setup code here, to run once:
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  Serial.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:

  MotoreDestra.forward();
  MotoreSinistra.forward();
  
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);

  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  durata = pulseIn(Echo, HIGH);
  distanza = durata * 0.0343 / 2;

  digitalWrite(Echo, LOW);

  Serial.println(distanza);

  if(distanza <= 10){
    MotoreDestra.stop();
    MotoreSinistra.stop();
    delay(100);
    MotoreDestra.stop();
    MotoreSinistra.forward();
    delay(500);
  }
  
}
