#ifndef _SDDS_AUTOSHOP_H_
#define _SDDS_AUTOSHOP_H_

#include <list>
#include <vector>

#include "Vehicle.h"

namespace sdds {
    class Autoshop {
        std::vector<Vehicle*> m_vehicles;

      public:
        Autoshop() {}
        Autoshop& operator+=(Vehicle* theVehicle);
        void display(std::ostream& os) const;
        ~Autoshop();

        template <typename T>
        void select(T test, std::list<const Vehicle*>& vehicles) {
            for (auto& vehicle : m_vehicles) {
                if (test(vehicle))
                    vehicles.push_back(vehicle);
            }
        }
    };
}

#endif