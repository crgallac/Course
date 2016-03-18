#include<stdlib.h>
#include <math.h>
#include <Encoder.h>
#include <pwm01.h>
 
   int32_t  pwm_duty;

   uint32_t  pwm_freq = 40000; //Hz 

   uint32_t pwmPinJ2=8; //J2
   uint32_t dirPinJ2= 22; 

   uint32_t pwmPinJ3=9; //J3
   uint32_t dirPinJ3= 26; 

   uint32_t pwmPinJ4=7; //J4
   uint32_t dirPinJ4= 30; 

   uint32_t pwmPinJ5=6; //J5
   uint32_t dirPinJ5= 34; 

long newPositionJ2  = -999;
long newPositionJ3  = -999;
long newPositionJ4  = -999;
long newPositionJ5  = -999;

Encoder myEncJ2(24, 25); //pins for J3
Encoder myEncJ3(28, 29);// pins for J2
Encoder myEncJ4(32, 33); //pins for J3
Encoder myEncJ5(36, 37);// pins for J2

void setup() {
  // put your setup code here, to run once:
 SerialUSB.begin(115200);
  while (!Serial) ;

   pinMode(dirPinJ2, OUTPUT);
   pinMode(pwmPinJ2, OUTPUT);
  pinMode(dirPinJ3, OUTPUT);
  pinMode(pwmPinJ3, OUTPUT);

   pinMode(dirPinJ4, OUTPUT);
   pinMode(pwmPinJ4, OUTPUT);
  pinMode(dirPinJ5, OUTPUT);
  pinMode(pwmPinJ5, OUTPUT);


   pwm_set_resolution(12);

   pwm_setup(pwmPinJ2 , pwm_freq, 1);  
   pwm_setup(pwmPinJ3 , pwm_freq, 1);  
   pwm_setup(pwmPinJ4 , pwm_freq, 1);  
   pwm_setup(pwmPinJ5 , pwm_freq, 1); 

}

unsigned long timer; 

void loop() {
  // put your main code here, to run repeatedly:

timer=millis(); 

if(timer%100 == 0){
float thetaJ2= 360.0/13824.0*myEncJ2.read(); // Angle of the motor //J2
float thetaJ3 = 360.0/13824.0*myEncJ3.read(); //Angle of the motor //J3
float thetaJ4= 360.0/13824.0*myEncJ4.read(); // Angle of the motor //J4
float thetaJ5 = 360.0/13824.0*myEncJ5.read(); //Angle of the motor //J5

SerialUSB.println("J2:");
SerialUSB.println(thetaJ2); 
SerialUSB.println("J3:"); 
SerialUSB.println(thetaJ3); 
SerialUSB.println("J4:");
SerialUSB.println(thetaJ4); 
SerialUSB.println("J5:");
SerialUSB.println(thetaJ5); 
}

if(timer%100 == 0){
double omegaT= timer/1000.0; 
//pwm_duty= 2000; 
pwm_duty= 4096*sin(omegaT);
//SerialUSB.println("duty:");
//SerialUSB.println(pwm_duty);
//pwm_duty=0; 
}
 if( pwm_duty < 0){
  digitalWrite(dirPinJ2, LOW);
  digitalWrite(dirPinJ3, LOW);
  digitalWrite(dirPinJ4, LOW);
  digitalWrite(dirPinJ5, LOW);
 }else{
  digitalWrite(dirPinJ2, HIGH);
  digitalWrite(dirPinJ3, HIGH);
  digitalWrite(dirPinJ4, HIGH);
  digitalWrite(dirPinJ5, HIGH);
 }
 
//int dutyOut= 4096* abs(pwm_duty); 

uint16_t duty_out= abs(pwm_duty); 

  pwm_write_duty( pwmPinJ2, duty_out);  
  pwm_write_duty( pwmPinJ3, duty_out ); 
  pwm_write_duty( pwmPinJ4, duty_out );  
  pwm_write_duty( pwmPinJ5, duty_out ); 

}
