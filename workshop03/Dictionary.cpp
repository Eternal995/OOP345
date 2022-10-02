#include "Dictionary.h"

#include <iomanip>

namespace sdds {

    Dictionary& Dictionary::operator=(const Dictionary& source) {
        if (this == &source) {
            return *this;
        }

        m_term = source.m_term;
        m_definition = source.m_definition;

        return *this;
    }

    std::ostream& Dictionary::display(std::ostream& os) const {
        os.fill(' ');
        os.setf(std::ios::right);
        os.width(20);
        os << m_term << ": ";
        os.unsetf(std::ios::right);
        os.setf(std::ios::left);
        os << m_definition;
        os.unsetf(std::ios::left);
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Dictionary& dict) {
        dict.display(os);
        return os;
    }
}