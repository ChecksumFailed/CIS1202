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
	string title = "";
	string author = "";
	string publisher = "";
	string isbn = "";
	double price = 0;
	int year = 0;
	int numInStock = 0;

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
