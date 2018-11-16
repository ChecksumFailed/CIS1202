#ifndef CRUISESHIPCLASS_H
#define CRUISESHIPCLASS_H



#pragma once
#include "ShipClass.h"
class CruiseShip :	public ShipClass
{
	private:
		int maxPassenger; //maximum number of passengers on ship
	public:
		CruiseShip(); //construtor
		CruiseShip(int); //overloaded constructor
		~CruiseShip(); //desconstructor
		int getMaxPassenger(); //returns max passengers
		void setMaxPassenger(int); //sets max passengers
		virtual void print(); //prints ship information


};


//Default Constructor
CruiseShip::CruiseShip()
{
}
//Constructor with args
CruiseShip::CruiseShip(int maxPassenger) { this->maxPassenger = maxPassenger; }
//Default deconstructgor
CruiseShip::~CruiseShip()
{
}


/*
Purpose : gets ship max passenger
Input Parameters : n/a
I/O Parameters :
Output Parameters : n/a
Function Return Value:
	int  maxPassenger - Maximum number of passengers on ship
*/
int CruiseShip::getMaxPassenger() { return this->maxPassenger; }

/*
Purpose : sets ship max passenger
Input Parameters : n/a
I/O Parameters :
	int  maxPassenger - Maximum number of passengers on ship
Output Parameters : n/a
Function Return Value:

*/
void CruiseShip::setMaxPassenger(int maxPassenger) { this->maxPassenger = maxPassenger; }


/*
Purpose : Prints Ship Information
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: n/a

*/
void CruiseShip::print() {
	ShipClass::print();
	cout << "Max Passenger: " << this->maxPassenger << endl;
}

#endif // !CRUISESHIPCLASS.H
