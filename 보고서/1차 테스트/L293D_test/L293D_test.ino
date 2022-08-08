#include <SoftwareSerial.h>
#include <AFMotor.h>

AF_DCMotor motor_1(1);

void setup() {
  motor_1.setSpeed(70);
  motor_1.run(RELEASE);
}

void loop() {
  motor_1.run(FORWARD);
  delay(1000);
  motor_1.run(RELEASE);
  delay(1000);
  motor_1.run(BACKWARD);
  delay(1000);
  motor_1.run(RELEASE);
  delay(1000);
}
