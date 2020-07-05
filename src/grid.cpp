#include <iostream>
#include <vector>
#include <fstream>

#include "grid.h"

Grid::Grid(std::string file_path) {

    std::ifstream file_stream(file_path);

    if (!file_stream.is_open()) {
        throw std::runtime_error("Could not open grid file!");
    }

    std::string line;
    int y_coordinate = 0;

    while (std::getline(file_stream, line)) {
        _rows.emplace_back(y_coordinate, line);
        y_coordinate++;
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

    return &(_rows[y_coordinate]._nodes[x_coordinate]);
}

void Grid::Print() {
    for (Row row : _rows) {
        for (Node node : row._nodes) {
            std::cout << node._value << " ";
        }
        std::cout << std::endl;
    }
}
