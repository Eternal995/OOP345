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

#ifndef _SDDS_CRIMESTATISTICS_H_
#define _SDDS_CRIMESTATISTICS_H_

#include <iostream>
#include <list>
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
        void sort(const std::string field);
        void cleanList();
        bool inCollection(const std::string crime) const;
        std::list<Crime> getListForProvince(const std::string province) const;
    };
    std::ostream& operator<<(std::ostream& os, const Crime& crime);
    std::string removeSpaces(std::string source);
}

#endif