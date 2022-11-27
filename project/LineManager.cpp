// Name: Yongda Long
// Seneca Student ID: 172800211
// Seneca email: ylong9@myseneca.ca
// Date of completion: Nov 27, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"

#include <algorithm>
#include <fstream>

#include "Utilities.h"

namespace sdds {

    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
        Utilities u;
        std::string temp;

        std::ifstream ifs(file);
        if (!ifs.is_open())
            throw std::string("Unable to open file.");

        while (!ifs.eof()) {
            std::getline(ifs, temp);

            size_t pos = 0;
            bool more = true;
            std::string thisStation;
            std::string nextStation;

            thisStation = u.extractToken(temp, pos, more);
            if (more)
                nextStation = u.extractToken(temp, pos, more);

            Workstation* thisWorkStation;
            Workstation* nextWorkStation;
            std::for_each(stations.begin(), stations.end(), [&](Workstation* station) {
                if (thisStation == station->getItemName())
                    thisWorkStation = station;
            });

            if (!nextStation.empty()) {
                std::for_each(stations.begin(), stations.end(), [&](Workstation* station) {
                    if (nextStation == station->getItemName())
                        nextWorkStation = station;
                });
                thisWorkStation->setNextStation(nextWorkStation);
            }
            m_activeLine.push_back(thisWorkStation);
        }

        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station1) {
            if (std::none_of(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* station2) {
                    if (station2->getNextStation() != nullptr) {
                        if (station1->getItemName() == station2->getNextStation()->getItemName())
                            return true;
                    }
                    return false;
                }))
                m_firstStation = station1;
        });
        m_cntCustomerOrder = g_pending.size();
    }

    void LineManager::reorderStations() {
        std::vector<Workstation*> temp;
        temp.push_back(m_firstStation);
        while (temp.back()->getNextStation()) {
            temp.push_back(temp.back()->getNextStation());
        }
        m_activeLine = temp;
    }

    bool LineManager::run(std::ostream& os) {
        static int count = 0;
        os << "Line Manager Iteration: " << ++count << std::endl;
        if (!g_pending.empty()) {
            (*m_firstStation) += std::move(g_pending.front());
            g_pending.pop_front();
        }

        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&os](Workstation* station) {
            station->fill(os);
        });

        std::for_each(m_activeLine.begin(), m_activeLine.end(), [](Workstation* station) {
            station->attemptToMoveOrder();
        });

        return (g_completed.size() + g_incomplete.size()) == m_cntCustomerOrder;
    }

    void LineManager::display(std::ostream& os) const {
        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&os](Workstation* ws) {
            ws->display(os);
        });
    }
}