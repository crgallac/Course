#define POTpin A0
#define LED 10
#define PWMpin A1

void setup() {
  // initialize serial communication at 9600 bits per second:
  SerialUSB.begin(9600);
  while(!SerialUSB){}; 
  analogReadResolution(10); 
  analogWriteResolution(10); 
  pinMode(LED, OUTPUT); 
  analogWrite(LED,LOW); 
}

// the loop routine runs over and over again forever:
void loop() {
  int potValue = analogRead(POTpin); // read the input on analog pin 0
  SerialUSB.print("Pot Reading: ");
  SerialUSB.println(potValue);   // print out the value by serial
  analogWrite(LED, potValue);  
  int pwmValue= analogRead(PWMpin); 
  SerialUSB.print("PWM Reading: "); //print out the value by serial
  SerialUSB.println(pwmValue); 
  SerialUSB.println();
}
