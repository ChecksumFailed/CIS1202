#ifndef BOOKCLASS_H
#define BOOKCLASS_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#pragma once
class BookClass
{
private:
	string title;
	string author;
	string publisher;
	string isbn;
	double price;
	int year;
	int numInStock;

public:
	//Constructors
	BookClass();
		
	//mutators
	void storeBook(string, string, string,string, double, int, int);
	void displayBookInfo();
	void checkOutBook();
	void returnBook();

	//accessors
	string getTitle();
	int getNumInStock();

};


#endif // !BOOKCLASS_H
