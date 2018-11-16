#ifndef CARGOSHIPCLASS.h
#define CARGOSHIPCLASS.h




#pragma once
#include "ShipClass.h"
class CargoShipClass :public ShipClass
{
	private:
		int capacity;
	public:
		CargoShipClass();
		CargoShipClass(int);
		~CargoShipClass();
		int getCapacity();
		void setCapacity(int);
		virtual void print();
};


//Constructors
CargoShipClass::CargoShipClass()
{
}

CargoShipClass::CargoShipClass(int capacity) { this->capacity = capacity; }

//Deconstructor
CargoShipClass::~CargoShipClass(){}

int CargoShipClass::getCapacity() { return this->capacity; }
void CargoShipClass::setCapacity(int capacity) { this->capacity = capacity; }

void CargoShipClass::print() {
	ShipClass::print();
	cout << "Capacity: " << this->capacity << endl;
}
#endif // !CARGOSHIPCLASS.h