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
#ifndef _SDDS_MOVIE_H_
#define _SDDS_MOVIE_H_

#include "Book.h"

namespace sdds {
    class Movie {
        std::string m_title{};
        int m_year{0};
        std::string m_description{};

      public:
        Movie() {}
        const std::string& title() const { return m_title; }
        Movie(const std::string& strMovie);
        ~Movie() {}
        Movie(const Movie& source);
        Movie& operator=(const Movie& source);

        template <typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_title);
            spellChecker(m_description);
        }

        friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
    };
}

#endif