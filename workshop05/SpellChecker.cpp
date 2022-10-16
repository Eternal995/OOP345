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
#include "SpellChecker.h"

#include <fstream>
#include <iomanip>

namespace sdds {
    SpellChecker::SpellChecker(const char* filename) {
        std::ifstream fs(filename);
        if (!fs)
            throw "Bad file name!";

        int i = 0;
        while (fs) {
            fs >> m_badWords[i] >> m_goodWords[i];
            i++;
        }
    }

    void SpellChecker::operator()(std::string& text) {
        for (int i = 0; i < 6; i++) {
            while (text.find(m_badWords[i]) != std::string::npos) {
                text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
                m_count[i]++;
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream& os) const {
        os << "Spellchecker Statistics" << std::endl;
        for (int i = 0; i < 6; i++) {
            os.setf(std::ios::right);
            os.width(15);
            os << m_badWords[i];
            os.unsetf(std::ios::right);
            os << ": " << m_count[i] << " replacements" << std::endl;
        }
    }
}