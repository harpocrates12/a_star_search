#ifndef NODE_H
#define NODE_H

class Node {
    public:
        friend class Grid;
        Node(int x, int y, std::string value) : _x(x), _y(y), _value(value) {}
        int getX() { return _x; }
        int getY() { return _y; }
        std::string getValue() { return _value; }
        void setValue(std::string value) { _value = value; }
        Node* getParent() { return _parent_node; }
        void setParent(Node* parent_node) { _parent_node = parent_node; }
        bool Visited() { return _is_visited; }
        void SetVisited() { _is_visited = true; }
        int Weight() { return _weight; }
        void Weight(int weight) { _weight = weight; }
        int Heuristic() { return _heuristic; }
        void Heuristic(int heuristic) { _heuristic = heuristic; }

    private:
        int _x, _y;
        std::string _value;
        Node* _parent_node = nullptr;
        int _weight;
        int _heuristic;
        bool _is_visited = false;
};

#endif
