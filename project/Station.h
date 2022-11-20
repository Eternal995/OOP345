#ifndef _SDDS_STATION_H_
#define _SDDS_STATION_H_

#include <iostream>
#include <string>

namespace sdds {
    class Station {
        int m_id{};
        std::string m_itemName{};
        std::string m_desc{};
        size_t m_nextSerialNumber{};
        size_t m_noInStock{};
        static size_t m_widthField;
        static int m_idGenerator;

      public:
        Station(std::string record);
        const std::string& getItemName() const { return m_itemName; }
        size_t getNextSerialNumber() { return m_nextSerialNumber++; }
        size_t getQuantity() const { return m_noInStock; }
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}

#endif