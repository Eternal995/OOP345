#include "carads.h"

#include <cstring>
#include <iomanip>

double g_taxrate = 0.;
double g_discount = 0.;

namespace sdds {
    void listArgs(int argc, char** argv) {
        std::cout << "Command Line:" << std::endl;
        std::cout << "--------------------------" << std::endl;
        for (int i = 0; i < argc; i++) {
            std::cout << std::setw(3) << i + 1 << ": " << argv[i] << std::endl;
        }
        std::cout << "--------------------------" << std::endl
                  << std::endl;
    }

    Cars::~Cars() {
        if (m_brand != nullptr)
            delete[] m_brand;
    }

    Cars::Cars(const Cars& source) {
        m_brand = new char[strlen(source.m_brand) + 1];
        strcpy(m_brand, source.m_brand);
        strcpy(m_model, source.m_model);
        m_year = source.m_year;
        m_price = source.m_price;
        m_status = source.m_status;
        m_promo = source.m_promo;
    }

    Cars& Cars::operator=(const Cars& source) {
        if (this == &source)
            return *this;

        if (m_brand != nullptr) {
            delete[] m_brand;
            m_brand = nullptr;
        }

        if (source.m_brand != nullptr) {
            m_brand = new char[strlen(source.m_brand) + 1];
            strcpy(m_brand, source.m_brand);
        }

        strcpy(m_model, source.m_model);
        m_year = source.m_year;
        m_price = source.m_price;
        m_status = source.m_status;
        m_promo = source.m_promo;

        return *this;
    }

    Cars::operator bool() {
        return (m_status == 'N');
    }

    std::istream& Cars::read(std::istream& is) {
        if (!is)
            return is;

        char temp_brand[20];

        if (m_brand != nullptr) {
            delete[] m_brand;
            m_brand = nullptr;
        }

        is >> m_status;
        is.ignore();
        is.getline(temp_brand, 20, ',');

        if (temp_brand[0] != '\0') {
            m_brand = new char[strlen(temp_brand) + 1];
            strcpy(m_brand, temp_brand);
        }

        is.getline(m_model, 14, ',');
        is >> m_year;
        is.ignore();
        is >> m_price;
        is.ignore();
        char temp_promo;
        is >> temp_promo;
        m_promo = (temp_promo == 'Y') ? true : false;
        is.ignore();
        return is;
    }

    void Cars::display(bool reset) const {
        static int count = 0;
        if (reset) {
            count = 0;
        }
        std::cout.setf(std::ios::left);
        std::cout << std::setw(2) << std::setfill(' ') << ++count << ". ";
        if (m_brand[0] == '\0') {
            std::cout << "No Car" << std::endl;
            return;
        }
        std::cout << std::setw(10) << m_brand << "| ";
        std::cout << std::setw(15) << m_model << "| ";
        std::cout << m_year << " |";
        std::cout.unsetf(std::ios::left);
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        std::cout << std::setw(12) << m_price * (1 + g_taxrate) << "|";
        if (m_promo) {
            std::cout << std::setw(12) << m_price * (1 + g_taxrate) * (1 - g_discount);
        }
        std::cout << std::endl;
    }

    char Cars::getStatus() const {
        return m_status;
    }

    std::istream& operator>>(std::istream& is, Cars& car) {
        car.read(is);
        return is;
    }

    void operator>>(const Cars& car1, Cars& car2) {
        car2 = car1;
    }
}