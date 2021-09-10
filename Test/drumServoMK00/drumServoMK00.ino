#include <Servo.h>
Servo drumServo1;
Servo drumServo2;

void setup() {
  drumServo1.attach(2);
  drumServo1.attach(3);
}

void loop() {
  drumServo1.write(0);
  drumServo1.write(90);
  delay(500);
  drumServo2.write(0);
  drumServo2.write(90);
  delay(500);
  drumServo1.write(0);
  drumServo1.write(90);
  delay(500);
  drumServo2.write(0);
  drumServo2.write(90);
  delay(500);
}
