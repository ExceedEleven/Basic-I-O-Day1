#include <Arduino.h>
#include <Bounce2.h>
#define BUTTON 27
#define LDR 32
Bounce debouncer = Bounce();
#define RED 26
#define YELLOW 25
#define GREEN 33

int n=0;
void setup() {
  Serial.begin(115200);
  Serial.println("BUTTON");
  debouncer.attach(BUTTON, INPUT_PULLUP);
  debouncer.interval(25);
  ledcSetup(0,5000,8);
    ledcAttachPin(GREEN,0);
    ledcSetup(1,5000,8);
    ledcAttachPin(YELLOW,1);
    ledcSetup(2,5000,8);
    ledcAttachPin(RED,2);

}

void binary_led1(int n,int i,int r,int y, int g)
{
    n = n%8;
    if (n % 2 ==0) 
        ledcWrite(0,0);
    else 
        ledcWrite(0,i);
    
    if ((n ==2 || n==3) || (n ==6) || n ==7)
        ledcWrite(1,i);
    else 
        ledcWrite(1,0);

    if (n==4 || n ==5 || n ==6 || n==7)
        ledcWrite(2,i);
    else
        ledcWrite(2,0);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldr_analog = map(analogRead(LDR),2000,4095,0,255);
  debouncer.update();
  if(debouncer.fell()){
    n++;
  }
  binary_led1(n,ldr_analog,RED,YELLOW,GREEN);
   Serial.println(n);
}