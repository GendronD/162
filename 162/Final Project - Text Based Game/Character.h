/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#ifndef TEXT_BASED_GAME_CHARACTER_H
#define TEXT_BASED_GAME_CHARACTER_H
#include <vector>
#include "Event.h"
#include "Space.h"
class Event;
struct Item;

class Character {
private:
    int health = 0;
    int attack = 0;
    int defense = 0;
    int armor = 0;
    int weaponry = 0;
    Event* inv = nullptr;
    std::vector<Item> inventory;
    bool glowing_key;
    Space* currentLocation = nullptr;

protected:
public:
    //constructor
    Character();
    //overloaded constructor
    Character(int, int, int);
    //character functions
    int getHealth();
    int getAttack();
    int getDefense();
    int getArmor();
    int getWeaponry();
    Item getItem(int n);
    std::vector<Item> getInventory();
    void setHealth(int h);
    void setInventory(Item);
    int attackRoll();
    int defenseRoll();
    Event setInv(Event*);

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