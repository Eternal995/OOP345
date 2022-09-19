#ifndef _SDDS_CARADS_H_
#define _SDDS_CARADS_H_

#include <iostream>

extern double g_taxrate;
extern double g_discount;

namespace sdds {
    void listArgs(int argc, char** argv);

    class Cars {
        char* m_brand{nullptr};
        char m_model[15]{};
        int m_year{};
        double m_price{};
        char m_status{};
        bool m_promo{};

      public:
        Cars() {}
        Cars(const Cars& source);
        ~Cars();
        Cars& operator=(const Cars& source);
        operator bool();

        std::istream& read(std::istream& is);
        void display(bool reset) const;
        char getStatus() const;
    };

    std::istream& operator>>(std::istream& is, Cars& car);
    void operator>>(const Cars& car1, Cars& car2);
}

#endif