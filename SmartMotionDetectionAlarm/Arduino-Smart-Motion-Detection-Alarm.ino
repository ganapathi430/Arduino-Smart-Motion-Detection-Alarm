#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define PIR_PIN 2
#define BUZZER_PIN 8

void setup() {

  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);

  display.setTextSize(2);
  display.setCursor(10,10);
  display.println("SMART");

  display.setCursor(8,35);
  display.println("ALARM");

  display.display();
  delay(2000);
}

void loop() {

  int motion = digitalRead(PIR_PIN);

  display.clearDisplay();
  display.setTextColor(WHITE);

  display.setTextSize(1);
  display.setCursor(12,0);
  display.println("SMART SECURITY");

  display.drawLine(0,10,127,10,WHITE);

  if (motion == HIGH) {

    display.setCursor(0,20);
    display.println("STATUS : ALERT");

    display.setCursor(0,35);
    display.println("MOTION : DETECTED");

    display.setCursor(0,50);
    display.println("ALARM  : ON");

    tone(BUZZER_PIN, 2000);

  }
  else {

    display.setCursor(0,20);
    display.println("STATUS : SAFE");

    display.setCursor(0,35);
    display.println("MOTION : NONE");

    display.setCursor(0,50);
    display.println("ALARM  : OFF");

    noTone(BUZZER_PIN);

  }

  display.display();

  delay(100);

}