#include <Servo.h>

Servo myservo;
int servoValue = 0;
byte data[2];
int pos = 0;
int a;
int b;


void setup() {
  myservo.attach(9);
 
   Serial.begin(9600);
}


void loop() {

 if(Serial.available() > 0){
    /*data[0] = Serial.read();
    data[1] = Serial.read();*/
    Serial.readBytes(data, 2);
   }
  a = data[0] & 0xff;
  b = data[1] & 0xff;
  servoValue = a*256+b;
  servoValue = map(servoValue, 0, 1023, 0, 180);
  myservo.write(servoValue);
  delay(15);
}
