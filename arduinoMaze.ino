#include <Servo.h>


Servo myServo1;
Servo myServo2;

const int trigPin1 = 9;
const int echoPin1 = 10;

const int trigPin2 = 5;
const int echoPin2 = 6;

long duration1;
int distance1;
float angle1;

long duration2;
int distance2;
float angle2;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  Serial.begin(9600);
  myServo1.attach(3);
  myServo2.attach(11);
}

void loop() {
  dist1();
  dist2();
  servoControl1();
  servoControl2();
}

void dist1() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;
}

void dist2() {
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;
}


void servoControl1() {
  distance1 = constrain(distance1, 10, 50);
  angle1 = map(distance1, 10, 50, 70, 110);
  myServo1.write(angle1);

//  Serial.print("distance1 = ");
//  Serial.print(distance1);
//  Serial.print("  angle1 = ");
//  Serial.print(angle1);
}

void servoControl2() {
  distance2 = constrain(distance2, 10, 50);
  angle2 = map(distance2, 10, 50, 70, 110);
  myServo2.write(angle2);
  
//  Serial.print("  distance2 = ");
//  Serial.print(distance2);
//  Serial.print("  angle2 = ");
//  Serial.println(angle2);
}
