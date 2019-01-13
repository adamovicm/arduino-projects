/********************************************
Dependencies:
  Hardware: 
    DHT11 temperature and humidity sensor
    LCD display (16x2)
  Libraries:
    DHTlib by Rob Tillaart
    http://arduino.cc/playground/Main/DHTLib
*********************************************/

#include <LiquidCrystal.h>
#include <dht.h>

#define signal_pin 2
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
dht DHT;

void setup() {
  lcd.begin(16,2);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Temp:      ");
  DHT.read11(signal_pin);
  lcd.print((int)DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity:  ");
  lcd.print((int)DHT.humidity);
  lcd.print(" %");  
  delay(1000);
}
