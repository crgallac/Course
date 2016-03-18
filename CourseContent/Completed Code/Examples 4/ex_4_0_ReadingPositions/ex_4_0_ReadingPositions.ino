#define ENCpin1 28
#define ENCpin2 29

#include <Encoder.h>

Encoder myEnc(ENCpin1, ENCpin2);

void setup() {
  SerialUSB.begin(9600);
  while(!SerialUSB); 
  SerialUSB.println("Basic Encoder Test:");
}

long oldPosition  = -999;
long newPosition = 999; 
void loop() {
  newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    SerialUSB.println(newPosition);
  }
}
