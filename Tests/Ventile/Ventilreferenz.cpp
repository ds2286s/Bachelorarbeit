/*
* Autor: Jonas Hamers
* Testfallname: Shuttertest, Focustest, Hauptblitztest, Vorblitztest
* Datum: 06.07.2015
*/

#include "Arduino.h"

void setup();
void loop();
void referenz(); //Referenzzeit
void test1(); //Zeit zwischen Tropfen 1 u. Shutter
void test2(); // Zeit zwischen Tropfen 1 u. Focus
void test3(); // Zeit zwischen Tropfen 1 u. Hauptblitz
void test4(); // Zeit zwischen Tropfen 1. u. Vorblitz

//Referenzzeit
double timestamp1 = 0;
volatile int tropfen = 0; // 0 noch kein Signal für Erstes Ventil
//Focustest
double timestamp2 = 0;
double diff1 = 32;
double diff2 = 34;
volatile int shutter = 0; // falls 1: dann ist focus "abgestempelt" und shutter ist an der Reihe 
//Shuttertest
double timestamp3 = 0;
double diff3 = 34;
double diff4 = 36;
//Hauptblitztest
double timestamp4 = 0;
double diff5 = 49;
double diff6 = 51;
//Vorblitztest
double timestamp5 = 0;
double diff7 = 44;
double diff8 = 46;

void setup() 
{
  Serial.begin(9600);
  attachInterrupt(2, referenz, RISING);
  attachInterrupt(4, test1, RISING);
// attachInterrupt(4, test2, RISING); Shutter interrupt liegt auf Focus interrupt
  attachInterrupt(0, test3, RISING);
  attachInterrupt(1, test4, RISING);
}

void loop() 
{
  
}

void referenz()
{
  // Timer starten; Referenzzeit Ventil 1
  if(tropfen ==0)
  {
     Serial.print("start");
	 tropfen = 1;
	 timestamp1 = millis(); // Zeit in Sekunden
  }	 
  
}

void test1()
{
	if(tropfen ==1)
	{
		 if(shutter == 0)
		 {
			 // Zeit abmessen für Focus
			 timestamp2 = millis();
			 if( (timestamp2 - timestamp1) > diff2 || (timestamp2 - timestamp1) < diff1)
			 {
				 //Differenz zu hoch || Differenz zu niedrig -> n.b.
				 Serial.println("Test 005: failed");
				 Serial.println("erwartete Differenz: "); 
				 Serial.print(diff1);
				 Serial.print("-");
				 Serial.print(diff2);
				 Serial.print("ms  tatsaechliche Differenz: ");
				 Serial.print((timestamp2 - timestamp1)); 
				 Serial.println("ms ");
			 }else
			 {
				 //Test bestanden
				 Serial.println("Test 005: passed");
			 }
			 shutter = 1; 
		 }else
		 {
		     test2();
		 }
	 }
}


void test2()
{
	  // Zeit abmessen für Shutter
	  timestamp3 = millis();
	  if( (timestamp3 - timestamp1) > diff4 || (timestamp3 - timestamp1) < diff3)
	  {
		//Differenz zu hoch || Differenz zu niedrig -> n.b.
		Serial.println("Test 004: failed");
		Serial.println("erwartete Differenz: "); 
		Serial.print(diff1);
		Serial.print("-");
		Serial.print(diff2);
		Serial.print("ms  tatsaechliche Differenz: ");
		Serial.print((timestamp3 - timestamp1)); 
		Serial.println("ms ");
	  }else
	  {
		//Test bestanden
		Serial.println("Test 004: passed");
	  }
}


void test3()
{
	 if(tropfen == 1)
	 {
		 // Zeit abmessen für Hauptblitz
		 timestamp4 = millis();
		 if( (timestamp4 - timestamp1) > diff6 || (timestamp4 - timestamp1) < diff5)
		 {
			 //Differenz zu hoch || Differenz zu niedrig -> n.b.
			 Serial.println("Test 006: failed");
			 Serial.println("erwartete Differenz: "); 
			 Serial.print(diff1);
			 Serial.print("-");
			 Serial.print(diff2);
			 Serial.print("ms  tatsaechliche Differenz: ");
			 Serial.print((timestamp4 - timestamp1)); 
			 Serial.println("ms ");
		 }else
		 {
			 //Test bestanden
			 Serial.println("Test 006: passed");
		 }
	 }	 
}


void test4()
{
	 if(tropfen ==1)
	 {
		 // Zeit abmessen für Hauptblitz
		 timestamp5 = millis();
		 if( (timestamp5 - timestamp1) > diff8 || (timestamp5 - timestamp1) < diff7)
		 {
		     //Differenz zu hoch || Differenz zu niedrig -> n.b.
			 Serial.println("Test 007: failed");
			 Serial.println("erwartete Differenz: "); 
			 Serial.print(diff1);
			 Serial.print("-");
			 Serial.print(diff2);
			 Serial.print("ms  tatsaechliche Differenz: ");
			 Serial.print((timestamp5 - timestamp1)); 
			 Serial.println("ms ");
		 }else
		 {
			 //Test bestanden
			 Serial.println("Test 007: passed");
		 }
		 tropfen = 2;
		 Serial.print("exit"); //Abschluss letzter Test
	 }	 
}