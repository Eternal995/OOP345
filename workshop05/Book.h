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
#ifndef _SDDS_BOOK_H_
#define _SDDS_BOOK_H_

#include <iostream>
#include <string>

namespace sdds {
    class Book {
        std::string m_author{};
        std::string m_title{};
        std::string m_country{};
        size_t m_year{0};
        double m_price{0.0};
        std::string m_description{};

      public:
        Book() {}
        const std::string& title() const { return m_title; }
        const std::string& country() const { return m_country; }
        const size_t& year() const { return m_year; }
        double& price() { return m_price; }
        Book(const std::string& strBook);
        ~Book() {}
        Book(const Book& source);
        Book& operator=(const Book& source);

        template <typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_description);
        }

        friend std::ostream& operator<<(std::ostream& os, const Book& book);
    };

    std::string removeSpaces(std::string source);
}

#endif