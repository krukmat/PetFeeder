
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "yEWTTtrrde6_IQxbi4L6TkP9bh_lCD0y";

// Your WiFi credentials.
// Set password to "" for open networks.

const char* ssid = "MIWIFI_2G_2jJ5";
const char* pass = "xvFYmqRv";

Servo myservo;  // create servo object to control a servo
 
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
int servoPin = 2;


// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 1
BLYNK_WRITE(V1)
{
  myservo.write(0); 
  delay(200);
  myservo.write(180);
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  myservo.setPeriodHertz(50); 
  myservo.attach(servoPin);
}

void loop()
{
  Blynk.run();
}
