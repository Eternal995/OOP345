#include "carads.h"

#include <iomanip>

double g_taxrate = 0.;
double g_discount = 0.;

namespace sdds {
    void listArgs(int argc, char** argv) {
        std::cout << "Command Line:" << std::endl;
        std::cout << "--------------------------" << std::endl;
        for (int i = 0; i < argc; i++) {
            std::cout << i + 1 << ": " << argv[i] << std::endl;
        }
    }

    std::istream& Cars::read(std::istream& is) {
        if (!is)
            return is;

        is >> m_status;
        is.ignore();
        is.getline(m_brand, ',');
        is.getline(m_model, ',');
        is >> m_year;
        is.ignore();
        is >> m_price;
        is.ignore();
        char temp;
        is >> temp;
        m_promo = (temp == 'Y') ? true : false;
        return is;
    }

    void Cars::display(bool reset) const {
        static int count = 0;
        if (reset) {
            count = 0;
        }
        std::cout.setf(std::ios::left);
        std::cout.precision(2);
        std::cout << std::setw(2) << std::setfill(' ') << ++count << ". ";
        if (!m_brand) {
            std::cout << "No Car" << std::endl;
            return;
        }
        std::cout << std::setw(10) << m_brand << "|";
        std::cout << std::setw(15) << m_model << "|";
        std::cout << m_year << "|";
        std::cout.unsetf(std::ios::left);
        std::cout.setf(std::ios::right);
        std::cout << std::setw(12) << m_price * (1 + g_taxrate) << "|";
        if (m_promo) {
            std::cout << std::setw(12) << m_price * (1 + g_taxrate) * (1 - g_discount);
        }
        std::cout << std::endl;
    }

    char Cars::getStatus() const {
        return m_status;
    }
}