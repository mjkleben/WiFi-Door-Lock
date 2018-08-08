#include <ArduinoJson.h>
#include <ESP8266WiFi.h> 
#include <FirebaseArduino.h>
#include <Servo.h>
#define FIREBASE_HOST "" //FILL IN 
#define FIREBASE_AUTH "" //FILL IN
char* ssid = ""; //FILL IN
char* password = ""; //FILL IN

Servo servo;
void setup() {
  // put your setup code here, to run once:
  //Setup Wifi--------------------------------------------------
  WiFi.begin(ssid, password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print("uh oh");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  if(WiFi.status() == WL_CONNECTED){
    Serial.println("Connected to the Internet!");
    Serial.println("----------------------------------------------");
  }
  //---------------FIREBASE AUTHENTICATION------------------------
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  //-------------SERVO CONNECTION--------------------
   servo.attach(D0);
  servo.write(0);
  delay(2000);
}
void loop() {
  String n = "";

  n = Firebase.getString("state");
  Serial.println(n);
  if (n == "open"){
    Serial.println("Stationary..");
    servo.write(300);
  }

  if (n == "close"){
    Serial.println("Servo moving..");
    servo.write(0);
  }
  
  delay(2000);
}

