#include <string>
#include <vector>
#include <iostream>
#include "Patron.hpp"
#include "Library.hpp"

/****************************************************************
* a constructor that initializes the currentDate to zero.
* currentDate - stores the current date represented as an integer 
* number of "days" since the Library object was created
*****************************************************************/
//constructor for the library
Library::Library()
{
	currentDate = 0;	//initial library date is 0
	//payment = 0.0;
}

/****************************************************************
* addBook - adds the parameter to holdings
*****************************************************************/
//adds a book to the library
void Library::addBook(Book* newBook)
{
	holdings.push_back(newBook);	//books held in holdings, push_back adds new book to vector
}

/****************************************************************
* addPatron - adds the parameter to members
*****************************************************************/
//adds a patron to the library
void Library::addPatron(Patron* newPatron)
{
	members.push_back(newPatron);	//patrons held in members, push_back adds new patron to vector
}

/****************************************************************
* checkOutBook -
* if the specified Book is not in the Library, return "book not found"
* if the specified Patron is not in the Library, return "patron not found"
* if the specified Book is already checked out, return "book already checked out"
* if the specified Book is on hold by another Patron, return "book on hold by other patron"
* otherwise update the Book's checkedOutBy, dateCheckedOut and Location; 
* if the Book was on hold for this Patron, update requestedBy; 
* update the Patron's checkedOutBooks; return "check out successful"
*****************************************************************/
//Patron and book they check out
std::string Library::checkOutBook(std::string pID, std::string bID)
{
	/*********************************************************************************/
	//requestBook takes pID and bID - set pointers to retrieve the member(patron)
	//and holding (book)
	//if (getPatron(pID) == NULL)
	//	std::cout << "get patron is NULL" << std::endl;
	//if (getBook(bID) == NULL)
		//std::cout << "get book is NULL" << std::endl;
	/********************************************************************************/
	//Patron *libMember;
	//Book *libHolding;
	//libMember->getPatron(pID);
	//libHolding->getBook()
	//Patron* libMember = NULL;	//gets patron ID from patron class and initializes it to *patron
	//Book* libHolding = NULL;	

	Patron* libMember = getPatron(pID);	//gets patron ID from patron class and initializes it to *patron
	Book* libHolding = getBook(bID);	//gets book ID from book class and intializes it to *book

	/********************************************************************************/
	//testing pointers for null with:
	//if(libMember != NULL)
	//{
	//	std::cout << "libMember not null" << std::endl;
	//}
	//if(libHolding != NULL)
	//{
	//	std::cout << "libHolding not null" << std::endl;
	//}
	/********************************************************************************/

	//if specified book not in lib system, return "book not found"
	if(libHolding == NULL)	//if book not found/in the system
	{
		return "book not found";	//returns statement
		//return bnf;
	}
		

	//if specified patron not in lib system, return "patron not found"
	if(libMember == NULL)	//if patron not found 
	{
		return "patron not found";	//return statement
		//return pnf;
			//end function here??
	}

	//if specified book is already checked out, return "book already checked out"
	//if (*libHolding.getLocation() == CHECKED_OUT)	//conditional to see if true	
	//if ((*libHolding).getLocation() == CHECKED_OUT)	//conditional to see if true	
	if (libHolding->getLocation() == CHECKED_OUT)	//conditional to see if true
	{
		return "book already checked out";	//return statement
		//return baco;
	}


	//does this location fix the error?
	//if the book was on hold for this patron, update their original request
	//if (*libHolding.getLocation() == ON_HOLD_SHELF)	//conditional to see if true	
	//if ((*libHolding).getLocation() == ON_HOLD_SHELF)	//conditional to see if true	
	else if (libHolding->getLocation() == ON_HOLD_SHELF) //if book is on hold 
	{
		//conditional to check book holding
		//if (libHolding.getRequestedBy() != libMember)	//"if the book requested by pID != patron"
		//if ((*libHolding).getRequestedBy() != libMember)	//"if the book requested by pID != patron"
		if (libHolding->getRequestedBy() != libMember)	//"if the book requested by pID != patron"
		{
			return "book on hold by other patron";
			//return bohbop;
		}
		else
			//sets requests to null since the patron has the book now
			//libHolding.setRequestedBy(NULL);	//book location no longer set as ON_HOLD_SHELF
			//(*libHolding).setRequestedBy(NULL);	//book location no longer set as ON_HOLD_SHELF
			libHolding->setRequestedBy(NULL);	//book location no longer set as ON_HOLD_SHELF
	}

	//Update checkedOutBy with patron ID
	else 
	{//libHolding.setCheckedOutBy(libMember);	//this sets the patron to the holder of th book
	libHolding->setCheckedOutBy(libMember);	//this sets the patron to the holder of th book

	//Update dateCheckedOut with the libraries current date
	//libHolding.setDateCheckedOut(currentDate);	//this sets checkoutdate to current lib date
	libHolding->setDateCheckedOut(currentDate);	//this sets checkoutdate to current lib date

	//Update the books new location
	libHolding->setLocation(CHECKED_OUT);	//this marks the book as checked out

	//if the book was on hold for this patron, update their original request
	/*if (libHolding->getLocation() == ON_HOLD_SHELF) 
	{
		//conditional to check book holding
		if (libHolding->getRequestedBy() != libMember)	//"if the book requested by pID != patron"
			std::cout << "book on hold by other patron" << std::endl;
		else
			//sets requests to null since the patron has the book now
			libHolding->setRequestedBy(NULL);	//book location no longer set as ON_HOLD_SHELF
	}*/

	//std::cout << "made it to just before addBook" << std::endl;

	//Update the list of books the patron has checked out
	//libMember.addBook(libHolding);	//updates book to patrons list
	libMember->addBook(libHolding);	//updates book to patrons list

	//return that the checkout was successful
	//if (libMember->addBook(libHolding) == libHolding)
	return "check out successful";
	//return checkos;
	}
}

