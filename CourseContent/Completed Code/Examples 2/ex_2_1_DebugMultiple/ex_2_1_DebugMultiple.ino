#define TIMER1 100 //100 ms
#define TIMER2 900 //900 ms
#define TIMER3 TIMER1+TIMER2 //100+900 ms?

//global vars
// setting up the output pins
int LED1pin= 10; 
int LED2pin= 11; 
int LED3pin= 12; 

bool LED1state= HIGH; 
bool LED2state= HIGH; 
bool LED3state= HIGH; 

unsigned long timer, timerOld; 

void setup() {
  // put your setup code here, to run once:
SerialUSB.begin(9600); //initialize the Serial connection between our board and computer
while(!SerialUSB){}; //wait to make sure that the connection is made

//initialize the pin configuration
pinMode(LED1pin, OUTPUT); 
pinMode(LED2pin, OUTPUT); 
pinMode(LED3pin, OUTPUT); 
//initialize the pin states
digitalWrite(LED1pin, LED1state); 
digitalWrite(LED2pin, LED2state); 
digitalWrite(LED3pin, LED3state); 
}

//exercise: use SerialUSB.println(<variable>); to try and find out why the LED's aren't blinking like we want them to
void loop() {
  // put your main code here, to run repeatedly: 
timer=millis(); 
  
if(timer%TIMER1==0 && timer != timerOld){
LED1state= !LED1state; 
digitalWrite(LED1pin, LED1state); 
}

if(timer%TIMER2==0 && timer != timerOld){
LED2state= !LED2state; 
digitalWrite(LED2pin, LED2state); 
}

if(timer%(5*(TIMER1+TIMER2))==0 && timer != timerOld){
LED3state= !LED3state; 
digitalWrite(LED3pin, LED3state); 
}
timerOld=timer; 

}


