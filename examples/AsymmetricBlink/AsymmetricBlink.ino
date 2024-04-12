#include <Arduino.h>
#include <magxTasksCoordinator.h>

/**
 * author: Alex Gabriel Malisa
 * email : alexgabrielmalisa@gmail.com
 * 
 * 
 * AsymmetricBlink: In this example, we create 2 tasks:
 *      1. LED_ON_TIMER: 
 *          This task will switch ON LED 
 *      1. LED_OFF_TIMER: 
 *          This task will switch OFF LED 
 */

// Create magxTasksCoordinator object
/**
 * Expected arguments:
 *      timeOutMs - This is the time in milliseconds after which the callback will be invoked.
 *  NOTE: This object can receive a few more arguments, but I limit to 1 arg for this example's scope.
*/
magxTaskCoordinator LED_ON_TIMER(300);
magxTaskCoordinator LED_OFF_TIMER(1000);
magxTasksManager manager;

// Then define timerType 
/**
 * This is the enum class with only two elements { Periodic, OneShot }
 * Periodic means the event will be repeated continuously at an interval set by the timeoutMs variable.
 * OneShot means the event will execute only once after timeoutMs has elapsed.
*/

// Example:
// LED_ON_TIMER.setType(magxTaskCoordinator::OneShot);

//Callbacks for both LED_ON_TIMER and LED_OFF_TIMER tasks

void LED_ON_TIMER_CB()
{
    digitalWrite(LED_BUILTIN,HIGH);
    LED_OFF_TIMER.start();

}
void LED_OFF_TIMER_CB()
{
    digitalWrite(LED_BUILTIN,LOW);
    LED_ON_TIMER.start();
}
void setup() {
    // Initialize Serial Monitor
    Serial.begin(9600);

    // Initialize LED pin
    pinMode(LED_BUILTIN, OUTPUT);

    // Set the callback function for LED blinking task
    LED_ON_TIMER.setCallback(LED_ON_TIMER_CB);
    LED_OFF_TIMER.setCallback(LED_OFF_TIMER_CB);

    // Set the timer type (Periodic or OneShot)
    LED_ON_TIMER.setType(magxTaskCoordinator::OneShot);
    LED_OFF_TIMER.setType(magxTaskCoordinator::OneShot);

    manager.addTimer(&LED_ON_TIMER);
    manager.addTimer(&LED_OFF_TIMER);

    // Start the LED blinking task
    LED_ON_TIMER.start();
    
}

void loop() {
    // Update the task coordinator
    manager.updateTimers();
}
