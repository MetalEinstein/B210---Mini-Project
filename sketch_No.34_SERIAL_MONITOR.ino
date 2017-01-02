int pinPot = A0;

void setup(){
  pinMode(pinPot, INPUT);
  Serial.begin(9600);
}


int potValue;
byte data[2];

void loop() {
  potValue = analogRead(pinPot);
  // delay(100);
 Serial.write(potValue/ 256);
   delay(30);
 Serial.write(potValue % 256);
   delay(30);
  //Serial.print("value = ");
  //Serial.print(potValue);
  
}
