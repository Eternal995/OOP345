#ifndef _SDDS_COLLECTION_H_
#define _SDDS_COLLECTION_H_

#include <iostream>
#include <string>

namespace sdds {
    template <typename T>
    class Collection {
        std::string m_name{};
        T* m_obj{nullptr};
        size_t m_size{0};
        void (*m_observer)(const Collection<T>&, const T&){nullptr};

      public:
        Collection(const std::string& name) : m_name{name} {}
        ~Collection() { delete[] m_obj; }
        Collection(const Collection& source) = delete;
        Collection& operator=(const Collection& source) = delete;
        const std::string& name() const { return m_name; }
        size_t size() const { return m_size; }
        void setObserver(void (*observer)(const Collection<T>&, const T&)) { m_observer = observer; }

        Collection<T>& operator+=(const T& item) {
            if (m_size != 0) {
                for (size_t i = 0; i < m_size; i++) {
                    if (m_obj[i].title() == item.title())
                        return *this;
                }
            }

            T* temp = new T[m_size + 1];
            for (size_t i = 0; i < m_size; i++) {
                temp[i] = m_obj[i];
            }
            temp[m_size++] = item;
            if (m_obj != nullptr) {
                delete[] m_obj;
                m_obj = nullptr;
            }
            m_obj = temp;
            temp = nullptr;

            if (m_observer) {
                m_observer(*this, item);
            }

            return *this;
        }

        T& operator[](size_t idx) const {
            if (idx >= m_size) {
                std::string error = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.";
                throw std::out_of_range(error);
            }
            return m_obj[idx];
        }

        T* operator[](const std::string& title) const {
            for (size_t i = 0; i < m_size; i++) {
                if (m_obj[i].title() == title)
                    return &m_obj[i];
            }
            return nullptr;
        }

        std::ostream& display(std::ostream& os) const {
            for (size_t i = 0; i < m_size; i++) {
                os << m_obj[i];
            }
            return os;
        }
    };

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
        collection.display(os);
        return os;
    }

}

#endif