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
        int totalCrime = 0, totalResolved = 0;
        std::for_each(m_crime.begin(), m_crime.end(), [&os, &totalCrime, &totalResolved](const Crime& crime) {
            os << crime << std::endl;
            totalCrime += crime.m_case;
            totalResolved += crime.m_resolved;
        });
        os << std::setw(89) << std::setfill('-') << '\n'
           << std::setfill(' ') << "|"
           << std::right << std::setw(79) << "Total Crimes: "
           << std::setw(6) << totalCrime << " |" << '\n'
           << "|"
           << std::setw(79) << "Total Resolved Cases: "
           << std::setw(6) << totalResolved << " |" << std::endl;
    }

    void CrimeStatistics::sort(const std::string field) {
        std::sort(m_crime.begin(), m_crime.end(), [field](const Crime& lfs, const Crime& rhs) {
            if (field == "Province")
                return lfs.m_province < rhs.m_province;
            if (field == "Crime")
                return lfs.m_crime < rhs.m_crime;
            if (field == "Cases")
                return lfs.m_case < rhs.m_case;
            return lfs.m_resolved < rhs.m_resolved;
        });
    }

    void CrimeStatistics::cleanList() {
        std::transform(m_crime.begin(), m_crime.end(), m_crime.begin(), [](Crime crime) {
            if (crime.m_crime == "[None]")
                crime.m_crime = "";
            return crime;
        });
    }

    bool CrimeStatistics::inCollection(const std::string crime) const {
        return std::any_of(m_crime.begin(), m_crime.end(), [crime](const Crime c) {
            return c.m_crime == crime;
        });
    }

    std::list<Crime> CrimeStatistics::getListForProvince(const std::string province) const {
        int length = std::count_if(m_crime.begin(), m_crime.end(), [province](const Crime c) {
            return c.m_province == province;
        });
        std::list<Crime> result(length);
        std::copy_if(m_crime.begin(), m_crime.end(), result.begin(), [province](const Crime c) {
            return c.m_province == province;
        });
        return result;
    }

    std::ostream& operator<<(std::ostream& os, const Crime& crime) {
        os << "| " << std::left << std::setw(21) << crime.m_province
           << " | " << std::setw(15) << crime.m_district
           << " | " << std::setw(20) << crime.m_crime
           << " | " << std::right << std::setw(6) << crime.m_year
           << " | " << std::setw(4) << crime.m_case
           << " | " << std::setw(3) << crime.m_resolved << " |";
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