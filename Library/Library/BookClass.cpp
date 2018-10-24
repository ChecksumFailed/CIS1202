#include "BookClass.h"


//Constructors
BookClass::BookClass()
{
}

/*
	string title;
	string author;
	string publisher;
	string isbn;
	double price;
	int year;
	int numInStock;*/

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

void BookClass::checkOutBook() {
	if (numInStock > 0) {
		numInStock--;
		cout << "Checked out one copy of " << title << endl;
	}
	else {
		cout << "Error: No copies of " << title << " in stock.";
 	}

}

void BookClass::returnBook() {
	numInStock++;
}

//accessors

void BookClass::displayBookInfo() {
	cout << endl <<setw(20) << "Title: " << title << endl;
	cout << setw(20) << "Author: " << author << endl;
	cout << setw(20) << "Publisher: " << publisher << endl;
	cout << setw(20) << "ISBN: " << isbn << endl;
	cout << setw(20) << "Price: " << price << endl;
	cout << setw(20) << "Year: " << year << endl;
	cout << setw(20) << "Books in Stock: " << numInStock << endl << endl;
	
}


int BookClass::getNumInStock() {
	return numInStock;
}

string BookClass::getTitle() {
	return title;
}



