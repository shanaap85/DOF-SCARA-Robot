#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Servo channels
#define SERVO_BIG 0
#define SERVO_SMALL 1

// Stepper
#define STEP_PIN 2
#define DIR_PIN 3

#define SERVOMIN 150
#define SERVOMAX 600

int totalSteps = 1000;   // 120°
int numRamps = 5;        // number of ramp segments

void setServoAngle(int ch, int angle) {
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(ch, 0, pulse);
}

void stepMotor(int steps) {
  for(int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);
  }
}

void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  digitalWrite(DIR_PIN, HIGH);

  pwm.begin();
  pwm.setPWMFreq(50);

  setServoAngle(SERVO_BIG, 40);
  setServoAngle(SERVO_SMALL, 90); // pen down
}

void loop() {

  int stepsPerRamp = totalSteps / numRamps;

  int startAngle = 40;
  int endAngle = 90;

  for(int r = 0; r < numRamps; r++) {

    // 🔺 Ramp UP
    for(int i = 0; i < stepsPerRamp; i++) {

      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(800);
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(800);
    
      int angle = map(i, 0, stepsPerRamp, startAngle, endAngle);
      setServoAngle(SERVO_BIG, angle);
    }
      
    // 🔻 Quick reset
    setServoAngle(SERVO_BIG, startAngle);
    delay(200);
  }

   while(1);
}
