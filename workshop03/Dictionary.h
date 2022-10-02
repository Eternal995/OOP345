#ifndef _SDDS_DICTIONARY_H_
#define _SDDS_DICTIONARY_H_

#include <iostream>
#include <string>

namespace sdds {
    class Dictionary {
        std::string m_term{};
        std::string m_definition{};

      public:
        const std::string& getTerm() const {
            return m_term;
        }
        const std::string& getDefinition() const {
            return m_definition;
        }
        Dictionary(const std::string& term, const std::string& definition) : m_term{term}, m_definition{definition} {}

        // TODO: Code the missing prototype functions and operators
        //       that the class needs in order to work with the Queue class.
        //       Implement them in the Dictionary.cpp file.
        Dictionary() : m_term{""}, m_definition{""} {};
        Dictionary& operator=(const Dictionary& source);
        bool operator==(const Dictionary& source) const;
        std::ostream& display(std::ostream& os) const;
    };
    std::ostream& operator<<(std::ostream& os, const Dictionary& dict);
}

#endif