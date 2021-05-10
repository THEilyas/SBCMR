//Kütüphaneler
#include<SoftwareSerial.h>
SoftwareSerial myblue(10,11);//RX/TX
#include <Wire.h>
#define MPU 0x68
//Veriler
//Gyro
int iX ,iY ,iZ , IsI , GyX , GyY ,GyZ;
//Motor Hız ve yön ayarı için değişkenler
int ena = 3;
int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;
int enb = 9;
int enaSpeed = 0;
int enbSpeed = 0;
//Bluetooth
char blVerb;
// Tek birkez döndürülecek döngü
void setup(){
//Serial Haberleşmeyi Başlat
Serial.begin(9600);
myblue.begin(9600);
//Gyro İçin gerekli
Wire.begin();
Wire.beginTransmission(MPU);
Wire.write(0x6B);
Wire.write(0);
Wire.endTransmission(true);
//Motor sürücü kontrol pinleri
pinMode(ena , OUTPUT);
pinMode(in1 , OUTPUT);
pinMode(in2 , OUTPUT);
pinMode(in3 , OUTPUT);
pinMode(in4 , OUTPUT);
pinMode(enb , OUTPUT);
}                                                                                                                      
void loop(){
Motordrive();
}
//Fonksiyon
void Motordrive(){
//Bluetooth verileri al 
blVerb = myblue.read();
Serial.println(blVerb);
/*İleri*/

if(blVerb == 'A'){
  analogWrite(ena , enaSpeed);
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , LOW);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , LOW);
  analogWrite(enb , enbSpeed);
}
/*Geri*/
if(blVerb == 'B'){
  analogWrite(ena , enaSpeed);
  digitalWrite(in1 , LOW);
  digitalWrite(in2 , HIGH);
  digitalWrite(in3 , LOW);
  digitalWrite(in4 , HIGH);
  analogWrite(enb , enbSpeed);
}
/*Sağ*/
if(blVerb == 'C'){
  analogWrite(ena , enaSpeed);
  digitalWrite(in1 , LOW);
  digitalWrite(in2 , HIGH);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , LOW);
  analogWrite(enb , enbSpeed);
}
/*Sol*/
if(blVerb == 'D'){
  analogWrite(ena , enaSpeed);
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , LOW);
  digitalWrite(in3 , LOW);
  digitalWrite(in4 , HIGH);
  analogWrite(enb , enbSpeed);
}
//Hız Ver
if(enaSpeed < 255 & enbSpeed < 255 & blVerb == 'E'){
  enaSpeed = enaSpeed + 51;
  enbSpeed = enbSpeed + 51;
}
//Hızı Düşür
if(enaSpeed > 0 & enbSpeed > 0 & blVerb == 'F'){
  enaSpeed = enaSpeed - 51;
  enbSpeed = enbSpeed - 51;     
}
  }
/*Gyro
Wire.beginTransmission(MPU);
Wire.write(0x3B); // ilk sensör verisi adresi
Wire.endTransmission(false);
Wire.requestFrom(MPU , 14, true); //   14 bit veri isteniyor-
iX = Wire.read()<<8|Wire.read();
iY = Wire.read()<<8|Wire.read();
iZ = Wire.read()<<8|Wire.read();
IsI = Wire.read()<<8|Wire.read();
GyX = Wire.read()<<8|Wire.read();
GyY = Wire.read()<<8|Wire.read();
GyZ = Wire.read()<<8|Wire.read();
 
//Serial.print("ivme X :"); 
//Serial.print(iX);
//Serial.print("/ivme Y :"); 
//Serial.print(iY);
//Serial.print("/ivme Z :"); 
//Serial.print(iZ);
//Serial.print("/Gyro X :"); 
//Serial.print(GyX);
//Serial.print("/Gyro Y :"); 
//Serial.print(GyY);
//Serial.print("/Gyro Z :"); 
//Serial.print(GyZ);
Serial.println("");*/
