//For arduino uno

#include <Stepper.h>

#include<Servo.h>

const int stepsPerRevolution = 200;//Define # of steps in stepper rotation

Stepper myStepper1(stepsPerRevolution, 10, 11, 12,13);//define stepper 1 at given pins (10, 11, 12, 13)

Stepper myStepper2(stepsPerRevolution, 6, 7, 8, 9);//define stepper 2 at given pins (6, 7, 8, 9)

Servo ser1;//define name for servo motor

int poser = 0; // initial position of server

int val; // initial value of input

void setup() {

myStepper1.setSpeed(40);//Set speed of stepper

myStepper2.setSpeed(40);//Set speed of stepper

Serial.begin(9600); // Serial comm begin at 9600bps

ser1.attach(A1); //define pin for servo motor

}

void loop() {

if (Serial.available()) // if serial value is available

{

val = Serial.read();// then read the serial value

if (val == 'd') //if value input is equals to d

{

poser += 1; //then position of servo motor increases by 1 ( anti clockwise)

ser1.write(poser);// the servo will move according to position

delay(15);//delay for the servo to get to the position

}

if (val == 'a') //if value input is equals to a

{

poser -= 1; //then position of servo motor decreases by 1 (clockwise)

ser1.write(poser);// the servo will move according to position

delay(15);//delay for the servo to get to the position

}

if (val == 'o') //if value input is equals to o

{

Serial.println("clockwise");//clockwise motion

myStepper1.step(stepsPerRevolution);//confirm clockwise motion

delay(15);//delay for the stepper to get to the position

}
{

if (val == 'p') //if value input is equals to p

{

Serial.println("counterclockwise");//counterclockwise motion

myStepper1.step(-stepsPerRevolution);//counterclockwise steps

delay(15);//delay for the stepper to get to the position

}
if (val == 'k') //if value input is equals to k

{

Serial.println("clockwise");//clockwise motion

myStepper2.step(stepsPerRevolution);//clockwise steps

delay(15);//delay for the stepper to get to the position

}
{

if (val == 'l') //if value input is equals to l

{

Serial.println("counterclockwise");//counterclockwise motion

myStepper2.step(-stepsPerRevolution);//counterclockwise steps

delay(15);//delay for the stepper to get to the position

}
}}}}
