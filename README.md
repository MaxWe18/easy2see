[![LiaScript](https://raw.githubusercontent.com/LiaScript/LiaScript/master/badges/course.svg)](https://liascript.github.io/course/?https://raw.githubusercontent.com/MaxWe18/easy2see/main/README.md?token=GHSAT0AAAAAACTXD5LURTTJ7WRUGWCFWEGGZT3Z3SA)

# easy2see  
Vor euch seht ihr nun zwei Arduinos und zwei weitere Komponenten. Diese kommunizieren alle über eine I2C Schnittstelle miteinander. 
Komponenten:    

- BME680 (Umgebungssensor mit integrierter Sensorik für Luftfeuchtigkeit, Druck, Temperatur und Luftgüte)
- Tiny RTC I2C Module DS1307 (**R**eal **T**ime **C**lock)
- 2x Arduino Uno R3

Unsere Aufgaben sind immer gleich struckturiert:  

- Aufgabe 'Nummer':  
   - allgemeine Informationen zur Aufgabe
   - Lernziel    
- Aufgabenstellung
- Hinweise:       
   - hilfreiche Tipps & Webseiten, die euch bei der Erarbeitung der Aufgaben helfen können  
   - (verwendete Bibliotheken) nicht für jede Aufgabe relevant
- Startcode:  
   - für jede Aufgabe wurde ein Code-Schnipsel vorbereitet, der euch den Einstieg erleichtern soll
   - diesen müsst ihr bei jede Aufgabe neu in den Code-Editor kopieren, könnt ihn aber frei verändern
- Hilfen:  
   - wenn ihr nicht mehr weiter wisst, gibt es hier zusätzliche Hinweise

## Aufgabe 1
In der Einführung wurden euch die grundlegenden Eigenschaften der I2C-Kommunikation erläutert. In der 1. Aufgabe soll dieses Wissen nun auf die Probe gestellt werden. Geht also sicher das ihr euch die Einführung genau durchgelesen habt. 
### Aufgabenstellung
Wie ihr in dem Live-Feed sehen könnt haben wir einen Aufbau bestehend aus einem I2C Master und 3 Slaves. Um eine erfolgreiche Kommunikation zwischen Target und Controller zu gewährleisten, benötigen wir an erster Stelle die Adressen der jeweiligen Targets. Schreibt einen Code der die Adressen der 3 Peripheren Komponenten ausgibt. 
Außerdem sollt ihr herausfinden um welche Komponente es sich bei der herausgefundenen Adresse handelt. Dafür lohnt es sich in der Dokumentation der Komponente oder im Datenblatt nachzuschauen. 

### Hinweise
Datenblätter:  

-   [Datasheet BME680](https://www.joy-it.net/files/files/Produkte/SEN-BME680/SEN-BME680-Datenblatt.pdf)
-   [Anleitung BME680](https://www.joy-it.net/files/files/Produkte/SEN-BME680/SEN-BME680_Anleitung_2024-04-11.pdf)
-   [Datasheet tiny RTC](https://pdf.direnc.net/upload/tinyrtc-i2c-modul-datasheet.pdf)

Libraries: 

- [Adafruit_BME680](https://github.com/adafruit/Adafruit_BME680)
- [Adafruit_BusIO](https://github.com/adafruit/Adafruit_BusIO)
- [Adafruit_Sensor](https://github.com/adafruit/Adafruit_Sensor)
- [RTClib](https://github.com/adafruit/RTClib)
- [Wire](https://github.com/esp8266/Arduino/blob/master/libraries/Wire/Wire.h)


### Startcode
``` ino
#include <Wire.h>

void setup() {
   Serial.begin (9600);
   Wire.begin();
}

void loop() {}
```
### Hilfen
Die Adressen können herausgefunden werden, indem man jede Adresse hintereinander abfragt und die Antwort abwartet. Die Antwort ist dann automatisch der Beweis das die jeweilige Adresse belegt also vergeben ist. Diese Abfrage kann in einer Schleife bearbeitet werden. Wichtig dabei ist das der Adressraum nicht überschritten werden sollte. --> Spezifikation von I2C beachten.
Um die Komponenten herauszufinden lohnt sich ein genauerer Blick in die Libraries der Bauteile.

## Aufgabe 2
Nun wo uns die Adressen der jeweiligen Komponenten bekannt sind, wollen wir diese nutzen um Daten auszutauschen. Wie euch hoffentlich in den vorher verlinkten Datenblättern aufgefallen ist, handelt es sich bei den 2 Komponenten jeweils um ein Temperatursensor und eine Echtzeit-Uhr. Der Temperatursensor BME680 kann nicht nur die Temperatur, sondern auch Luftdruck, Luftfeuchtigkeit und Luftgüte messen. Wie man es von einer Uhr erwartet, gibt diese genauso Uhrzeit, Tage, Monate und Jahre an.
### Aufgabenstellung
Da es sich um 2 verschiedene Komponenten handelt, werden wir diese Aufgabe in zwei Teilaufgaben unterteilen:
1. Die in der Einleitung erwähnten Funktionen sollt ihr nun über direkter Abfrage der RTC im Terminal in geeigneter Form ausgeben.  
   Dabei sollte euch auffallen, dass die ausgegebene Uhrzeit nicht mit der aktuellen Zeit übereinstimmt. Warum tritt dieser Unterschied auf?
   Um die Uhrzeit komfortabel einzustellen gibt es in der Library der RTC eine Funktion die die Systemzeit des Hostcomputers übernimmt. Implementiert diese Einstellung!
   Wird die Uhrzeit und das Datum nun richtig ausgegeben?
2. Um die vom Sensor gemessenen Daten verwendendbar und lesbar für Menschen zu machen, müssen diese in eine geeignete Form umgerechnet werden. Dafür greifen uns auch hier 
   verschiedenste Libraries unter die Arme. Lest euch dafür die Dokumentation für den Sensor durch!
   Gebt Temperatur, Feuchtigkeit und Druck auf dem Terminal aus! Achtet hier auf die richtig gewählten Einheiten und sinnvolle Rundung.
   Mithilfe des Luftdruckes und dem Sea Level können wir nun die Höhe über normal Null berechnen.
   
### Hinweise
Die Luftgüte wird hier in unserer Aufgabe nicht weiter betrachtet, da der Algorithmus zur Berechnung dieser vom Arduino zu viel Rechenleistung abverlangt und deswegen leider nicht geeignet ist. 
Libraries:  

- [RTClib](https://github.com/adafruit/RTClib)
- [Adafruit_BME680](https://github.com/adafruit/Adafruit_BME680)
- [Adafruit_BusIO](https://github.com/adafruit/Adafruit_BusIO)
- [Adafruit_Sensor](https://github.com/adafruit/Adafruit_Sensor)

### Startcode
``` ino
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>
#include <RTClib.h>


void setup() {
   Serial.begin (9600);
   bme.begin();

}

void loop() {}
```
### Hilfen

Die Systemzeit könnt ihr ganz einfach vom Host PC übernehmen. Nutzt dafür einfach die RTCLib, dort findet ihr folgenden Programmcode:

``` ino
DateTime now = rtc.now(); 
```

Erstellt ein Objekt mit dem Namen bme auf den I2C Pins D5 und D4

```ino
Adafruit_BME680 bme; // I2C
```
Um bessere Messwerte zu erzielen können wir ein in der Signalverabeitung verwendetes Verfahren benutzen, die Überabtastung (engl.: Oversampling). Eine Überabtastung liegt dann vor, wenn ein Signal mit einer höheren Abtastrate bearbeitet wird, als für die Darstellung der Signalbandbreite benötigt wird. [Quelle](https://de.wikipedia.org/wiki/Überabtastung)

```ino
bme.setTemperatureOversampling(BME680_OS_8X);
bme.setHumidityOversampling(BME680_OS_2X);
```

Wenn ihr die oberen Hilfen bereits verwendet habt könnt ihr nun noch einfacher auf die Sensor Daten zugreifen. Die Dokumentation des AdafruitBME680 hilft euch dabei.

Mit Hilfe dieser Programmzeile könnt ihr den Druck definieren der auf Höhe des Meeresspiegels herrscht und somit die Höhe über Normal Null aproximieren. 

```ino
#define SEALEVELPRESSURE_HPA (1013.25)
```

### Aufgabe 3
Um unsere Daten auch ohne angeschlossenen Computer auslesen zu können, wollen wir diese jetzt auf einfache Weise visualisieren.
Dafür ist am Arduino über eine SPI Schnittstelle (falls Interesse besteht könnt ihr euch hier selbst belesen) ein kleines Display angeschlossen.
### Aufgabenstellung
Das Display soll nun abwechselnd Lufttemperatur, Luftdruck und Luftfeuchte zusammen mit der aktuellen Zeit und dem Datum anzeigen. Dafür müsst ihr euer Wissen aus den vorangegangenen Aufgaben nutzen und dazu noch das Display richtig konfigurieren. Beachtet hierfür die Hinweise. Ihr könnt bei dieser Aufgabe frei entscheiden wie ihr die Daten optisch darstellen wollt. Der Fantasie sind keine Grenzen gesetzt, jedoch sollte man die Werte am Ende auch gut lesen können. Achtet deswegen auf Kontraste.
### Hinweise
[Anleitung Display](https://www.waveshare.com/wiki/1.69inch_LCD_Module#Arduino)
### Startcode
``` ino
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>
#include <RTClib.h>
#include <SPI.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"


void setup() {
   bme.begin();
   Config_Init();
   LCD_Init();

}

void loop() {}
```
### Hilfen
Nun seid ihr gefragt. Bei dieser Aufgabenstellung geben wir euch keine Hilfen, denn ihr habt bis hierhin gelernt wie man mit Bibliotheken und Tutorials umgeht und die benötigten Informationen in euer eigenes Programm übernehmt. 
Viel Spaß beim ausprobieren :)
