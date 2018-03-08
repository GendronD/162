/*************************************************************************
** Program name: Stack and Queue STL Containers
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#include "Space.h"
Space::Space()
{
    this->top = nullptr;
    this->bottom = nullptr;
    this->right = nullptr;
    this->left = nullptr;
}
Space* Space::getTop()
{
    if (top == nullptr)
    {
        std::cout << "That path leads no where, let's try another way." << std::endl;
        return nullptr;
    }
    else
    {
        return top;
    }
}
Space* Space::getBottom()
{
    if (bottom == nullptr)
    {
        std::cout << "That path leads no where, let's try another way." << std::endl;
        return nullptr;
    }
    else
    {
        return bottom;
    }
}
Space* Space::getRight()
{
    if (right == nullptr)
    {
        std::cout << "That path leads no where, let's try another way." << std::endl;
        return nullptr;
    }
    else
    {
        return right;
    }
}
Space* Space::getLeft()
{
    if (left == nullptr)
    {
        std::cout << "That path leads no where, let's try another way." << std::endl;
        return nullptr;
    }
    else
    {
        return left;
    }
}
std::string Space::getLocation()
{
    return location;
}
void Space::newLocation(Space* t, Space* b, Space* r, Space* l, std::string loc, Character* ch)
{
    top = t;
    bottom = b;
    right = r;
    left = l;
    location = loc;
    character = ch;
}