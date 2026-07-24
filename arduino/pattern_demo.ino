#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <AccelStepper.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define STEP_PIN 2
#define DIR_PIN 3

AccelStepper stepper(1, STEP_PIN, DIR_PIN);

/* Servo pulse limits */
#define SERVOMIN 150
#define SERVOMAX 600

int angleToPulse(int angle)
{
  return map(angle,0,180,SERVOMIN,SERVOMAX);
}

/* Smooth servo motion */
void moveServo(int channel,int startAngle,int endAngle)
{
  if(startAngle < endAngle)
  {
    for(int i=startAngle;i<=endAngle;i++)
    {
      pwm.setPWM(channel,0,angleToPulse(i));
      delay(20);
    }
  }
  else
  {
    for(int i=startAngle;i>=endAngle;i--)
    {
      pwm.setPWM(channel,0,angleToPulse(i));
      delay(20);
    }
  }
}

void setup()
{
  Serial.begin(9600);

  pwm.begin();
  pwm.setPWMFreq(50);

  /* Stepper slow speed */
  stepper.setMaxSpeed(300);
  stepper.setAcceleration(100);

  /* Initial positions */
  pwm.setPWM(1,0,angleToPulse(90));   // MG90 metal (elbow)
  pwm.setPWM(2,0,angleToPulse(10));   // MG90S pen up

  delay(2000);
}

void loop()
{

  /* 1 Rotate base slowly */
  stepper.moveTo(400);

  while(stepper.distanceToGo()!=0)
  {
    stepper.run();
  }

  delay(1000);

  /* 2 Pen down */
  moveServo(2,10,60);

  delay(500);

  /* 3 Move elbow */
  moveServo(1,90,120);

  delay(1500);

  /* 4 Pen up */
  moveServo(2,60,10);

  delay(500);

  /* 5 Return elbow */
  moveServo(1,120,90);

  delay(500);

  /* 6 Rotate base back */
  stepper.moveTo(0);

  while(stepper.distanceToGo()!=0)
  {
    stepper.run();
  }

  delay(4000);

}

