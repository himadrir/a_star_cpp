#include "Astar.cpp"
#include <stdio.h>
#include <assert.h>

static void print_grid(std::vector<std::vector<int>>& map)
{   
    std::cout<<"0 - free, 1 - occupied"<<std::endl;
    std::cout<<"MAP"<<std::endl;

    for(int i = 0; i<map.size();i++)
    {
        for(int j = 0; j<map[0].size();j++)
        {
            std::cout<<map[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

int main()
{
    Astar astar_obj;
    int startX = 0, startY = 0;
    int goalX = 4, goalY = 3;
    std::vector<std::vector<int>> map = { // 0  1  2  3  4
                                            {0, 1, 0, 0, 1}, // 0
                                            {0, 0, 0, 1, 1}, // 1
                                            {1, 1, 0, 1, 0}, // 2
                                            {1, 0, 0, 0, 1}, // 3
                                            {0, 0, 1, 0, 1}, // 4
                                         };

    assert(map[startX][startY] != 1, "not free!");
    assert(map[goalX][goalY] != 1, "not free!");
    
    assert(startX < map.size() && startX >= 0, "out of bounds!");
    assert(startY < map[0].size() && startY >= 0, "out of bounds!");
    
    assert(goalX < map.size() && goalX >= 0, "out of bounds!");
    assert(goalY < map[0].size() && goalY >= 0, "out of bounds!");

    std::cout<<"A* implementation!"<<std::endl;
    
    Node start(startX, startY);  
    Node goal(goalX, goalY);

    std::vector<Node> path = astar_obj.findPath(map, start, goal);

    std::cout<<"path size: "<<path.size()<<std::endl;



    if(!path.empty())
    {   
        int path_cost = 0;

        print_grid(map);

        std::cout<<"path found : ";

        for(const auto& node: path)
        {
            std::cout<<"("<<node.x<<","<<node.y<<"), ";

            path_cost += node.fCost;
        }

        std::cout<<"\nPath cost: "<<path_cost<<std::endl;
    }


    else
    {
        std::cout<<"No path!";
    }

    return 0;
}