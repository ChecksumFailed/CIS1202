#ifndef SHIPCLASS.H
#define SHIPCLASS.H


#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

#pragma once
class ShipClass
{

private:
	string ship;
	int year;

public:
	ShipClass(); //default constructor
	ShipClass(string, int); //constructor with params
	~ShipClass(); //default deconstructor
	string getShip(); //Return ship name
	int getYear(); // Return Year ship was build
	void setShip(string); //Set name
	void setYear(int); //set year
	virtual void print(); 
};


//Default Constructor
ShipClass::ShipClass()
{

}
//Constructer with param
ShipClass::ShipClass(string shipStr,int yearInt)
{
	ship = shipStr;
	year = yearInt;
}
//Default deconstrudtor
ShipClass::~ShipClass()
{
}

//Getter function
string ShipClass::getShip() { return ship; }
int ShipClass::getYear() { return year; }

//Setter Functions
void ShipClass::setShip(string ship) { this->ship = ship; }
void ShipClass::setYear(int year) { this->year = year; }

void ShipClass::print() {
	cout << setw(15) << "Ship Name: " << this->ship << endl;
	cout << setw(15) << "Year Built: " << this->year << endl;
}

#endif // !SHIPCLASS.H