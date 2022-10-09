#include "Reservation.h"

#include <iomanip>

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

    Reservation::Reservation(const Reservation& source) {
        operator=(source);
    }

    Reservation& Reservation::operator=(const Reservation& source) {
        if (this == &source)
            return *this;
        m_id = source.m_id;
        m_name = source.m_name;
        m_email = source.m_email;
        m_count = source.m_count;
        m_day = source.m_day;
        m_hour = source.m_hour;
        return *this;
    }

    void Reservation::update(int day, int time) {
        m_day = day;
        m_hour = time;
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& res) {
        os << "Reservation ";
        os.setf(std::ios::right);
        os.fill(' ');
        os.width(10);
        os << res.m_id << ": ";
        os.width(20);
        os << res.m_name << "  ";
        os.unsetf(std::ios::right);
        os.setf(std::ios::left);
        os.width(20);
        os << "<" + res.m_email + ">"
           << "    ";
        os.unsetf(std::ios::left);
        if (res.m_hour <= 9 && res.m_hour >= 6)
            os << "Breakfast";
        else if (res.m_hour <= 15 && res.m_hour >= 11)
            os << "Lunch";
        else if (res.m_hour <= 21 && res.m_hour >= 17)
            os << "Dinner";
        else
            os << "Drinks";
        os << " on day " << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_count;
        if (res.m_count == 1)
            os << " person.";
        else
            os << " people.";
        os << std::endl;
        return os;
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
}