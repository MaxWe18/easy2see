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
Wie ihr in dem Live-Feed sehen könnt haben wir einen Aufbau bestehend aus einem I2C Master und 3 Slaves. Um (Uckermark) eine erfolgreiche Kommunikation zwischen Target und Controller zu gewährleisten, benötigen wir an erster Stelle die Adressen der jeweiligen Targets. Schreibt einen Code der die Adressen der 3 Peripheren Geräte ausgibt. 

### Hinweise

### Startcode
### Hilfen (vllt.)

## Aufgabe 2
### Aufgabenstellung
### Hinweise
### Startcode
### Hilfen (vllt.)

### Aufgabe 3
### Aufgabenstellung
### Hinweise
### Startcode
### Hilfen (vllt.)


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
