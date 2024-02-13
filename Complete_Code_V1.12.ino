// Step motor and photoresistor code for Heisenberg Uncertainty Princilpe experiment.

#include <Stepper.h>

// Constants
const int stepsPerRevolution = 10096; // Adjust as needed for 28BYJ-48
const float stepAngleDegrees = 0.088; // Step angle in degrees (1.8°)
const float leadMM = 10; // Lead of the ball screw (distance traveled per rotation, in mm)

// Create a stepper motor object called 'myStepper', note the pin order:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

float totalDistanceMM = 0.0; // Initialize total distance traveled

void setup() {
  // Set up serial communication
  Serial.begin(9600);

  // Set the speed to move 1 mm per step:
  myStepper.setSpeed(1 / (stepAngleDegrees * leadMM));
}

void loop() {
  // Move one step forward:
  myStepper.step(10); // Changed to move 1 step (1 mm)

  // Calculate distance traveled in millimeters:
  float distanceTraveledMM = 0.02; // Each step moves 0.02 mm
  totalDistanceMM += distanceTraveledMM; // Update total distance

  // Read the input on analog pin 0 (you'll need to connect a resistor or sensor):
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1024.0);
  // Calculate resistance (assuming a fixed resistor):
  float resistance = (5.0 * 4700.0) / (5.0 - voltage); // Corrected formula

  // Print out the value you read:
  Serial.print("Distance traveled: ");
  Serial.print(totalDistanceMM, 2); // Display distance with 2 decimal places
  Serial.print(" mm | Resistance: ");
  Serial.print(resistance, 2); // Display resistance with 2 decimal places
  Serial.println(" Ohms");
}
