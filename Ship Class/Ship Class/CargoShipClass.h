#ifndef CARGOSHIPCLASS_H
#define CARGOSHIPCLASS_H




#pragma once
#include "ShipClass.h"
class CargoShip :public ShipClass
{
	private:
		int capacity; //capacity in tons
	public:
		CargoShip(); //constructor
		CargoShip(int); //overloaded constructor
		~CargoShip(); //deconstrutor
		int getCapacity(); //gets capacity in tons
		void setCapacity(int); //sets capacity
		virtual void print(); //prints ship information
};


//Constructors
CargoShip::CargoShip()
{
}

CargoShip::CargoShip(int capacity) { this->capacity = capacity; }

//Deconstructor
CargoShip::~CargoShip(){}


/*
Purpose : returns ship capacity
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: 
	int  capacity - capacity of ship
*/
int CargoShip::getCapacity() { return this->capacity; }

/*
Purpose : sets ship capacity
Input Parameters : n/a
I/O Parameters : 
	int  capacity - capacity of ship
Output Parameters : n/a
Function Return Value:
	
*/
void CargoShip::setCapacity(int capacity) { this->capacity = capacity; }

/*
Purpose : Prints Ship Information
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: n/a

*/
void CargoShip::print() {
	ShipClass::print();
	cout << "Capacity: " << this->capacity << endl;
}
#endif // !CARGOSHIPCLASS.h