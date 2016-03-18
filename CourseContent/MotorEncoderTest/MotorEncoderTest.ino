#include <Encoder.h>
#include <pwm01.h>

   uint32_t  pwm_dutyJ2;
   uint32_t  pwm_dutyJ3; 
   uint32_t  pwm_dutyJ4;
   uint32_t  pwm_dutyJ5; 

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

Encoder myEncJ2(24, 25); //pins for J2
Encoder myEncJ3(28, 29);// pins for J3
Encoder myEncJ4(32, 33); //pins for J4
Encoder myEncJ5(36, 37);// pins for J5

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
}
