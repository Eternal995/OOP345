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

#include "TennisLog.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

namespace sdds {
    void TennisMatch::display(std::ostream& os) const {
        if (m_id[0] == '\0') {
            os << "Empty Match";
            return;
        }

        os.fill('.');

        os.setf(std::ios::right);
        os.width(20);
        os << "Tourney ID"
           << " : ";
        os.unsetf(std::ios::right);
        os.setf(std::ios::left);
        os.width(30);
        os << m_id << std::endl;
        os.unsetf(std::ios::left);

        os.setf(std::ios::right);
        os.width(20);
        os << "Match ID"
           << " : ";
        os.unsetf(std::ios::right);
        os.setf(std::ios::left);
        os.width(30);
        os << m_matchID << std::endl;
        os.unsetf(std::ios::left);

        os.setf(std::ios::right);
        os.width(20);
        os << "Tourney"
           << " : ";
        os.unsetf(std::ios::right);
        os.setf(std::ios::left);
        os.width(30);
        os << m_name << std::endl;
        os.unsetf(std::ios::left);

        os.setf(std::ios::right);
        os.width(20);
        os << "Winner"
           << " : ";
        os.unsetf(std::ios::right);
        os.setf(std::ios::left);
        os.width(30);
        os << m_winner << std::endl;
        os.unsetf(std::ios::left);

        os.setf(std::ios::right);
        os.width(20);
        os << "Loser"
           << " : ";
        os.unsetf(std::ios::right);
        os.setf(std::ios::left);
        os.width(30);
        os << m_loser << std::endl;
        os.unsetf(std::ios::left);
    }

    std::ostream& operator<<(std::ostream& os, const TennisMatch& log) {
        log.display(os);
        return os;
    }

    TennisLog::TennisLog(const char* file) {
        std::ifstream is = std::ifstream(file, std::ios_base::in);
        std::string temp;
        size_t count = 0;

        if (!is.is_open())
            return;

        while (std::getline(is, temp) && !is.eof()) {
            count++;
        }

        m_count = --count;

        m_match = new TennisMatch[m_count];

        is.clear();
        is.seekg(0);

        std::getline(is, temp);

        for (size_t i = 0; i < count; i++) {
            std::getline(is, m_match[i].m_id, ',');
            std::getline(is, m_match[i].m_name, ',');
            is >> m_match[i].m_matchID;
            is.ignore();
            std::getline(is, m_match[i].m_winner, ',');
            std::getline(is, m_match[i].m_loser);
        }
    }

    TennisLog::TennisLog(const TennisLog& source) {
        // if (source.m_count == 0) {
        //     m_match = nullptr;
        //     m_count = 0;
        //     return;
        // }

        // m_count = source.m_count;
        // m_match = new TennisMatch[m_count];
        // for (size_t i = 0; i < m_count; i++) {
        //     m_match[i] = source.m_match[i];
        // }
        operator=(source);
    }

    TennisLog::TennisLog(TennisLog&& source) {
        // m_count = source.m_count;
        // m_match = source.m_match;
        // source.m_match = nullptr;
        operator=(std::move(source));
    }

    TennisLog& TennisLog::operator=(const TennisLog& source) {
        if (this == &source) {
            return *this;
        }

        if (source.m_count == 0) {
            m_match = nullptr;
            m_count = 0;
            return *this;
        }

        if (m_match != nullptr) {
            delete[] m_match;
        }

        m_count = source.m_count;
        m_match = new TennisMatch[m_count];
        for (size_t i = 0; i < m_count; i++) {
            m_match[i] = source.m_match[i];
        }
        return *this;
    }

    TennisLog& TennisLog::operator=(TennisLog&& source) {
        if (this == &source) {
            return *this;
        }

        if (m_match != nullptr) {
            delete[] m_match;
        }

        m_count = source.m_count;
        source.m_count = 0;
        m_match = source.m_match;
        source.m_match = nullptr;
        return *this;
    }

    TennisLog::~TennisLog() {
        if (m_match != nullptr) {
            delete[] m_match;
        }
    }

    void TennisLog::addMatch(const TennisMatch& match) {
        TennisMatch* temp = new TennisMatch[m_count + 1];
        for (size_t i = 0; i < m_count; i++) {
            temp[i] = m_match[i];
        }
        temp[m_count] = match;
        delete[] m_match;
        m_match = temp;
        m_count++;
    }

    TennisLog TennisLog::findMatches(std::string name) {
        TennisLog result{};
        for (size_t i = 0; i < m_count; i++) {
            if (m_match[i].m_winner == name || m_match[i].m_loser == name) {
                result.addMatch(m_match[i]);
            }
        }
        return result;
    }

    TennisMatch TennisLog::operator[](size_t index) {
        if (index >= m_count) {
            TennisMatch empty{};
            return empty;
        }

        return m_match[index];
    }

    TennisLog::operator size_t() const {
        return m_count;
    }
}