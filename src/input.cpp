#include <iostream>

#include "input.h"

void InputCoordinates(int* start_point, int* target_point) {
    std::cout << "Please enter a starting x coordinate: ";
    std::cin >> start_point[0];
    std::cout << std::endl;

    std::cout << "Please enter a starting y coordinate: ";
    std::cin >> start_point[1];
    std::cout << std::endl;
    
    std::cout << "Please enter a target x coordinate: ";
    std::cin >> target_point[0];
    std::cout << std::endl;
    
    std::cout << "Please enter a target y coordinate: ";
    std::cin >> target_point[1];
    std::cout << std::endl;
}
