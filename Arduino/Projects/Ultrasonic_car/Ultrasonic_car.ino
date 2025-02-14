/******************************************************************************
***************************2023.9.9********************************************
// Before uploading the code you have to install the necessary library
// To Install the libraries go to sketch >> Include Library >> Add .ZIP File >> Select the Downloaded ZIP files From the Above links //
*******************************************************************************/
#include <AFMotor.h>  
#include <NewPing.h>
#include <Servo.h> 

#define TRIG_PIN A0 
#define ECHO_PIN A1 
#define MAX_DISTANCE 100 //200
#define MAX_SPEED 120 // sets speed of DC  motors
#define MAX_SPEED_OFFSET 20

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 
  

AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
Servo myservo;   

boolean goesForward=false;
int distance = 150;//150
int speedSet = 0;

void setup() {

  myservo.attach(10);  
  myservo.write(115); 
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
 int distanceR = 0;
 int distanceL = 0;
 delay(40);
 
 if(distance<=35)
 {
  moveStop();
  delay(100);
  moveBackward();
  delay(300);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
  {
    turnRight();
    moveStop();
  }else
  {
    turnLeft();
    moveStop();
  }
 }else
 {
  moveForward();
 }
 distance = readPing();
}

int lookRight()
{
    myservo.write(50); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
}

int lookLeft()
{
    myservo.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

void moveStop() {
  motor3.run(RELEASE); 
  motor4.run(RELEASE);
 
} 
  
void moveForward() {

 if(!goesForward)
  {
    goesForward=true;
    motor3.run(FORWARD);      
    motor4.run(FORWARD);
    
   for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
   {
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
   
    delay(5);
   }
  }
}

void moveBackward() {
    goesForward=false;
    motor3.run(BACKWARD);      
    motor4.run(BACKWARD);
   
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
  
    delay(5);
  }
}  

void turnRight() {
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  
  delay(500);
  motor3.run(FORWARD);      
  motor4.run(FORWARD);
      
} 
void turnLeft() {
  motor3.run(BACKWARD);     
  motor4.run(FORWARD);  
   
  delay(500);
  motor3.run(FORWARD);     
  motor4.run(FORWARD);
 
}  
