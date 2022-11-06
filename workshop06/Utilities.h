#ifndef _SDDS_UTILITIES_H_
#define _SDDS_UTILITIES_H_

#include <iostream>
#include <string>

#include "Car.h"
#include "Van.h"

namespace sdds {
    Vehicle* createInstance(std::istream& is);
    std::string removeSpaces(std::string source);
}

#endif