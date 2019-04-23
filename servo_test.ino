#include <Servo.h>
#define PIN_SERVO 9

Servo servo;

int pulsante=2;
int stato_pulsante=0;

void setup() {
  servo.attach(PIN_SERVO);
  pinMode(pulsante,INPUT);
}

void loop() {

  stato_pulsante=digitalRead(pulsante);
  Serial.print(stato_pulsante);

  int randomVal = random(0, 180);

  if(stato_pulsante == HIGH) {
    for(int i=0; i<randomVal; i++) {
      servo.write(i);
      delay(10);
    }
  
    for(int i = randomVal; i>= 0; i--) {
      servo.write(i);
      delay(10);    
    }    
  }
}
