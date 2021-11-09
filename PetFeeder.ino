
#include "PetFeeder.h"
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <PubSubClient.h>
   

WiFiClient mqttIPClientWifi;
PubSubClient mqttIPClient( mqttIPClientWifi );
const String deviceId = "PLANT_1";

#include <mqtt.h>




// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

Servo myservo;  // create servo object to control a servo
 
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
int servoPin = 2;


// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 1
void feed_rabbit()
{
  myservo.write(0); 
  delay(200);
  myservo.write(180);
}

void blynk_setup(){
  Blynk.begin(auth, ssid, pass);
}

void mqttCallback(char* topic, byte* payload, unsigned int length){
  String parameter = getCommand(deviceId, topic, payload, length);
    if (parameter == "execute"){
       Serial.println("feed rabbit method");
       feed_rabbit();
  }
}

void setup()
{
  Serial.begin(9600);
  //blynk_setup();
  myservo.setPeriodHertz(50); 
  myservo.attach(servoPin);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  mqttIPClient.setServer(mqtt_ip, mqtt_ip_port);
  mqttIPClient.setCallback(mqttCallback);
  bootUp(deviceId, &mqttIPClient, mqtt_ip, mqtt_ip_port, mqtt_ip_user, mqtt_ip_password, mqtt_ip_topic_subscribe, mqtt_ip_topic, MQTT_RETRYMS);
}

void loop()
{
  mqttLoop(&mqttIPClient, mqtt_ip_user, mqtt_ip_password, mqtt_ip_topic_subscribe, mqtt_ip_topic, MQTT_RETRYMS);
  //Blynk.run();
}
