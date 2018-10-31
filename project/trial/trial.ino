/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>
int incomingByte;


Servo myservo;  // create servo object to control a servo


void setup() {
  myservo.attach(9);
  Serial.begin(9600);// attaches the servo on pin 9 to the servo object
}

void loop() {
  if(Serial.available()>0)
  {
  incomingByte = Serial.parseInt();
  Serial.println(incomingByte);
  
       // scale it to use it with the servo (value between 0 and 180)
  myservo.write(incomingByte);                  // sets the servo position according to the scaled value
                            // waits for the servo to get there
}
}
