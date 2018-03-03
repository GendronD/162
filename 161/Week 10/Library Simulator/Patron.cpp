#include "Patron.hpp"
#include <string>
#include <vector>
#include <iostream>

/****************************************************************
* a constructor that takes an idNum and name and initializes 
* fineAmount to zero
*****************************************************************/
//overloaded constructor
Patron::Patron(std::string idn, std::string n) : idNum(idn), name(n)
	{
		//idNum = idn;
		//name = n;
		fineAmount = 0.0;
	}

/****************************************************************
* idNum - a unique identifier for a Patron - you can assume 
* uniqueness, you don't have to enforce it
*****************************************************************/
//Getter for idNum
std::string Patron::getIdNum()
{
	return idNum;	//gets idNum from private
}

/****************************************************************
* name - cannot be assumed to be unique
*****************************************************************/
//Getter for name
std::string Patron::getName()
{
	return name;	//gets name from private
}

/****************************************************************
* checkedOutBooks - a vector of pointers to Books that Patron 
* currently has checkedOut
*****************************************************************/
//Getter for Vector of checked out books
std::vector<Book*> Patron::getCheckedOutBooks()
{
	//if tests don't work, maybe use a for loop to specifically pull each book??
	return checkedOutBooks;	//gets vector of books, checkedOutBooks, from private
}

/****************************************************************
* addBook - adds the specified Book to checkedOutBooks
*****************************************************************/
//Function adds a book to the book vector
void Patron::addBook(Book* b)
{
	//for test
	//getCheckedOutBooks();
	if (b != NULL)
	{
		//std::cout << "book added to book vector" << std::endl;
		checkedOutBooks.push_back(b);	//adds book to vector Book* with push_back
	}
}

/****************************************************************
* removeBook - removes the specified Book from checkedOutBooks
*****************************************************************/
//Function removes a book from the book vector Book*
void Patron::removeBook(Book* b)
{
	for (int k = 0; k < checkedOutBooks.size(); k++)	//loop to cycle through vector
	{
		if (checkedOutBooks.at(k) == b) 	//condition to check if book is correct
			checkedOutBooks.erase(checkedOutBooks.begin() + k);	//erases said book
			//return 0; //needed?
	}
}

/****************************************************************
* fineAmount - how much the Patron owes the Library in late fines 
* (measured in dollars); this is allowed to go negative
*****************************************************************/
//Getter gets the amount of patrons fine
double Patron::getFineAmount()
{
	return fineAmount;	//gets fine amount from private
}

/****************************************************************
* amendFine - a positive argument increases the fineAmount, a 
* negative one decreases it
*****************************************************************/
//Function: Add or decrease fine amount
void Patron::amendFine(double amount)	//amount(+) for increase fine/amount(-) for paid fine
{
	fineAmount = fineAmount + amount;	//increments or decrements fine amount by designated fee or amendment
}