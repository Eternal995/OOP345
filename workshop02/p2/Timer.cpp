#include "Timer.h"

namespace sdds {
    void Timer::start() {
        m_startTime = std::chrono::steady_clock::now();
    }

    long long Timer::stop() {
        m_endTime = std::chrono::steady_clock::now();
        long long time = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime).count();
        return time;
    }
}