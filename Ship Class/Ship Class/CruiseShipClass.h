#ifndef CRUISESHIPCLASS_H
#define CRUISESHIPCLASS_H



#pragma once
#include "ShipClass.h"
class CruiseShip :	public ShipClass
{
	private:
		int maxPassenger;
	public:
		CruiseShip();
		CruiseShip(int);
		~CruiseShip();
		int getMaxPassenger();
		void setMaxPassenger(int);
		virtual void print();


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

int CruiseShip::getMaxPassenger() { return this->maxPassenger; }
void CruiseShip::setMaxPassenger(int maxPassenger) { this->maxPassenger = maxPassenger; }

void CruiseShip::print() {
	ShipClass::print();
	cout << "Max Passenger: " << this->maxPassenger << endl;
}

#endif // !CRUISESHIPCLASS.H
