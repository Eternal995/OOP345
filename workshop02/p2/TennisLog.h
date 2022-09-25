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

#ifndef _SDDS_TENNISLOG_H_
#define _SDDS_TENNISLOG_H_

#include <iostream>
#include <string>

namespace sdds {
    struct TennisMatch {
        std::string m_id{};
        std::string m_name{};
        unsigned int m_matchID{0};
        std::string m_winner{};
        std::string m_loser{};

        void display(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& os, const TennisMatch& log);

    class TennisLog {
        TennisMatch* m_match{nullptr};
        size_t m_count{0};

      public:
        TennisLog() {}
        TennisLog(const char* file);
        TennisLog(const TennisLog& source);
        TennisLog(TennisLog&& source);
        TennisLog& operator=(const TennisLog& source);
        TennisLog& operator=(TennisLog&& source);
        ~TennisLog();
        void addMatch(const TennisMatch& match);
        TennisLog findMatches(std::string name);
        TennisMatch operator[](size_t index);
        operator size_t() const;
    };
}

#endif