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

#ifndef _SDDS_UNIQUEQUEUE_H_
#define _SDDS_UNIQUEQUEUE_H_

#include <cmath>

#include "Queue.h"

namespace sdds {
    template <typename T>
    class UniqueQueue : public Queue<T, 100> {
      public:
        UniqueQueue() {}

        ~UniqueQueue(){};

        bool push(const T& item) {
            for (unsigned int i = 0; i < this->size(); i++) {
                if (item == this->m_element[i])
                    return false;
            }
            return Queue<T, 100>::push(item);
        }
    };

    template <>
    bool UniqueQueue<double>::push(const double& item) {
        for (unsigned int i = 0; i < m_no; i++) {
            if (std::fabs(item - m_element[i]) <= 0.005)
                return false;
        }

        return Queue<double, 100>::push(item);
    }
}

#endif