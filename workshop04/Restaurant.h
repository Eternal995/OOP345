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

#ifndef _SDDS_RESTAURANT_H_
#define _SDDS_RESTAURANT_H_

#include <iostream>

#include "Reservation.h"

namespace sdds {
    class Restaurant {
        Reservation** m_res{nullptr};
        size_t m_cnt{0};

      public:
        Restaurant() {}
        Restaurant(const Reservation* reservations[], size_t cnt);
        ~Restaurant();
        Restaurant(const Restaurant& source);
        Restaurant(Restaurant&& source);
        Restaurant& operator=(const Restaurant& source);
        Restaurant& operator=(Restaurant&& source);
        size_t size() const { return m_cnt; }
        void deallocate();
        friend std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant);
    };
}

#endif