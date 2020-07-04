#include <iostream>
#include <vector>

#include "grid.h"

Grid::Grid(int row_count, int column_count) {
    for (int i = 0; i < row_count; i++) {
        _rows.emplace_back(i, column_count);
    }
}

bool Grid::hasCoordinates(int* coordinates) {
    int x_coordinate = coordinates[0];
    int y_coordinate = coordinates[1];

    if (y_coordinate < 0 || y_coordinate >= _rows.size()) {
        return false;
    }

    if (x_coordinate < 0 || x_coordinate >= _rows[0]._nodes.size()) {
        return false;
    }

    return true;
}

Node* Grid::getNode(int* coordinates) {
    int x_coordinate = coordinates[0];
    int y_coordinate = coordinates[1];

    return &(_rows[x_coordinate]._nodes[y_coordinate]);
}

void Grid::Set(char value, int* coordinates) {
    int x_coordinate = coordinates[0];
    int y_coordinate = coordinates[1];

    _rows[x_coordinate]._nodes[y_coordinate]._value = value;
}

void Grid::Print() {
    for (Row row : _rows) {
        for (Node node : row._nodes) {
            std::cout << node._value << " ";
        }
        std::cout << std::endl;
    }
}
