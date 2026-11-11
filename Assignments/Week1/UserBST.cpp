#include <iostream>
#include <list>
#include <format>

struct TreeElement 
{
    int id;
    TreeElement* Left;
    TreeElement* Right;

    TreeElement(int id)
    {
        this->id = id;
        this->Left = nullptr;
        this->Right = nullptr;
    }
};

TreeElement* PopulateTree(const std::list<int>* elements);
TreeElement* InsertElement(TreeElement* root, int id);
std::list<int> FindLeaves(TreeElement* current);
bool IsLeaf(TreeElement* element);
void Cleanup(TreeElement* root);

void PrintInfo(std::string text);
void PrintOutput(std::string text);
void PrintHeader(std::string text);

int main() 
{
    PrintHeader("This is the assignment for Week 1 - a simple Binary Search Tree\n");

    // Elements of BST (42, obviously...)
    std::list<int> elements = std::list<int>();

    PrintInfo("Enter values for the nodes\n");
    PrintInfo("Value + Enter to create a new node, Empty + Enter to end\n");
    bool done = false;
    while(!done)
    {
        std::string input;
        PrintOutput("Node: ");
        std::getline(std::cin, input);

        if(!std::cin || input.empty())
        {
            done = true;   
        } else
        {
            try 
            {
                int value = std::stoi(input);
                elements.push_back(value);
            } catch(...)
            {
                PrintInfo("Invalid input, try again...\n");
            }
        }
    }


    PrintInfo("Building BST...\n");
    for(int n : elements)
        PrintOutput(std::format("[{}] ", n));
    PrintInfo("\n");
    auto root = PopulateTree(&elements);

    PrintInfo("Leaves found:\n");
    auto leaves = FindLeaves(root);
    for(int n : leaves)
        PrintOutput(std::format("[{}] ", n));
    PrintInfo("\n");

    PrintInfo("All done, bye!\n");

    Cleanup(root);
    return 0;
}


void PrintHeader(std::string text)
{
    std::cout << "\033[34m" << text << "\033[0m";
}
void PrintInfo(std::string text)
{
    std::cout << "\033[36m" << text << "\033[0m";
}
void PrintOutput(std::string text)
{
    std::cout << "\033[32m" << text << "\033[0m";
}

TreeElement* PopulateTree(const std::list<int>* elements)
{
    TreeElement* root = nullptr;

    for(int element : *elements)
    {
        auto e = InsertElement(root, element);
        if(root == nullptr)
            root = e;
    }

    return root;
}

TreeElement* InsertElement(TreeElement* root, int id)
{
    if(root == nullptr)
        return new TreeElement(id); 

    if(root->id == id)
        return root; // Already exists, I cannot have duplicate elements

    if(root->id > id)
        root->Left = InsertElement(root->Left, id);
    else
        root->Right = InsertElement(root->Right, id);

    return root;
}

bool IsLeaf(TreeElement* element)
{
    return element != nullptr && element->Left == nullptr && element->Right == nullptr;
}

std::list<int> FindLeaves(TreeElement* current)
{
    std::list<int> result;

    if(current == nullptr)
        return result;

    if(IsLeaf(current))
    {
        // Is Leaf
        result.push_back(current->id);
    } else
    {
        if(current->Left != nullptr)
        {
            auto leaves = FindLeaves(current->Left);
            for(int leaf : leaves)
                result.push_back(leaf);
        }
        if(current->Right != nullptr)
        {
            auto leaves = FindLeaves(current->Right);
            for(int leaf : leaves)
                result.push_back(leaf);
        }
    }

    return result;
}

void Cleanup(TreeElement* current)
{
    if(current == nullptr)
        return;

    Cleanup(current->Left);
    Cleanup(current->Right);

    delete current;
}