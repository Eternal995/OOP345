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
#ifndef _SDDS_CAR_H_
#define _SDDS_CAR_H_

#include <iostream>
#include <string>

#include "Vehicle.h"

namespace sdds {
    class Car : public Vehicle {
        std::string m_maker{};
        std::string m_condition{};
        double m_speed{0.0};

      public:
        Car() {}
        Car(std::istream& is);
        std::string condition() const { return m_condition; }
        double topSpeed() const { return m_speed; }
        void display(std::ostream& os) const;
        std::string removeSpaces(std::string source);
    };
}

#endif