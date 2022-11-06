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
#include "Autoshop.h"

namespace sdds {
    Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
        m_vehicles.push_back(theVehicle);
        return *this;
    }

    void Autoshop::display(std::ostream& os) const {
        for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
            (*i)->display(os);
            os << std::endl;
        }
    }

    Autoshop::~Autoshop() {
        for (auto& vehicle : m_vehicles) delete vehicle;
    }
}