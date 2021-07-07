// C++ code
//
#include <Servo.h>

int distance = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_5;

void setup()
{
  servo_5.attach(5, 500, 2500);

  pinMode(3, OUTPUT);
}

void loop()
{
  distance = 0.01723 * readUltrasonicDistance(12, 12);
  if (distance > 100) {
    servo_5.write(0);
    digitalWrite(3, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    servo_5.write(180);
    digitalWrite(3, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }
}