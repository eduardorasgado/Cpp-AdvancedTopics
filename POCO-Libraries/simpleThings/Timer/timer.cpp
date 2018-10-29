
#include "Poco/Timer.h"
#include "Poco/Thread.h"
#include "Poco/Stopwatch.h"
#include <iostream>

using Poco::Timer;
using Poco::TimerCallback;
using Poco::Thread;
using Poco::Stopwatch;

class TimerPro
{
    public:
        // will save the last state(second of time)
        TimerPro()
        {
            this->sw.start();
        }
        void onTimer(Timer& timer)
        {
            // this function will be called each time
            std::cout << "Callback  called after " << (this->sw.elapsed()/1000)/1000 << " seconds " << std::endl;
        }
    private:
        Stopwatch sw;
};

int askingTime()
{
    int seconds;
    std::cout << "Insert the time: ", std::cin >> seconds;
    return seconds;
}

int main() {
    int seconds = askingTime();
    std::cout << "Start the timer("<< seconds << " seconds)" << std::endl;

    TimerPro myTimer;
    // starting point, lapses
    Timer timer(1000, 1000);
    // initialize the timer
    timer.start(TimerCallback<TimerPro>(myTimer, &TimerPro::onTimer));
    // stop time
    Thread::sleep((seconds)*1000);
    timer.stop();
    std::cout << "Time finished" << std::endl;
    return 0;
}