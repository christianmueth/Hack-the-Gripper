#include <Stepper.h>
#include<Servo.h>
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 10, 11, 12,13);
Stepper myStepper2(stepsPerRevolution, 6, 7, 8, 9);
Stepper myStepper3(stepsPerRevolution, 2, 3, 4, 5);
Servo ser1;

int poser = 0; // initial position of server

int val; // initial value of input

void setup() {
myStepper.setSpeed(40);
myStepper2.setSpeed(40);
myStepper3.setSpeed(20);
Serial.begin(9600); // Serial comm begin at 9600bps
ser1.attach(A1);

}

void loop() {

if (Serial.available()) // if serial value is available

{

val = Serial.read();// then read the serial value

if (val == 'd') //if value input is equals to d

{

poser += 1; //than position of servo motor increases by 1 ( anti clockwise)

ser1.write(poser);// the servo will move according to position

delay(15);//delay for the servo to get to the position

}

if (val == 'a') //if value input is equals to a

{

poser -= 1; //than position of servo motor decreases by 1 (clockwise)

ser1.write(poser);// the servo will move according to position

delay(15);//delay for the servo to get to the position

}

if (val == 'o') //if value input is equals to a

{

Serial.println("clockwise");
myStepper3.step(stepsPerRevolution);

delay(15);//delay for the servo to get to the position

}
{

if (val == 'p') //if value input is equals to d

{

Serial.println("counterclockwise");
myStepper3.step(-stepsPerRevolution);
delay(15);//delay for the servo to get to the position

}
if (val == 'k') //if value input is equals to a

{

Serial.println("clockwise");
myStepper2.step(stepsPerRevolution);

delay(15);//delay for the servo to get to the position

}
{

if (val == 'l') //if value input is equals to d

{

Serial.println("counterclockwise");
myStepper2.step(-stepsPerRevolution);
delay(15);//delay for the servo to get to the position

}

if (val == 'n') //if value input is equals to a

{

Serial.println("clockwise");
myStepper.step(stepsPerRevolution);

delay(15);//delay for the servo to get to the position

}
{

if (val == 'm') //if value input is equals to d

{

Serial.println("counterclockwise");
myStepper.step(-stepsPerRevolution);
delay(15);//delay for the servo to get to the position

}


}}}}}
