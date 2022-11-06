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
#ifndef _SDDS_LUXURYVAN_H_
#define _SDDS_LUXURYVAN_H_

#include "Van.h"

namespace sdds {
    class Luxuryvan : public Van {
        std::string m_consumption{};

      public:
        Luxuryvan() {}
        Luxuryvan(std::istream& is);
        void display(std::ostream& os) const;
        std::string consumption() const { return m_consumption; }
    };
}

#endif