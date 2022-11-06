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
#ifndef _SDDS_RACECAR_H_
#define _SDDS_RACECAR_H_

#include "Car.h"

namespace sdds {
    class Racecar : public Car {
        double m_booster{0.0};

      public:
        Racecar() {}
        Racecar(std::istream& is);
        void display(std::ostream& os) const;
        double topSpeed() const { return Car::topSpeed() * (1 + m_booster); }
    };
}

#endif