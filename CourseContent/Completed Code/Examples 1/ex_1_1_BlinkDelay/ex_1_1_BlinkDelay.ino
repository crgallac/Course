#define PIN 13

void setup() {
  // put your setup code here, to run once:
pinMode(PIN, OUTPUT); 
digitalWrite(PIN, HIGH); 
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(PIN, LOW); 
delay(1000); 
digitalWrite(PIN, HIGH); 
delay(1000); 
}
