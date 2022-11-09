#include "CrimeStatistics.h"

#include <algorithm>
#include <fstream>
#include <iomanip>

namespace sdds {
    CrimeStatistics::CrimeStatistics(const char* file) {
        std::ifstream ifs(file);
        Crime temp;
        std::string read;

        if (!ifs) {
            throw "Invalid file name.";
        }

        while (!ifs.eof()) {
            std::getline(ifs, read);
            temp.m_province = removeSpaces(read.substr(0, 25));
            temp.m_district = removeSpaces(read.substr(25, 25));
            temp.m_crime = removeSpaces(read.substr(50, 25));
            try {
                temp.m_year = std::stoi(removeSpaces(read.substr(75, 5)));
                temp.m_case = std::stoi(removeSpaces(read.substr(80, 5)));
                temp.m_resolved = std::stoi(removeSpaces(read.substr(85, 5)));
            } catch (...) {
                std::cout << "Invalid input";
            }
            m_crime.push_back(temp);
        }
        ifs.close();
    }

    void CrimeStatistics::display(std::ostream& os) const {
        std::for_each(m_crime.begin(), m_crime.end(), [&os](const Crime& m_crime) {
            os << m_crime << std::endl;
        });
    }

    std::ostream& operator<<(std::ostream& os, const Crime& crime) {
        os << "| " << std::left << std::setw(21) << crime.m_province
           << " | " << std::setw(15) << crime.m_district
           << " | " << std::setw(20) << crime.m_crime
           << " | " << std::right << std::setw(6) << crime.m_year
           << " | " << std::setw(4) << crime.m_case
           << " | " << std::setw(3) << crime.m_resolved;
        return os;
    }

    std::string removeSpaces(std::string source) {
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