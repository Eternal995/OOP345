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
#include "Racecar.h"

namespace sdds {
    Racecar::Racecar(std::istream& is) : Car(is) {
        is.seekg(std::ios_base::beg);
        std::string temp;
        std::getline(is, temp);
        temp = temp.substr(temp.find_last_of(',') + 1);
        m_booster = std::stod(removeSpaces(temp));
    }

    void Racecar::display(std::ostream& os) const {
        Car::display(os);
        os << "*";
    }
}