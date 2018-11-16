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

/*
Programmer Name: Ben Scherer
Program # : 12
Course: CIS 1202 Section 502
Date : 11/15/2018
Program Description : Ship Class. Utilizes custom classes, inheritance and virtual functions.
*/
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


/*
Purpose : Validates Input and updates ship object
Input Parameters : n/a
I/O Parameters : 
	ShipClass &ship - ShipClass object
Output Parameters : n/a
Function Return Value: n/a
*/
void getShip(ShipClass &ship) {

	cout << "Please Enter Ship Name: ";
	ship.setName(BenUtils::getString());

	cout << "Please Enter Year Built: ";
	ship.setYear(BenUtils::getInt());

	
	

}

/*
Purpose : Validates Input and updates ship object
Input Parameters : n/a
I/O Parameters :
	CruiseShip &ship - ShipClass object
Output Parameters : n/a
Function Return Value: n/a
*/
void getCruiseShip(CruiseShip &ship) {
	
	cout << "Please Enter Ship Name: ";
	ship.setName(BenUtils::getString());

	cout << "Please Enter Year Built: ";
	ship.setYear(BenUtils::getInt());
	

	cout << "Please enter the maximum passenger capacity: ";
	ship.setMaxPassenger(BenUtils::getInt());
	cout << endl;
	


}
/*
Purpose : Validates Input and updates ship object
Input Parameters : n/a
I/O Parameters :
	CargoShip &ship - ShipClass object
Output Parameters : n/a
Function Return Value: n/a
*/
void getCargoShip(CargoShip &ship) {
	
	cout << "Please Enter Ship Name: ";
	ship.setName(BenUtils::getString());

	cout << "Please Enter Year Built: ";
	ship.setYear(BenUtils::getInt());


	cout << "Please enter cargo capacity in tonnage: ";
	ship.setCapacity(BenUtils::getInt());
	cout << endl;

	
}