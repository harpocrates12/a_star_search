#include <vector>

#include "row.h"

Row::Row(int y_coordinate, int column_count) {
    for (int i = 0; i < column_count; i++) {
        _nodes.emplace_back(i, y_coordinate, '0');
    }
}
