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

#include "Dictionary.h"

#include <iomanip>

namespace sdds {

    Dictionary& Dictionary::operator=(const Dictionary& source) {
        if (this == &source) {
            return *this;
        }

        m_term = source.m_term;
        m_definition = source.m_definition;

        return *this;
    }

    bool Dictionary::operator==(const Dictionary& source) const {
        if (this == &source)
            return true;
        return (m_term == source.m_term && m_definition == source.m_definition);
    }

    std::ostream& Dictionary::display(std::ostream& os) const {
        os.fill(' ');
        os.setf(std::ios::right);
        os.width(20);
        os << m_term << ": ";
        os.unsetf(std::ios::right);
        os.setf(std::ios::left);
        os << m_definition;
        os.unsetf(std::ios::left);
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Dictionary& dict) {
        dict.display(os);
        return os;
    }
}