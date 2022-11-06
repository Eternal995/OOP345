#include "Car.h"

#include <iomanip>

#include "Utilities.h"

namespace sdds {
    Car::Car(std::istream& is) {
        std::string temp;
        std::getline(is, temp, '\n');

        std::string current;
        int pos;

        pos = temp.find(',');
        temp = temp.substr(pos + 1);

        pos = temp.find(',');
        current = temp.substr(0, pos);
        temp = temp.substr(pos + 1);
        m_maker = removeSpaces(current);

        std::string condition;
        pos = temp.find(',');
        current = temp.substr(0, pos);
        temp = temp.substr(pos + 1);
        condition = removeSpaces(current);
        if (condition[0] == 'n') {
            m_condition = "new";
        } else if (condition[0] == 'u') {
            m_condition = "used";
        } else if (condition[0] == 'b') {
            m_condition = "broken";
        }

        m_speed = std::stod(removeSpaces(temp));
    }

    void Car::display(std::ostream& os) const {
        os << "| " << std::right << std::setw(10) << m_maker << " | "
           << std::left << std::setw(6) << m_condition << " | "
           << std::fixed << std::setw(6) << std::setprecision(2) << m_speed << " |";
    }
}