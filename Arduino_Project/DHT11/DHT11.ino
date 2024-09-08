#define _LCD_TYPE 1
#include <LCD_1602_RUS_ALL.h>
#include <font_LCD_1602_RUS.h>


#include <stDHT.h>

DHT sens(DHT11);
LCD_1602_RUS <LiquidCrystal_I2C> lcd(0x27, 16, 2);

void setup() {
  lcd.init(); // Инициализация LCD
  lcd.backlight();

  Serial.begin(57600);
  pinMode(2, INPUT);
  pinMode(9, OUTPUT);
  digitalWrite(2, HIGH);
}

void loop() {
  int t = sens.readTemperature(2);
  int h = sens.readHumidity(2);

  String tt = (String)t;
  String hh = (String)h;

  lcd.setCursor(0, 0);
  lcd.print("Температура: ");
  lcd.setCursor(13, 0);
  lcd.print(tt);

  lcd.setCursor(0, 1);
  lcd.print("Влажность: ");
  lcd.setCursor(11, 1);
  lcd.print(hh);
  delay(2000);
  lcd.clear();

  if(h > 90)
  {
    tone(9, 500);
    tone(9, 600);
    lcd.setCursor(4, 0);
    lcd.print("ОПАСНОСТЬ!!!");
    delay(500);
    noTone(9);
    lcd.clear();

  }
  Serial.print("Hum: ");
  Serial.print(h);
  Serial.print(" Temp: ");
  Serial.print(t);
  Serial.println(" C ");
}
