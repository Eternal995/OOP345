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
#ifndef _SDDS_SPELLCHECKER_H_
#define _SDDS_SPELLCHECKER_H_

#include <iostream>
#include <string>

namespace sdds {
    class SpellChecker {
        std::string m_badWords[6]{};
        std::string m_goodWords[6]{};
        int m_count[6]{0};

      public:
        SpellChecker() {}
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}

#endif