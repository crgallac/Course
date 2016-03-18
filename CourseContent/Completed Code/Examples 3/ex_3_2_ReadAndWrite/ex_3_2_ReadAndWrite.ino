#define POTpin A0
#define LED 10

void setup() {
  // initialize serial communication at 9600 bits per second:
  SerialUSB.begin(9600);
  while(!SerialUSB){}; 
  analogReadResolution(12); 
  analogWriteResolution(12); //point of interest
  pinMode(A0, INPUT); 
  pinMode(LED, OUTPUT); 
  analogWrite(LED,LOW); 
}

// the loop routine runs over and over again forever:
void loop() {
  delay(100); 
  int potValue = analogRead(A0); // read the input on analog pin 0
  SerialUSB.print("Pot Reading: ");
  SerialUSB.println(potValue);   // print out the value by serial
  
  int pwmValue=potValue; //Set output to the potentiometer reading
  analogWrite(LED,pwmValue); //Write PWM Output
  
  SerialUSB.print("PWM Reading: "); // print out the value by serial
  SerialUSB.println(pwmValue); 
  SerialUSB.println();

  
}
