#include <AFMotor.h>

AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

const int trigPin = A4;
const int echoPin = A5;
long duration, distance;

const int LDR = A0;
int input_val = 0;

void setup() {
  
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);

}

void loop() {

  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  Serial.println(distance);

  input_val = analogRead(LDR);
  Serial.print("LDR Value is: ");
  Serial.println(input_val);
  
  delay(50);
  
if (input_val > 20){
  if (distance < 45){
    stop();
    digitalWrite(A2, HIGH);
    digitalWrite(A1, LOW);
  }
  else{
    forward();
    digitalWrite(A2, LOW);
    digitalWrite(A1, LOW);
  }
}
else{
  stop();
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  
}
} 

void forward(){

  motor3.setSpeed(110);
  motor4.setSpeed(110);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
    
} 

void stop(){

  motor3.setSpeed(0);
  motor4.setSpeed(0);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
 
}

void uturn(){

  motor3.setSpeed(140);
  motor4.setSpeed(140);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}
