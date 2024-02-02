
class Node
{
public:
    Node(int x, int y): x(x), y(y), gCost(0), hCost(0), fCost(0), parent(nullptr) {}
    
    int x, y;
    int gCost, hCost, fCost;
    Node* parent; 


    bool operator==(const Node& other) const {
        return x == other.x && y == other.y; // Assuming Node equality is based on coordinates
    }   
};

