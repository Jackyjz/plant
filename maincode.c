#include <LiquidCrystal.h>

const int rs = 12, en = 8, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7); 

const int moistureSensorPin = A0;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);

}

void loop() {
  // Read the value from the moisture sensor
  int sensorValue = analogRead(moistureSensorPin);
  Serial.println(sensorValue);

  // Convert the sensor value to a percentage
  // Assuming 0 is completely dry and 1023 is completely wet
  // int moisturePercentage = map(sensorValue, 0, 1023, 0, 100);

  // Serial.print("Moisture Level: ");
  // Serial.print(moisturePercentage);
  // Serial.println("%");
  // delay(1000);

  // Serial.print("output soemthing");
  // while (Serial.available()==0)
  // {

  // }

  // int something = Serial.parseInt();
  // Serial.print(something);


  lcd.clear();
  lcd.print("Rebotted");
  lcd.setCursor(0, 1);
  lcd.print("Moisture Sensor");
  delay(3000);

  lcd.clear();
  lcd.print("Moisture Level: \n");
  lcd.setCursor(0, 1);
  lcd.print(sensorValue);
  delay(3000);

  lcd.clear();
  if(sensorValue<680){
    lcd.print("Too");
    lcd.setCursor(0, 1);
    lcd.print("Hydrated");
    delay(3000);
  }
  else if(sensorValue<=684){
    lcd.print("Well");
    lcd.setCursor(0, 1);
    lcd.print("Hydrated");
    delay(3000);
  }
  else{
    lcd.print("Not");
    lcd.setCursor(0, 1);
    lcd.print("Hydrated");
    delay(3000);
  }

}
