// Name: Yongda Long
// Seneca Student ID: 172800211
// Seneca email: ylong9@myseneca.ca
// Date of completion: Nov 19, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

namespace sdds {
    char Utilities::m_delimiter{};

    std::string removeSpaces(std::string source) {
        int leading = 0, trailing = source.size() - 1;
        while (source[leading] == ' ' || source[trailing] == ' ') {
            if (source[leading] == ' ')
                leading++;
            if (source[trailing] == ' ')
                trailing--;
        }
        return source.substr(leading, trailing - leading + 1);
    }

    std::string Utilities::extractToken(const std::string& source, size_t& next_pos, bool& more) {
        if (source[next_pos] == m_delimiter) {
            more = false;
            throw std::string("Delimiter is found at next_pos.");
        }

        std::string result = source.substr(next_pos);
        int temp = result.find(m_delimiter);

        if (temp == -1) {
            result = removeSpaces(result);
            more = false;
        } else {
            result = removeSpaces(result.substr(0, temp));
            more = true;
            next_pos += temp + 1;
        }

        if (m_widthField < result.length())
            m_widthField = result.length();

        return result;
    }
}