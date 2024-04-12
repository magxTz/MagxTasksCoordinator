#include <Arduino.h>
#include <magxTasksCoordinator.h>

/**
 * author: Alex Gabriel Malisa
 * email : alexgabrielmalisa@gmail.com
 * 
 * 
 * simpleTask: In this task, we create two tasks:
 *      1. LED blinker on pin 13  
 *          This task will blink the LED at a frequency of 10Hz (100ms).
 */

// Create magxTasksCoordinator object
/**
 * Expected arguments:
 *      timeOutMs - This is the time in milliseconds after which the callback will be invoked.
 *  NOTE: This object can receive a few more arguments, but I limit to 1 arg for this example's scope.
*/
magxTaskCoordinator ledBlinker(100);

// Then define timerType 
/**
 * This is the enum class with only two elements { Periodic, OneShot }
 * Periodic means the event will be repeated continuously at an interval set by the timeoutMs variable.
 * OneShot means the event will execute only once after timeoutMs has elapsed.
*/

// Example:
// ledBlinker.setType(magxTaskCoordinator::Periodic);
// ledBlinker.setType(magxTaskCoordinator::OneShot);

void setup() {
    // Initialize Serial Monitor
    Serial.begin(9600);

    // Initialize LED pin
    pinMode(LED_BUILTIN, OUTPUT);

    // Set the callback function for LED blinking task
    ledBlinker.setCallback(ledBlinkCallback);

    // Set the timer type (Periodic or OneShot)
    ledBlinker.setType(magxTaskCoordinator::Periodic);

    // Start the LED blinking task
    ledBlinker.start();
}

void loop() {
    // Update the task coordinator
    ledBlinker.update();
}

// Callback function for LED blinking task
void ledBlinkCallback() {
    // Toggle LED state
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
