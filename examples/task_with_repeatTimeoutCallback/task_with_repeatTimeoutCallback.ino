#include <Arduino.h>
#include <magxTasksCoordinator.h>

/**
 * author: Alex Gabriel Malisa
 * email : alexgabrielmalisa@gmail.com
 * 
 * 
 * task_with_repeatTimeoutCallback: In this example, we create 2 tasks:
 *      1. TEMPERATURE_TIMER: 
 *          This task collects Temperature data
 *      2. SimpleBlink: 
 *          This task blinks LED_BUILTIN 
 *      
 */

// Create magxTasksCoordinator object
/**
 * Expected arguments:
 *      ?timeOutMs: 
 *              -This is the time in milliseconds after which the callback will be invoked.
 *      ?repeatCount
 *              -This specifies the number of times the first callback will be invoked
 *      ?repeatTimeoutMs 
 *              -This is the time in milliseconds after which the callback will be invoked.
 *   
*/
magxTaskCoordinator TEMPERATURE_TIMER (100,10,5000);
magxTaskCoordinator BLINK_TIMER (1000);
magxTasksManager manager;

// Then define timerType 
/**
 * This is the enum class with only two elements { Periodic, OneShot }
 * Periodic means the event will be repeated continuously at an interval set by the timeoutMs variable.
 * OneShot means the event will execute only once after timeoutMs has elapsed.
*/

// Example:
// TEMPERATURE_TIMER.setType(magxTaskCoordinator::Periodic);
//  BLINK_TIMER.setType(magxTaskCoordinator::Periodic);

//Callbacks for both TEMPERATURE_TIMER and BLINK_TIMER tasks
float temperature=0.0;
//Get random temperature mock data
void GET_TEMP_CB(){
    if(temperature == 0.0){
      Serial.println("    TEMPERATURE DATA   ");
      Serial.print("Current                 ");
      Serial.println("cummulative");
    }
    float num = random(0,100);
    temperature += num;
    Serial.print(num);
    Serial.print("                      ");
    Serial.println(temperature);
    
}
void BLINK_TIMER_CB(){
  //flash LED symmetrically
  digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
  
}

//Compute the avarage of temperature data
void TEMP_AVG_CB(){
  float temp_avg= temperature/10;
  Serial.println("");
  Serial.print("TEMPERATURE - AVARAGE");
  Serial.print("                ");
  Serial.println(temp_avg);
  Serial.println("");
  temperature=0.0;
}



void setup() {
    // Initialize Serial Monitor
    Serial.begin(9600);
    randomSeed(analogRead(A0));
    pinMode(LED_BUILTIN,OUTPUT);

    

    // Set the callback
    TEMPERATURE_TIMER.setCallback(GET_TEMP_CB);
    BLINK_TIMER.setCallback(BLINK_TIMER_CB);
    TEMPERATURE_TIMER.setRepeatTimeoutCallback(TEMP_AVG_CB);
    

    // Set the timer type (Periodic or OneShot)
    TEMPERATURE_TIMER.setType(magxTaskCoordinator::Periodic);
    BLINK_TIMER.setType(magxTaskCoordinator::Periodic);

    manager.addTimer(&BLINK_TIMER);
    manager.addTimer(&TEMPERATURE_TIMER);

    // Start the TEMPERATURE_TIMER task
    TEMPERATURE_TIMER.start();
    BLINK_TIMER.start();
    
}

void loop() {
    // Update the task coordinator
    manager.updateTimers();
}
