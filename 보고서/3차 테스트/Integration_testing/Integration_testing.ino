#include <SoftwareSerial.h>
#include <AFMotor.h>

int Trig_Pin = A5;
int Echo_Pin = A4;

AF_DCMotor motor_1(1);

void setup() {
  motor_1.setSpeed(70);
  motor_1.run(RELEASE);
  pinMode(Trig_Pin, OUTPUT);
  pinMode(Echo_Pin, INPUT);

  Serial.begin(9600);
}

void loop() {
  float Duration, Distance;
  digitalWrite(Trig_Pin, HIGH);
  delay(10);
  digitalWrite(Trig_Pin, LOW);
  Duration = pulseIn(Echo_Pin, HIGH);
  Distance = (((float) (340 * Duration) / 10000) / 2) - 0.6;

  if (Distance <= 10) {
    motor_1.setSpeed(0);
    motor_1.run(RELEASE);
    Serial.print("0  :  ");
  }
  else if (Distance <= 15) {
    motor_1.setSpeed(40);
    motor_1.run(FORWARD);
    Serial.print("40  :  ");
  }
  else if (Distance <= 20) {
    motor_1.setSpeed(50);
    motor_1.run(FORWARD);
    Serial.print("50  :  ");
  }
  else if (Distance <= 25) {
    motor_1.setSpeed(60);
    motor_1.run(FORWARD);
    Serial.print("60  :  ");
  }
  else if (Distance <= 30) {
    motor_1.setSpeed(70);
    motor_1.run(FORWARD);
    Serial.print("70  :  ");
  }
  else {
    motor_1.setSpeed(90);
    motor_1.run(FORWARD);
    Serial.print("90  :  ");
  }
 
  Serial.print(Distance);                     // 시리얼 창에 줄바꿈 없이 거리 출력
  Serial.println("cm");                       // 단위 출력
}
