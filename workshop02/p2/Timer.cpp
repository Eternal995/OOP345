/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP345NBB

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

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