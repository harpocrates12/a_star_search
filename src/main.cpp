#include <iostream>

#include "grid.h"
#include "input.h"
#include "build_path.h"

int main(){
    Grid grid(15, 15);

    grid.Print();

    int start_point[2];
    int target_point[2];

    InputCoordinates(start_point, target_point);
    BuildPath(grid, start_point, target_point);

    // grid.Print();

    return 0;
}
