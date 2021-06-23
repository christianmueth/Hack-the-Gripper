#include <SoftwareSerial.h>
#include <Servo.h>

Servo ESC;
Servo servo;
SoftwareSerial mySerial(2, 3);
int k = 160;
char bt='S';
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
 ESC.attach(13);
  servo.attach(9);
  servo.write(k);
   Stop();
}

void loop() 
{
bt = mySerial.read();

if(bt=='F')
{
 forward(); 
}

if(bt=='B')
{
 backward(); 
}

if(bt=='L')
{
 left(); 
}

if(bt=='R')
{
 right(); 
}

if(bt=='S')
{
 Stop(); 
}

}
void forward()
{
      ESC.write(700);
       ESC.write(2000);
}

void backward()
{
      ESC.write(700);
}
void left()
{
  k = k+15;
 servo.write(k);
}
void right()
{
  k = k-15;
  servo.write(k);
}
void Stop()
{

  
}
