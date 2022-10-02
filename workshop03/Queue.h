#ifndef _SDDS_QUEUE_H_
#define _SDDS_QUEUE_H_

#include <iostream>

#include "Dictionary.h"

namespace sdds {
    template <typename T, int CAPACITY>
    class Queue {
        T m_element[CAPACITY]{};
        T m_empty{};
        unsigned int m_no{0};

      public:
        Queue() {}

        bool push(const T& item) {
            if (m_no >= CAPACITY) {
                return false;
            }
            m_element[m_no] = item;
            m_no++;
            return true;
        }

        T pop() {
            T temp{};
            if (m_no == 0) {
                return m_empty;
            }
            temp = m_element[0];
            for (unsigned int i = 0; i < m_no; i++) {
                m_element[i] = m_element[i + 1];
            }
            m_no--;
            return temp;
        }

        unsigned int size() {
            return m_no;
        }

        std::ostream& display(std::ostream& os = std::cout) {
            os << "----------------------" << std::endl;
            os << "| Dictionary Content |" << std::endl;
            os << "----------------------" << std::endl;
            for (unsigned int i = 0; i < m_no; i++) {
                os << m_element[i] << std::endl;
            }
            os << "----------------------" << std::endl;
            return os;
        }

        T operator[](unsigned int index) {
            if (index >= m_no) {
                return m_empty;
            }

            return m_element[index];
        }
    };

    template <>
    Queue<Dictionary, 100u>::Queue() {
        Dictionary temp("Empty Term", "Empty Substitute");
        m_empty = temp;
    }
}

#endif