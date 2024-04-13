#include "magxTasksCoordinator.h"
#include "./dependecies/vector.h"

magxTaskCoordinator::magxTaskCoordinator(uint32_t timeoutMs, uint32_t repeatCount, uint32_t stoppageMs) {
    this->timeoutMs = timeoutMs;
    this->count = 0;
    this->dynamicDelayMs = 0;
    this->timeoutCallback = nullptr;
    this->repeatTimeoutCallback = nullptr;
    this->running = false;
    this->timerType = OneShot; // Initialize timerType
    this->repeatCount = repeatCount;
    this->stoppageMs = stoppageMs;
    reset();
}

void magxTaskCoordinator::setCallback(void (*timeoutCallback)()) {
    this->timeoutCallback = timeoutCallback;
}

void magxTaskCoordinator::setRepeatTimeoutCallback(void (*callback)()) {
    if (repeatCount > 1 && stoppageMs >= 500) {
        this->repeatTimeoutCallback = callback;
    } else {
        Serial.println("This task does not support RepeatTimeoutCallback");
    }
}

void magxTaskCoordinator::setType(TimerType timerType) {
    this->timerType = timerType;
}

void magxTaskCoordinator::start() {
    lastCheckTime = millis();
    running = true;
}

void magxTaskCoordinator::stop() {
    running = false;
}

void magxTaskCoordinator::reset() {
    lastCheckTime = millis();
}

void magxTaskCoordinator::update() {
    if (!running || !timeoutCallback) {
        return;
    }

    uint32_t currentTime = millis();
    uint32_t elapsedTime = currentTime - lastCheckTime;

    if (elapsedTime >= (timeoutMs + dynamicDelayMs)) {
        timeoutCallback();

        if (repeatCount > 1 && stoppageMs >= 1) {
            if (count >= repeatCount) {
                dynamicDelayMs = stoppageMs;
                count = 0;
                if (repeatTimeoutCallback) {
                    repeatTimeoutCallback();
                }
            } else {
                dynamicDelayMs = 0;
            }
            count++;
        }

        if (timerType == Periodic) {
            reset();
        } else {
            stop();
        }
    }
}

bool magxTaskCoordinator::isRunning() {
    return running;
}

void magxTaskCoordinator::triggerCallback() {
    if (timeoutCallback) {
        timeoutCallback();
    }
}

void magxTasksManager::addTimer(magxTaskCoordinator* timer) {
    timers.push_back(timer);
}

void magxTasksManager::updateTimers() {
    for (magxTaskCoordinator* timer : timers) {
        timer->update();
    }
}
