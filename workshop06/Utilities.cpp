#include "Utilities.h"

#include <sstream>

namespace sdds {
    Vehicle* createInstance(std::istream& is) {
        Vehicle* result = nullptr;
        std::string temp;
        getline(is, temp);
        if (!is || temp.empty())
            return result;
        temp.erase(0, temp.find_first_not_of(' '));
        if (temp[0] == 'c' || temp[0] == 'C') {
            std::stringstream sstr(temp);
            result = new Car(sstr);
        } else if (temp[0] == 'v' || temp[0] == 'V') {
            std::stringstream sstr(temp);
            result = new Van(sstr);
        }
        return result;
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