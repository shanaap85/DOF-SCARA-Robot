# Arduino Programs

This folder contains Arduino sketches used to control the 4-DOF SCARA Robot.

### pattern_demo.ino

This Arduino sketch demonstrates coordinated motion of the SCARA robot by controlling:

- NEMA 23 Stepper Motor using TB6600 Driver
- MG90 Metal Gear Servo (Joint-2)
- MG90S Servo (Pen Lift)
- PCA9685 Servo Driver

### Functional Sequence

1. Rotates the robot base.
2. Lowers the pen.
3. Moves the elbow joint.
4. Lifts the pen.
5. Returns the elbow to its initial position.
6. Rotates the base back to the home position.

### Libraries Used

- Wire.h
- Adafruit_PWMServoDriver
- AccelStepper


## draw_circle.ino

This program demonstrates circular trajectory generation using coordinated control of a stepper motor and servo motors.

### Hardware Used

- Arduino Uno
- PCA9685 Servo Driver
- TB6600 Stepper Driver
- NEMA 23 Stepper Motor
- MG90 Metal Gear Servo
- MG90S Servo

### Features

- Smooth servo movement
- Stepper motor position control
- Circular path generation using trigonometric functions
- Pen lift mechanism
- Coordinated multi-axis motion

### Libraries

- Wire.h
- Adafruit_PWMServoDriver
- AccelStepper
- math.h

### Motion Sequence

1. Initialize servo and stepper motors.
2. Lower the pen.
3. Calculate circular coordinates using sine and cosine functions.
4. Synchronize base rotation and elbow movement.
5. Complete the circle.
6. Lift the pen.

## draw_stair_pattern.ino

This Arduino sketch demonstrates coordinated motion between a stepper motor and servo motors to generate a staircase (ramp) pattern.

### Hardware Used

- Arduino Uno
- PCA9685 Servo Driver
- TB6600 Stepper Driver
- NEMA 23 Stepper Motor
- MG996R Servo Motor
- MG90S Servo Motor

### Features

- Stepper motor position control
- Smooth servo angle adjustment
- Coordinated multi-axis motion
- Staircase (ramp) pattern generation
- Pen control mechanism

### Libraries

- Wire.h
- Adafruit_PWMServoDriver

### Motion Sequence

1. Initialize the servo motors and stepper motor.
2. Rotate the stepper motor incrementally.
3. Gradually increase the servo angle to create a ramp.
4. Reset the servo to the initial angle.
5. Repeat the process to generate multiple ramp segments.
