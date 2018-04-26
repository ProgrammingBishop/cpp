#include <iostream>
#include <vector>
#include <queue>


class Node
{
public:
    int key;
    Node *parent;
    std::vector<Node*> children;
    
    Node() { this->parent = NULL; }
    
    /*
    The current node's parent will be indexed at this node's input value
    The parent at said index inherits this node as a child
    */
    void setParent(Node *theParent)
    {
        parent = theParent;
        parent->children.push_back(this);
    }
};


// Forward Declarations
void buildTree();


int main (int argc, char **argv)
{
    buildTree();
    system("pause");
    return 0;
}


/*
Calculate the height for the tree of nodes:
    1) Enqueue the nodes of the tree in breadth-first order
    2) Increment the height once all the nodes for any given level has been processed
*/
int levelTraversal(std::vector<Node> *nodes, int parent_index)
{
    if (nodes->empty()) { return 0; }
    
    Node nextInQueue;
    std::queue<Node> queue;
    queue.push(nodes->at(parent_index)); // Enqueue the root node to begin

    int enque     = queue.size(); 
    int maxHeight = 0;
    int index, counter;

    while (!queue.empty())
    {
        counter = enque;
        enque   = 0;
	/*
	When the for loop completes, it will mean that a level of the tree has been processed
	And the height should be incremented by 1 for that processed level
	*/
        for (index = 0; index < counter; index++)
        {
            nextInQueue = queue.front();
            if (!nextInQueue.children.empty())
            {
                for (Node* child : nextInQueue.children)
                {
                    queue.push(*child);
		    // Enque indicates the number of nodes to process for the next level
		    enque++;
                }
            }
            queue.pop();
        }
        maxHeight++;
    }
    
    return maxHeight;
}


/*
A) The first line of user input specifies how many nodes the tree will contain
B) The second line of user input will consist of n numbers where n is the value of the first input
C) The index of each input in the vector will be the key value of that node
D) The value at each input in the vector will be the index of that node's parent
E) Each Node object in the vector will have a key (index), parent (input value at index), and a vector of children, if any
F) The root will be indicated by a value of -1
*/
void buildTree()
{
    int parent_index, number_of_nodes, root_index;
    std::vector<Node> nodes;

    std::cin >> number_of_nodes;
    nodes.resize(number_of_nodes);
    
    for (int child_index = 0; child_index < number_of_nodes; child_index++)
    {
        std::cin >> parent_index;
        if (parent_index >= 0)
        {
            nodes[child_index].setParent(&nodes[parent_index]);
        }
        
        if (parent_index <  0)
        {
            root_index = child_index;
        }
        nodes[child_index].key = child_index;
    }
    
    std::cout << levelTraversal(&nodes, root_index) << std::endl;
}
