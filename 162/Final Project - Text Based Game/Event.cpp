/*************************************************************************
** Program name: Stack and Queue STL Containers
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#include "Event.h"
Event::Event()
{

}
void Event::setCharacter(Character* c)
{
    character = c;
}

////////////////////
/////// DOOR ///////
////////////////////
void Event::event_door()
{
    if (character->getInventory().size() >= 6)///players inventory has key
    {
        has_key = true;
        std::cout << "You slip the key into the port stone, you feel the air around you"
                  << "begin to vibrate.  It glows a bright blue color. Suddenly, you are"
                  << " lifted from the ground and blinded by a flash."
                  << std::endl;
    }
    else
    {
        std::cout << "There is an interesting stone here with a key shaped hole. I wonder"
                  << " if it does something." << std::endl;
    }
}

//////////////////////
/////// COMBAT ///////
//////////////////////
void Event::event_combat()
{
    std::cout << "You finally discover the Evil SegFault's Lair.  Corpses of sourcecode"
              << " lay about the cave, mangled and broken. The creature turns and sees "
              << "you - you raise your sword and shield and prepare for your chance at glory."
              << std::endl;

    ///enter combat loop here
}


/*void Event::call_event(int a)
{
    if (a == 1)
    {
        event_door();
    }
    else if (a == 2)
    {
        event_combat();
    }
}*/

/////////////////////
/////// ITEMS ///////
/////////////////////
void Event::item_action(Item item_type)
{

    int item_id = item_type.id;

    if(item_id == 1)    //sword item
    {
        std::cout << "You've found the Magical Pointer Sword!" << std::endl;
        character->setInventory("Sword");
    }
    else if (item_id == 2)  //shield item
    {
        std::cout << "You've found the Magical Valgrind Shield!" << std::endl;
        character->setInventory("Shield");
    }
    else if (item_id == 3)
    {
        std::cout << "You've found Old Fortran's Cat, Backus" << std::endl;
        std::cout << "You should bring it back." << std::endl;
        std::cout << "Backus notices your intent, and starts off at a run." << std::endl;
        std::cout << "*1 hour and a few scratches later you have Backus in tow*" << std::endl;
        std::cout << "*Time to head back to the Old Fortran*" << std::endl;
        character->setInventory("Cat");
    }
    else if (item_id == 4)
    {
        std::cout << "You receive a glimmering key from Old Fortran." << std::endl;
        std::cout << "You wonder what door it may unlock..." << std::endl;
        character->setInventory("key");
    }
    else if (item_id == 5)
    {
        std::cout << "With a view of Castle Code in the distance, you remove "
                  << "the Evil SegFaults head with your magic blade."
                  << std::endl;
        character->setInventory("Evil SegFault's Head");
    }
    else
    {
        std::cout << "No Items Found!" << std::endl;
    }
}
Item Event::getItem(std::string name)
{
    for (int i = 0; i < game_inv.size(); i++)
    {
        if(name == game_inv[i].name)
        {
            return game_inv[i];
        }
        else
        {
            std::cout << "Item not found" << std::endl;
        }
    }
}

////////////////////////
/////// Dialogue ///////
////////////////////////
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
        std::cout << "'What was that!??', you say as you sit up from the ordeal." << std::endl;
        std::cout << "*You gasp as you realize the scenery has changed*" << std::endl;
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