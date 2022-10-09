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

#include "ConfirmationSender.h"

namespace sdds {
    ConfirmationSender::ConfirmationSender(const ConfirmationSender& source) {
        operator=(source);
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& source) {
        operator=(std::move(source));
    }

    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& source) {
        if (this == &source)
            return *this;

        if (m_res != nullptr) {
            delete[] m_res;
            m_res = nullptr;
        }

        m_cnt = source.m_cnt;
        m_res = new const Reservation*[m_cnt];
        for (size_t i = 0; i < m_cnt; i++) {
            m_res[i] = source.m_res[i];
        }

        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& source) {
        if (m_res != nullptr) {
            delete[] m_res;
            m_res = nullptr;
        }

        m_res = source.m_res;
        m_cnt = source.m_cnt;
        source.m_res = nullptr;
        source.m_cnt = 0;

        return *this;
    }

    ConfirmationSender::~ConfirmationSender() {
        if (m_res != nullptr) {
            delete[] m_res;
            m_res = nullptr;
        }
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
        for (size_t i = 0; i < m_cnt; i++) {
            if (m_res[i] == &res)
                return *this;
        }

        const Reservation** temp = new const Reservation*[m_cnt + 1];
        for (size_t i = 0; i < m_cnt; i++) {
            temp[i] = m_res[i];
        }
        temp[m_cnt] = &res;
        delete[] m_res;
        m_res = temp;
        temp = nullptr;
        m_cnt++;

        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
        bool found = false;
        size_t index = 0;
        for (size_t i = 0; i < m_cnt; i++) {
            if (m_res[i] == &res) {
                found = true;
                index = i;
            }
        }

        if (!found)
            return *this;

        const Reservation** temp = new const Reservation*[m_cnt - 1];
        for (size_t i = 0; i < index; i++) {
            temp[i] = m_res[i];
        }
        for (size_t i = index; i < m_cnt - 1; i++) {
            temp[i] = m_res[i + 1];
        }
        delete[] m_res;
        m_res = temp;
        temp = nullptr;
        m_cnt--;

        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs) {
        os << "--------------------------" << std::endl
           << "Confirmations to Send" << std::endl
           << "--------------------------" << std::endl;

        if (cs.m_cnt == 0) {
            os << "There are no confirmations to send!" << std::endl;
        } else {
            for (size_t i = 0; i < cs.m_cnt; i++) {
                os << *(cs.m_res[i]);
            }
        }

        os << "--------------------------" << std::endl;

        return os;
    }
}