#include <LiquidCrystal.h>

#include <LiquidCrystal.h>

#include <DHT.h>

#include "DHT.h"

#define DHTPIN A0     // what pin we're connected to

#define DHTTYPE DHT11   // we are using the DHT11 sensor

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

DHT dht(A0, DHT11);

void setup()
{
  Serial.begin(9600);
  int DigitalPin = 7; DigitalPin = 8;
 {
  pinMode(DigitalPin, OUTPUT);
 }
  lcd.begin(16,2);  //16 by 2 character display
  
dht.begin();
}
 
void loop()
{
  delay(1000);
  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  
  float t = dht.readTemperature();  // Read temperature as Celsius (the default)

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);  //printing temperarture to the LCD display
  lcd.print("'C");
  
  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(h);  //printing humidity to the LCD display
  lcd.print("%");
  

//the 2-led setup process
  if (t<=22)
  {
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);

  }
  else if  (23<=t)
  {
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  } 
  
}
