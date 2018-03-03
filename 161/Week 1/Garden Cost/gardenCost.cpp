/*************************************************
 * *Author: Devin Gendron
 ** Date: 9/24/17
 ** Description: Program that calculates how much a garden center needs to spend for a flower garden display.
 * ***********************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	double soilCost, seedCost, fenceCost, totalCost;

	//What does the soil cost?//
	cout << "What does the soil cost?\n";
	cin >> soilCost;

	//What do the flower seeds cost?//
	cout << "What do the flower seeds cost?\n";
	cin >> seedCost;

	//What does the fence cost?//
	cout << "What does the fence cost?\n";
	cin >> fenceCost;

	//Calculate the total cost.//
	totalCost = soilCost + seedCost + fenceCost;

	//Print total cost of flower garden display//
	cout << "The total cost is " << totalCost << endl;

	return 0;
}	
