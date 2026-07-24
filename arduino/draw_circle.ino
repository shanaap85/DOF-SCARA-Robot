#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <AccelStepper.h>
#include <math.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define STEP_PIN 2
#define DIR_PIN 3

AccelStepper stepper(1, STEP_PIN, DIR_PIN);

/* Channels */
#define ELBOW 1
#define PEN   2

#define SERVOMIN 150
#define SERVOMAX 600

int yPos = 90;
int penPos = 10;

/* Convert angle */
int angleToPulse(int angle){
  return map(angle,0,180,SERVOMIN,SERVOMAX);
}

/* Smooth servo */
void moveServo(int ch, int &cur, int target){
  while(cur != target){
    cur += (cur < target) ? 1 : -1;
    pwm.setPWM(ch,0,angleToPulse(cur));
    delay(8);
  }
}

/* Stepper move */
void moveBase(int target){
  stepper.moveTo(target);
  while(stepper.distanceToGo()!=0){
    stepper.run();
  }
}

/* Pen */
void penDown(){ moveServo(PEN, penPos, 60); }
void penUp(){ moveServo(PEN, penPos, 10); }

/* -------- CIRCLE -------- */
void drawCircle(){

  int centerX = 200;
  int radius  = 40;   
  int centerY = 90;

  penDown();

  for(int angle = 0; angle <= 360; angle += 6){

    float rad = angle * 3.1416 / 180;

    int x = centerX + radius * cos(rad);
    int y = centerY + 20 * sin(rad);

    moveBase(x);
    moveServo(ELBOW, yPos, y);

    delay(15);
  }

  penUp();
}

/* -------- SETUP -------- */
void setup(){

  pwm.begin();
  pwm.setPWMFreq(50);

  stepper.setMaxSpeed(400);
  stepper.setAcceleration(150);

  pwm.setPWM(ELBOW,0,angleToPulse(yPos));
  pwm.setPWM(PEN,0,angleToPulse(penPos));

  delay(2000);
}

/* -------- LOOP -------- */
void loop(){

  drawCircle();

  delay(5000);
}
