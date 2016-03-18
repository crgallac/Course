#define TIMER1 1000

int LED1pin= 10; 

bool LED1state= HIGH; 

unsigned long timer = 0; 
unsigned long timerOld = 0; 

void setup() {
  // put your setup code here, to run once:
SerialUSB.begin(9600); //initialize the Serial connection between our board and computer
while(!SerialUSB){}; //wait to make sure that the connection is made

pinMode(LED1pin, OUTPUT); 

digitalWrite(LED1pin, LED1state); 
}

void loop() {
  // put your main code here, to run repeatedly: 
timer=millis(); 
SerialUSB.println(timer); 
if((timer%TIMER1)==0 && timer != timerOld){
LED1state= !LED1state; 
digitalWrite(LED1pin, LED1state); 
}
timerOld=timer; 
}


