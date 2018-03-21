/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#ifndef TEXT_BASED_GAME_EVENT_COMBAT_H
#define TEXT_BASED_GAME_EVENT_COMBAT_H
#include "Space.h"
#include "Character.h"
#include "Menu.h"
#include <iostream>
#include <vector>

struct Item
{
    std::string name = " ";
    int id = 0;
    Item(std::string n, int i) : name(n), id(i)
    {

    }
};

class Event {
private:
    ///need player inventory
    Character* character = nullptr;
    bool has_key;
    bool door = false;

    ///items
    Item sword = Item("Sword", 1);
    Item shield = Item("Shield", 2);
    Item cat = Item("Cat", 3);
    Item key = Item("Key", 4);
    Item evil_segfault_head = Item("Evil SegFault's Head", 5);

    ///game items vector
    std::vector<Item> game_inv = {sword, shield, cat, key, evil_segfault_head};

protected:
public:
    //default constructor
    Event(Character*);
    //~Event();

    //functions
    void setCharacter(Character*);
    void event_door();
    void event_combat();

    //items
    void item_action(int);
    int getItem(std::string name);

    //dialogue
    void dialogue_action(int a);
};


#endif //TEXT_BASED_GAME_EVENT_COMBAT_H