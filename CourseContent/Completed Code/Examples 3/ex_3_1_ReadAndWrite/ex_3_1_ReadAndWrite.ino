#define POTpin A0


void setup() {
  // initialize serial communication at 9600 bits per second:
  SerialUSB.begin(9600);
  while(!SerialUSB){}; 
  pinMode(A0, INPUT); 
}

// the loop routine runs over and over again forever:
void loop() {
  delay(100); 
  int potValue = analogRead(A0); // read the input on analog pin 0
  SerialUSB.print("Pot Reading: ");
  SerialUSB.println(potValue);   // print out the value by serial
  SerialUSB.println(); 
  }
