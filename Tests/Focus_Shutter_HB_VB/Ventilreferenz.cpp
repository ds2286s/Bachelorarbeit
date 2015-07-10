/*
* Autor: Jonas Hamers
* Testfallname: Shuttertest, Focustest, Hauptblitztest, Vorblitztest
* Datum: 06.07.2015
*/
#include "Arduino.h"

void loop();
void setup();

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
double diff1 = 29;
double diff2 = 33;
volatile int shutter = 0; // falls 1: dann ist focus "abgestempelt" und shutter ist an der Reihe 
//Shuttertest
double timestamp3 = 0;
double diff3 = 31;
double diff4 = 35;
//Hauptblitztest
double timestamp4 = 0;
double diff5 = 48;
double diff6 = 52;
//Vorblitztest
double timestamp5 = 0;
double diff7 = 43;
double diff8 = 47;

boolean testA = false;
boolean testB = false;
boolean testC = false;
boolean testD = false;
boolean testE = false;
boolean ref = false;


void setup() 
{
  Serial.begin(57600);

 EICRB |= (1<<ISC60)|(1<<ISC61);
    EIMSK |= (1<<INT6);
  
  attachInterrupt(2, referenz, RISING);
  attachInterrupt(4, test1, RISING);
// attachInterrupt(4, test2, RISING); Shutter interrupt liegt auf Focus interrupt
  attachInterrupt(0, test3, RISING);
  attachInterrupt(1, test4, RISING);

}

void loop() 
{
  if(testA==true && testB==true && testC==true && testD==true )
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

  // Timer starten; Referenzzeit Ventil 1
  if(tropfen == 0 && ref == false)
  {
    ref = true;     
    noInterrupts();
    Serial.println("start");
    interrupts();     
    timestamp2=0;
    timestamp3=0;
    timestamp4=0;
    tropfen = 1;
	  timestamp1 = millis(); // Zeit in Sekunden
  }	 
  
}

void test1()
{        
  if(tropfen == 1 && (testA == false || testB == false))
  {
	    if(shutter == 0)
	    {
		     testA=true;
		     shutter = 1;
		     // Zeit abmessen für Focus
		     timestamp2 = millis();
			 if( (timestamp2 - timestamp1) > diff2 || (timestamp2 - timestamp1) < diff1)
			 {
			//Differenz zu hoch || Differenz zu niedrig -> n.b.
				noInterrupts();
				Serial.println("Test 005: failed");
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
				 Serial.println("Test 005: passed");
         Serial.print("tatsaechliche Differenz: ");
       Serial.print((timestamp2 - timestamp1)); 
        Serial.println("ms ");
				 interrupts();
			}                
		 }else
		 {    
			 shutter = 0;  
			 test2(); 		 
		 }
	}
}


void test2()
{
      testB=true;
	  // Zeit abmessen für Shutter
	  timestamp3 = millis();
	  if( (timestamp3 - timestamp1) > diff4 || (timestamp3 - timestamp1) < diff3)
	  {
		//Differenz zu hoch || Differenz zu niedrig -> n.b.
                noInterrupts();
		Serial.println("Test 004: failed");
		Serial.print("erwartete Differenz: "); 
		Serial.print(diff3);
		Serial.print("-");
		Serial.print(diff4);
		Serial.print("ms  tatsaechliche Differenz: ");
		Serial.print((timestamp3 - timestamp1)); 
		Serial.println("ms ");
                interrupts();
	  }else
	  {
		//Test bestanden
                noInterrupts();
		Serial.println("Test 004: passed");
   Serial.print("tatsaechliche Differenz: ");
   Serial.print((timestamp3 - timestamp1)); 
    Serial.println("ms ");
                interrupts();
	  }
}


void test3()
{

	 if(tropfen == 1 && testC == false)
	 {
		testC=true;
		 // Zeit abmessen für Hauptblitz
		 timestamp4 = millis();
		 if( (timestamp4 - timestamp1) > diff6 || (timestamp4 - timestamp1) < diff5)
		 {
			 //Differenz zu hoch || Differenz zu niedrig -> n.b.
                         noInterrupts();
			 Serial.println("Test 006: failed");
			 Serial.print("erwartete Differenz: "); 
			 Serial.print(diff5);
			 Serial.print("-");
			 Serial.print(diff6);
			 Serial.print("ms  tatsaechliche Differenz: ");
			 Serial.print((timestamp4 - timestamp1)); 
			 Serial.println("ms ");
                        interrupts();
		 }else
		 {
			 //Test bestanden
             noInterrupts();
			 Serial.println("Test 006: passed");
       Serial.print("tatsaechliche Differenz: ");
      Serial.print((timestamp4 - timestamp1)); 
       Serial.println("ms ");
             interrupts();
		 }
	 }	 
}


void test4()
{
 
	 if(tropfen == 1 && testD == false)
	 {
	     testD=true;
		 // Zeit abmessen für Vorblitz
		 timestamp5 = millis();
		 if( (timestamp5 - timestamp1) > diff8 || (timestamp5 - timestamp1) < diff7)
		 {
		     //Differenz zu hoch || Differenz zu niedrig -> n.b.
                         noInterrupts();
			 Serial.println("Test 007: failed");
			 Serial.print("erwartete Differenz: "); 
			 Serial.print(diff7);
			 Serial.print("-");
			 Serial.print(diff8);
			 Serial.print("ms  tatsaechliche Differenz: ");
			 Serial.print((timestamp5 - timestamp1)); 
			 Serial.println("ms ");
                         interrupts();
		 }else
		 {
			 //Test bestanden
                         noInterrupts();
			 Serial.println("Test 007: passed");
       Serial.print("tatsaechliche Differenz: ");
      Serial.print((timestamp5 - timestamp1)); 
       Serial.println("ms ");
                         interrupts();
		 }
	 }	 
}