#include "LineManager.h"

#include <algorithm>
#include <fstream>

#include "Utilities.h"

namespace sdds {

    // LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
    //     Utilities u;

    //     std::ifstream ifs(file);
    //     if (!ifs.is_open())
    //         throw std::string("Unable to open file.");

    //     while (!ifs.eof()) {
    //         std::string temp;
    //         std::getline(ifs, temp);
    //         size_t pos = 0;
    //         bool more = true;
    //         std::string thisStation;
    //         std::string nextStation;

    //         thisStation = u.extractToken(temp, pos, more);
    //         if (more)
    //             nextStation = u.extractToken(temp, pos, more);

    //         std::cout << thisStation << " " << nextStation << std::endl;

    //         Workstation* thisWorkStation{nullptr};
    //         Workstation* nextWorkStation{nullptr};
    //         std::for_each(stations.begin(), stations.end(), [&](Workstation* station) {
    //             if (thisStation == station->getItemName())
    //                 thisWorkStation = station;
    //             else if (!nextStation.empty()) {
    //                 if (nextStation == station->getItemName())
    //                     nextWorkStation = station;
    //             }
    //         });

    //         thisWorkStation->setNextStation(nextWorkStation);
    //         m_activeLine.push_back(thisWorkStation);
    //         m_cntCustomerOrder++;
    //     }

    //     ifs.close();

    //     std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station1) {
    //         if (std::none_of(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station2) {
    //                 if (station2->getNextStation() == nullptr)
    //                     return true;
    //                 return (station2->getNextStation()->getItemName() == station1->getItemName());
    //             })) {
    //             m_firstStation = station1;
    //         }
    //     });
    // }

    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
        Utilities utl;
        std::string temp;

        std::ifstream assemble_file(file);
        if (!assemble_file) {
            std::string err = "ERROR: Cannot open file [" + file + "]";
            throw err;
        }

        while (!assemble_file.eof()) {
            std::getline(assemble_file, temp);
            try {
                Workstation* temp_workstation;
                Workstation* next_station;
                size_t pos = 0;
                bool more = true;

                // extract the string of the two stations (if exists)
                std::string file_item = utl.extractToken(temp, pos, more);
                std::string next_file_item;
                if (more) {
                    next_file_item = utl.extractToken(temp, pos, more);
                }

                // find the station that matches the station in the file
                std::for_each(stations.begin(), stations.end(),
                              [&](Workstation* stations) {
                                  if (stations->getItemName() == file_item) {
                                      // store first station in temp pointer
                                      temp_workstation = stations;
                                  }
                              });
                if (!next_file_item.empty()) {
                    std::for_each(stations.begin(), stations.end(),
                                  [&](Workstation* stations) {
                                      if (stations->getItemName() == next_file_item) {
                                          // store next station in another temp pointer
                                          next_station = stations;
                                      }
                                  });
                    temp_workstation->setNextStation(next_station);
                }
                // push the temp workstation to the activeLine
                m_activeLine.push_back(temp_workstation);
            } catch (const std::string error) {
                std::cout << error << std::endl;
            }
        }

        // finds the first station regardless of the order of AssemblyLine.txt
        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* first_line) {
            // find the activeLine where it's station does not show up in the next station
            // if that station is not in any nextStation, it is the first station
            bool found = false;
            found = std::none_of(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* activeLine) {
                bool match = false;
                if (activeLine->getNextStation() != nullptr) {
                    // if the activeLine's next station item is the same as the first_line's item,
                    // then it is not the first station.
                    if (first_line->getItemName() == activeLine->getNextStation()->getItemName())
                        match = true;
                }
                return match;
            });

            if (found) {
                m_firstStation = first_line;
            }
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

        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station) {
            station->fill(os);
        });

        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* station) {
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