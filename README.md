# easy2see
Repository für Softwareentwicklungsprojekt SoSe 2024

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
