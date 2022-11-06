#include "Luxuryvan.h"

namespace sdds {
    Luxuryvan::Luxuryvan(std::istream& is) : Van(is) {
        is.seekg(std::ios_base::beg);
        std::string temp;
        std::getline(is, temp);
        temp = temp.substr(temp.find_last_of(',') + 1);
        temp = removeSpaces(temp);
        if (temp != "e") {
            throw "Invalid Record!";
        }
    }

    void Luxuryvan::display(std::ostream& os) const {
        Van::display(os);
        os << " electric van  *";
    }
}