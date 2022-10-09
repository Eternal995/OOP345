#ifndef _SDDS_RESERVATION_H_
#define _SDDS_RESERVATION_H_

#include <iostream>
#include <string>

namespace sdds {
    class Reservation {
        std::string m_id{};
        std::string m_name{};
        std::string m_email{};
        int m_count{0};
        int m_day{0};
        int m_hour{0};

      public:
        Reservation() {}
        Reservation(const std::string& res);
        Reservation(const Reservation& source);
        ~Reservation() {}
        Reservation& operator=(const Reservation& source);
        void update(int day, int time);
        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };

    std::string removeSpaces(std::string source);
}

#endif