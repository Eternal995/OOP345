// Name: Yongda Long
// Seneca Student ID: 172800211
// Seneca email: ylong9@myseneca.ca
// Date of completion: Nov 26, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _SDDS_CUSTOMERORDER_H_
#define _SDDS_CUSTOMERORDER_H_

#include <string>

#include "Station.h"

namespace sdds {
    struct Item {
        std::string m_itemName{};
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        Item(const std::string& src) : m_itemName(src){};
    };

    class CustomerOrder {
        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{0};
        Item** m_lstItem{nullptr};
        static size_t m_widthField;

      public:
        CustomerOrder() {}
        CustomerOrder(const std::string& source);
        CustomerOrder(const CustomerOrder& source);
        CustomerOrder& operator=(const CustomerOrder& source) = delete;
        CustomerOrder(CustomerOrder&& source) noexcept;
        CustomerOrder& operator=(CustomerOrder&& source) noexcept;
        ~CustomerOrder();
        bool isOrderFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;
    };
}

#endif