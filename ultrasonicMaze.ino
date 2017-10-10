#include <Servo.h>
// 서보모터 객체 생성
Servo myServo1;
Servo myServo2;

//1번 초음파 센서 초기화
const int trigPin1 = 9;
const int echoPin1 = 10;

//2번 초음파 센서 초기화
const int trigPin2 = 5;
const int echoPin2 = 6;

//1번 초음파 센싱, 거리 측정, 각도 초기화
long duration1;
int distance1;
float angle1;

//2번 초음파 센싱, 거리 측정, 각도 초기화
long duration2;
int distance2;
float angle2;

void setup() {
  //1번 초음파센서 핀모드 세팅
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  //2번 초음파센서 핀모드 세팅
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  //시리얼 모니터링을 위한 세팅
  Serial.begin(9600);

  //1, 2서보모터 핀 설정 
  myServo1.attach(3);
  myServo2.attach(11);
}

void loop() {
  //거리 측정 함수 호출
  dist1();
  dist2();

  //서보모터 컨트롤 함수 호출
  servoControl1();
  servoControl2();
}

void dist1() {
  //1번 초음파센서 거리 측정
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;
}

void dist2() {
  //2번 초음파센서 거리 측정
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;
}


void servoControl1() {
  //측정된 거리의 한도 설정
  distance1 = constrain(distance1, 10, 50);
  //거리를 각도로 전환
  angle1 = map(distance1, 10, 50, 70, 110);
  //서보모터에 해당 각도적용
  myServo1.write(angle1);

//  Serial.print("distance1 = ");
//  Serial.print(distance1);
//  Serial.print("  angle1 = ");
//  Serial.print(angle1);
}

void servoControl2() {
  //측정된 거리의 한도 설정
  distance2 = constrain(distance2, 10, 50);
  //거리를 각도로 전환
  angle2 = map(distance2, 10, 50, 70, 110);
  //서보모터에 해당 각도적용
  myServo2.write(angle2);
  
//  Serial.print("  distance2 = ");
//  Serial.print(distance2);
//  Serial.print("  angle2 = ");
//  Serial.println(angle2);
}
