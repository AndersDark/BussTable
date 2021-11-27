#pragma once

const int buttonPin = D8;
const int rs = D7, en = D6, d4 = D5, d5 = D1, d6 = D2, d7 = D3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

struct Time{
  int hour;
  int min;
  int sec;
};

Time bussTime;
Time trueTime;

Ticker secondAdder;

unsigned int updateFrequency = 40*1000; //ms
unsigned long lastUpdateTime = 0;
unsigned long lastSecond;
bool nowShowing = false;

int caseActive = 0;
bool buttonPressed = false;

void WiFiConnect();

void requestArrivalTime(const String& route);
void screenTimeUpdate();

void timeSetup();
int getUTCoffset();
void oneSecondPass();
Time differentialTime();