/****************************************************************
* returnBook - 
* if the specified Book is not in the Library, return "book not found"
* if the Book is not checked out, return "book already in library"
* update the Patron's checkedOutBooks; update the Book's location 
* depending on whether another Patron has requested it; update 
* the Book's checkedOutBy; return "return successful"
*****************************************************************/
//Book is returned
std::string Library::returnBook(std::string bID)
{
	Book* libHolding = getBook(bID);	//gets book ID from book class and intializes it to *book
	Patron* libMember = libHolding->getCheckedOutBy();

	//if the specified book is not in the library, return "book not found"
	if(libHolding == NULL)	//conditional to check for book
		return "book not found";	//return statement
	//else if (libHolding.getLocation() != CHECKED_OUT)	//conditional to check for book loc
	else if (libHolding->getLocation() != CHECKED_OUT)	//conditional to check for book loc
		return "book already in library";	//return statement

	//update the patron's checkedOutBooks,
	//libMember.removeBook(libHolding);
	libMember->removeBook(libHolding);

	//update the location of the book now that it is returned
	//if (libHolding.getRequestedBy())	//if the book is requested by someone else
	if (libHolding->getRequestedBy())	//if the book is requested by someone else
			//libHolding.setLocation(ON_HOLD_SHELF);	//set it on the hold shelf for them
			libHolding->setLocation(ON_HOLD_SHELF);	//set it on the hold shelf for them
	else 
	{
		//libHolding.setLocation(ON_SHELF);	//sets book on library shelf
		libHolding->setLocation(ON_SHELF);	//sets book on library shelf
		return "return successful";	//return statement
	}
	//libHolding.setCheckedOutBy(NULL);	//sets that no one has the book checked out	
	libHolding->setCheckedOutBy(NULL);	//sets that no one has the book checked out
}

/****************************************************************
* requestBook - 
* if the specified Book is not in the Library, return "book not found"
* if the specified Patron is not in the Library, return "patron not found"
* if the specified Book is already requested, return "book already on hold"
* update the Book's requestedBy; if the Book is on the shelf, update 
* its location to on hold; return "request successful"
*****************************************************************/
//Patron requests a book
std::string Library::requestBook(std::string pID, std::string bID)
{
	//requestBook takes pID and bID - set pointers to retrieve the member(patron)
	//and holding (book)
	Patron* libMember = getPatron(pID);
	Book* libHolding = getBook(bID);

	//if the specified book is not in the library, return "book not found"
	if(libHolding == NULL)	//conditional to check
		return "book not found";	//return statement

	//if the specified patron is not in the library system, return "patron not found"
	if(libMember == NULL)	//conditional to check
		return "patron not found";	//return statement

	//if the specified book is already on hold
	//if (libHolding.getLocation() == ON_HOLD_SHELF)	//conditional to check
	if (libHolding->getLocation() == ON_HOLD_SHELF)	//conditional to check
	{
		//if(getBook(bID).getRequestedBy(pID) != getPatron(pID))
		return "book already on hold";	//return statement
	}
	
	//if the specified book is on the shelf
	//if (libHolding.getLocation() == ON_SHELF)	//conditional to check
	if (libHolding->getLocation() == ON_SHELF)	//conditional to check
	{
		//libHolding.setLocation(ON_HOLD_SHELF);	//sets new location to on_hold_shelf
		libHolding->setLocation(ON_HOLD_SHELF);	//sets new location to on_hold_shelf
		//libHolding.setRequestedBy(libMember);	//sets patron as one who requested
		libHolding->setRequestedBy(libMember);	//sets patron as one who requested
		return "request successful";	//return statement
	}
}

