#include "BookClass.h"


//Constructors
BookClass::BookClass()
{
}


//Mutators
void BookClass::storeBook(string bookTitle, string authorName, string bookPublisher, string bookISBN, double bookPrice, int bookYear, int booksInStock) {

	title = bookTitle;
	author = authorName;
	publisher = bookPublisher;
	isbn = bookISBN;
	price = bookPrice;
	year = bookYear;
	numInStock = booksInStock;

}


/*
Purpose : Checks out copy of book.  Delimts one from stock
Input Parameters : n/a
I/O Parameters : 
	numInStock - Number of book in stock
Output Parameters : n/a
Function Return Value: n/a
*/
void BookClass::checkOutBook() {
	if (numInStock > 0) {
		numInStock--;
		cout << "\nChecked out " << title << ". " << numInStock << " now in stock" <<  endl;
	}
	else {
		cout << "\nError: No copies of " << title << " in stock.";
 	}

}
/*
Purpose : Checks out copy of book.  adds one to stock
Input Parameters : n/a
I/O Parameters :
	numInStock - Number of book in stock
Output Parameters : n/a
Function Return Value: n/a
*/
void BookClass::returnBook() {
	numInStock++;
	cout << "\nReturned copy of " << title << ". " << numInStock << " now in stock" <<  endl;
}

//accessors

/*
Purpose : Prints information about object
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: n/a
*/
void BookClass::displayBookInfo() {

	cout << endl <<setw(20) << "Title: " << title << endl;
	cout << setw(20) << "Author: " << author << endl;
	cout << setw(20) << "Publisher: " << publisher << endl;
	cout << setw(20) << "ISBN: " << isbn << endl;
	cout << setw(20) << "Price: " << price << endl;
	cout << setw(20) << "Year: " << year << endl;
	cout << setw(20) << "Books in Stock: " << numInStock << endl << endl;
	
}

/*
Purpose : returns the number of books in stock
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: 
	numInStock - number of books in stock
*/
int BookClass::getNumInStock() {
	return numInStock;
}
/*
Purpose : returns the title of book
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value:
	title - Title of book
*/
string BookClass::getTitle() {
	return title;
}



