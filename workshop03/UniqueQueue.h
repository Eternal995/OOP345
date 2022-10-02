#ifndef _SDDS_UNIQUEQUEUE_H_
#define _SDDS_UNIQUEQUEUE_H_

#include <cmath>

#include "Queue.h"

namespace sdds {
    template <typename T>
    class UniqueQueue : public Queue<T, 100> {
      public:
        UniqueQueue() {}

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