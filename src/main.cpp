#include <Arduino.h>
#include <Bounce2.h>
#define BUTTON 27
#define LDR 32
Bounce debouncer = Bounce();
int n=0;

void setup() {
  Serial.begin(115200);
  Serial.println("BUTTON");
  debouncer.attach(BUTTON, INPUT_PULLUP);
  debouncer.interval(25);

}

void loop() {
  // put your main code here, to run repeatedly:
  debouncer.update();
  if(debouncer.fell()){
    n++;
    Serial.println(n);
  }

}