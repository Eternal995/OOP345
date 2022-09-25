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