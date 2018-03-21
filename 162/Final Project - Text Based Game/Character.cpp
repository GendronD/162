/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#include "Character.h"

//constructor
Character::Character()
{
    health = 25;
    attack = 0;
    defense = 0;
    weaponry = 2;
    armor = 2;
    glowing_key = false;
    currentLocation = nullptr;
}

//overloaded constructor -> used to create seg fault monster
Character::Character(int h, int a, int w) : health(h), armor(a), weaponry(w)
{

}
int Character::getHealth()
{
    return health;
}
int Character::getAttack()
{
    return attack;
}
int Character::getDefense()
{
    return defense;
}
int Character::getArmor()
{
    return armor;
}
int Character::getWeaponry()
{
    return weaponry;
}

//checks inventory for item
Item Character::getItem(int n)
{
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].id == n)
        {
            return inventory[i];
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

//adds to users inventory when item is encountered
void Character::setInventory(Item i)
{
    if (inventory.size() < 6)
    {
        inventory.push_back(i);
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

    attack = roll;

    return attack;
}
int Character::defenseRoll()
{
    int roll = 0;
    std::cout << "Sir Codesalot raises his shield!" << std::endl;
    roll = (rand() % 6 + 1);
    std::cout << "He deflects " << roll << " damage!" << std::endl;

    defense = roll;

    return defense;
}
Event Character::setInv(Event* i)
{
    inv = i;
}
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
        //std::cout << "Let's stay on the path, no need to get lost." << std::endl;
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
        //std::cout << "Let's stay on the path, no need to get lost." << std::endl;
    }
    else if (currentLocation->getBottom() != nullptr)
    {
        std::cout << "Traveling to " << currentLocation->getBottom()->getLocation() << "." << std::endl;
        currentLocation = currentLocation->getBottom();
    }
}
void Character::travel_right()
{
    if (currentLocation->getRight() == nullptr)
    {
        //std::cout << "Let's stay on the path, no need to get lost." << std::endl;
    }
    else if (currentLocation->getRight() != nullptr)
    {
        std::cout << "Traveling to " << currentLocation->getRight()->getLocation() << "." << std::endl;
        currentLocation = currentLocation->getRight();
    }
}
void Character::travel_left()
{
    if (currentLocation->getLeft() == nullptr)
    {
        //std::cout << "Let's stay on the path, no need to get lost." << std::endl;
    }
    else if (currentLocation->getLeft() != nullptr)
    {
        std::cout << "Traveling to " << currentLocation->getLeft()->getLocation() << "." << std::endl;
        currentLocation = currentLocation->getLeft();
    }
}