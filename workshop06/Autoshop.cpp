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