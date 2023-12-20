#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define BUZZER_PIN 3
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  Serial.println(sensorValue);
  
  if(sensorValue > 200){
    analogWrite(BUZZER_PIN, 50);
    display.print("Gaz");
    // display.print("Alcohol");
    // display.print("Smoke");
    
    }
   else{
    analogWrite(BUZZER_PIN, 0);
    display.print(sensorValue);
    }
  display.display();
  display.clearDisplay();
  delay(1000); 
}
