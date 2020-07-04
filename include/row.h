#ifndef ROW_H
#define ROW_H

#include <vector>

#include "node.h"

class Row {
    public:
        friend class Grid;

        Row(int y_coordinate, int column_count);

    private:
        std::vector<Node> _nodes;
};

#endif
