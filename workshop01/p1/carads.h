#ifndef _SDDS_CARADS_H_
#define _SDDS_CARADS_H_

#include <iostream>

extern double g_taxrate;
extern double g_discount;

namespace sdds {
    void listArgs(int argc, char** argv);

    class Cars {
        char m_brand[10]{};
        char m_model[10]{};
        int m_year{};
        double m_price{};
        char m_status{};
        bool m_promo{};

      public:
        Cars() {}

        std::istream& read(std::istream& is);

        void display(bool reset) const;

        char getStatus() const;
    };
}

#endif