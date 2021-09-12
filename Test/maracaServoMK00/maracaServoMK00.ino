#include <Servo.h>
Servo maracaServo1;
Servo maracaServo2;

void setup() {
  maracaServo1.attach(4);   // Maraca 1 attached to arduino Digital 4 pin
  maracaServo2.attach(5);   // Maraca 2 attached to arduino Digital 5 pin
}

void loop() {
  maracaServo1.write(0);    // Maraca 1 moves to 0 angle
  maracaServo1.write(90);   // Maraca 1 moves to 90 angle
  delay(500);             // Time delay in ms ie 1000ms = 1 second
  maracaServo2.write(0);    // Maraca 2 moves to 0 angle
  maracaServo2.write(90);   // Maraca 2 moves to 90 angle
  delay(500);
  maracaServo1.write(90);
  maracaServo1.write(0);
  delay(500);
  maracaServo2.write(90);
  maracaServo2.write(0);
  delay(500);           //Copy and paste the above set of codes and change the servo angles and time delay to make some tunes 
}
