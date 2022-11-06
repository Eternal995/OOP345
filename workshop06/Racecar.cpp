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