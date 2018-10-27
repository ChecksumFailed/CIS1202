#include <iostream>
#include <iomanip>
#include "BookClass.h"
#include "BenUtils.h"

using namespace std;

BenUtils utils; //Utils class.  Contains my commonly used functions
//functions
void getBookInfo(BookClass &); //Gets user input & validates.  Updates BookClass Object


/*
Programmer Name: Ben Scherer
Program # : 10
Course: CIS 1202 Section 502
Date : 10/24/2018
Program Description : Book Class program. Leverages a custom class to store information about books.
*/
int main() {
	BookClass bookObj; //New book object

	
	getBookInfo(bookObj); //Populate book obj

	//Print contents of new book
	bookObj.displayBookInfo(); 

	//Test checkout process
	bookObj.checkOutBook();
	 cout << bookObj.getTitle() << " - " << bookObj.getNumInStock() << " remaining in stock\n";

	 //test checkin process
	bookObj.returnBook();
	cout << bookObj.getTitle() << " - " << bookObj.getNumInStock() << " remaining in stock\n";

	cout << "Press any key to exit\n";
	getchar();
	return EXIT_SUCCESS;
}

/*
Purpose : Gets user input and populates properties of book obj
Input Parameters : n/a
I/O Parameters : 
	BookClas book - reference to book object
Output Parameters : 
	string title,author,publisher,isbn - Placeholders for string values
	double price - placeholder for double value
	int year,numInStock - placeholders for int values
Function Return Value: n/a
*/
void getBookInfo(BookClass &book) {
	string title,author,publisher,isbn;
	double price;
	int year,numInStock;
	cout << "\nEnter book information. \n";
	cout << "Enter Book Title: ";
	getline(cin, title);
	cout << "Enter Author Name: ";
	getline(cin, author);
	cout << "Enter book publisher: ";
	getline(cin, publisher);
	cout << "Enter book ISBN: ";
	getline(cin, isbn);
	cout << "Enter book price: ";
	price = utils.getDouble();
	cout << "Enter year published: ";
	year = utils.getInt();
	cout << "Enter the number of books in stock: ";
	numInStock = utils.getInt();
	cout << endl;

	book.storeBook(title, author, publisher, isbn, price, year, numInStock);

}