// Workshop 9 - Multi-threading
// TreasureMap.cpp
// Michael Huang

#include "TreasureMap.h"

#include <fstream>
#include <functional>
#include <future>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

namespace sdds {

    size_t digForTreasure(const std::string& str, char mark) {
        size_t cnt = 0;
        for (auto& x : str) {
            if (x == mark) {
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename) {
        std::fstream fin(filename);
        if (fin) {
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while (fin) {
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        } else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap() {
        delete[] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const {
        if (map) {
            for (size_t i = 0; i < rows; ++i) {
                os << map[i] << std::endl;
            }
        } else
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename) {
        // Binary write
        if (map) {
            // TODO: Open a binary file stream to the filename and
            //         then write the row number to the binary file
            //         then each of the rows of the map.
            //       If the file cannot be open, raise an exception to
            //         inform the client.

            // END TODO
            std::ofstream ofs(filename, std::ios::binary);
            if (!ofs.is_open()) {
                throw std::string("Unable to open file.");
            }
            ofs.write((char*)&rows, sizeof(rows));
            ofs.write((char*)&colSize, sizeof(rows));
            for (size_t i = 0; i < rows; i++) {
                ofs.write((char*)(&map[i][0]), sizeof(char) * colSize);
            }
            ofs.close();

        } else {
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename) {
        // Binary read
        // TODO: Open a binary file stream to the filename
        //         and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        //         for the map followed another 4 bytes for the colSize
        //         of each row in the map.
        //       Afterwards is each row of the map itself.
        //       If the file cannot be open, raise an exception to inform
        //         the client.
        std::ifstream ifs(filename, std::ios::binary);
        if (!ifs.is_open()) {
            throw std::string("Unable to open file.");
        }
        ifs.read((char*)&rows, sizeof(rows));
        ifs.read((char*)&colSize, sizeof(colSize));
        if (map != nullptr)
            delete[] map;
        map = new std::string[rows];
        for (size_t i = 0; i < rows; i++) {
            map[i].resize(colSize);
            ifs.read((char*)(&map[i][0]), sizeof(char) * colSize);
        }
        ifs.close();
        // END TODO
    }

    void TreasureMap::clear() {
        delete[] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark) {
        size_t count = 0;

        // // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        // for (size_t i = 0; i < rows; ++i) {
        //     count += digForTreasure(map[i], mark);
        // }

        return count;
    }
}