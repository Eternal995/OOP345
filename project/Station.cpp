#include "Station.h"

#include "Utilities.h"
#include "iomanip"

namespace sdds {
    size_t Station::m_widthField{0};
    int Station::m_idGenerator{0};

    Station::Station(std::string record) {
        m_id = ++m_idGenerator;
        size_t pos = 0;
        bool more = true;
        Utilities util{};
        m_itemName = util.extractToken(record, pos, more);
        m_nextSerialNumber = stoi(util.extractToken(record, pos, more));
        m_noInStock = stoi(util.extractToken(record, pos, more));
        m_widthField = (m_widthField > util.getFieldWidth()) ? m_widthField : util.getFieldWidth();
        m_desc = util.extractToken(record, pos, more);
    }

    void Station::updateQuantity() {
        if (m_noInStock >= 1)
            m_noInStock--;
    }

    void Station::display(std::ostream& os, bool full) const {
        os << std::right << std::setfill('0') << std::setw(3) << m_id << " | "
           << std::left << std::setfill(' ') << std::setw(m_widthField) << m_itemName << "  | "
           << std::right << std::setfill('0') << std::setw(6) << m_nextSerialNumber << " | ";
        if (full) {
            os << std::right << std::setfill(' ') << std::setw(4) << m_noInStock << " | " << m_desc;
        }
        os << std::endl;
    }
}