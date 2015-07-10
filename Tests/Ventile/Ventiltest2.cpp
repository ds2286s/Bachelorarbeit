/*
* Autor: Jonas Hamers
* Testfallname: Ventiltest2
* Datum: 06.07.2015
*/
#include "Arduino.h"

void setup();
void loop();
void referenz(); //Referenzzeit
void test1(); //Zeit zwischen Tropfen 1 u. 2

//Referenzzeit
unsigned long timestamp1 = 0;
int tropfen = 0;
//Ventiltest1
unsigned long timestamp2 = 0;
unsigned long diff1 = 99999;
unsigned long diff2 = 10001;

boolean ref = false;
boolean ventil2 = false;

void setup() 
{
  Serial.begin(9600);
  attachInterrupt(3, referenz, RISING);
  attachInterrupt(2, test1, RISING);
}

void loop() 
{
  
}

void referenz()
{
  // Timer starten; Referenzzeit Ventil 1
  if(tropfen == 0 && ref ==false)
  {
    ref = true;
    noInterrupts();
  Serial.println("start");
  interrupts();
  timestamp1 = millis(); // Zeit in Sekunden
  tropfen = 1;
  }
}

void test1()
{
    if(tropfen == 1 && ventil2 == false)
  {
    ventil2 = true;
    // Zeit abmessen für Ventil 2
    timestamp2 = millis();
    if( (timestamp2 - timestamp1) > diff2 || (timestamp2 - timestamp1) < diff1)
    {
    //Differenz zu hoch || Differenz zu niedrig -> n.b.
    noInterrupts();
    Serial.println("Test 002: failed");
    Serial.print("erwartete Differenz: "); 
    Serial.print(diff1);
    Serial.print("-");
    Serial.print(diff2);
    Serial.print("ms  tatsaechliche Differenz: ");
    Serial.print((timestamp2 - timestamp1)); 
    Serial.println("ms ");
    interrupts();
    }else
    {
    //Test bestanden
    noInterrupts();
    Serial.println("Test 002: passed");
    Serial.print("tatsaechliche Differenz: ");
    Serial.print((timestamp2 - timestamp1)); 
    Serial.println("ms ");
    interrupts();
    }
    noInterrupts();
    Serial.print("exit"); //Abschluss letzter Test
    interrupts();
    tropfen = 2;
  }
}
