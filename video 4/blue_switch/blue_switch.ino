#include <L298N.h>
#include <SoftwareSerial.h>

const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

L298N MotoreDestra(IN3, IN4);
L298N MotoreSinistra(IN1, IN2);

SoftwareSerial BT(10, 11);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BT.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  if(BT.available()){
    char c = BT.read();


    switch(c){
      case 'a':
        MotoreDestra.forward();
        MotoreSinistra.forward();
        break;
      
      case 'i':     
        MotoreDestra.backward();
        MotoreSinistra.backward();
        break;
    
      case 'l':
        MotoreDestra.forward();
        MotoreSinistra.stop();
        break;

      case 'r':
        MotoreDestra.stop();
        MotoreSinistra.forward();
        break;
      
      case 's':
        MotoreDestra.stop();
        MotoreSinistra.stop();
        break;
    }
    
  }
  
  
}
