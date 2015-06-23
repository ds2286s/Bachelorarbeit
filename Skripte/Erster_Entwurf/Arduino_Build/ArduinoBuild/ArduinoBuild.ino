
void printHello();


char foo;
void setup() {
  char foo2;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  printHello();
}

void printHello(){
  Serial.println("Hello you!");  
}
