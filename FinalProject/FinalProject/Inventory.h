#ifndef INVENTORY_H
#define INVENTORY_H
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

#pragma once
class Inventory
{

private: 
	
	std::string name; //name or descriptor of item
	double purchasePrice = 0.0; //purchase price of item
	
	double depreciatedPrice = 0.00; 
	int yearPurchased = 1970; //year item purchased
	//Assum 20% rate and 5 years of value. Calculates straight line depreciation for simplicity
	int depreciationYears = 5; //number of years in life of item.
	double depreciationRate = 0.2;
	
	

public:
	string iType;//inventory type
	Inventory();
	Inventory(std::string, double, int);
	~Inventory();

	//Getters
	std::string getName();
	double getPurchasePrice();
	int getYearPurchased();
	int getDepreciationYears();
	double getDepreciatedPrice();
	string getIType();
	virtual void updateItem();

	//setters
	void setName(std::string);
	void setPurchasePrice(double);
	void setYearPurchased(int);
	void setDepreciationYears(int);
	

	//math
	void calculateDepreciation();
	int getCurrentYear();
	virtual void print();

	////Seriallize/Deserialize
	virtual void write(ostream &);
	virtual void read(istream &);
	static string readString(istream &);
	void writeString(ostream &, string &);

	//Input/output
	 template <class T> static T getInput(); //gets and validates input
	 template <class T> static T getInput(T, T);//gets and validates input,checks against range
	virtual void populateProperties(); //prompts user and validates input.
	static string getString(); //Gets and validates string input
	
	

};

//Templated methods. These have to be in header file.

/*
Purpose : Gets  input and validates
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value:
	T tmpHolder - placeholder to validate input against
*/
template <typename T>
T Inventory::getInput() {
	cin.clear();
	T tmpHolder; //stores user choice

	bool isValid = false;

	do {
		cin >> tmpHolder;
		if (cin.fail()) {
			cout << "\nYou have entered invalid input.  Try Again\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
			isValid = true;
	} while (!isValid);
	cin.clear();
	cin.ignore();
	return tmpHolder;
}

/*
Purpose : Gets  input and validates against range
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value:
	T tmpHolder - placeholder to validate input against
*/
template <class T>
T Inventory::getInput(T low, T high) {
	cin.clear();
	T tmpHolder; //temporary variable for getlne
	bool isValid = false;

	do {
		cin >> tmpHolder;
		if (cin.fail() || tmpHolder < low || tmpHolder > high) {
			cout << "\nYou have entered invalid input.  Try Again:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}
		else
			isValid = true;
	} while (!isValid);
	cin.clear();
	cin.ignore();
	return tmpHolder;

}
#endif