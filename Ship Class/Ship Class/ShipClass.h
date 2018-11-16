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
	string name;
	int year;

public:
	ShipClass(); //default constructor
	ShipClass(string, int); //constructor with params
	~ShipClass(); //default deconstructor
	string getName(); //Return ship name
	int getYear(); // Return Year ship was build
	void setName(string); //Set name
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
	name = shipStr;
	year = yearInt;
}
//Default deconstrudtor
ShipClass::~ShipClass()
{
}

//Getter function
string ShipClass::getName() { return name; }
int ShipClass::getYear() { return year; }

//Setter Functions
void ShipClass::setName(string ship) { this->name = ship; }
void ShipClass::setYear(int year) { this->year = year; }

void ShipClass::print() {
	cout  << "\nShip Name: " << this->name << endl;
	cout << "Year Built: " << this->year << endl;
}

#endif // !SHIPCLASS_H