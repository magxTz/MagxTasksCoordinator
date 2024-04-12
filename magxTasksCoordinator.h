#ifndef magxTasksCoordinator_h
#define magxTasksCoordinator_h

#include <Arduino.h>
#include "./dependecies/vector.h"

class magxTaskCoordinator {
private:
    uint32_t timeoutMs;
    uint32_t count;
    uint32_t repeatCount;
    uint32_t stoppageMs;
    uint32_t dynamicDelayMs;
    void (*timeoutCallback)();
    void (*repeatTimeoutCallback)();
    uint32_t lastCheckTime;
    bool running;

public:
    enum TimerType { OneShot, Periodic };
    TimerType timerType;

    magxTaskCoordinator(uint32_t timeoutMs, uint32_t repeatCount = 1, uint32_t stoppageMs = 0);
    void setCallback(void (*timeoutCallback)());
    void setRepeatTimeoutCallback(void (*callback)());
    void setType(TimerType timerType);
    void start();
    void stop();
    void reset();
    void update();
    bool isRunning();
    void triggerCallback();
};

class magxTasksManager {
public:
    void addTimer(magxTaskCoordinator* timer);
    void updateTimers();

private:
    vector<magxTaskCoordinator*> timers;
};

#endif // magxTasksCoordinator_h
