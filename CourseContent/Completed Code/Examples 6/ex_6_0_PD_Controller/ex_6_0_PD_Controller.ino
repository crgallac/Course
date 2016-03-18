#include <Encoder.h>
#include <pwm01.h>

#define POTpin A0
#define PWMpinJ3 9
#define DIRpinJ3 26
#define PWMfreq 40000


Encoder myEncJ3(28, 29);// pins for J2
 
void setup() {
  // put your setup code here, to run once:
 SerialUSB.begin(9600);
  while (!Serial) ;

  analogReadResolution(12); 
  pinMode(DIRpinJ3, OUTPUT);
  pinMode(PWMpinJ3, OUTPUT);
   pwm_set_resolution(12); //Uncomment
   pwm_setup(PWMpinJ3 , PWMfreq, 1);  //Uncomment
}

uint32_t timer; 
uint32_t potValue, potValueOld;
int32_t motorValueJ3  = -999;
int32_t motorValueOldJ3  = 999;
int16_t  pwmDuty;
int16_t U; 
uint16_t K=10; 

void loop() {
  // put your main code here, to run repeatedly:

//Get Potentiometer Value

potValue= analogRead(A0);  
potValue=map(potValue,0,4095,0,10500); //maps the 270 degrees of the potentiometer to 270 degrees of the motor 
 if (potValue != potValueOld) {
    potValueOld=potValue; 
//    SerialUSB.print("Pot Value: "); 
//    SerialUSB.println(potValue); 
  }

////Get Motor position Value 
motorValueJ3= myEncJ3.read(); 
  if (motorValueJ3 != motorValueOldJ3) {
    motorValueOldJ3 = motorValueJ3;
//    SerialUSB.print("Motor Value: "); 
//    SerialUSB.println(motorValueJ3);
  }

////Create Control Law: PD Controller 
U=-K*(motorValueJ3-potValue);
pwmDuty= constrain(U, -4095, 4095);
//SerialUSB.println("duty:");
//SerialUSB.println(pwmDuty);

 if( pwmDuty < 0){
  digitalWrite(DIRpinJ3, LOW);
 }else{
  digitalWrite(DIRpinJ3, HIGH);
 }
 
uint16_t dutyOut= abs(pwmDuty); 

//analogWrite(pwmPinJ3, duty_out); //Comment
  pwm_write_duty( PWMpinJ3, dutyOut);  //Uncomment
}
