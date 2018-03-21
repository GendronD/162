/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#include "Event.h"
#include "Character.h"
#include "Mountain_Pass.h"

Event::Event(Character* sca)
{
    character = sca;
}

//sets character to interact with events
void Event::setCharacter(Character* c)
{
    character = c;
}

/////// DOOR ///////
//door event to transport character
void Event::event_door()
{
    if(door == false)
    {
        if (character->getInventory().size() > 3) //players inventory has key
        {
            has_key = true;
            dialogue_action(5);

            character->travel_bottom();

            std::cout << std::endl;
            std::cout << "..." << std::endl;
            std::cout << std::endl;

            dialogue_action(6);
            door = true;
        }
        else
        {
            std::cout << "There is an interesting stone here with a key shaped hole. I wonder"
                      << " if it does something." << std::endl;
        }
    }
    else
    {
        std::cout << "Looks like there's no way back through the portal, better keep moving." << std::endl;
        character->travel_bottom();
    }
}

/////// COMBAT ///////
//character fights seg fault monster
void Event::event_combat()
{
    int damage = 0;
    int gameOver = 0;
    int cC = 0;


    Character *segFault = nullptr;
    segFault = new Character(35, 2, 1);  //35 health, 2 armor, 1 weaponry

    do {
        std::cout << "Sir Codesalot attacks!" << std::endl;

        character->attackRoll();
        std::cout << "Sir Codesalot's attack power is: " << character->getAttack() + character->getWeaponry() << std::endl;

        std::cout << "The Evil SegFault defends!" << std::endl;
        segFault->defenseRoll();
        std::cout << "The Evil SegFault's defense is: " << segFault->getDefense() << std::endl;

        damage = character->getAttack() + character->getWeaponry() - segFault->getDefense() - segFault->getArmor();
        if (damage > 0)
        {
            std::cout << "Sir Codesalot did " << damage << " points of damage to The Evil SegFault." << std::endl;
            segFault->setHealth(damage);
            std::cout << "The Evil SegFault now has " << segFault->getHealth() << " left." << std::endl;
        }
        else
        {
            std::cout << "The Attack was completely defended!" << std::endl;
            std::cout << "The Evil SegFault still has " << segFault->getHealth() << " left." << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;

        if(segFault->getHealth() > 0)
        {
            std::cout << "The Evil SegFault attacks!" << std::endl;
            segFault->attackRoll();
            std::cout << "The Evil SegFault's attack power is: " << segFault->getAttack() + segFault->getWeaponry() << std::endl;
            std::cout << "Sir Codesalot defends!" << std::endl;
            character->defenseRoll();
            std::cout << "Sir Codesalot's defense is: " << character->getDefense() << std::endl;
            damage = segFault->getAttack() + segFault->getWeaponry() - character->getDefense() - character->getArmor();
            if (damage > 0)
            {
                std::cout << "The Evil SegFault did " << damage << " points of damage to Sir Codesalot." << std::endl;
                character->setHealth(damage);
                std::cout << "Sir Codesalot now has " << character->getHealth() << " left." << std::endl;
            }
            else
            {
                std::cout << "The Attack was completely defended!" << std::endl;
                std::cout << "Sir Codesalot still has " << character->getHealth() << " left." << std::endl;
            }
        }

        std::cout << std::endl;
        std::cout << std::endl;

        if (character->getHealth() < 1) {
            std::cout << "The Evil SegFault stands over you as you take your last breathe - suddenly all is dark." << std::endl;
            std::cout << "GAME OVER" << std::endl;
            std::cout << std::endl;
            gameOver = 1;
        } else if (segFault->getHealth() < 1) {
            std::cout << "The Evil SegFault has been defeated!" << std::endl;
            item_action(5);
            std::cout << std::endl;
            gameOver = 1;

            //final dialogues
            dialogue_action(8);
            std::cout << std::endl;
            std::cout << "Some arduous traveling later..." << std::endl;
            std::cout << std::endl;
            dialogue_action(9);
        }
        else
        {
            cC = contCombat();
            switch (cC)
            {
                case 1 : //play again
                    gameOver = 0;
                    break;
            }
        }

    }while(gameOver == 0);
    delete segFault;
    segFault = nullptr;

}

/////////////////////
/////// ITEMS ///////
/////////////////////
//function to put items in character's inventory
void Event::item_action(int item_id)
{
    if(item_id == 1)    //sword item
    {
        std::cout << "You've found the Magical Pointer Sword! +2 to Weaponry!" << std::endl;
        character->setInventory(sword);
    }
    else if (item_id == 2)  //shield item
    {
        std::cout << "You've found the Magical Valgrind Shield! +2 to Armor!" << std::endl;
        character->setInventory(shield);
    }
    else if (item_id == 3)
    {
        std::cout << "You've found Old Fortran's Cat, Backus" << std::endl;
        std::cout << "You should bring it back." << std::endl;
        std::cout << "Backus notices your intent, and starts off at a run." << std::endl;
        std::cout << "*1 hour and a few scratches later you have Backus in tow*" << std::endl;
        std::cout << "*Time to head back to the Old Fortran*" << std::endl;
        character->setInventory(cat);
    }
    else if (item_id == 4)
    {
        std::cout << "You receive a glimmering key from Old Fortran." << std::endl;
        std::cout << "You wonder what door it may unlock..." << std::endl;
        character->setInventory(key);
    }
    else if (item_id == 5)
    {
        std::cout << "You remove the Evil SegFaults head with your magic blade." << std::endl;
        character->setInventory(evil_segfault_head);
    }
    else if (item_id == -1)
    {
        std::cout << "No Items Found!" << std::endl;
    }
    else
    {
        std::cout << "how" << std::endl;
    }
}
int Event::getItem(std::string name)
{
    for (int i = 0; i < game_inv.size(); i++)
    {
        if(name == game_inv[i].name)
        {
            return game_inv[i].id;
        }
    }
    return -1;
}

////////////////////////
/////// Dialogue ///////
////////////////////////
//function that controls dialogue events
void Event::dialogue_action(int a)
{
    int dialogue_act = a;
    if(dialogue_act == 1)    //begin quest
    {
        std::cout << "Sir Codesalot walked through the Linker Forest." << std::endl;
        std::cout << "He wondered, 'How will I ever get accepted into " << std::endl;
        std::cout << "the Knights of The Code Table... I've tried everything'." << std::endl;
        std::cout << "*Suddenly a man walks away from a Caravan also passing "
                  << " through the forest*" << std::endl;
        std::cout << "'I hear you're looking for membership to that fancy table?', "
                  << "said the Man." << std::endl;
        std::cout << "'Yes', you reply, eager for any advice." << std::endl;
        std::cout << "'Old Fortran lost his cat again - maybe finding him will help.'" << std::endl;
        std::cout << "*Sigh - another boring tasks.  Might as well*" << std::endl;
        std::cout << "*You turn to thank the man, but he's vanished..."
                  << " you shrug and continue on your way - looking for Old Fortran." << std::endl;
    }
    else if (dialogue_act == 2)  //cat quest
    {
        std::cout << "'YOU! YOU! WITH THAT SILLY HELMET!'" << std::endl;
        std::cout << "*You notice an old man running up to you*" << std::endl;
        std::cout << "'What is wrong old man?', you say as he reaches you" << std::endl;
        std::cout << "'My cat! Poor ol' Backus got lost. Can you help find him?'" << std::endl;
        std::cout << "*Nodding your head* 'Surely, point me in the direction he was last seen.'" << std::endl;
        std::cout << "*The old man points both up and to the right*" << std::endl;
        std::cout << "'He went one of those ways....'" << std::endl;
        std::cout << "*You sigh yet again* 'I'll see what I can do.'" << std::endl;
    }
    else if (dialogue_act == 3) //cat clues
    {
        std::cout << "*You find paw prints in the ground leading up the path*" << std::endl;
    }
    else if (dialogue_act == 4) //cat returned
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "*Sometime later..." << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "'YOU'VE FOUND HIM! MY DEAR BACKUS'" << std::endl;
        std::cout << "*The man embraces his cat with a smile*" << std::endl;
        std::cout << "'There's only one way I can thank you', exclaims Old Fortran." << std::endl;
        std::cout << "'Here, please take this.'" << std::endl;
        std::cout << "'It's a special thing it is. Do take care of it.'" << std::endl;
        std::cout << "*You look in the sack to see an old key.  When you look up Old Fortran is gone*" << std::endl;

    }
    else if (dialogue_act == 5) //door quest
    {
        std::cout << "*As you walk, you notice your pouch with the key beginning to glow*" << std::endl;
        std::cout << "*You peek inside and see that a ray of light points in a certain direction and decide to follow*" << std::endl;
        std::cout << "*You reach a stone with runes etched in it's face with a key shaped hole in the center*" << std::endl;
        std::cout << "*Curious, you slide the key in and turn*" << std::endl;
        std::cout << "*Nothing seems to happen, you turn about to walk away when you notice something*" << std::endl;
        std::cout << "*You're arms are glowing blue, then the rest of you too*" << std::endl;
        std::cout << "'Ummmmmm', you manage to say before a blinding flash of light hits you and you get twisted all around." << std::endl;
    }
    else if (dialogue_act == 6)
    {
        std::cout << "'What was that!?', you say as you sit up from the ordeal." << std::endl;
        std::cout << "You gasp as you realize the scenery has changed" << std::endl;
        std::cout << "*Attempting to get your bearings, you look around and see a notice on a tree.*" << std::endl;
        std::cout << "*It reads, 'EVIL SEGFAULT IN AREA. REWARD OF ENTRY TO KNIGHTS OF THE CODE TABLE'*" << std::endl;
        std::cout << "*A grin spreads across your face.  Finally, a chance to prove myself*" << std::endl;
        std::cout << "*As sun starts to set, you begin your search for the Evil SegFault*" << std::endl;
    }
    else if (dialogue_act == 7)
    {
        std::cout << "*As the night grows on, you begin to think it may be too late* " << std::endl;
        std::cout << "*In the distance you see what seems like a cozy cave*" << std::endl;
        std::cout << "'That should be safe', you say as you walk on in." << std::endl;
        std::cout << "*Upon entering, you realize this cave isn't as it seems.*" << std::endl;
        std::cout << "*All around are mangled corpses of men bearing the emblem of the Knight of The Code Table*" << std::endl;
        std::cout << "'Well looks like I found it', you say as you hear a roar deeper in the tunnel." << std::endl;
        std::cout << "*Suddenly the beast appears and charges.  You raise your shield and prepare your sword.  This is it*" << std::endl;
    }
    else if (dialogue_act == 8)
    {
        std::cout << "'I did it! Barely, but I did it!'" << std::endl;
        std::cout << "*Grinning with your trophy in hand, you start your journey towards Castle Code*" << std::endl;
    }
    else if (dialogue_act == 9)
    {
        std::cout << "*You kick in the doors to Castle Code and raise up your trophy of the Evil SegFault, grinning*" << std::endl;
        std::cout << "*You hear gasps of awe and open your eyes and gasp yourself*" << std::endl;
        std::cout << "*Down at the table you see Old Fortran and Backus surrounded by members of the Knights of the Code Table*" << std::endl;
        std::cout << "'YOU!', you exclaim. 'YOU!', Old Fortran replies with a chuckle" << std::endl;
        std::cout << "'Did you put me to this?!', you frantically ask." << std::endl;
        std::cout << "Old Fortran giggles and says, 'Why, but of course! I heard of your skills.  I needed to test you!'" << std::endl;
        std::cout << "You stand mouth agape and say, 'But all those corpses! That could have been me!'" << std::endl;
        std::cout << "I knew you could do it, but now I have something even more important for you to take on." << std::endl;
        std::cout << "You raise an eyebrow, 'What's that you say?'" << std::endl;
        std::cout << "Old Fortran laughs and replies, 'Count Codinterview is back to his old games.'" << std::endl;
        std::cout << "'Will you help us defeat him?'" << std::endl;
        std::cout << "You smile, 'Let's Go.'" << std::endl;

        std::cout << std::endl;
        std::cout << "The End." << std::endl;
    }
    else
    {
        std::cout << "No Dialogue." << std::endl;
    }
}