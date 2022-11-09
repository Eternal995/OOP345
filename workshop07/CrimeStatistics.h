#ifndef _SDDS_CRIMESTATISTICS_H_
#define _SDDS_CRIMESTATISTICS_H_

#include <iostream>
#include <string>
#include <vector>

namespace sdds {
    struct Crime {
        std::string m_province;
        std::string m_district;
        std::string m_crime;
        int m_case;
        int m_year;
        int m_resolved;
    };

    class CrimeStatistics {
        std::vector<Crime> m_crime;

      public:
        CrimeStatistics() {}
        CrimeStatistics(const char* file);
        void display(std::ostream& os) const;
    };
    std::ostream& operator<<(std::ostream& os, const Crime& crime);
    std::string removeSpaces(std::string source);
}

#endif