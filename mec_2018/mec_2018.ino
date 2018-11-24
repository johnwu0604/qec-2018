#include <Servo.h>

const int EN_L = 8;
const int EN_R = 3;

// left motor
const int INA_L = 11;
const int INB_L = 9;

// right motor
const int INA_R = 6;
const int INB_R = 5;

// speed
int currentSpeed = 255;

Servo servos1; 
int SERVOS_PIN = 10;

// Serial Variables
int incomingByte = 0;   

void setup() {
        Serial.begin(9600); 

        servos1.attach(SERVOS_PIN);
        servos1.write(90);
        
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

    if (incomingByte == 112) { //p
      increaseSpeed();
    }

    if (incomingByte == 108) { //l
      decreaseSpeed();
    }

    if (incomingByte == 109) { //m
      raiseArm();
    }

    if (incomingByte == 110) { //n
      lowerArm();
    }

    delay(20);
    stopMotors();
  }
}

void forward() {
  digitalWrite(EN_L, HIGH);
  analogWrite(INA_L, 255);
  analogWrite(INB_L, 0);

  digitalWrite(EN_R, HIGH);
  analogWrite(INA_R, currentSpeed);
  analogWrite(INB_R, 0);
}

void backward() {
  digitalWrite(EN_L, HIGH);
  analogWrite(INA_L, 0);
  analogWrite(INB_L, 255);

  digitalWrite(EN_R, HIGH);
  analogWrite(INA_R, 0);
  analogWrite(INB_R, currentSpeed);
}

void turnLeft() {
  digitalWrite(EN_L, HIGH);
  analogWrite(INA_L, 0);
  analogWrite(INB_L, 255);

  digitalWrite(EN_R, HIGH);
  analogWrite(INA_R, currentSpeed);
  analogWrite(INB_R, 0);
}

void turnRight() {
  digitalWrite(EN_L, HIGH);
  analogWrite(INA_L, 255);
  analogWrite(INB_L, 0);

  digitalWrite(EN_R, HIGH);
  analogWrite(INA_R, 0);
  analogWrite(INB_R, currentSpeed);
}

void stopMotors() {
  digitalWrite(EN_L, LOW);
  analogWrite(INA_L, 0);
  analogWrite(INB_L, 0);

  digitalWrite(EN_R, LOW);
  analogWrite(INA_R, 0);
  analogWrite(INB_R, 0);
}

void lowerArm() {
  Serial.print("Lower arm");
  servos1.write(50);
  delay(10);
  servos1.write(90);
}

void raiseArm() {
  Serial.print("Raise arm");
  servos1.write(130);
  delay(10);
  servos1.write(90);
}

void increaseSpeed() {
  if (currentSpeed < 255) {
    currentSpeed+=5;
  }
  Serial.print("Current speed: ");
  Serial.println(currentSpeed);
}

void decreaseSpeed() {
  if (currentSpeed > 100) {
    currentSpeed-=5;
  }
  Serial.print("Current speed: ");
  Serial.println(currentSpeed);
}
