#ifndef CARGOSHIPCLASS_H
#define CARGOSHIPCLASS_H




#pragma once
#include "ShipClass.h"
class CargoShip :public ShipClass
{
	private:
		int capacity;
	public:
		CargoShip();
		CargoShip(int);
		~CargoShip();
		int getCapacity();
		void setCapacity(int);
		virtual void print();
};


//Constructors
CargoShip::CargoShip()
{
}

CargoShip::CargoShip(int capacity) { this->capacity = capacity; }

//Deconstructor
CargoShip::~CargoShip(){}

int CargoShip::getCapacity() { return this->capacity; }
void CargoShip::setCapacity(int capacity) { this->capacity = capacity; }

void CargoShip::print() {
	ShipClass::print();
	cout << "Capacity: " << this->capacity << endl;
}
#endif // !CARGOSHIPCLASS.h