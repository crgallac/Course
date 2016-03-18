#define POTpin A0
#define LEDVoltage A1
#define LED 10
#define DACpin DAC0



void setup() {
  // initialize serial communication at 9600 bits per second:
  SerialUSB.begin(9600);
  while(!SerialUSB){}; 
   analogReadResolution(10); 
  analogWriteResolution(10);  
}

// the loop routine runs over and over again forever:
void loop() {
//  delay(100); 

  int potValue = analogRead(POTpin); // read the input on analog pin 0
  SerialUSB.print("Pot Reading: ");
  SerialUSB.println(potValue);   // print out the value by serial
  int pwmValue=potValue; 
  analogWrite(DACpin, pwmValue);

  int voltageReading =analogRead(LEDVoltage); 
  SerialUSB.print("LED Voltage: ");
  SerialUSB.println(voltageReading);   // print out the value by serial
  
}
