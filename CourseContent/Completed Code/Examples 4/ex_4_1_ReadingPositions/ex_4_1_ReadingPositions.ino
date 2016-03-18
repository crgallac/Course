#define ENCpin1_1 28
#define ENCpin1_2 29
#define ENCpin2_1 24
#define ENCpin2_2 25

#include <Encoder.h>

Encoder myEnc1(ENCpin1_1, ENCpin1_2);
Encoder myEnc2(ENCpin2_1, ENCpin2_2);

void setup() {
  SerialUSB.begin(9600);
  while(!SerialUSB); 
  SerialUSB.println("Basic Encoder Test:");
}

long oldPosition1  = -999;
long oldPosition2  = -999;

void loop() {
  long newPosition1 = myEnc1.read();
  if (newPosition1 != oldPosition1) {
    oldPosition1 = newPosition1;
    SerialUSB.print("Motor 1: "); 
    SerialUSB.println(newPosition1);
  }
  long newPosition2 = myEnc2.read();
    if (newPosition2 != oldPosition2) {
    oldPosition2 = newPosition2;
    SerialUSB.print("Motor 2: ");
    SerialUSB.println(newPosition2);
  }
}
