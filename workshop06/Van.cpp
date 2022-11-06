#include "Van.h"

#include <iomanip>

namespace sdds {
    Van::Van(std::istream& is) {
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
        if (condition[0] == 'p') {
            m_type = "pickup";
        } else if (condition[0] == 'm') {
            m_type = "mini-bus";
        } else if (condition[0] == 'c') {
            m_type = "camper";
        } else {
            throw "Invalid Record!";
        }

        pos = temp.find(',');
        current = temp.substr(0, pos);
        temp = temp.substr(pos + 1);
        condition = removeSpaces(current);
        if (condition[0] == 'd') {
            m_purpose = "delivery";
        } else if (condition[0] == 'p') {
            m_purpose = "passenger";
        } else if (condition[0] == 'c') {
            m_purpose = "camping";
        } else {
            throw "Invalid Record!";
        }

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
            throw "Invalid Record!";
        }

        m_speed = std::stod(removeSpaces(temp));
    }

    void Van::display(std::ostream& os) const {
        os << "| " << std::right << std::setw(8) << m_maker << " | "
           << std::left << std::setw(12) << m_type << " | "
           << std::setw(12) << m_purpose << " | "
           << std::setw(6) << m_condition << " | "
           << std::fixed << std::setw(6) << std::setprecision(2) << m_speed << " |";
    }

    std::string Van::removeSpaces(std::string source) {
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