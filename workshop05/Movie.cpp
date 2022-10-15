#include "Movie.h"

namespace sdds {
    Movie::Movie(const std::string& strMovie) {
        std::string current{}, rest{};
        int temp{};

        temp = strMovie.find(',');
        current = strMovie.substr(0, temp);
        rest = strMovie.substr(temp + 1);
        m_title = removeSpaces(current);

        temp = rest.find(',');
        current = rest.substr(0, temp);
        rest = rest.substr(temp + 1);
        m_year = std::stoi(removeSpaces(current));

        m_description = removeSpaces(rest);
    }

    Movie::Movie(const Movie& source) {
        operator=(source);
    }

    Movie& Movie::operator=(const Movie& source) {
        if (this == &source)
            return *this;

        m_title = source.m_title;
        m_year = source.m_year;
        m_description = source.m_description;

        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const Movie& movie) {
        os.setf(std::ios::right);
        os.fill(' ');
        os.width(40);
        os << movie.m_title << " | ";
        os.unsetf(std::ios::right);
        os.width(4);
        os << movie.m_year << " | " << movie.m_description << std::endl;
        return os;
    }
}