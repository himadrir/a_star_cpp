#include"Astar.h"
#include<algorithm>
#include <iostream>


std::vector<Node> Astar::findPath(const std::vector<std::vector<int>>& grid, Node start, Node goal) 
{
    std::priority_queue<Node*, std::vector<Node*>, std::greater<Node*>> visiting;
    std::vector<std::vector<bool>> visitedSet(grid.size(), std::vector<bool>(grid[0].size(), false)); // initialise the whole grid as false as we vist we will mark them true
    
    std::cout<<"grid sz: "<<visitedSet.size()<<","<<visitedSet[0].size()<<std::endl;
    
    

    visiting.push(&start);

    while (!visiting.empty()) 
    {
        Node* current = visiting.top();
        
        visiting.pop();
                
        if (*current == goal) {
            // Reconstruct path (implementation omitted for brevity)
            return Astar::reconstructPath(current);
        }

        visitedSet[current->x][current->y] = true;
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        
        for(int i=0;i<4;i++)
        {
            // std::cout<<"calculating!"<<std::endl;
            int newX = current->x + dx[i];
            int newY = current->y + dy[i];
            
            if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] != 1 && !visitedSet[newX][newY])
            {
                Node* neighbor = new Node(newX, newY);

                neighbor->gCost = current->gCost+1;
                neighbor->hCost = Astar::heuristic(*neighbor, goal);
                neighbor->fCost = neighbor->gCost + neighbor->hCost;
                neighbor->parent = current;
                visiting.push(neighbor);

            }
        }

        /* USE THIS FOR DEBUGGING!
        for(int rows = 0; rows<visitedSet.size();rows++)
        {
            for(int cols = 0; cols<visitedSet[0].size();cols++)
            {
                std::cout<<visitedSet[rows][cols]<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<"*******************"<<std::endl;
        */
        
    }

    return {}; // No path found
}

int Astar::heuristic(const Node& a, const Node& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}


std::vector<Node> Astar::reconstructPath(Node* goal) {
    std::vector<Node> path;
    Node* current = goal;
    // std::cout<<"goal reached!"<<std::endl;
    while (current != nullptr) {
        path.push_back(*current);
        current = current->parent;
    }
    std::reverse(path.begin(), path.end()); // Reverse to get start -> goal order
    return path;
}
