#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}#include <Arduino.h>
#define GREEN 33
void setup()
{
    ledcSetup(0, 5000, 8);
    ledcAttachPin(GREEN, 0);
}
void loop()
{
  for (int i = 0; i < 255; i++) {
    ledcWrite(0, i);
    delay(5);
  }
  for (int i = 255; i > 0; i--) {
    ledcWrite(0, i);
    delay(5);
  }
  delay(1000);
}