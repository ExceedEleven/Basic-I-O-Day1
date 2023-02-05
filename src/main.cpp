#include <Arduino.h>
#include <Bounce2.h>
#define BUTTON 27
#define LDR 32
Bounce debouncer = Bounce();
int n=0;
#define RED 26
#define YELLOW 25
#define GREEN 33

int n=0;
void setup() {
  Serial.begin(115200);
  Serial.println("BUTTON");
  debouncer.attach(BUTTON, INPUT_PULLUP);
  debouncer.interval(25);
  pinMode(GREEN,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);

}

void binary_led1(int n,int r,int y, int g)
{
    n = n%8;
    if (n % 2 ==0) 
        digitalWrite(g, LOW);
    else 
        digitalWrite(g, HIGH);
    
    if ((n ==2 || n==3) || (n ==6) || n ==7)
        digitalWrite(y,HIGH);
    else 
        digitalWrite(y,LOW);

    if (n==4 || n ==5 || n ==6 || n==7)
        digitalWrite(r,HIGH);
    else
        digitalWrite(r,LOW);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  debouncer.update();
  if(debouncer.fell()){
    n++;
    Serial.println(n);
  }
}