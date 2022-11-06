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
#include "Luxuryvan.h"

namespace sdds {
    Luxuryvan::Luxuryvan(std::istream& is) : Van(is) {
        is.seekg(std::ios_base::beg);
        std::string temp;
        std::getline(is, temp);
        temp = temp.substr(temp.find_last_of(',') + 1);
        temp = removeSpaces(temp);
        if (temp != "e") {
            throw "Invalid record!";
        }
    }

    void Luxuryvan::display(std::ostream& os) const {
        Van::display(os);
        os << " electric van  *";
    }
}