uint8_t PIN = 13;
bool STATE = HIGH; 
uint32_t counter=0; 

void setup() {
  // put your setup code here, to run once:
pinMode(PIN, OUTPUT); 
digitalWrite(PIN, STATE); 
}

void loop() {
	// put your main code here, to run repeatedly:
	 counter++;
	 if (counter==500000){
		 counter = 0; 
	 STATE = !STATE;
	 digitalWrite(PIN, STATE);
	}
}


