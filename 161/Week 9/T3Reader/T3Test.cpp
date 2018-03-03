#include "Board.hpp"
#include "T3Reader.hpp"
#include <iostream>

int main()
{
	T3Reader game('x');
	bool test = game.readGameFile("draw.txt");
	if (test)
  		std::cout << "pass\n";
	else
  		std::cout << "fail\n";

	return 0;
}