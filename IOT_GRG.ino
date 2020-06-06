//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

const int sensorMin1 =3110;
const int sensorMax1 =4095;
const int sensorMin2 =3110;
const int sensorMax2 =4095;
const int sensorMin3 =3110;
const int sensorMax3 =4095;
const int sensorMin4 =1460;
const int sensorMax4 =2230;
const int sensorMin5 =1440;
const int sensorMax5 =2270;
const int sensorMin6 =1460;
const int sensorMax6 =2209;
//int m1, m2, m3, m4, m5, m6;


BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
  int sensorValue1 = analogRead(36);
  int sensorValue2 = analogRead(39);
  int sensorValue3 = analogRead(34);
    
  int sensorValue4 = analogRead(35);
  int sensorValue5 = analogRead(32);
  int sensorValue6 = analogRead(33);

  int m1 = (sensorValue1/3603);
  int m2 =(sensorValue2/3603);
  int m3 =(sensorValue3/3603);
  int m4 = (sensorValue4/1950);
  int m5 = (sensorValue5/2000);
  int m6 =(sensorValue6/1950);
 



  /*int sensorValue1 = analogRead(36);
  int sensorValue2 = analogRead(39);
  int sensorValue3 = analogRead(34);
    
  int sensorValue4 = analogRead(35);
  int sensorValue5 = analogRead(32);
  int sensorValue6 = analogRead(33);

  long int m1 = (sensorValue1/3603);
  int m2 =(sensorValue2/3603);
  int m3 =(sensorValue3/3603);
  
  int m41 = (sensorValue4/1470);
  int m42 = (sensorValue4/1870);
  int m43 = (sensorValue4/2270);
  
  int m51 =(sensorValue5/1470);
  int m52 = (sensorValue5/1870);
  int m53 = (sensorValue5/2270);
  
  int m61 = (sensorValue6/1470);
  int m62 =(sensorValue6/1870);
  int m63 = (sensorValue6/2240);*/
  
  //print out the read:
 /* Serial.print("sensorValue1: ");
  Serial.println(sensorValue1);*/


  
  {
  char b1[8] = {m1};
   itoa(m1, b1, 8);//covert int to string
  SerialBT.println(b1);
  Serial.println("b1 :");
  Serial.println(b1);
  SerialBT.print("|");
  }
  
 /* Serial.print("sensorValue2: ");
  Serial.println(sensorValue2);*/
  
   {
  char b2[8] = {m2};
  itoa(m2, b2, 8);//covert int to string
  SerialBT.println(b2); 
  Serial.println("b2 :");  
  Serial.println(b2);
  SerialBT.print("|");
  }
  
 /* Serial.print("sensorValue3: ");
  Serial.println(sensorValue3);*/
  
  {
  char b3[8] = {m3};
  itoa(m3, b3, 8);//covert int to string
  SerialBT.println(b3);
  Serial.println("b3 :");
  Serial.println(b3);
  SerialBT.print("|");
   }

    {
  char b4[8] = {m4};
  itoa(m4, b4, 8);//covert int to string
  SerialBT.println(b4);
  Serial.println("b4 :");
  Serial.println(b4);
  SerialBT.print("|");
   }

    {
  char b5[8] = {m5};
  itoa(m5, b5, 8);//covert int to string
  SerialBT.println(b5);
  Serial.println("b5 :");
  Serial.println(b5);
  SerialBT.print("|");
   }

    {
  char b6[8] = {m6};
  itoa(m6, b6, 8);//covert int to string
  SerialBT.println(b6);
  Serial.println("b6 :");
  Serial.println(b6);
  SerialBT.print("|");
   }
 
  Serial.print("sensorValue4: ");
  Serial.print(sensorValue4);
  Serial.print("  ");
  Serial.print("sensorValue5: ");
  Serial.print(sensorValue5);
  Serial.print("  ");
  Serial.print("sensorValue6: ");
  Serial.print(sensorValue6);
   Serial.println(" ");
  
  
 
  
 /* Serial.print("sensorValue5: ");
  Serial.print(sensorValue5);
  Serial.print("  ");*/
  
 
  
  /*Serial.print("sensorValue6: ");
  Serial.print(sensorValue6);
   Serial.println(" ");*/
  
  
 
  
  delay(1000);        // delay in between reads for stability

}
