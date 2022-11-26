#include "CustomerOrder.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

#include "Utilities.h"

namespace sdds {
    size_t CustomerOrder::m_widthField = 0;

    CustomerOrder::CustomerOrder(const std::string& source) {
        Utilities u{};
        size_t pos = 0;
        bool more = true;
        m_name = u.extractToken(source, pos, more);
        m_product = u.extractToken(source, pos, more);
        m_cntItem = std::count(source.begin(), source.end(), u.getDelimiter()) - 1;
        if (m_cntItem == 0)
            return;
        m_lstItem = new Item*[m_cntItem];
        for (size_t i = 0; i < m_cntItem; i++)
            m_lstItem[i] = new Item(u.extractToken(source, pos, more));
        m_widthField = (u.getFieldWidth() > m_widthField) ? u.getFieldWidth() : m_widthField;
    }

    CustomerOrder::CustomerOrder(const CustomerOrder& source) {
        throw std::string("Cannot make copies.");
    }

    CustomerOrder::CustomerOrder(CustomerOrder&& source) noexcept {
        *this = std::move(source);
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& source) noexcept {
        if (this == &source)
            return *this;
        if (m_lstItem != nullptr) {
            for (size_t i = 0; i < m_cntItem; i++)
                if (m_lstItem[i] != nullptr)
                    delete m_lstItem[i];
            delete[] m_lstItem;
        }
        m_name = source.m_name;
        m_product = source.m_product;
        m_cntItem = source.m_cntItem;
        m_lstItem = source.m_lstItem;
        source.m_cntItem = 0;
        source.m_lstItem = nullptr;
        return *this;
    }

    CustomerOrder::~CustomerOrder() {
        for (size_t i = 0; i < m_cntItem; i++) delete m_lstItem[i];
        delete[] m_lstItem;
    }

    bool CustomerOrder::isOrderFilled() const {
        for (size_t i = 0; i < m_cntItem; i++)
            if (!m_lstItem[i]->m_isFilled)
                return false;
        return true;
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        for (size_t i = 0; i < m_cntItem; i++)
            if ((!m_lstItem[i]->m_isFilled) && (m_lstItem[i]->m_itemName == itemName))
                return false;
        return true;
    }

    void CustomerOrder::fillItem(Station& station, std::ostream& os) {
        for (size_t i = 0; i < m_cntItem; i++) {
            if (station.getItemName() != m_lstItem[i]->m_itemName)
                continue;
            if (station.getQuantity() > 0) {
                station.updateQuantity();
                m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                m_lstItem[i]->m_isFilled = true;
                os << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            } else {
                os << "Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
        }
    }

    void CustomerOrder::display(std::ostream& os) const {
        os << m_name << " - " << m_product << std::endl;
        for (size_t i = 0; i < m_cntItem; i++) {
            os << "[" << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber << "] "
               << std::left << std::setfill(' ') << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - "
               << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
        }
    }
}