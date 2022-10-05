#include "Reservation.h"

#include <iomanip>
#include <iostream>
#include <string>

namespace sdds {
    Reservation::Reservation(const std::string& res) {
        std::string current{}, rest{};
        int temp{};

        temp = res.find(':');
        current = res.substr(0, temp);
        rest = res.substr(temp + 1);
        m_id = removeSpaces(current);

        temp = rest.find(',');
        current = rest.substr(0, temp);
        rest = rest.substr(temp + 1);
        m_name = removeSpaces(current);

        temp = rest.find(',');
        current = rest.substr(0, temp);
        rest = rest.substr(temp + 1);
        m_email = removeSpaces(current);

        temp = rest.find(',');
        current = rest.substr(0, temp);
        rest = rest.substr(temp + 1);
        m_count = std::stoi(removeSpaces(current));

        temp = rest.find(',');
        current = rest.substr(0, temp);
        rest = rest.substr(temp + 1);
        m_day = std::stoi(removeSpaces(current));

        temp = rest.find(',');
        current = rest.substr(0, temp);
        rest = rest.substr(temp + 1);
        m_hour = std::stoi(removeSpaces(current));
    }

    void Reservation::update(int day, int time) {
        m_day = day;
        m_hour = time;
    }

    std::string removeSpaces(const std::string source) {
        int leading = 0, trailing = source.size() - 1;
        while (source[leading] == ' ' || source[trailing] == ' ') {
            if (source[leading] == ' ')
                leading++;
            if (source[trailing] == ' ')
                trailing--;
        }
        return source.substr(leading, trailing - leading + 1);
    }

    void Reservation::display(std::ostream& os) const {
        os << "Reservation ";
        os.setf(std::ios::right);
        os.fill(' ');
        os.width(10);
        os << m_id << ": ";
        os.width(20);
        os << m_name << "  ";
        os.unsetf(std::ios::right);
        os.setf(std::ios::left);
        os.width(20);
        os << "<" + m_email + ">"
           << "    ";
        os.unsetf(std::ios::left);
        if (m_hour <= 9 && m_hour >= 6)
            os << "Breakfast";
        else if (m_hour <= 15 && m_hour >= 11)
            os << "Lunch";
        else if (m_hour <= 21 && m_hour >= 17)
            os << "Dinner";
        else
            os << "Drinks";
        os << " on day " << m_day << " @ " << m_hour << ":00 for " << m_count;
        if (m_count == 1)
            os << " person.";
        else
            os << " people.";
        os << std::endl;
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& res) {
        res.display(os);
        return os;
    }
}