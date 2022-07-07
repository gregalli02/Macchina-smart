#include <L298N.h>

const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

L298N MotoreDestra(IN3, IN4);
L298N MotoreSinistra(IN1, IN2);


void setup() {
  // put your setup code here, to run once:
}
 
void loop() {
  // put your main code here, to run repeatedly:

  MotoreDestra.forward();
  MotoreSinistra.forward();
  delay(1000);
  MotoreDestra.backward();
  MotoreSinistra.backward();
  delay(1000);
  MotoreDestra.stop();
  MotoreSinistra.forward();
  delay(1000);
  MotoreDestra.forward();
  MotoreSinistra.stop();
  delay(1000);
  MotoreDestra.stop();
  MotoreSinistra.stop();
  delay(1000);
  
}
