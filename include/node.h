#ifndef NODE_H
#define NODE_H

class Node {
    public:
        friend class Grid;
        Node(int x, int y, char value) : _x(x), _y(y), _value(value) {}
        int getX() { return _x; }
        int getY() { return _y; }
        char getValue() { return _value; }
        void setValue(char value) { _value = value; }
        bool Visited() { return _is_visited; }
        void SetVisited() { _is_visited = true; }
        int Weight() { return _weight; }
        void Weight(int weight) { _weight = weight; }
        int Heuristic() { return _heuristic; }
        void Heuristic(int heuristic) { _heuristic = heuristic; }

    private:
        int _x, _y;
        char _value;
        int _weight;
        int _heuristic;
        bool _is_visited = false;
};

#endif
