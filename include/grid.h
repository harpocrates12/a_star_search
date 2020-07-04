#ifndef GRID_H
#define GRID_H

#include <vector>

#include "row.h"

class Grid {
    public:
        Grid(int row_count, int column_count);
        bool hasCoordinates(int* coordinates);
        Node* getNode(int* coordinates);
        void Set(char value, int* coordinates);
        void Print();

    private:
        std::vector<Row> _rows;
};

#endif
