#include<vector>
#include<queue>
#include "Node.h"



class Astar
{
public:
    std::vector<Node> findPath(const std::vector<std::vector<int>>& grid, Node start, Node goal);

private:
    int heuristic(const Node& a, const Node& b);
    std::vector<Node> Astar::reconstructPath(Node* goal);
};
