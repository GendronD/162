/*************************************************************************
** Program name: Stack and Queue STL Containers
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#include "Character.h"
Character::Character()
{
    Event inv;
    health = 15;
    attack = 3;
    defense = 3;
    glowing_key = false;
}
int Character::getHealth()
{
    return health;
}
int Character::getAttack()
{
    return attack;
}
Item Character::getItem(int n)
{
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].id == n)
        {
            return inventory.[i];
        }
        else
        {
            std::cout << "Item not found in the inventory." << std::endl;
        }
    }
}
std::vector<Item> Character::getInventory()
{
    return inventory;
}
void Character::setHealth(int h)
{
    health = health - h;
}
void Character::setInventory(std::string n)
{
    if (n == inv.getItem("Sword").name && inventory.size() < 6)
    {
        inventory.push_back(inv.getItem("Sword"));
        attack = attack + 2;
        std::cout << "Attack has increased by 2!" << std::endl;
    }
    else if (n == inv.getItem("Shield").name && inventory.size() < 6)
    {
        inventory.push_back(inv.getItem("Shield"));
        defense = defense + 2;
        std::cout << "Defense has increased by 2!" << std::endl;
    }
    else if (n == inv.getItem("Cat").name && inventory.size() < 6)
    {
        inventory.push_back(inv.getItem("Cat"));
    }
    else if (n == inv.getItem("Key").name && inventory.size() < 6)
    {
        inventory.push_back(inv.getItem("Key"));
        glowing_key = true;
    }
    else if (n == inv.getItem("Evil SegFault's Head").name && inventory.size() < 6)
    {
        inventory.push_back(inv.getItem("Evil SegFault's Head"));
    }
    else
    {
        std::cout << "Inventory full." << std::endl;
    }
}
int Character::attackRoll()
{
    int roll = 0;
    std::cout << "Sir Codesalot takes a mighty swing with his sword!" << std::endl;
    roll = (rand() % 6 + 1);
    std::cout << "He does " << roll << " damage in his attack." << std::endl;

    attack = attack + roll;

    return attack;
}
int Character::defenseRoll()
{
    int roll = 0;
    std::cout << "Sir Codesalot raises his shield!" << std::endl;
    roll = (rand() % 6 + 1);
    std::cout << "He deflects " << roll << " damage!" << std::endl;

    defense = defense + roll;

    return defense;
}


//////////
Space* Character::getCurrentLocation()
{
    return currentLocation;
}
void Character::setCurrentLocation(Space* loc)
{
    currentLocation = loc;
}
//character travel
void Character::travel_top()
{
    if (currentLocation->getTop() == nullptr)
    {
    std::cout << "Let's stay on the path, no need to get lost." << std::endl;
    }
    else if (currentLocation->getTop() != nullptr)
    {
        std::cout << "Traveling to " << currentLocation->getTop()->getLocation() << "." << std::endl;
        currentLocation = currentLocation->getTop();
    }
}
void Character::travel_bottom()
{
    if (currentLocation->getBottom() == nullptr)
    {
        std::cout << "Let's stay on the path, no need to get lost." << std::endl;
    }
    else if (currentLocation->getBottom() != nullptr)
    {
        std::cout << "Traveling to " << currentLocation->getTop()->getLocation() << "." << std::endl;
        currentLocation = currentLocation->getBottom();
    }
}
void Character::travel_right()
{
    if (currentLocation->getRight() == nullptr)
    {
        std::cout << "Let's stay on the path, no need to get lost." << std::endl;
    }
    else if (currentLocation->getRight() != nullptr)
    {
        std::cout << "Traveling to " << currentLocation->getTop()->getLocation() << "." << std::endl;
        currentLocation = currentLocation->getRight();
    }
}
void Character::travel_left()
{
    if (currentLocation->getLeft() == nullptr)
    {
        std::cout << "Let's stay on the path, no need to get lost." << std::endl;
    }
    else if (currentLocation->getLeft() != nullptr)
    {
        std::cout << "Traveling to " << currentLocation->getTop()->getLocation() << "." << std::endl;
        currentLocation = currentLocation->getLeft();
    }
}