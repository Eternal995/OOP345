#ifndef _SDDS_LUXURYVAN_H_
#define _SDDS_LUXURYVAN_H_

#include "Van.h"

namespace sdds {
    class Luxuryvan : public Van {
        std::string m_consumption{};

      public:
        Luxuryvan() {}
        Luxuryvan(std::istream& is);
        void display(std::ostream& os) const;
        std::string consumption() const { return m_consumption; }
    };
}

#endif