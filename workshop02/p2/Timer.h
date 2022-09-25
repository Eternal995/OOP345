#ifndef _SDDS_TIMER_H_
#define _SDDS_TIMER_H_

#include <chrono>
#include <iostream>

namespace sdds {
    class Timer {
        std::chrono::steady_clock::time_point m_startTime;
        std::chrono::steady_clock::time_point m_endTime;

      public:
        void start();
        long long stop();
    };
}

#endif