// Name: Yongda Long
// Seneca Student ID: 172800211
// Seneca email: ylong9@myseneca.ca
// Date of completion: Nov 19, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _SDDS_UTILITIES_H_
#define _SDDS_UTILITIES_H_

#include <string>

namespace sdds {
    class Utilities {
        size_t m_widthField{1};
        static char m_delimiter;

      public:
        void setFieldWidth(size_t newWidth) { m_widthField = newWidth; }
        size_t getFieldWidth() const { return m_widthField; }
        std::string extractToken(const std::string& source, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter) { m_delimiter = newDelimiter; }
        static char getDelimiter() { return m_delimiter; }
    };
}

#endif