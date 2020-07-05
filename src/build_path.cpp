#include <iostream>
#include <thread>

#include "build_path.h"
#include "grid.h"
#include "node.h"

int Heuristic(Node* start_node, Node* target_node) {
    int target_x = target_node->getX();
    int target_y = target_node->getY();
    int start_x = start_node->getX();
    int start_y = start_node->getY();

    return (std::abs(target_x) - std::abs(start_x)) + (std::abs(target_y) - std::abs(start_y));
}

std::vector<Node*> Neighbors(Node* node, Grid &grid) {
    std::vector<Node*> neighbor_nodes;
    int x_coordinate = node->getX();
    int y_coordinate = node->getY();

    std::vector<std::vector<int>> possible_moves = {
        {x_coordinate, y_coordinate - 1},
        {x_coordinate, y_coordinate + 1},
        {x_coordinate - 1, y_coordinate},
        {x_coordinate + 1, y_coordinate}
    };

    for (std::vector<int> mv : possible_moves) {
        int move[2] = {mv[0], mv[1]};
        // if move left is on grid
        if (grid.hasCoordinates(move)) {
            // get neighbor_node
            Node* neighbor_node = grid.getNode(move);
            // add neighbor_node to neighbor_nodes
            neighbor_nodes.emplace_back(neighbor_node);
        }
    }

    return neighbor_nodes;
}

void ExpandList(Grid &grid, std::vector<Node*> &open_list, Node* current_node, Node* target_node) {
    // gather neighbors of current node
    std::vector<Node*> neighbor_nodes = Neighbors(current_node, grid);

    // for every neighbor node
    for (Node* node_ptr : neighbor_nodes) {
        if (node_ptr->Visited()) {
            // if node has been visited
            // skip iteration
            continue;
        }
        if (node_ptr->getValue() == "x") {
            // if node is obstacle
            // skip iteration
            continue;
        }

        // set parent node
        node_ptr->setParent(current_node);

        // calculate and set weight
        node_ptr->Weight(
            current_node->Weight() + 1
        );
        // calculate and set Heuristic
        node_ptr->Heuristic(
            Heuristic(node_ptr, target_node)
        );
        // add to open_list
        open_list.emplace_back(node_ptr);
    }

    // Sort the open list by aggregate weight (distance + heuristic); descending
    std::sort(open_list.begin(), open_list.end(), [](Node* node_ptr_a, Node* node_ptr_b){
        return (node_ptr_a->Weight() + node_ptr_a->Heuristic()) > (node_ptr_b->Weight() + node_ptr_b->Heuristic());
    });
}

void RenderPath(Node* node, Grid &grid) {
    node = node->getParent();

    while (node->getParent() != nullptr) {
        Node* parent_node = node->getParent();
        node->setValue("\u25A3");
        node = parent_node;
    }
}

void BuildPath(Grid &grid, int* start_point, int* target_point) {
    Node* start_node = grid.getNode(start_point);
    start_node->setValue("\u25EF");

    Node* target_node = grid.getNode(target_point);
    target_node->setValue("\u2691");

    // start an open list; initialize with start_point
    std::vector<Node*> open_list = { start_node };

    while (!open_list.empty()){
        // uncomment this to pace the visualisation
        // std::this_thread::sleep_for(std::chrono::milliseconds(10));

        // get the last node from the vector
        // this node holds the lowest aggregate weight (see ExpandList(...) func)
        Node* current_node = open_list.back();
        open_list.pop_back();

        // if node is target node -> break;
        if (current_node == target_node) {
            RenderPath(current_node, grid);
            system("clear");
            grid.Print();
            return;
        } else {
            // if node is not target node
            // mark node as visited
            current_node->SetVisited();
            current_node->setValue("\u25CC");
            // clear the terminal & print the grid
            system("clear");
            grid.Print();
            // expand open list
            ExpandList(grid, open_list, current_node, target_node);
        }
    }
}
