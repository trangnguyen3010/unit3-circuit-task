#include <Servo.h>  //include the servo library

Servo myservo;  //create a servo object

void setup() {
  Serial.begin(9600);  //begin serial communication with the computer

  //prompt the user to enter a command
  Serial.println("Enter an angle for the servo motor to spin (10-170):");

  myservo.attach(9);  //tell the servo object that its servo is plugged into pin 9
}

void loop() {
  if (Serial.available() > 0)  //if the user has sent a command to the RedBoard
  {
    String angle = Serial.readStringUntil('\n');      //read the characters in the command until you reach the second space

    //print the command that was just received in the serial monitor
    Serial.println(angle.toInt());

    if ( !(angle.toInt() >= 10 && angle.toInt() <= 170)) {
      Serial.println("Angle must be between 10 and 170!!");
      return;
    }

    myservo.write(angle.toInt());  //move the servo to the 10 degree position
  }
}
