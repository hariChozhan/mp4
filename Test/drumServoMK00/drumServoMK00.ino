#include <Servo.h>
Servo drumServo1;
Servo drumServo2;

void setup() {
  drumServo1.attach(2);   // Drum Stick 1 attached to arduino Digital 2 pin
  drumServo1.attach(3);   // Drum Stick 2 attached to arduino Digital 3 pin
}

void loop() {
  drumServo1.write(0);    // Drum Stick 1 moves to 0 angle
  drumServo1.write(90);   // Drum Stick 1 moves to 90 angle
  delay(500);             // Time delay in ms ie 1000ms = 1 second
  drumServo2.write(0);    // Drum Stick 2 moves to 0 angle
  drumServo2.write(90);   // Drum Stick 2 moves to 90 angle
  delay(500);
  drumServo1.write(0);
  drumServo1.write(90);
  delay(500);
  drumServo2.write(0);
  drumServo2.write(90);
  delay(500);           //Copy and paste the above set of codes and change the servo angles and time delay to make some tunes 
}
