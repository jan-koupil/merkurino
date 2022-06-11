#ifndef SimpleTimer_H
#define SimpleTimer_H

#include <Arduino.h>
#include <limits.h>

class SimpleTimer
{
private:
    unsigned long interval_ = 1000UL; // milliseconds
    unsigned long startTime_;
    bool isRunning_;
    unsigned long nextTickTime_;
    unsigned long lastTickTime_;

    void setNextTickTime(unsigned long currentTime);

public:
    void setInterval(unsigned long interval);
    void start();
    void stop();
    bool hasTicked();
    bool isRunning();
};

#endif
