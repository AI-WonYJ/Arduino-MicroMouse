#include <SoftwareSerial.h>
#include <AFMotor.h>

int Trig_Pin = A5;
int Echo_Pin = A4

AF_DCMotor motor_1(1);

void setup() {
  motor_1.setSpeed(70);
  motor_1.run(RELEASE);
  pinMode(Trig_Pin, OUTPUT);
  pinMode(Echo_Pin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  float Duration, Distance;
  digitalWrite(Trig_Pin, HIGH);
  delay(10);
  digitalWrite(Trig_Pin, LOW);
  Duration = PulseIn(Echo_Pin, HIGH);
  Distance = (((float) (340 * Duration) / 10000) / 2) - 0.6;

  if (Distance <= 30) {
    motor_1.setSpeed(50);
    motor_1.run(FORWARD);
  }
  else if (Distance <= 20) {
    motor_1.setSpeed(20);
    motor_1.run(FORWARD);
  }
  else if (Distance <= 10) {
    motor_1.run(RELEASE);
  }
  else {
    motor_1.setSpeed(80);
  }
}
