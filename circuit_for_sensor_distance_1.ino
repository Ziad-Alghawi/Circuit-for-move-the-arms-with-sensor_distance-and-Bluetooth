// C++ code
//
#include <Servo.h>
 
/*------------------------------
  For the bluooth
  ------------------------------
//char inputByte; //bluooth
*/
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

Servo servos_left;
Servo servos_right;

void setup()
{
  /* ------------------------------
  For the bluooth
  ---------------------------------
  Serial.begin(9600);//bluooth
 pinMode(13,OUTPUT);
  */
  
  servos_left.attach(5, 500, 2500);
  servos_right.attach(6, 500, 2500);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);

}

void loop()
{
  /*
  ------------------------------
  For the bluooth
  ------------------------------
  while(Serial.available()>0){   //bluooth
  inputByte= Serial.read();
  Serial.println(inputByte);
  if (inputByte=='Z'){
  digitalWrite(13,HIGH);
  }
  else if (inputByte=='z'){
  digitalWrite(13,LOW);
  } 
  }
  ------------------------------------------
  */
  distance = 0.01723 * readUltrasonicDistance(12, 12);
  if (distance > 100) {
    servos_left.write(0);
    servos_right.write(0);
    digitalWrite(3,HIGH ); //green light here will be turn on for open the gate 
    digitalWrite(2,LOW ); // red light here will be turn off 

    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    servos_left.write(180);
    servos_right.write(180);
    digitalWrite(3, LOW); //green light here will be turn off 
    digitalWrite(2, HIGH); // red light here will be turn on for close the gate

    delay(1000); // Wait for 1000 millisecond(s)
  }
}