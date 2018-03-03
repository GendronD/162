/*********************************************************************
** Program name: War Game with Dice Design
** Author: Devin Gendron
** Date: 1/28/17
** Description: War game with two players using a loaded and unloaded dice.
*********************************************************************/
#include "gameMenu.hpp"
#include "inputValidation.hpp"
#include "promptPlayer.hpp"
#include "dieClass.hpp"
#include "loadedDieClass.hpp"
#include "gameClass.hpp"

int main()
{
	srand(time(NULL));						//time seed
	Game game;								//game object

	int menuC = game.menu();				//main menu

	switch (menuC)
	{
		case 1 : //Play Game	
				{	
					game.rounds();
					int dType = game.dieType();

					switch (dType)	//Determines game by player dice type
					{
						case 1 :	//Player 1 = Die, Player 2 = Loaded Die
								{
									Die *player1 = new Die();
									Die *player2 = new LoadedDie();
									game.setPlayer1(player1);
									game.setPlayer2(player2);
									game.setGame();			//sets player/dice objects
									game.runGame();		//runs game
								}
									break;

						case 2 :
								{	//Player 1 = Loaded Die, Player 2 = Die
									Die *player1 = new LoadedDie();
									Die *player2 = new Die();
									game.setPlayer1(player1);
									game.setPlayer2(player2);
									game.setGame();			//sets player/dice objects
									game.runGame();		//runs game
								}
									break;

						case 3 :	
								{	//Player 1 = Die, Player 2 = Die
									Die *player1 = new Die();
									Die *player2 = new Die();
									game.setPlayer1(player1);
									game.setPlayer2(player2);
									game.setGame();			//sets player/dice objects
									game.runGame();		//runs game
								}
									break;

						case 4 :	
								{	//Player 1 = Loaded Die, Player 2 = Loaded Die
									Die *player1 = new LoadedDie();
									Die *player2 = new LoadedDie();
									game.setPlayer1(player1);
									game.setPlayer2(player2);
									game.setGame();			//sets player/dice objects
									game.runGame();		//runs game
								}
									break;
					}
					break;
				}
				break;

		case 2 : //Quit Game
				{
					game.gameQuit();		//Quit Game Functions
				}
					break;
	}

	return 0;
}