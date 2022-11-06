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
#include "Car.h"

#include <iomanip>

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
        if (condition.empty() || condition == " " || condition[0] == 'n') {
            m_condition = "new";
        } else if (condition[0] == 'u') {
            m_condition = "used";
        } else if (condition[0] == 'b') {
            m_condition = "broken";
        } else {
            throw "Invalid record!";
        }

        try {
            m_speed = std::stod(removeSpaces(temp));
        } catch (const std::invalid_argument& err) {
            throw "Invalid record!";
        }
    }

    void Car::display(std::ostream& os) const {
        os << "| " << std::right << std::setw(10) << m_maker << " | "
           << std::left << std::setw(6) << m_condition << " | "
           << std::fixed << std::setw(6) << std::setprecision(2) << topSpeed() << " |";
    }

    std::string Car::removeSpaces(std::string source) {
        int leading = 0, trailing = source.size() - 1;
        while (source[leading] == ' ' || source[trailing] == ' ') {
            if (source[leading] == ' ')
                leading++;
            if (source[trailing] == ' ')
                trailing--;
        }
        return source.substr(leading, trailing - leading + 1);
    }
}