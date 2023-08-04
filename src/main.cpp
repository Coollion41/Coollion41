#include <Arduino.h>

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
const int D = 8;
const int E = 7;
const int F = 6;
const int G = 5;
const int A = 4;
const int B = 3;

const int Buzz = 11;
// const int LED = 13;

void setup()
{
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
  

  while(digitalRead(D) == LOW)
  {
    tone(Buzz,T_D);
  }

  while(digitalRead(E) == LOW)
  {
    tone(Buzz,T_E);
  }

  while(digitalRead(F) == LOW)
  {
    tone(Buzz,T_F);
  }

  while(digitalRead(G) == LOW)
  {
    tone(Buzz,T_G);
  }

  while(digitalRead(A) == LOW)
  {
    tone(Buzz,T_A);
  }

  while(digitalRead(B) == LOW)
  {
    tone(Buzz,T_B);
  }

  noTone(Buzz);

}