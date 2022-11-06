#ifndef _SDDS_RACECAR_H_
#define _SDDS_RACECAR_H_

#include "Car.h"

namespace sdds {
    class Racecar : public Car {
        double m_booster{0.0};

      public:
        Racecar() {}
        Racecar(std::istream& is);
        void display(std::ostream& os) const;
        double topSpeed() const { return Car::topSpeed() * (1 + m_booster); }
    };
}

#endif