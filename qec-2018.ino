#include <SparkFun_TB6612.h>
#include <Servo.h>

// MOTOR SHIELD CONFIG
// Pins for all inputs, keep in mind the PWM defines must be on PWM pins
// the default pins listed are the ones used on the Redbot (ROB-12097) with
// the exception of STBY which the Redbot controls with a physical switch
#define AIN1 2
#define BIN1 7
#define AIN2 4
#define BIN2 8
#define PWMA 5
#define PWMB 6
#define STBY 9
// these constants are used to allow you to make your motor configuration 
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;
const int offsetB = 1;

// Motor Variables
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

// Servos Variables
Servo servos1; 
Servo servos2;
int SERVOS_1_PIN = 10;

// Serial Variables
int incomingByte = 0;   

void setup() {
        Serial.begin(9600); 
        // init servos
        servos1.attach(SERVOS_1_PIN);
        servos1.write(20);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.println(incomingByte);

    // L Key - Lower Arm
    if (incomingByte == 108) {
      Serial.println("Lower Arm");
      lowerArm();
    }

    // P Key - Raise Arm
    if (incomingByte == 112) {
      Serial.println("Raise Arm");
      raiseArm();
    }

    // K Key - Release Ball
    if (incomingByte == 107) {
      Serial.println("Release Ball");
      releaseBall();
    }

    // W Key - Move Forward
    if (incomingByte == 119) {
      Serial.println("Forward");
      moveForward();
    }

    // S Key - Move Backward
    if (incomingByte == 115) {
      Serial.println("Backward");
      moveBackward();
    }

    // D Key - Turn Right
    if (incomingByte == 100) {
      Serial.println("Right");
      turnRight();
    }

    // A Key - Turn Left
    if (incomingByte == 97) {
      Serial.println("Left");
      turnLeft();
    }
    delay(80);
    brake(motor1, motor2);
  }

}

void lowerArm() {
  servos1.write(150);
}

void raiseArm() {
  servos1.write(90);
}

void releaseBall() {
  servos1.write(0);
}

void moveForward() {
  forward(motor1, motor2, 80);
}

void moveBackward() {
  back(motor1, motor2, -80);
}

void turnRight() {
  right(motor1, motor2, 70);
}

void turnLeft() {
  left(motor1, motor2, 70);
}




