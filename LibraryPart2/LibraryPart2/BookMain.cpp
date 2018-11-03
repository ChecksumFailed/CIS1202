#include <iostream>
#include <iomanip>
#include "BookClass.h"
#include "BenUtils.h"
#include <fstream>

using namespace std;


//functions
void getBookInfo(BookClass &); //Gets user input & validates.  Updates BookClass Object
void getBooks(BookClass[], int &); //reads in books from books.txt
void showBooks(BookClass[], int); //Loops through books array and prints data
void showTitles(BookClass[], int); //Loops through books array and prints title
int findBook(string, BookClass[], int); //Searches array for book matching title
int getMenuChoice(); //Displays menu and gets user choice


/*
Programmer Name: Ben Scherer
Program # : 11
Course: CIS 1202 Section 502
Date : 11/3/2018
Program Description : Library part 2. Leverages a custom class to store information about books.
*/
int main() {
	const int MAX_BOOKS = 100;
	BookClass books[MAX_BOOKS];
	int librarySize = 0;
	int searchIndex; //used to store value returned by findBook function
	string searchString;
	//Load books.txt
	getBooks(books, librarySize);

	int choice;
	do {
		choice = getMenuChoice();
		switch (choice) {
		case 1:
			showBooks(books, librarySize);
			break;
		case 2:
			showTitles(books, librarySize);
			break;
		case 3:
			cout << "Enter Book Title:";
			getline(cin, searchString);
			searchIndex = findBook(searchString,books,librarySize);
			cout << endl;
			if (searchIndex)
				cout << books[searchIndex].getNumInStock() << " copies of " << books[searchIndex].getTitle() << " in stock\n";
			else
				cout << "No copies of " << searchString << " in stock\n";
			break;
		case 4:
			cout << "Enter title of book to checkout:";
			getline(cin, searchString);
			searchIndex = findBook(searchString, books, librarySize);
			cout << endl;
			if (searchIndex)
				books[searchIndex].checkOutBook();
			else
				cout << "No copies of " << searchString << " in stock\n";
			break;
		case 5:
			cout << "Enter title of book to checkin:";
			getline(cin, searchString);
			searchIndex = findBook(searchString, books, librarySize);
			cout << endl;
			if (searchIndex)
				books[searchIndex].returnBook();
			else
				cout << "No copies of " << searchString << " in stock\n";
			break;
		}
	} while (choice != 6);


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
	string title, author, publisher, isbn;
	double price;
	int year, numInStock;
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
	price = BenUtils::getDouble();
	cout << "Enter year published: ";
	year = BenUtils::getInt();
	cout << "Enter the number of books in stock: ";
	numInStock = BenUtils::getInt();
	cout << endl;

	book.storeBook(title, author, publisher, isbn, price, year, numInStock);

}

/*
Purpose : Loops through books array and print information for each object
Input Parameters :
	BookClass books[] - array of book objects
	int size - number of books in array
I/O Parameters :
Output Parameters :
Function Return Value: n/a
*/
int findBook(string title,BookClass books[], int size) {
	for (int i = 0; i < size; i++) {
		if (title == books[i].getTitle())
			return i;
	}
	return NULL;

}

/*
Purpose : Loops through books array and print information for each object
Input Parameters : 
	BookClass books[] - array of book objects
	int size - number of books in array
I/O Parameters :
Output Parameters :
Function Return Value: n/a
*/
void showBooks(BookClass books[], int size) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		books[i].displayBookInfo();
	}

}

/*
Purpose : Loops through books array and prints title field
Input Parameters :
	BookClass books[] - array of book objects
	int size - number of books in array
I/O Parameters :
Output Parameters :
Function Return Value: n/a
*/
void showTitles(BookClass books[], int size) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << "\t" <<  books[i].getTitle() << endl;
	}

}

/*
Purpose : Display menu and get user choice
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: int
*/
int getMenuChoice() {
	cout << "\nBen's Library\n\n";
	cout << "Please select from a choice below\n";
	cout << "\n1 - Display all books\n"
		<< "2 - Display Book Titles\n"
		<< "3 - Find Book\n"
		<< "4 - Check Out\n"\
		<< "5 - Check In\n"
		<< "6 - Quit\n"
		<< "Enter Choice: ";

	return BenUtils::getInt(1, 6);
}

/*
Purpose : Reads in text file and populates books array
Input Parameters : Description of value parameters; sent into the function, but not changed by the function
I/O Parameters : 
	BookClass books[] - array of book objects
	int &size - number of books in array
Output Parameters :
	string bookTitle, authorName, bookPublisher, bookISBN - String properties of book object
	double bookPrice - price of book
	int bookYear, booksInStock - int properties of book object
Function Return Value: n/a
*/
void getBooks(BookClass books[], int &size) {
	//Variables to read in data from file.
	string bookTitle, authorName, bookPublisher, bookISBN;
	double bookPrice;
	int bookYear, booksInStock;

	ifstream f("books.txt");// open file stream
	if (f.fail())
		return;//if file doesnt exist, retu6rn to main

	while (!f.eof()) {
		//Use getline to account for spaces in string
		getline(f, bookTitle);
		getline(f, authorName);
		getline(f, bookPublisher);
		//read in double/int values
		f >> bookISBN >> bookPrice >> bookYear >> booksInStock; 
		f.ignore(1, '\n'); //tell stream to ignore one newline so getline works on next read

		//Store book 
		books[size].storeBook(bookTitle, authorName, bookPublisher, bookISBN, bookPrice, bookYear, booksInStock);
		//increment size of array
		size++; 
	}
}

/*
Purpose : One sentence describing WHAT it does
Input Parameters : Description of value parameters; sent into the function, but not changed by the function
I/O Parameters : Description of reference parameters that have one value upon entering the routine and different value upon leaving the routine
Output Parameters : Description of reference parameters that receive their initial value inside the function
Function Return Value: (for non-void functions) Description of any value returned by the function
*/