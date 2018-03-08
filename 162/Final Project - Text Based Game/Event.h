/*************************************************************************
** Program name: Stack and Queue STL Containers
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#ifndef TEXT_BASED_GAME_EVENT_COMBAT_H
#define TEXT_BASED_GAME_EVENT_COMBAT_H
#include "Space.h"
#include "Character.h"
#include <iostream>
#include <vector>

struct Item
{
    std::string name = " ";
    int id = 0;
    Item(std::string name, int id)
    {
        this->name;
        this->id;
    }
};

class Event {
private:
    ///need player inventory
    Character* character;
    bool has_key;

    ///items
    Item sword = Item("Sword", 1);
    Item shield = Item("Shield", 2);
    Item cat = Item("Cat", 3);
    Item key = Item("Key", 4);
    Item evil_segfault_head = Item("Evil SegFault's Head", 5);
    ///game items vector
    std::vector<Item> game_inv = {sword, shield, cat, key, evil_segfault_head};
    //////
    /////
    ///dialogue ids
    int begin_quest = 1;
    int cat_quest = 2;
    int paws_clue = 3;
    int end_cat_quest = 4;
    int door_quest = 5;
    int teleported = 6;
    int before_battle = 7;
    int after_battle = 8;
    int castle_code = 9;

protected:
public:
    //default constructor
    Event();

    //functions
    void setCharacter(Character* c);
    void event_door();
    void event_combat();
    void call_event(int a);

    //items
    void item_action(Item item_type);
    Item getItem(std::string name);
    //void call_event(Item a);

    //dialogue
    void dialogue_action(int a);
};


#endif //TEXT_BASED_GAME_EVENT_COMBAT_H