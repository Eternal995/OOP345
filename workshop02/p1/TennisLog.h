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
        ~TennisLog();
        void addMatch(const TennisMatch& match);
        TennisLog& findMatches(std::string name);
        TennisMatch& operator[](size_t index);
        operator size_t() const;
    };

}

#endif