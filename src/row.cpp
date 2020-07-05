#include <vector>
#include <sstream>

#include "row.h"

Row::Row(int y_coordinate, std::string line) {
    std::istringstream line_stream(line);
    std::string token;
    int x_coordinate = 0;

    while  (line_stream >> token) {
        _nodes.emplace_back(x_coordinate, y_coordinate, token);
        x_coordinate++;
    }
}
