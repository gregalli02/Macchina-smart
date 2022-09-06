#include<Wire.h>
#include <SoftwareSerial.h>

const int MPU = 0x68; // I2C address of the MPU-6050
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;

SoftwareSerial BTSerial(10, 11); // RX | TX

int x, y;
int x2, y2;

String posizione = "";

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
  BTSerial.begin(9600);
}


void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14, true); // request a total of 14 registers
  AcX = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY = Wire.read() << 8 | Wire.read(); 


  getDirectionX(AcX);
  getDirectionY(AcY);

 /*
  if((x2==0)&&(y2==0))  Serial.println("F");  //fermo
  else if((x2==1)&&(y2==0)) Serial.println("A");  //avanti
  else if((x2==2)&&(y2==0)) Serial.println("I"); //indietro
  else if((x2==0)&&(y2==1)) Serial.println("D"); //destra
  else if((x2==0)&&(y2==2)) Serial.println("S"); //sinistra
  else if((x2==1)&&(y2==1)) Serial.println("D"); //avanti destra
  else if((x2==1)&&(y2==2)) Serial.println("S"); //avanti sinistra
  else if((x2==2)&&(y2==1)) Serial.println("D"); //indietro destra
  else if((x2==2)&&(y2==2)) Serial.println("S"); //indietro sinistra
  

  */
  if((x2==0)&&(y2==0))  BTSerial.write("F");  //fermo
  else if((x2==1)&&(y2==0)) BTSerial.write("A");  //avanti
  else if((x2==2)&&(y2==0)) BTSerial.write("I"); //indietro
  else if((x2==0)&&(y2==1)) BTSerial.write("D"); //destra
  else if((x2==0)&&(y2==2)) BTSerial.write("S"); //sinistra
  else if((x2==1)&&(y2==1)) BTSerial.write("D"); //avanti destra
  else if((x2==1)&&(y2==2)) BTSerial.write("S"); //avanti sinistra
  else if((x2==2)&&(y2==1)) BTSerial.write("D"); //indietro destra
  else if((x2==2)&&(y2==2)) BTSerial.write("S"); //indietro sinistra
 
 
  
  
}


void getDirectionX(int16_t a){
  if((a > -2000) && (a < 2000)) x2=0; //FERMO
  else if(a > 11000) x2=1;            //AVANTI
  else if(a < -10000) x2=2;            //INDIETRO
  return;
}

int getDirectionY(int16_t a){
  if((AcY > -8000) && (AcY < 8000)) y2=0; //FERMO
  else if(AcY < -10000) y2=1;               //DESTRA
  else if(AcY > 8000) y2=2;              //SINISTRA
  return;
}
