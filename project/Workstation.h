#ifndef _SDDS_WORKSTATION_H_
#define _SDDS_WORKSTATION_H_

#include <deque>

#include "CustomerOrder.h"
#include "Station.h"

namespace sdds {
    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;

    class Workstation : public Station {
        std::deque<CustomerOrder> m_orders{};
        Workstation* m_pNextStation{nullptr};

      public:
        Workstation(const std::string& source) : Station(source) {}
        Workstation(const Workstation& source) = delete;
        Workstation(Workstation&& source) = delete;
        Workstation& operator=(const Workstation& source) = delete;
        Workstation& operator=(Workstation&& source) = delete;
        ~Workstation() {}
        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station) { m_pNextStation = station; }
        Workstation* getNextStation() const { return m_pNextStation; }
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);
    };
}

#endif