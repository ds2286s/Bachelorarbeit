/*
* Autor: Jonas Hamers
* Testfallname: Shutter-/Hauptblitz-/Vorblitz-Focus-Test
* Datum: 06.07.2015
*/

#include "Arduino.h"

void setup();
void loop();
void referenz(); //Referenzzeit Tropfen 1
void referenz2(); //Zeit Focus
void test1(); //Zeit zwischen Focus u. Shutter
void test2(); // Zeit zwischen Focus u. Hauptblitz
void test3(); // Zeit zwischen Focus u. Vorblitz


//Referenzzeit
double timestamp1 = 0;
int tropfen = 0;
int shutter = 0;
//Shuttertest
double timestamp2 = 0;
double diff1 = 0;
double diff2 = 4;
//Hauptblitztest
double timestamp3 = 0;
double diff3 = 15;
double diff4 = 19;
//Vorblitztest
double timestamp4 = 0;
double diff5 = 10;
double diff6 = 14;
int  ctr = 0;
boolean testA = false;
boolean testB = false;
boolean testC = false;
boolean testD = false;
boolean ref = false;


void setup() 
{
  Serial.begin(9600);
  attachInterrupt(2, referenz, RISING);
  attachInterrupt(4, referenz2, RISING);
  //attachInterrupt(4, test1, RISING); Shutter liegt auf Focus interrupt
  attachInterrupt(0, test2, RISING);
  attachInterrupt(1, test3, RISING);
}

void loop() 
{
	 if(digitalRead(6)==LOW && ref &&ctr <2){
		ctr = ctr+1;
		referenz2();
	}

	
	
  if(testA==true && testB==true && testC==true && testD == true)
  {
    noInterrupts();
    Serial.println("exit");
    interrupts();
    tropfen = 2;
    testA = false;
    testB = false;
    testC = false;
    testD = false;
   }
}

void referenz()
{
  if(tropfen == 0 && ref == false)
  {  
    ref = true;
    noInterrupts();
    Serial.println("start");
    interrupts();
    tropfen = 1;
    timestamp1=0;
    timestamp2=0;
    timestamp3=0;
    timestamp4=0;
  }
}

void referenz2()
{
  if(tropfen == 1 && ref ==true)
  {  
    if(shutter == 0 && testA ==false)
    {
        shutter = 1 ;
        testA = true; 
        // Timer starten; Referenzzeit Focus
        timestamp1 = millis(); // Zeit in Sekunden
    }else if (testB == false)
    {
      testB = true; 
      test1();
    }
  }
}

void test1()
{
    
    // Zeit abmessen für Shutter
    timestamp2 = millis();
    if( (timestamp2 - timestamp1) > diff2 || (timestamp2 - timestamp1) < diff1)
    {
    //Differenz zu hoch || Differenz zu niedrig -> n.b.
    noInterrupts();
    Serial.println("Test 008: failed");
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
    Serial.println("Test 008: passed");
    Serial.print("tatsaechliche Differenz: ");
    Serial.print((timestamp2 - timestamp1)); 
    Serial.println("ms ");
    interrupts();
    interrupts();
    }
}


void test2()
{
  if(tropfen == 1 && testC == false)
  { 
   testC = true;
    // Zeit abmessen für Focus
    timestamp3 = millis();
    if( (timestamp3 - timestamp1) > diff4 || (timestamp3 - timestamp1) < diff3)
    {
    //Differenz zu hoch || Differenz zu niedrig -> n.b.
    noInterrupts();
    Serial.println("Test 009: failed");
    Serial.print("erwartete Differenz: "); 
    Serial.print(diff1);
    Serial.print("-");
    Serial.print(diff2);
    Serial.print("ms  tatsaechliche Differenz: ");
    Serial.print((timestamp3 - timestamp1)); 
    Serial.println("ms ");
    interrupts();
    }else
    {
    //Test bestanden
    noInterrupts();
    Serial.println("Test 009: passed");
    Serial.print("tatsaechliche Differenz: ");
    Serial.print((timestamp3 - timestamp1)); 
    Serial.println("ms ");
    interrupts();
    interrupts();
    }
  }
}


void test3()
{
  if(tropfen == 1 && testD == false)
  { 
    testD = true;
    // Zeit abmessen für Hauptblitz
    timestamp4 = millis();
    if( (timestamp4 - timestamp1) > diff6 || (timestamp4 - timestamp1) < diff5)
    {
    //Differenz zu hoch || Differenz zu niedrig -> n.b.
    noInterrupts();
    Serial.println("Test 010: failed");
    Serial.print("erwartete Differenz: "); 
    Serial.print(diff1);
    Serial.print("-");
    Serial.print(diff2);
    Serial.print("ms  tatsaechliche Differenz: ");
    Serial.print((timestamp4 - timestamp1)); 
    Serial.println("ms ");
    interrupts();
    }else
    {
    //Test bestanden
    noInterrupts();
    Serial.println("Test 010: passed");
    Serial.print("tatsaechliche Differenz: ");
    Serial.print((timestamp4 - timestamp1)); 
    Serial.println("ms ");
    interrupts();
    }
  } 
}


