#include <L298N.h>


const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

L298N MotoreDestra(IN3, IN4);
L298N MotoreSinistra(IN1, IN2);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char c = Serial.read();


    if(c == 'a'){
        MotoreDestra.forward();
        MotoreSinistra.forward();
    }
    else if(c == 'i'){
     
        MotoreDestra.backward();
        MotoreSinistra.backward();
    }
    else if(c == 'l'){
        MotoreDestra.forward();
        MotoreSinistra.stop();
    }
     else if(c == 'r'){
        MotoreDestra.stop();
        MotoreSinistra.forward();
     }
      else{
        MotoreDestra.stop();
        MotoreSinistra.stop();
      
    }
    
  }
  
  
}
