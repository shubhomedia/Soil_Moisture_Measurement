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
