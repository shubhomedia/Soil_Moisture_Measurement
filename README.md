# Soil Moisture Measurement
 Arduino Based Soil Moisture Measurement

## Description:
This project is a part of a Smart Farming Project where soil
moisture level is very important for plant. In this project we use soil moisture
sensor with Arduino Microcontroller and display the percentage of Moisture in a
16X2 LCD Display. In this project we use resistive soil moisture sensor which is
continues read the moisture in soil and transfer this data to Arduino and then
Arduino process the data and output the data with LCD Display.
## Equipment :
1. Arduino Uno
2. Soil Moisture Sensor
3. Jumper wires (generic)
4. Breadboard (generic)
5. 16X2 LCD Display
6. I2C LCD Adapter Module

## Diagram:
![Circuit Diagram](https://i.imgur.com/LMmENCz.jpg "Circuit Diagram")

## Code

```c
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorPin = A0;
int sensorValue = 0;
int percentValue = 0;

void setup()
{
	Serial.begin(9600);
	// initialize the LCD
	lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  Serial.print("\n\nAnalog Value: ");
  Serial.print(sensorValue);

  percentValue = map(sensorValue, 1023, 200, 0, 100);
  Serial.print("\nPercentValue: ");
  Serial.print(percentValue);
  Serial.print("%");
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");

  lcd.setCursor(0, 1);  
  lcd.print("Percent: ");
  lcd.print(percentValue);
  lcd.print("%");
  delay(1000);
  lcd.clear();
}
```

## Advantages:
- Easy to use
- Cost Effective
- Expandable
- It delivers the results immediately.
- Offers accurate results.

## Disadvantages:
- Need some Technical Skills to Operate
- Might be Costly
- Mechanical Part so may be damage any time
- Sensors provide less accuracy in sandy soils due to large particles.

## Cost in BDT :
| S.L   | Component          | Cost  |
| ------|:-------------:| -----:|
| 1|Arduino Uno (China) | 450 BDT |
| 2|Soil Moisture Sensor|180 BDT |
| 3|Jumper wires (generic)|    20 BDT|
| 4|Breadboard (generic) X 2| 180 BDT |
| 5| 16X2 LCD Display |350 BDT|
| 6|I2C LCD Adapter Module|    180 BDT |
||Total Cost = |1,340 BDT