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
    };
}

#endif