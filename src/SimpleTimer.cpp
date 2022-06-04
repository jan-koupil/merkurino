#include <SimpleTimer.h>

void SimpleTimer::setNextTickTime(unsigned long currentTime)
{
    // nextTickTime_ += ((currentTime - nextTickTime_) % interval_ + 1) * interval_;
    do
    {
        lastTickTime_ = nextTickTime_;
        nextTickTime_ += interval_;
    } while (nextTickTime_ < currentTime);

    if (nextTickTime_ < lastTickTime_)
    {
        nextTickTime_ = ULONG_MAX;
    }
};

void SimpleTimer::setInterval(unsigned long interval)
{
    interval_ = interval;
};

void SimpleTimer::start()
{
    startTime_ = lastTickTime_ = millis();
    isRunning_ = true;
    setNextTickTime(startTime_);
};

void SimpleTimer::stop()
{
    isRunning_ = false;
};

bool SimpleTimer::hasTicked()
{
    if (!isRunning_)
        return false;

    unsigned long currentTime = millis();

    // overflow occured
    if (currentTime < lastTickTime_)
    {
        startTime_ = 0UL;
        nextTickTime_ = 0UL;
        lastTickTime_ = 0UL;
    }

    if (currentTime < nextTickTime_)
        return false;

    setNextTickTime(currentTime);
    return true;
};
