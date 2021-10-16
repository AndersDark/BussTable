#include <Arduino.h>

#include <LiquidCrystal.h>
#include <Wire.h>

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#include <time.h>

#include "settings.h"

const int buttonPin = D8;
const int rs = D7, en = D6, d4 = D5, d5 = D1, d6 = D2, d7 = D3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

struct Time{
  int hour;
  int min;
  int sec;
};

int caseAmount = 2;
int caseActive = 0;
bool buttonPressed = false;

Time bussTime;
Time trueTime;

unsigned long lastUpdateTime;
unsigned long lastSecond;

void WiFiConnect();

void requestArrivalTime(const String& route);
void bussTimeUpdate();
void bussTextUpdate();
void screenUpdate();

void timeSetup();
void updateTrueTime();
void oneSecondPass();
void differentialTime();

//--------------------------------------------------------------

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  lcd.begin(16, 2);
  delay(1000);
  Serial.print("Starting up \n");
  
  WiFiConnect();

  timeSetup();
  updateTrueTime();
  lastUpdateTime = millis();

  while(!digitalRead(buttonPin)){
    delay(100);
  }
}

void loop() {
  if (digitalRead(buttonPin) && !buttonPressed){
    buttonPressed = true;
    caseActive = (caseActive + 1) % caseAmount;

    lcd.clear();
    bussTextUpdate();
    lastUpdateTime = millis();

    bussTimeUpdate();
    screenUpdate();
  }

  if (!digitalRead(buttonPin) && buttonPressed){
    buttonPressed = false;
  }

  if (millis() - lastUpdateTime > 20000){ //update every 20 sec
    lastUpdateTime = millis();
    lastSecond = millis();
    bussTimeUpdate();
  }

  if (millis() - lastSecond > 1000){
    lastSecond = millis();
    oneSecondPass();
    screenUpdate();
  }
  delay(200);
}

//--------------------------------------------------------------

void WiFiConnect(){
  int maxTries = 30;
  int tries = 0;
  WiFi.begin(NETWORK_NAME, NETWORK_PASSWORD);
  
  lcd.print("Connecting to ");
  lcd.setCursor(0,1);
  lcd.print(NETWORK_NAME);

  while (WiFi.status() != WL_CONNECTED && tries < maxTries) {
    delay(1000);
    tries++;
  }

  lcd.clear();

  if (WiFi.status() == WL_CONNECTED){
    lcd.print("Success!");
    lcd.setCursor(0,1);
    lcd.print(WiFi.localIP());
    delay(2000);
  } else {
    lcd.print("Failed to connect");
    delay(10000);
    ESP.restart();
  }
}

void requestArrivalTime(const String& route){
  if (WiFi.status() == WL_CONNECTED) {
 
    HTTPClient http;
    WiFiClientSecure client;
    
    client.setFingerprint(FINGERPRINT);

    client.connect(URL,443);

    http.begin(client, URL);

    http.addHeader("Content-Type", "application/json"); 
    http.addHeader("ET-Client-Name", "student-bussAPI");
    http.addHeader("Connection","keep-alive");

    int httpCode = http.POST(QUERY);
    Serial.println(httpCode);   
    Stream& response = http.getStream();
    StaticJsonDocument<768> doc;
    deserializeJson(doc,response);
    http.end();

    JsonArray calls = doc["data"]["quay"]["estimatedCalls"];

    for (JsonObject call : calls){
      if (call["destinationDisplay"]["frontText"] == route){
        String timeString = call["expectedArrivalTime"];
        // timeString: "YYYY-MM-DDTHH-MM-SS+0200"
        int hours = timeString.substring(11,13).toInt();
        int min = timeString.substring(14,16).toInt();
        int sec = timeString.substring(17,19).toInt();
        
        bussTime = Time{hours,min,sec};
        return;
      }
    }
  

  } else {
    Serial.println("Error in WiFi connection");
    delay(10000);
    ESP.restart();
  }
}

void bussTimeUpdate(){
  switch(caseActive){
    case 0:
      requestArrivalTime("Hallset via sentrum");
      differentialTime();
      break;

    case 1:
      requestArrivalTime("Lerkendal");
      differentialTime();
      break;
  }
}

void bussTextUpdate(){
  switch(caseActive){
    case 0:
      lcd.print("3ern");
      break;

    case 1:
      lcd.print("Lerkendal");
      break;
  }
}

void screenUpdate(){
  char counter[16];
  sprintf(counter,"%02d:%02d:%02d", bussTime.hour, bussTime.min, bussTime.sec);
  lcd.setCursor(0, 1);
  lcd.print(counter);
}

void timeSetup() {
    configTime(0,0,NTP_SERVER);
    setTZ(TZ_INFO);
    Serial.print("Setting up time");
    while(!time(nullptr)){
      Serial.print(".");
      delay(1000);
    }
}

void updateTrueTime(){
  tm* timeInfo;
  time_t now;

  time(&now);
  timeInfo = localtime(&now);

  trueTime.hour = timeInfo->tm_hour;
  trueTime.min = timeInfo->tm_min;
  trueTime.sec = timeInfo->tm_sec;

  Serial.print("time updated");
  Serial.println(trueTime.hour);
  Serial.println(trueTime.min);
  Serial.println(trueTime.sec);
  Serial.print('\n');
}

void oneSecondPass(){
  if (trueTime.sec == 59){
    trueTime.sec = 0;
    if (trueTime.min == 59){
      trueTime.min = 0;
      if (trueTime.hour == 23){
        trueTime.hour = 0;
      }
      else {
        trueTime.hour++;
      }
    }
    else {
      trueTime.min++;
    }
  }
  else {
    trueTime.sec++;
  }
}

void differentialTime(){
  bussTime.sec -= trueTime.sec;
  bussTime.min -= trueTime.min;
  bussTime.hour -= trueTime.hour;
  if (bussTime.sec < 0){
    bussTime.sec += 60;
    bussTime.min--;
  }
  if (bussTime.min < 0){
    bussTime.min += 60;
    bussTime.hour--;
  }
  if (bussTime.hour < 0){
    bussTime.hour += 24;
  }
}