/***********************************************************
** Author: Devin Gendron
** Date: 10/11/17
** Description: Guessing game using loops
************************************************************/

#include <iostream>

int main()
{

	//set variables
	int num;			//int for player input
	int guess;			//int for player guess
	bool continueGuessing = true;	//bool for while loop
	int counter = 0;		//counter for while loop
	int endLoop;			//ends loop

	//Prompt user for an integer: "Enter the number for the player to guess."
	std::cout << "Enter the number for the player to guess." << std::endl;//Prompt
	std::cin >> num; //input

	//Prompt user to enter guess: "Enter your guess."
	std::cout << "Enter your guess." << std::endl;

	//Setup do while loop that repeats infinitely until correct number is chosen
	do
	{
		std::cin >> guess;

		//Nest if-loop with condition for "too high"
		if (guess > num) {
			std::cout << "Too high - try again." << std::endl;
		}

		//Nest elseif-loop with condition for "too low"
		else if (guess < num) {
			std::cout << "Too low - try again." << std::endl;
		}

		//Nest else if-loop with conidition for correct guess
		else if (guess == num)
			continueGuessing = false;
			counter += 1;

	} while (continueGuessing);

	//display the amount of guesses it took: "You guessed it in '#' tries."
	std::cout << "You guessed it in " << counter << " tries." << std::endl;

	return 0;
}
