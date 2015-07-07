/*
* Autor: Jonas Hamers
* Testfallname: Shutter-/Hauptblitz-/Vorblitz-Focus-Test
* Datum: 06.07.2015
*/

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
double diff1 = 1;
double diff2 = 3;
//Hauptblitztest
double timestamp3 = 0;
double diff3 = 16;
double diff4 = 18;
//Vorblitztest
double timestamp4 = 0;
double diff5 = 11;
double diff6 = 13;


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
  
}

void referenz()
{
  if(tropfen == 0)
  {  
	Serial.print("start");
	tropfen = 1;
  }
}

void referenz2()
{
  if(tropfen == 1)
  {  
	if(shutter == 0)
	{
		  // Timer starten; Referenzzeit Focus
		  timestamp1 = millis(); // Zeit in Sekunden
	}else
	{
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
		Serial.println("Test 008: failed");
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
		Serial.println("Test 008: passed");
	  }
}


void test2()
{
	if(tropfen == 1 )
	{	
	  // Zeit abmessen für Focus
	  timestamp3 = millis();
	  if( (timestamp3 - timestamp1) > diff4 || (timestamp3 - timestamp1) < diff3)
	  {
		//Differenz zu hoch || Differenz zu niedrig -> n.b.
		Serial.println("Test 009: failed");
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
		Serial.println("Test 009: passed");
	  }
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
		Serial.println("Test 010: failed");
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
		Serial.println("Test 010: passed");
	  }
	  Serial.print("exit"); //Abschluss letzter Test
	  tropfen = 2;
	} 
}


