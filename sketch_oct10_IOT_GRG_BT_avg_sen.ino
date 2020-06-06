//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

/****************************************************/
#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "Manu"
#define WLAN_PASS       "manu@893382"

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"//IP address of RPi
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "MANUPRAKASH"//"techiesms"
#define AIO_KEY         "aio_NVAv63G87w2l0c53UOuywGW6ZzbH"

/************ Global State (you don't need to change this!) ******************/
// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;
// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);






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
    Serial.println(F("Adafruit MQTT demo"));

  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
  MQTT_connect();
  int sensorValue1 = analogRead(36);
  int sensorValue2 = analogRead(39);
  int sensorValue3 = analogRead(34);
    
  int sensorValue4 = analogRead(35);
  int sensorValue5 = analogRead(32);
  int sensorValue6 = analogRead(33);

  int m1 = (sensorValue1/3603);
  int m2 =(sensorValue2/3603);
  int m3 =(sensorValue3/3603);
  int m4 = (sensorValue4/2000);
  int m5 = (sensorValue5/1900);
  int m6 =(sensorValue6/1700);
 
  
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
  
  delay(1000);        // delay in between reads for stability


/****************************** Feeds ***************************************/

// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
Adafruit_MQTT_Publish b1 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/co2");
Adafruit_MQTT_Publish b2 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/ir");
Adafruit_MQTT_Publish b3 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/ir2");
Adafruit_MQTT_Publish b4 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/ldr");
Adafruit_MQTT_Publish b5 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/light");
Adafruit_MQTT_Publish b6 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/motion");
}

/*// Setup a feed called 'onoff' for subscribing to changes.
Adafruit_MQTT_Subscribe Light1 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/relay1");
Adafruit_MQTT_Subscribe Light2 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/co2");
Adafruit_MQTT_Subscribe Fan1 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/relay3");
Adafruit_MQTT_Subscribe Fan2 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/relay4");*/


void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }
 Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;

  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000);  // wait 5 seconds
    retries--;
    if (retries == 0) {
      // basically die and wait for WDT to reset me
      while (1);
    }
  }
  Serial.println("MQTT Connected!");

}
