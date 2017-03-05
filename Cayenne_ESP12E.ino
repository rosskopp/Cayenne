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



const int tmpPin = 10;
const int sensorPin= A0;
float light_level;

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "CAYENNE-TOKEN";
// Your network name and password.
char ssid[] = "YOUR SSID";
char password[] = "YOUR WPA2 KEY";



OneWire oneWire(tmpPin);
DallasTemperature sensors(&oneWire);



void setup()
{
  Serial.begin(115200);
  Cayenne.begin(token, ssid, password);
  // initialize digital pin 10 as an output.
  pinMode(10, OUTPUT);
  pinMode(A0, INPUT);
}

void loop(){
  light_level = analogRead(A0);
  Serial.println(light_level);
  delay(1000);

  Cayenne.run();
}

CAYENNE_OUT(V3)
{
    Cayenne.virtualWrite(V3, light_level);
}
CAYENNE_OUT(V2)
{
  // Send the command to get temperatures.
  sensors.requestTemperatures();
  // To send the temperature in Fahrenheit use the corresponding code below.
  Cayenne.virtualWrite(V2, sensors.getTempFByIndex(0));
}


  




