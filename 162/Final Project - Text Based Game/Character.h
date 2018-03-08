/*************************************************************************
** Program name: Stack and Queue STL Containers
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#ifndef TEXT_BASED_GAME_CHARACTER_H
#define TEXT_BASED_GAME_CHARACTER_H
#include <vector>
#include "Event.h"
#include "Space.h"

class Character {
private:
    int health = 0;
    int attack = 0;
    int defense = 0;
    Event inv;
    std::vector<Item> inventory;
    bool glowing_key;
    Space* currentLocation;

protected:
public:
    //constructor
    Character();
    //character functions
    int getHealth();
    int getAttack();
    Item getItem(int n);
    std::vector<Item> getInventory();
    void setHealth(int h);
    void setInventory(std::string n);
    int attackRoll();
    int defenseRoll();

    //location functions
    Space* getCurrentLocation();
    void setCurrentLocation(Space*);
    //character travel
    void travel_top();
    void travel_bottom();
    void travel_right();
    void travel_left();
};


#endif //TEXT_BASED_GAME_CHARACTER_H
