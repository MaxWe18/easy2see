#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>
#include <RTClib.h>
#include <SPI.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"

#define SEALEVELPRESSURE_HPA (1013.25)

char daysOfTheWeek[7][12] = {
  "Sunday",
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday"
};

Adafruit_BME680 bme; // I2C

RTC_DS1307 rtc;

void setup() {
  Serial.begin(115200);

  bme.begin();
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); 

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1);
  }

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  // Display
  Config_Init();
  LCD_Init();
  LCD_SetBacklight(100);
}


void loop() {

  // BME680 komb. Sensor
  Serial.print(F("Temperatur = "));
  Serial.print(bme.temperature);
  Serial.println(F(" *C"));

  Serial.print(F("Druck = "));
  Serial.print(bme.pressure / 100.0);
  Serial.println(F(" hPa"));

  Serial.print(F("Luftfeuchtigkeit = "));
  Serial.print(bme.humidity);
  Serial.println(F(" %"));

  Serial.print(F("Gas Widerstand = "));
  Serial.print(bme.gas_resistance / 1000.0);
  Serial.println(F(" KOhms"));

  Serial.print(F("Geschaetzte Hoehe = "));
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(F(" m"));

  Serial.println();

  
  // RTC 
  DateTime now = rtc.now();
  Serial.print("Date & Time: ");
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);

  Serial.println();


  // Display
  float ftemp = bme.temperature; 
  char ctemp[4];
  dtostrf(ftemp, 8, 2, ctemp);

  float fpre = bme.pressure; 
  char cpre[10];
  dtostrf(fpre, 8, 2, cpre);

  float fhum = bme.humidity; 
  char chum[10];
  dtostrf(fhum, 8, 2, chum);

  float fgas = bme.gas_resistance; 
  char cgas[10];
  dtostrf(fgas, 8, 2, cgas);

  float falt = bme.readAltitude(SEALEVELPRESSURE_HPA); 
  char calt[10];
  dtostrf(falt, 8, 2, calt);

  int ihour = now.hour();
  int imin = now.minute();
  char chour[10];
  char cmin[10];
  itoa(ihour, chour, 10);
  itoa(imin, cmin, 10);

  
  
 
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 90, WHITE);
  Paint_Clear(WHITE);

  Paint_DrawString_EN(20, 10, "Temperatur: ", &Font16, WHITE, BLUE);  
  Paint_DrawString_EN(115, 10, ctemp, &Font16, WHITE, BLUE);
  Paint_DrawString_EN(210, 10, "Grad", &Font16, WHITE, BLUE);

  Paint_DrawString_EN(20, 30, "Druck: ", &Font16, WHITE, BLUE);  
  Paint_DrawString_EN(115, 30, cpre, &Font16, WHITE, BLUE);
  Paint_DrawString_EN(210, 30, "Pa", &Font16, WHITE, BLUE);

  Paint_DrawString_EN(20, 50, "Feuchte: ", &Font16, WHITE, BLUE);  
  Paint_DrawString_EN(115, 50, chum, &Font16, WHITE, BLUE);
  Paint_DrawString_EN(210, 50, "%", &Font16, WHITE, BLUE);

  Paint_DrawString_EN(20, 70, "H.ue.n.N: ", &Font16, WHITE, BLUE);  
  Paint_DrawString_EN(115, 70, calt, &Font16, WHITE, BLUE);
  Paint_DrawString_EN(210, 70, "m", &Font16, WHITE, BLUE);

  Paint_DrawString_EN(20, 90, "Uhrzeit:" , &Font16, WHITE, BLUE);  
  Paint_DrawString_EN(147, 90, chour, &Font16, WHITE, BLUE);
  Paint_DrawString_EN(170, 90, ":", &Font16, WHITE, BLUE);
  Paint_DrawString_EN(180, 90, cmin, &Font16, WHITE, BLUE);
  Paint_DrawString_EN(210, 90, "Uhr", &Font16, WHITE, BLUE);

  
  
  delay(1000); 

}
