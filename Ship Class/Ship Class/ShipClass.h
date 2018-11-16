#ifndef SHIPCLASS_H
#define SHIPCLASS_H


#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

#pragma once
class ShipClass
{

private:
	string name; //name of ship
	int year; //year ship built

public:
	ShipClass(); //default constructor
	ShipClass(string, int); //constructor with params
	~ShipClass(); //default deconstructor
	string getName(); //Return ship name
	int getYear(); // Return Year ship was build
	void setName(string); //Set name
	void setYear(int); //set year
	virtual void print();  //prints ship informatin
};


//Default Constructor
ShipClass::ShipClass()
{

}
//Constructer with param
ShipClass::ShipClass(string shipStr,int yearInt)
{
	name = shipStr;
	year = yearInt;
}
//Default deconstrudtor
ShipClass::~ShipClass()
{
}


/*
Purpose : gets ship Name
Input Parameters : n/a
I/O Parameters :
Output Parameters : n/a
Function Return Value:
	string  name - name of ship
*/
string ShipClass::getName() { return name; }


/*
Purpose : gets ship year
Input Parameters : n/a
I/O Parameters :
Output Parameters : n/a
Function Return Value:
	int  year - Year ship built
*/
int ShipClass::getYear() { return year; }


/*
Purpose : sets ship Name
Input Parameters : n/a
I/O Parameters :
	string  name - name of ship
Output Parameters : n/a
Function Return Value:
*/
void ShipClass::setName(string ship) { this->name = ship; }

/*
Purpose : sets ship year
Input Parameters : n/a
I/O Parameters :
	int  year - Year ship built
Output Parameters : n/a
Function Return Value:

*/
void ShipClass::setYear(int year) { this->year = year; }


/*
Purpose : Prints Ship Information
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: n/a

*/
void ShipClass::print() {
	cout  << "\nShip Name: " << this->name << endl;
	cout << "Year Built: " << this->year << endl;
}

#endif // !SHIPCLASS_H