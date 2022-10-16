/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP345NBB

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Book.h"

#include <iomanip>

namespace sdds {

    Book::Book(const std::string& strBook) {
        std::string current{}, rest{};
        int temp{};

        temp = strBook.find(',');
        current = strBook.substr(0, temp);
        rest = strBook.substr(temp + 1);
        m_author = removeSpaces(current);

        temp = rest.find(',');
        current = rest.substr(0, temp);
        rest = rest.substr(temp + 1);
        m_title = removeSpaces(current);

        temp = rest.find(',');
        current = rest.substr(0, temp);
        rest = rest.substr(temp + 1);
        m_country = removeSpaces(current);

        temp = rest.find(',');
        current = rest.substr(0, temp);
        rest = rest.substr(temp + 1);
        m_price = std::stod(removeSpaces(current));

        temp = rest.find(',');
        current = rest.substr(0, temp);
        rest = rest.substr(temp + 1);
        m_year = std::stoi(removeSpaces(current));

        m_description = removeSpaces(rest);
    }

    std::ostream& operator<<(std::ostream& os, const Book& book) {
        os.setf(std::ios::right);
        os.fill(' ');
        os.width(20);
        os << book.m_author << " | ";
        os.width(22);
        os << book.m_title << " | ";
        os.width(5);
        os << book.m_country << " | ";
        os.width(4);
        os << book.m_year << " | ";
        os.unsetf(std::ios::right);
        os.setf(std::ios::fixed);
        os.width(6);
        os.precision(2);
        os << book.m_price << " | ";
        os.unsetf(std::ios::fixed);
        os << book.m_description << std::endl;
        return os;
    }

    std::string removeSpaces(const std::string source) {
        int leading = 0, trailing = source.size() - 1;
        while (source[leading] == ' ' || source[trailing] == ' ') {
            if (source[leading] == ' ')
                leading++;
            if (source[trailing] == ' ')
                trailing--;
        }
        return source.substr(leading, trailing - leading + 1);
    }

    Book::Book(const Book& source) {
        operator=(source);
    }
    Book& Book::operator=(const Book& source) {
        if (this == &source)
            return *this;

        m_author = source.m_author;
        m_title = source.m_title;
        m_country = source.m_country;
        m_year = source.m_year;
        m_price = source.m_price;
        m_description = source.m_description;

        return *this;
    }
}