/****************************************************************
* payFine - 
* takes as a parameter the amount that is being paid (not the negative of that amount)
* if the specified Patron is not in the Library, return "patron not found"
* use amendFine to update the Patron's fine; return "payment successful"
*****************************************************************/
//Patron pays their fine
std::string Library::payFine(std::string pID, double payment)
{
	Patron* libMember = getPatron(pID);	//patron id to patron pointer
	//if the specified patron is not in the library, return "patron not found"
	if (libMember == NULL)	//conditional to check
	{
		return "patron not found";	//return statement
	}
	//use amendFine to update the Patron's fine; return "payment successful"
	else
	{
		//libMember.amendFine((payment * -1.0));	//amends fine
		libMember->amendFine((payment * -1.0));	//amends fine
		return "payment successful";	//return statement
	}
}

/****************************************************************
* incrementCurrentDate - 
* increment current date; increase each Patron's fines by 10 cents 
* for each overdue Book they have checked out (using amendFine)
* If a book is checked out on day 0, then on day 1, the patron 
* has had it for 1 day.  On day 21, the patron has had it for 21 
* days, so it is still not overdue.  On day 22, the book is overdue 
* and fines will be charged.
*****************************************************************/
//increments current date 
void Library::incrementCurrentDate()
{
	//for seg fault testing
	//std::cout << "incrementCurrentDate function started" << std::endl;

	double daysOverdue = 0;
	double incrementFineBy = 0; 

	//increment current date
	currentDate++;

	//for testing seg fault
	//std::cout << "current date incremented" << std::endl;

	//increase each patron's fines by 10 cents for each overdue book they have checked out
	for (int b = 0; b < members.size(); b++)
	{	
		std::string patronID = members.at(b)->getIdNum();
		std::string bookID = holdings.at(b)->getIdCode();

		Patron* libMember = getPatron(patronID);
		//std::cout << libMember << std::endl;
		Book* libHolding = getBook(bookID);
		//std::cout << libHolding << std::endl;

		//std::cout << currentDate << std::endl;

		if(currentDate - libHolding->getDateCheckedOut() > libHolding->getCheckOutLength())
			//daysOverdue = checkOutLength - dateCheckedOut;
			//incrementFineBy = daysOverdue * 0.10;
		{
			daysOverdue = libHolding->getCheckOutLength() - libHolding->getDateCheckedOut();

			//std::cout << daysOverdue <<std::endl;

			incrementFineBy = daysOverdue * 0.10;

			//std::cout << incrementFineBy << std::endl;

			libMember->amendFine(incrementFineBy);
		}
	}
}

/****************************************************************
* getPatron - returns a pointer to the Patron corresponding to the
* ID parameter, or NULL if no such Patron is a member
*****************************************************************/
//Gets patron from book vector
/*Patron* Library::getPatron(std::string pID)
{
	//retrieving specific member from vector, must use for loop
	for (int j = 0; j < members.size(); j++)	//loop to locate member
	{
		if (pID == members.at(j)->getIdNum())	//conditional to check member
			return members.at(j);	//return patron
		//else
			//return NULL;
	}
	return NULL;	//returns null if no such patron is a member
}*/

Patron* Library::getPatron(std::string pID)
{
	int patronCounter = 0;
	//retrieving specific member from vector, must use for loop
	for (int j = 0; j < members.size(); j++)	//loop to locate member
	{
		if (members.at(j)->getIdNum() == pID)	//conditional to check member
			return members.at(j);	//return patron
		else
			patronCounter++;
		//else
			//return NULL;
	}
	if (patronCounter == members.size())
		return NULL;	//returns null if no such patron is a member
}

/****************************************************************
* getBook - returns a pointer to the Book corresponding to the ID 
* parameter, or NULL if no such Book is in the holdings
*****************************************************************/
//Gets book from book vector
Book* Library::getBook(std::string bID)
{
	int bookCounter = 0;
	//retrieving specific holding from vector, must use for loop
	for (int i = 0; i < holdings.size(); i++)	//loop to locate holding
	{
		if (holdings.at(i)->getIdCode() == bID)	//conditional to check holding
			//bookCounter++;
			return holdings.at(i);	//return book
		else
			bookCounter++;
		//else 
			//return NULL;
		/*for (int i = 0; i < holdings.size(); i++)
		{
			if (bID != holdings.at(i)->getIdCode())
				return NULL;
		}*/
	}
	if (bookCounter == holdings.size())
		return NULL; 
		//return NULL;	//returns null if no book

}
