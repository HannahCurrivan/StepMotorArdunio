# StepMotorArdunio
A very simple Ardunio code to move a step motor and take resistance readings.
The following code is combining the step motor function and retrieving data from the photoresister. This leads to two outputs the distance travelled along a rail and the resistance from the photoresister.


After going through a number of versions to ultimately land on a Arduino script that works best for the Heisenberg Uncertainty Prinple experimental setup. 

It begins with including an outside library called "Stepper.h>.
```python
#include <Stepper.h>
```

Layout three constants, one is to adjust as needed for 28BYJ-48m, followed by the step angle in degrees, and finally include lead  of the ball screw which is the distance traveled r rotation in mm.  
```python
// Constants
const int stepsPerRevolution = 10096; // Adjust as needed for 28BYJ-48
const float stepAngleDegrees = 0.088; // Step angle in degrees (1.8°)
const float leadMM = 10; // Lead of the ball screw (distance traveled per rotation, in mm)
```

Now state the pins which the Ardunio is driving the step motor, and in this case it is pin, 8,10,9,11.
```python
// Create a stepper motor object called 'myStepper', note the pin order:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
```

Then providing the code to initialise the total distance traveled.
```python
float totalDistanceMM = 0.0; // Initialize total distance traveled
```

Within the "Void setup()", the serial communication is set to 9600, and set the speed of the step emotor to move 1mm per step.
```python
void setup() {
  // Set up serial communication
  Serial.begin(9600);

  // Set the speed to move 1 mm per step:
  myStepper.setSpeed(1 / (stepAngleDegrees * leadMM));
}
```

In the following "Void loop()" it states the step motor steps (+ for forward, - for backward). Then it calculates the distance traveled in millimeters.
```python
void loop() {
  // Move one step forward:
  myStepper.step(10); // Changed to move 1 step (1 mm)

  // Calculate distance traveled in millimeters:
  float distanceTraveledMM = 0.02; // Each step moves 0.02 mm
  totalDistanceMM += distanceTraveledMM; // Update total distance
```

The photoresistor 

