#include <Arduino.h>
#include <magxTasksCoordinator.h>

/**
 * author: Alex Gabriel Malisa
 * email : alexgabrielmalisa@gmail.com
 * 
 * 
 * Blink_with_repeatTimeoutCallback: In this example, we create a task to control LED 
 *      1. BLINK_TIMER: 
 *          
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
magxTaskCoordinator BLINK_TIMER (1000,2,1000);
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

//Callbacks for BLINK_TIMER 

void ON_CB(){
  //flash LED symmetrically
  digitalWrite(LED_BUILTIN,HIGH);
  
}
void OFF_CB(){
  //flash LED symmetrically
  digitalWrite(LED_BUILTIN,LOW);
  
}





void setup() {
    // Initialize Serial Monitor
    Serial.begin(9600);
    pinMode(LED_BUILTIN,OUTPUT);

    

    // Set the callback
    BLINK_TIMER.setCallback(ON_CB);
    BLINK_TIMER.setRepeatTimeoutCallback(OFF_CB);
    

    // Set the timer type (Periodic or OneShot)
    BLINK_TIMER.setType(magxTaskCoordinator::Periodic);

    manager.addTimer(&BLINK_TIMER);

    // Start the TEMPERATURE_TIMER task
    BLINK_TIMER.start();
    
}

void loop() {
    // Update the task coordinator
    manager.updateTimers();
}
