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

#ifndef _SDDS_CONFIRMATIONSENDER_H_
#define _SDDS_CONFIRMATIONSENDER_H_

#include <iostream>

#include "Reservation.h"

namespace sdds {
    class ConfirmationSender {
        const Reservation** m_res{nullptr};
        size_t m_cnt{0};

      public:
        ConfirmationSender() {}
        ConfirmationSender(const ConfirmationSender& source);
        ConfirmationSender(ConfirmationSender&& source);
        ConfirmationSender& operator=(const ConfirmationSender& source);
        ConfirmationSender& operator=(ConfirmationSender&& source);
        ~ConfirmationSender();
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs);
    };
}

#endif