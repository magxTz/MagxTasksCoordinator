#include <magxTasksCoordinator.h>
void callback1();
void callback2();
void callback3();
void repeatCallback();
magxTaskCoordinator timer1(60);
magxTaskCoordinator timer2(200);
magxTaskCoordinator timer3(500,10,5000);

magxTasksManager manager;

#define LED2 12
#define LED3 9
#define PUSH1 11
#define PUSH2 10
#define PUSH3 8

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(PUSH1, INPUT);
  pinMode(PUSH2, INPUT);
  pinMode(PUSH3, INPUT);
  timer1.setCallback(callback1);
  timer1.setType(magxTaskCoordinator::Periodic);
  timer2.setCallback(callback2);
  timer2.setType(magxTaskCoordinator::Periodic);
  timer3.setCallback(callback3);
  timer3.setType(magxTaskCoordinator::Periodic);
  //timer3.setRepeatTimeoutCallback(repeatCallback);
  
  manager.addTimer(&timer1);
  manager.addTimer(&timer2);
  manager.addTimer(&timer3);
  timer1.start();
  timer3.start();
}
void loop()
{
  manager.updateTimers();
  if(digitalRead(PUSH1))
  {
    timer2.start();
  }
  if(digitalRead(PUSH2))
  {
    timer2.stop();
  }
  
  
}
void callback1(){
  digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
}
void callback3(){
  digitalWrite(LED3,!digitalRead(LED3));
}
void callback2(){
  digitalWrite(LED2,!digitalRead(LED2));
}

void repeatCallback(){
  Serial.println("RepeatTimeoutCallback called!");
}