#include <iostream>
#include <iomanip>
#include <string>
#include "ShipClass.h"
#include "CruiseShipClass.h"
#include "CargoShipClass.h"
#include "BenUtils.h"

using namespace std;

//functions
void getShip(ShipClass &);
void getCruiseShip(CruiseShip &);
void getCargoShip(CargoShip &);


int main() {
	
	//Create ship object
	cout << "\nSHIP:\n";
	ShipClass ship; //ShipClass Object
	getShip(ship);
	ship.print();

	cout << "\nCRUISE SHIP\n";
	CruiseShip CruiseShip;
	getCruiseShip(CruiseShip);
	CruiseShip.print();

	cout << "\nCARGO SHIP\n";
	CargoShip CargoShip;
	getCargoShip(CargoShip);
	CargoShip.print();

	cout << "Press any key to exit\n";
	getchar();
	return EXIT_SUCCESS;
}

void getShip(ShipClass &ship) {

	cout << "Please Enter Ship Name: ";
	ship.setName(BenUtils::getString());

	cout << "Please Enter Year Built: ";
	ship.setYear(BenUtils::getInt());

	
	

}


void getCruiseShip(CruiseShip &ship) {
	
	cout << "Please Enter Ship Name: ";
	ship.setName(BenUtils::getString());

	cout << "Please Enter Year Built: ";
	ship.setYear(BenUtils::getInt());
	

	cout << "Please enter the maximum passenger capacity: ";
	ship.setMaxPassenger(BenUtils::getInt());
	cout << endl;
	

}

void getCargoShip(CargoShip &ship) {
	
	cout << "Please Enter Ship Name: ";
	ship.setName(BenUtils::getString());

	cout << "Please Enter Year Built: ";
	ship.setYear(BenUtils::getInt());


	cout << "Please enter cargo capacity in tonnage: ";
	ship.setCapacity(BenUtils::getInt());
	cout << endl;

	
}