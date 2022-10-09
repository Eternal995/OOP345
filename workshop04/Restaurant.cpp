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

#include "Restaurant.h"

namespace sdds {
    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
        if (cnt < 1)
            return;
        m_cnt = cnt;
        m_res = new Reservation*[m_cnt];
        for (size_t i = 0; i < m_cnt; i++) {
            m_res[i] = new Reservation(*(reservations[i]));
        }
    }

    Restaurant::~Restaurant() {
        deallocate();
    }

    Restaurant::Restaurant(const Restaurant& source) {
        operator=(source);
    }

    Restaurant::Restaurant(Restaurant&& source) {
        operator=(std::move(source));
    }

    Restaurant& Restaurant::operator=(const Restaurant& source) {
        if (this == &source)
            return *this;

        deallocate();

        m_cnt = source.m_cnt;
        m_res = new Reservation*[m_cnt];
        for (size_t i = 0; i < m_cnt; i++) {
            m_res[i] = new Reservation(*(source.m_res[i]));
        }

        return *this;
    }

    Restaurant& Restaurant::operator=(Restaurant&& source) {
        if (this == &source)
            return *this;

        deallocate();

        m_cnt = source.m_cnt;
        source.m_cnt = 0;
        m_res = source.m_res;
        source.m_res = nullptr;

        return *this;
    }

    void Restaurant::deallocate() {
        if (m_cnt > 0) {
            for (size_t i = 0; i < m_cnt; i++) {
                if (m_res[i] != nullptr) {
                    delete m_res[i];
                    m_res[i] = nullptr;
                }
            }
        }

        m_cnt = 0;

        if (m_res != nullptr) {
            delete[] m_res;
            m_res = nullptr;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant) {
        static unsigned int call_cnt = 0;
        os << "--------------------------" << std::endl
           << "Fancy Restaurant (" << ++call_cnt << ")" << std::endl
           << "--------------------------" << std::endl;

        if (restaurant.m_cnt == 0) {
            os << "This restaurant is empty!" << std::endl;
        } else {
            for (size_t i = 0; i < restaurant.m_cnt; i++) {
                os << *(restaurant.m_res[i]);
            }
        }

        os << "--------------------------" << std::endl;

        return os;
    }
}