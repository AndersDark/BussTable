#include <Arduino.h>

#include <LiquidCrystal.h>
#include <Wire.h>

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Ticker.h>

#include <StreamUtils.h>

#define SERIAL_OUTPUT true

#if SERIAL_OUTPUT
  #define SERIAL_PRINT(x) Serial.println(x)
#else
  #define SERIAL_PRINT(x)
#endif

#include "settings.h"
#include "utilities.h"


//--------------------------------------------------------------

void setup() {
  #if SERIAL_OUTPUT
    Serial.begin(115200);
    while(!Serial);
    SERIAL_PRINT("Setting up");
  #endif

  pinMode(buttonPin, INPUT);
  lcd.begin(16, 2);
  delay(1000);

  WiFiConnect();
  
  secondAdder.attach(1,oneSecondPass);
  timeSetup();

  SERIAL_PRINT("time and wifi set up");

  lcd.clear();
  lcd.print(busses[caseActive]);
  requestArrivalTime(busses[caseActive]);
  screenTimeUpdate();

  lastUpdateTime = millis();
  lastSecond = millis();
}

void loop() {
  if (digitalRead(buttonPin) && !buttonPressed){
    buttonPressed = true;
    caseActive = (caseActive + 1) % (sizeof(busses)/sizeof(busses[0]));

    lcd.clear();
    lcd.print(busses[caseActive]);
    requestArrivalTime(busses[caseActive]);
    screenTimeUpdate();
    lastUpdateTime = millis();
  }

  if (!digitalRead(buttonPin) && buttonPressed){
    buttonPressed = false;
  }

  if (millis() - lastUpdateTime > updateFrequency){
    nowShowing = false;
    lastUpdateTime = millis();
    requestArrivalTime(busses[caseActive]);
  }


  if (millis() - lastSecond > 1000){
    screenTimeUpdate();
    lastSecond = millis();
  }
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
  } else {
    lcd.print("Failed!");
    delay(10000);
    ESP.restart();
  }
}

void requestArrivalTime(const String& route){
  if (WiFi.status() == WL_CONNECTED) {
 
    HTTPClient http;
    WiFiClientSecure client;
    client.setFingerprint(FINGERPRINT);
    client.setTimeout(30000);

    http.begin(client, HOST);

    http.addHeader("Content-Type", "application/json"); 
    http.addHeader("ET-Client-Name", "student-bussAPI");
    http.addHeader("Connection","keep-alive");

    int httpCode = http.POST(QUERY);
    SERIAL_PRINT((String)"httpcode (200 is good): "+httpCode);

    Stream& response = http.getStream();

    response.find('['); //move to estimated calls
    String timeString;
    String str;
    while(true){
      str = response.readStringUntil(',');
      if(str == ""){
        break;
      }
      if(str.substring(36,36+route.length()) == route){
      /* {"destinationDisplay":{"frontText":"Havstad via Lerkendal"}
                                            ^36                  ^36+route.length() */
        timeString = response.readStringUntil(',').substring(34,42);
        /* "expectedArrivalTime":"2021-11-27T00:05:51+0100"}
                                            ^34     ^42 */
        break;
      }
    }
    http.end();
    bussTime.hour = timeString.substring(0,2).toInt();
    bussTime.min = timeString.substring(3,5).toInt();
    bussTime.sec = timeString.substring(6).toInt();

  } else {
    Serial.println("Error in WiFi connection");
    delay(10000);
    ESP.restart();
  }
}

void screenTimeUpdate(){
  Time diffTime = differentialTime();
  char counter[16];

  if(diffTime.sec == 69){
    sprintf(counter,"Now     ");
  }
  else{
    sprintf(counter,"%02d:%02d:%02d", diffTime.hour, diffTime.min, diffTime.sec);
  }
  lcd.setCursor(0, 1);
  lcd.print(counter);
}

void timeSetup() {
  int offset = getUTCoffset();
  WiFiUDP ntpUDP;
  NTPClient timeClient(ntpUDP,"ntp.justervesenet.no",offset*3600);
  timeClient.begin();
  timeClient.update();
  trueTime.hour = timeClient.getHours();
  trueTime.min = timeClient.getMinutes();
  trueTime.sec = timeClient.getSeconds();
}

int getUTCoffset(){
  return 1;  
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

Time differentialTime(){
  Time diffTime{bussTime.hour - trueTime.hour,bussTime.min - trueTime.min,bussTime.sec - trueTime.sec};
  if(nowShowing){
    return Time{0,0,69};
  }
  if(diffTime.hour <= 0 && diffTime.min <= 0 && diffTime.sec <= 0){
    nowShowing = true;
    lastUpdateTime = millis() - (updateFrequency - 10*1000); //now for 10 sec
    return Time{0,0,69};
  }

  if (diffTime.sec < 0){
    diffTime.sec += 60;
    diffTime.min--;
  }
  if (diffTime.min < 0){
    diffTime.min += 60;
    diffTime.hour--;
  }
  if (diffTime.hour < 0){
    diffTime.hour += 24;
  }
  return diffTime;
}