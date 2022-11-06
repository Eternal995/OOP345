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
#ifndef _SDDS_VAN_H_
#define _SDDS_VAN_H_

#include <iostream>
#include <string>

#include "Vehicle.h"
namespace sdds {
    class Van : public Vehicle {
        std::string m_maker{};
        std::string m_type{};
        std::string m_condition{};
        std::string m_purpose{};
        double m_speed{0.0};

      public:
        Van() {}
        Van(std::istream& is);
        std::string condition() const { return m_condition; }
        double topSpeed() const { return m_speed; }
        std::string type() const { return m_type; }
        std::string usage() const { return m_purpose; }
        void display(std::ostream& os) const;
        std::string removeSpaces(std::string source);
    };
}

#endif