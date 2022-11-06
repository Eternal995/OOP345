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
        } else if (temp[0] == 'r' || temp[0] == 'R') {
            std::stringstream sstr(temp);
            result = new Racecar(sstr);
        } else if (temp[0] == 'l' || temp[0] == 'L') {
            std::stringstream sstr(temp);
            result = new Luxuryvan(sstr);
        } else {
            char error = temp[0];
            throw error;
        }
        return result;
    }
}