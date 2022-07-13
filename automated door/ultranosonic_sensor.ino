#include  <Servo.h>
int trigPin = 2;
int echoPin=7;
int pingtraveltime;

int servoPin=8;
int servopos=90;
int servopos2= 0;
Servo myservo;

int ledPinG=9;
int ledPinR=6;


void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(servoPin,OUTPUT);
  pinMode(ledPinG,OUTPUT);
  pinMode(ledPinR,OUTPUT);
  myservo.attach(servoPin);
 Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin,LOW);
delayMicroseconds(10);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
pingtraveltime= pulseIn(echoPin,HIGH);
delay(25);
Serial.println(pingtraveltime);
delay(100);

if ( pingtraveltime<250){
  digitalWrite(ledPinG,HIGH);
  digitalWrite(ledPinR,LOW);
  myservo.write(servopos);
}
else{
  digitalWrite(ledPinG,LOW);
  digitalWrite(ledPinR,HIGH);
  myservo.write(servopos2); 
}

}
