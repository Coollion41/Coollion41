#include <Arduino.h>

//#include "Timer_H"

//Arduino Piano by technoreview85.com
//C4 to C5

#define T_C 262
#define T_D 294
#define T_E 330
#define T_F 349
#define T_G 392
#define T_A 440
#define T_B 493
#define T_C5 523

// const int C5 = 10;
// const int C = 9;
const int D = 8;  //D
const int E = 7;  //E
const int F = 6;
const int G = 5;
const int A = 4;  //A
const int B = 3;
int buttonrecord = 0;
const int Buzz = 11;
// const int LED = 13;

int code = 0;
int buttonUpdate = 0;

unsigned long buttonTime = 0;
bool buttonPressed = false;

void setup()
{
  Serial.begin(9600);

  pinMode(D, INPUT);
  digitalWrite(D,HIGH);
  
  pinMode(E, INPUT);
  digitalWrite(E,HIGH);
  
  pinMode(F, INPUT);
  digitalWrite(F,HIGH);
  
  pinMode(G, INPUT);
  digitalWrite(G,HIGH);
  
  pinMode(A, INPUT);
  digitalWrite(A,HIGH);
  
  pinMode(B, INPUT);
  digitalWrite(B,HIGH);
}


void loop()
 {

  if(code > 999) {
    Serial.print("Code Entered: ");
    Serial.println(code);
    code = 0;
    tone(Buzz,T_A);
    delay(100);
    tone(Buzz,T_E);
    delay(100);
    tone(Buzz,T_D);
    delay(100);
    buttonPressed = false;
  }

  if (((buttonTime + 2000) < millis()) && buttonPressed)
  {
    code = 0;
    tone(Buzz,T_D);
    delay(100);
    tone(Buzz,T_E);
    delay(100);
    tone(Buzz,T_A);
    delay(100);
    buttonPressed = false;
    Serial.println("Code Reset");
  }

  while(digitalRead(D) == LOW)
  {
    tone(Buzz,T_D);
    buttonTime = millis();
    buttonPressed = true;
    buttonUpdate = 1;
  } 

  while(digitalRead(E) == LOW)
  {
    tone(Buzz,T_E);
    buttonTime = millis();
    buttonPressed = true;
    buttonUpdate = 2;
  }

  while(digitalRead(F) == LOW)
  {
    tone(Buzz,T_F);
    buttonTime = millis();
    buttonPressed = true;
    buttonUpdate = 3;
  }

  while(digitalRead(G) == LOW)
  {
    tone(Buzz,T_G);
    buttonTime = millis();
    buttonPressed = true;
    buttonUpdate = 4;
  }

  while(digitalRead(A) == LOW)
  {
    tone(Buzz,T_A);
    buttonTime = millis();
    buttonPressed = true;
    buttonUpdate = 5;
  }

  while(digitalRead(B) == LOW)
  {
    tone(Buzz,T_B);
    buttonTime = millis();
    buttonPressed = true;
    buttonUpdate = 6;
  }

  if (buttonUpdate != 0){
    code = code * 10 + buttonUpdate;
    buttonUpdate = 0;
    Serial.print("Code Update: ");
    Serial.println(code);
  }

  delay(60);

  noTone(Buzz);
  
  }