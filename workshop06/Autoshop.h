#ifndef _SDDS_AUTOSHOP_H_
#define _SDDS_AUTOSHOP_H_

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
    };
}

#endif