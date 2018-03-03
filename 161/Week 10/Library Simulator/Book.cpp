#include "Book.hpp"
#include "Patron.hpp"
#include <string>

/****************************************************************
* constructor - takes an idCode, title and author; checkedOutBy 
* and requestedBy should be initialized to NULL; a new Book should 
* be on the shelf
*****************************************************************/
//overloaded constructor
Book::Book(std::string idc, std::string t, std::string a) : idCode(idc), title(t), author(a)
{
	//idCode = idc;			//idcode set right in constructor
	//title = t;				//title set right in constructor
	//author = a;				//author set right in constructor
	//checkedOutBy = NULL;	//book starts on shelf/not checked out
	//requestedBy = NULL;		//book starts with no requests
	//dateCheckedOut = 0;		//not checked out yet
	//location = ON_SHELF;	//book starts on shelf

	setCheckedOutBy(NULL);	//book starts on shelf/not checked out
	setRequestedBy(NULL);	//book starts with no requests
	setDateCheckedOut(0);	//not checked out yet
	setLocation(ON_SHELF);	//book starts on shelf
}


/****************************************************************
* idCode - a unique identifier for a Book (think library bar code, 
* not ISBN) - you can assume uniqueness, you don't have to enforce it
*****************************************************************/
//gets idcode from private
std::string Book::getIdCode()
{
	return idCode;	//returns idCode from private
}

/****************************************************************
* title - cannot be assumed to be unique
*****************************************************************/
//get title from private
std::string Book::getTitle()
{
	return title;	//returns title from private
}

/****************************************************************
* the idCode, title and author don't need set methods, since they 
* will never change after the object has been created, therefore 
* these fields can be initialized directly within the constructor
*****************************************************************/
//get author from private
std::string Book::getAuthor()
{
	return author;	//returns author from private
}

/****************************************************************
* CHECK_OUT_LENGTH - constant that gives how long a Book can be 
* checked out for
*****************************************************************/
//retrieves checked out length
int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;	//returns check_out_length constant from private
}

/****************************************************************
* location - a Book can be either on the shelf, on the hold shelf, 
* or checked out
*****************************************************************/
//retrieves location of book 
Locale Book::getLocation()
{
	return location;	//returns location from private
}

/****************************************************************
* location - a Book can be either on the shelf, on the hold shelf, 
* or checked out
*****************************************************************/
//sets location of book when checked out, on hold, or on shelf
void Book::setLocation(Locale bookLocation)
{
	location = bookLocation;	//sets bookLocation in private
}

/****************************************************************
* checkedOutBy - pointer to the Patron who has it checked out (if any)
*****************************************************************/
//gets what patron checked the book out
Patron* Book::getCheckedOutBy()
{
	return checkedOutBy;	//gets who checked out the book from private
}

/****************************************************************
* checkedOutBy - pointer to the Patron who has it checked out (if any)
*****************************************************************/
//set who checked the book out
void Book::setCheckedOutBy(Patron* libPatron)
{
	checkedOutBy = libPatron;	//sets a patron to who checked the book out
}

/****************************************************************
* requestedBy - pointer to the Patron who has requested it (if any); 
* a Book can only be requested by one Patron at a time
*****************************************************************/
//get patron who requested a book
Patron* Book::getRequestedBy()
{
	return requestedBy;	//gets a patron that requested the book
}

/****************************************************************
* requestedBy - pointer to the Patron who has requested it (if any); 
* a Book can only be requested by one Patron at a time
*****************************************************************/
//sets a patron who requested a book
void Book::setRequestedBy(Patron* libPatron)
{
	requestedBy = libPatron;	//sets a patron to the requester of the book
}

/****************************************************************
* dateCheckedOut - when a book is checked out, this will be set to 
* the currentDate of the Library
*****************************************************************/
//gets what date the book was checked out
int Book::getDateCheckedOut()
{
	return dateCheckedOut;	//returns dateCheckedOut
}

/****************************************************************
* dateCheckedOut - when a book is checked out, this will be set to 
* the currentDate of the Library
*****************************************************************/
//set the date someone checked out a book
void Book::setDateCheckedOut(int checkOutDate)
{
	dateCheckedOut = checkOutDate;	//sets current library date "current date" to dateCheckedOut
}