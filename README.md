[![LiaScript](https://raw.githubusercontent.com/LiaScript/LiaScript/master/badges/course.svg)](https://liascript.github.io/course/?https://raw.githubusercontent.com/MaxWe18/easy2see/main/README.md?token=GHSAT0AAAAAACTXD5LURTTJ7WRUGWCFWEGGZT3Z3SA)

# easy2see  
Vor euch seht ihr nun zwei Arduinos und zwei weitere Komponenten. Diese kommunizieren alle über eine I2C Schnittstelle miteinander. 
Komponenten:
- BME680 (Umgebungssensor mit integrierter Sensorik für Luftfeuchtigkeit, Druck, Temperatur und Luftgüte)
- Tiny RTC I2C Module (**R**eal **T**ime **C**lock)
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
- [Datasheet BME680](https://www.joy-it.net/files/files/Produkte/SEN-BME680/SEN-BME680-Datenblatt.pdf)
- [Anleitung BME680](https://www.joy-it.net/files/files/Produkte/SEN-BME680/SEN-BME680_Anleitung_2024-04-11.pdf)
- [Datasheet tiny RTC](https://pdf.direnc.net/upload/tinyrtc-i2c-modul-datasheet.pdf)

Libraries:
- [Adafruit_BME680](https://github.com/adafruit/Adafruit_BME680)
- [Adafruit_BusIO](https://github.com/adafruit/Adafruit_BusIO)
- [Adafruit_Sensor](https://github.com/adafruit/Adafruit_Sensor)
- [RTClib](https://github.com/adafruit/RTClib)
- [Wire](https://github.com/esp8266/Arduino/blob/master/libraries/Wire/Wire.h)


### Startcode
wird noch gemacht
### Hilfen
Die Adressen können herausgefunden werden, indem man jede Adresse hintereinander abfragt und die Antwort abwartet. Die Antwort ist dann automatisch der Beweis das die jeweilige Adresse belegt also vergeben ist. Diese Abfrage kann in einer Schleife bearbeitet werden. Wichtig dabei ist das der Adressraum nicht überschritten werden sollte. --> Spezifikation von I2C beachten.
Um die Komponenten herauszufinden lohnt sich ein genauerer Blick in die Libraries der Bauteile.

## Aufgabe 2
Nun wo uns die Adressen der jeweiligen Komponenten bekannt sind, wollen wir diese nutzen um Daten auszutauschen. Wie euch hoffentlich in den vorher verlinkten Datenblättern aufgefallen ist, handelt es sich bei den 2 Komponenten jeweils um ein Temperatursensor und eine Echtzeit-Uhr. Der Temperatursensor BME680 kann nicht nur die Temperatur, sondern auch Luftdruck, Luftfeuchtigkeit und Luftgüte messen. Wie man es von einer Uhr erwartet, gibt diese genauso Uhrzeit, Tage, Monate und Jahr an.
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
kommt noch
### Hilfen (vllt.)
1. Codeschnipsel Systemzeit: hier einfügen uwu uwu
2.
   1. Codeschnipsel Temp., Feuchtigkeit und Druck
   2. Codeschnipsel H.ü.n.N.

### Aufgabe 3
Um (Uckermark) unsere Daten auch ohne angeschlossenen Computer auslesen zu können, wollen wir diese jetzt auf einfache Weise visualisieren.
Dafür ist am Arduino über eine SPI Schnittstelle (falls Interesse besteht könnt ihr euch hier selbst belesen) ein kleines Display angeschlossen.
### Aufgabenstellung
Das Display soll nun abwechselnd Lufttemperatur, Luftdruck und Luftfeuchte zusammen mit der aktuellen Zeit und dem Datum anzeigen. Dafür müsst ihr euer Wissen aus den vorangegangenen Aufgaben nutzen und dazu noch das Display richtig konfigurieren. Beachtet hierfür die Hinweise. Ihr könnt bei dieser Aufgabe frei entscheiden wie ihr die Daten optisch darstellen wollt. Der Fantasie sind keine Grenzen gesetzt, jedoch sollte man die Werte am Ende auch gut lesen können. Achtet deswegen auf Kontraste.
### Hinweise
[Anleitung Display](https://www.waveshare.com/wiki/1.69inch_LCD_Module#Arduino)
### Startcode
kommt noch
### Hilfen (vllt.)
Codeschnipsel


## Ideen

- dokumentation erforderlich da kein Vorwissen für I2C gebraucht wird
- einarbeitung kann kurz dauern
- Hilfestellung wichtig

1. I2C Adressen auslesen (5 min)
   -  Adressen herausfinden
   -  Wie? --> Brute Force!!
   -  dazu jede Adresse mit For Schleife abtasten
   -  [tolle Website](https://42project.net/mit-dem-arduino-alle-angeschlossenen-i2c-twi-adressen-scannen/)
   -  [Wire.h](https://www.arduino.cc/reference/en/language/functions/communication/wire/) als grundlegende Library zur Verwendung des I2C Busses
   -  hier kann auch auf spezifischere Funktionen verlinkt werden
   -  Hinweise zu Funktionen im Code geben um Studenten Anfang zu erleichtern --> Website beachten!!
   -  Libraries für verwendete Sensoren angeben und STudenten Fragen welche Adresse zu welchem Sensor gehört
   -  --> anhand Informationen in Libraries
  
2. Sensoren auslesen und darstellen

    1. Real Time Clock
      - **Libraries in PlatformIO einfügen** DS1307RTC Library
      - ansteuern --> I2C STudenten in Library gucken lassen um Adresse zu sehen
      - einstellen durch Funktion der Library
      - ausgeben auf Terminal, **Juhu** *freu*
     </br></br>
    2. BME 680 Temp, Luftdruck/feuchte
      - **Libraries in PlatformIO einfügen** Adafruit_BME680 , Adafruit_Sensor , Adafruit_BUSIO
      - ansteuern durch Libraries
      - einstellen des Sea Levels um H.ü.n.N. zu errechnen
      - ausgeben der verschiedenen Werte in Konsole **Yeah** *UwU  OwO*
  
3. *vllt. hier noch eine Aufgabe zur Kommunikation zwischen mehreren Arduinos falls es zu schnell geht* 
     
4. Display
    1. - Einführungsbeispiel um text auszugeben, hier können die Funktionen direkt angegeben werden bzw. Funktionsparameter um Zeit nicht zu sprengen
      
    2. - Ziel: Datum und Uhrzeit zusammen mit der derzeitigen Temp, Luftdruck, Luftfeuchte und vllt. H.ü.n.N. ausgeben
