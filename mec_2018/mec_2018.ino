#include <Servo.h>

const int EN_L = 11;
const int EN_R = 3;

// left motor
const int INA_L = 10;
const int INB_L = 9;

// right motor
const int INA_R = 6;
const int INB_R = 5;

Servo servos1; 
Servo servos2;
int SERVOS_1_PIN = 10;

// Serial Variables
int incomingByte = 0;   

void setup() {
        Serial.begin(9600); 
        
        pinMode(INA_L, OUTPUT);
        pinMode(INB_L, OUTPUT);
        pinMode(EN_L, OUTPUT);

        pinMode(INA_R, OUTPUT);
        pinMode(INB_R, OUTPUT);
        pinMode(EN_R, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.println(incomingByte);
    if (incomingByte == 119) { // w
      forward();
    }
    if (incomingByte == 115) { // s
      backward();
    }
    
    if (incomingByte == 97) { //a
      turnLeft();
    }

    if (incomingByte == 100) { //d
      turnRight();
    }

    delay(80);
    stopMotors();
  }
}

void forward() {
  digitalWrite(EN_L, HIGH);
  digitalWrite(INA_L, HIGH);
  digitalWrite(INB_L, LOW);

  digitalWrite(EN_R, HIGH);
  digitalWrite(INA_R, HIGH);
  digitalWrite(INB_R, LOW);
}

void backward() {
  digitalWrite(EN_L, HIGH);
  digitalWrite(INA_L, LOW);
  digitalWrite(INB_L, HIGH);

  digitalWrite(EN_R, HIGH);
  digitalWrite(INA_R, LOW);
  digitalWrite(INB_R, HIGH);
}

void turnLeft() {
  digitalWrite(EN_L, HIGH);
  digitalWrite(INA_L, LOW);
  digitalWrite(INB_L, HIGH);

  digitalWrite(EN_R, HIGH);
  digitalWrite(INA_R, HIGH);
  digitalWrite(INB_R, LOW);
}

void turnRight() {
  digitalWrite(EN_L, HIGH);
  digitalWrite(INA_L, HIGH);
  digitalWrite(INB_L, LOW);

  digitalWrite(EN_R, HIGH);
  digitalWrite(INA_R, LOW);
  digitalWrite(INB_R, HIGH);
}

void stopMotors() {
  digitalWrite(EN_L, LOW);
  digitalWrite(INA_L, LOW);
  digitalWrite(INB_L, LOW);

  digitalWrite(EN_R, LOW);
  digitalWrite(INA_R, LOW);
  digitalWrite(INB_R, LOW);
}
