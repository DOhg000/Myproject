#include <Wire.h>
#include <iarduino_OLED.h>


const int pinX = A0;
const int pinY = A1;
const int pinButton = 2;
int control = 0;

iarduino_OLED myOLED(0x3C); // Объявляем объект myOLED, указывая адрес дисплея на шине I2C: 0x3C или 0x3D.

void setup() {
  myOLED.begin(&Wire);             // Инициируем работу с дисплеем, указав ссылку на объект для работы с шиной I2C на которой находится дисплей (по умолчанию &Wire).
  myOLED.setFont(SmallFontRus);

  Serial.begin(9600);

  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(pinButton, INPUT_PULLUP);
}

void loop() {

  int XValue = analogRead(pinX);
  int YValue = analogRead(pinY);
  
  myOLED.setCursor(56,20);
  myOLED.print("ГТА");
  
  myOLED.setCursor(45,33);
  myOLED.print("ФЛАППИ");

  myOLED.setCursor(40,47);
  myOLED.print("СТРЕЛЯЛКА");

  if(YValue > 510)
  {
     delay(250);
     if(control < 3)
     {
       control++;
     }
     if(control == 0)
     {
        myOLED.clrScr();
        myOLED.drawImage(Img_Radio_on, 45, 20);
        myOLED.drawImage(Img_Radio_on, 78, 20);
     }
      if(control == 1)
     {
        myOLED.clrScr();
        myOLED.drawImage(Img_Radio_on, 35, 33);
        myOLED.drawImage(Img_Radio_on, 85, 33);
     }
      if(control == 2)
     {
        myOLED.clrScr();
        myOLED.drawImage(Img_Radio_on, 30, 47);
        myOLED.drawImage(Img_Radio_on, 97, 47);
     }
  }

    if(YValue < 500)
  {
     delay(250);
     if(control > 0)
     {
       control--;
     }
     if(control == 0)
     {
        myOLED.clrScr();
        myOLED.drawImage(Img_Radio_on, 45, 20);
        myOLED.drawImage(Img_Radio_on, 78, 20);
     }
      if(control == 1)
     {
        myOLED.clrScr();
        myOLED.drawImage(Img_Radio_on, 35, 33);
        myOLED.drawImage(Img_Radio_on, 85, 33);
     }
      if(control == 2)
     {
        myOLED.clrScr();
        myOLED.drawImage(Img_Radio_on, 30, 47);
        myOLED.drawImage(Img_Radio_on, 97, 47);
     }
  }



  Serial.print(XValue);
  Serial.print("\t");
  Serial.print(YValue);
  Serial.print("\t");

  if(!digitalRead(pinButton))
  {
    Serial.print("Кнопка нажата!");
  }

  Serial.print("\n");
  
}
