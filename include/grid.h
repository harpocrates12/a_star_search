#ifndef GRID_H
#define GRID_H

#include <vector>

#include "row.h"

class Grid {
    public:
        Grid(std::string file_path);
        bool hasCoordinates(int* coordinates);
        Node* getNode(int* coordinates);
        void Set(char value, int* coordinates);
        void Print();

    private:
        std::vector<Row> _rows;
};

#endif
