#ifndef _SDDS_UTILITIES_H_
#define _SDDS_UTILITIES_H_

#include <iostream>
#include <string>

#include "Luxuryvan.h"
#include "Racecar.h"
namespace sdds {
    Vehicle* createInstance(std::istream& is);
}

#endif