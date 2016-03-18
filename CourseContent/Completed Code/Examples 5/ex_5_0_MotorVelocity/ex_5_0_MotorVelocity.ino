#include <Encoder.h>
#include <pwm01.h>

   int32_t  pwm_duty;
   uint32_t  pwm_freq = 40000; //Hz  //Uncomment

   uint32_t pwmPinJ3=9; //J3
   uint32_t dirPinJ3= 26; 
 
void setup() {
  // put your setup code here, to run once:
 SerialUSB.begin(9600);
  while (!Serial) ;

  pinMode(dirPinJ3, OUTPUT);
  pinMode(pwmPinJ3, OUTPUT);
//  analogWriteResolution(12); //Comment out 
   pwm_set_resolution(12); //Uncomment
   pwm_setup(pwmPinJ3 , pwm_freq, 1);  //Uncomment
}

unsigned long timer; 

void loop() {
  // put your main code here, to run repeatedly:
timer= millis(); 
double omegaT= timer/1000.0; 

pwm_duty= 4096*sin(omegaT);

//SerialUSB.println("duty:");
//SerialUSB.println(pwm_duty);

 if( pwm_duty < 0){
  digitalWrite(dirPinJ3, LOW);
 }else{
  digitalWrite(dirPinJ3, HIGH);
 }
 
uint16_t duty_out= abs(pwm_duty); 


//analogWrite(pwmPinJ3, duty_out); //Comment
  pwm_write_duty( pwmPinJ3, duty_out);  //Uncomment
}
