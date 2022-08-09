// Step 1 핀모드 설정

int tri = A5;
int ech = A4;

void setup() {
  pinMode(tri,OUTPUT);
  pinMode(ech,INPUT);

  Serial.begin(9600);    // 9600속도로 시리얼 통신 시작
}
 
 
// Step 2 반복 실행 코드
 
void loop() {
 
  float Duration,Distance;
 
  digitalWrite(tri, HIGH);                       // 초음파 쏜다.
  delay(10);                                    // 10밀리초 동안
  digitalWrite(tri, LOW);                        // 초음파 끈다.
 
  Duration =pulseIn(ech, HIGH);                 //  echo핀이 HIGH 유지한 시간 저장
  Distance =((float)(340 *Duration) /10000) /2;             //거리를 cm로환산
 
  Serial.print(Distance - 0.6);                     // 시리얼 창에 줄바꿈 없이 거리 출력
  Serial.println("cm");                       // 단위 출력
 
}
