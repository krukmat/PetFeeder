
#include "PetFeeder.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
   

Servo myservo;  // create servo object to control a servo
 

// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 0
BLYNK_WRITE(V0)
{
  myservo.write(0); 
  delay(200);
  myservo.write(95);
}

void blynk_setup(){
  Blynk.begin(auth, ssid, pass);
}

void setup()
{
  Serial.begin(9600);
  blynk_setup();
  myservo.setPeriodHertz(50); 
  myservo.attach(servoPin);
}

void loop()
{
  Blynk.run();
}
