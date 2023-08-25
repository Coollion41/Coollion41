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


unsigned long buttonTime = 0;
bool buttonPressed = false;

void setup()
{
  Serial.begin(9600);
  // pinMode(LED, OUTPUT);
  // pinMode(C5, INPUT);
  // digitalWrite(C5,HIGH); 
  
  // pinMode(LED, OUTPUT);
  // pinMode(C, INPUT);
  // digitalWrite(C,HIGH);
  
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

  //  digitalWrite(LED,LOW);

  
}


void loop()
 {
  if (((buttonTime + 2000) < millis()) && buttonPressed)
  {
    tone(Buzz,T_D);
    delay(100);
    tone(Buzz,T_E);
    delay(100);
    tone(Buzz,T_A);
    delay(100);
    buttonPressed = false;
    buttonrecord = 0;
    
  }


  while(digitalRead(D) == LOW)
  {
    tone(Buzz,T_D);
    buttonTime = millis();
    buttonPressed = true;
    buttonrecord =1;
  } 

  while(digitalRead(E) == LOW)
  {
    tone(Buzz,T_E);
    buttonTime = millis();
    buttonPressed = true;
    buttonrecord =2;
  }

  while(digitalRead(F) == LOW)
  {
    tone(Buzz,T_F);
    buttonTime = millis();
    buttonPressed = true;
     buttonrecord =3;
  }

  while(digitalRead(G) == LOW)
  {
    tone(Buzz,T_G);
    buttonTime = millis();
    buttonPressed = true;
     buttonrecord =4;
  }

  while(digitalRead(A) == LOW)
  {
    tone(Buzz,T_A);
    buttonTime = millis();
    buttonPressed = true;
     buttonrecord =5;
  }

  while(digitalRead(B) == LOW)
  {
    tone(Buzz,T_B);
    buttonTime = millis();
    buttonPressed = true;
     buttonrecord =6;
  }
  
  noTone(Buzz);
  }