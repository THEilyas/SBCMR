//Kütüphaneler
#include <Wire.h>
#define MPU 0x68
//Veriler
int iX ,iY ,iZ , IsI , GyX , GyY ,GyZ;
//Motor Hız ve yön ayarı için değişkenler
int ena = 3;
int in1 = 4;
int in2 = 5;
int in3 = 6;
int in4 = 7;
int enb = 9;
int enaSpeed = 255;
int enbSpeed = 255;
int blVerb;
// Tek birkez döndürülecek döngü
void setup(){
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
if(Serial.available() > 0){
Serial.println("GO");
}
//Serial Haberleşmeyi Başlat
Serial.begin(9600);
}                                                                                                                      
void loop(){
//Bluetooth verileri al 
blVerb = Serial.read();
Serial.println(blVerb);
  //ileri
  if(blVerb == 49){
  digitalWrite(ena , HIGH);
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , LOW);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , LOW);
  digitalWrite(enb , HIGH);
  }
  //Geri
  if(blVerb == 50){
  digitalWrite(ena , HIGH);
  digitalWrite(in1 , LOW);
  digitalWrite(in2 , HIGH);
  digitalWrite(in3 , LOW);
  digitalWrite(in4 , HIGH);
  digitalWrite(enb , HIGH);
  }
  //Sağ
  if(blVerb == 51){
  digitalWrite(ena , HIGH);
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , LOW);
  digitalWrite(in3 , LOW);
  digitalWrite(in4 , HIGH);
  digitalWrite(enb , HIGH);
  }
  //Sol
  if(blVerb == 52){
  digitalWrite(ena , HIGH);
  digitalWrite(in1 , LOW);
  digitalWrite(in2 , HIGH);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , LOW);
  digitalWrite(enb , HIGH);
  }
}
void Motordrive(){
  /*İleri*/
  if(blVerb == 49){
  digitalWrite(ena , HIGH);
  digitalWrite(in1 , LOW);
  digitalWrite(in2 , HIGH);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , LOW);
  digitalWrite(enb , HIGH);
 }
  /*Geri*/
  if(blVerb == 50){
  digitalWrite(ena , HIGH);
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , HIGH);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , HIGH);
  digitalWrite(enb , HIGH);
 }
 /*Sağ*/
 if(blVerb == 51){
  digitalWrite(ena , HIGH);
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , HIGH);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , HIGH);
  digitalWrite(enb , HIGH);
 }
 /*Sol*/
 if(blVerb == 52){
  digitalWrite(ena , HIGH);
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , HIGH);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , HIGH);
  
  digitalWrite(enb , HIGH);
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
Serial.println("");*/--9622
}
