#ifndef _SDDS_LINEMANAGER_H_
#define _SDDS_LINEMANAGER_H_

#include <vector>

#include "Workstation.h"

namespace sdds {
    class LineManager {
        std::vector<Workstation*> m_activeLine{};
        size_t m_cntCustomerOrder{0};
        Workstation* m_firstStation{nullptr};

      public:
        LineManager(const std::string& file, std::vector<Workstation*>& stations);
        void reorderStations();
        bool run(std::ostream& os);
        void display(std::ostream& os) const;
    };
}

#endif