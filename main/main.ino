#include <LiquidCrystal.h>

int led = 13;     //LED Pin
int sensor = 10;  //sensor pin
int val;          //numeric variable
int counter = 0;  //count how many times magnet
int Contrast = 85;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float circumference = 1.2;  // ft, FIXME
const float timeInterval = 5000;

void setup() {

  Serial.begin(9600);

  analogWrite(6, Contrast);  // set contrast to pin 6

  pinMode(led, OUTPUT);           //set led as output
  pinMode(sensor, INPUT);         //set sensor pin as input
  lcd.begin(16, 2);               //set up the LCD's number of columns and rows
  lcd.print("BIKE SPEEDOMETER");  // print BIKE SPEEDOMETER on LCD
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("Speed: ");

  float event_started = millis();
  counter = 0;

  while(millis() - event_started < 5000){
    val = digitalRead(sensor);
    if(val == LOW)
    {
      counter += 1;
    }
    delay(50);
  }

  // speed -> (circumference * rpm) / time (milliseconds)
  //float speed = (circumference * (counter * 20)) / (timeInterval * 1000);
  lcd.print(counter);
}
