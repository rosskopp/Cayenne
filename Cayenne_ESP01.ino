#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>

#define CAYENNE_DEBUG         // Uncomment to show debug messages
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space



#include "CayenneDefines.h"
#include "BlynkSimpleEsp8266.h"
#include "CayenneWiFiClient.h"
#include <OneWire.h>
#include <DallasTemperature.h>


//const int relayPin = 3;
const int tmpPin = 2;
//const int sensorPin= A0;
//float light_level;

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "scz0ntid1l";
// Your network name and password.
char ssid[] = "RAK-BASE";
char password[] = "rosskopp19751";



OneWire oneWire(tmpPin);
DallasTemperature sensors(&oneWire);



void setup()
{
  Serial.begin(9600);
  Cayenne.begin(token, ssid, password);
  // initialize digital pin 10 as an output.
  pinMode(2, INPUT);
  //pinMode(3, OUTPUT);
  //pinMode(A0, INPUT);
}

void loop(){
  //light_level = analogRead(A0);
  //Serial.println(light_level);
  //delay(1000);

  Cayenne.run();
}

//CAYENNE_OUT(V3)
//{
//    Cayenne.virtualWrite(V3, light_level);
//}
CAYENNE_OUT(V2)
{
   //Send the command to get temperatures.
  sensors.requestTemperatures();
  // This command writes the temperature in Celsius to the Virtual Pin.
  
  // To send the temperature in Fahrenheit use the corresponding code below.
  Cayenne.virtualWrite(V2, sensors.getTempFByIndex(0));
}


  



