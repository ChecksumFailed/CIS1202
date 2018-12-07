#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
//Custom Class for inventory program
#include "Inventory.h"

#include "Display.h"
#include "Game.h"
#include "Movie.h"
#include "Music.h"



using namespace std;

/*
reading/writing to binary file.
create read/write methods in each class.
https://stackoverflow.com/questions/37038909/c-read-write-class-from-to-binary-file
read itype, then create appropriate object and call read

write:  just call the write function of the object. Which will call any parent functions needed.

*/

void displayMainMenu(); //Main Menu of program
template <class T> T getInput(); //gets and validates input
template <class T> T getInput(T,T);//gets and validates input,checks against range
void addItem(vector<Inventory *> &inv);

int main() {
	vector<Inventory *> inventoryDB; //Inventory Vector to hold pointers to derived classes.
	/*do {
		displayMainMenu();
		
	} while (getInput(1, 5) != 5);

	*/

	Music poo;
	poo.setArtist("Bono");
	poo.setGenre("Country");
	poo.setMediaType("Digital");
	poo.setName("Best of U2");
	poo.setPurchasePrice(9.99);
	poo.setRating(8.5);
	poo.setYearPurchased(1999);
	poo.setYear(1997);
	poo.calculateDepreciation();
	poo.print();


	cout << "Press any key to exit";
	getchar();
	return EXIT_SUCCESS;
}



void displayMainMenu() {
	cout << "CIS 1202 Home Inventory Database\n\n";
	cout << "1 - Print Inventory\n";
	cout << "2 - Print Inventory Summary(Count/Cost/Depreciation)\n";
	cout << "3 - Search/Update/Delete Item\n";
	cout << "4 - Add inventory item\n";
	cout << "5 - Quit\n";
	cout << "Please enter choice: ";
	



}

/*
Purpose : Gets  input and validates
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value:
	T tmpHolder - placeholder to validate input against
*/
template <typename T>
T getInput() {
	cin.clear();
	T tmpHolder; //stores user choice
	
	bool isValid = false;

	do {
		cin >> tmpHolder;
		if (cin.fail()) {
			cout << "\nYou have entered invalid input.  Try Again\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			isValid = true;
	} while (!isValid);
	cin.clear();
	cin.ignore();
	return tmpHolder;
}

/*
Purpose : Gets  input and validates against range
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value:
	T tmpHolder - placeholder to validate input against
*/
template <class T>
T getInput(T low, T high) {
	cin.clear();
	T tmpHolder; //temporary variable for getlne
	bool isValid = false;

	do {
		cin >> tmpHolder;
		if (cin.fail() || tmpHolder < low || tmpHolder > high) {
			cout << "\nYou have entered invalid input.  Try Again:";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
		else
			isValid = true;
	} while (!isValid);
	cin.clear();
	cin.ignore();
	return tmpHolder;

}


void addItem(vector<Inventory *> &inv) {

	//const string INVENTORY_TYPES[] = { "Display","Game","Movie","Music","Misc" };
	cout << "1 - Display\n"
		<< "2 - Game\n"
		<< "3 - Movie\n"
		<< "4 - Music\n"
		<< "5 - Misc Item\n"
		<< "6 - Exit\n"
		<< "Choose and item: ";
	int choice = getInput(1, 6);
}

void loadDB(vector<Inventory *> &inv,string fileName) {
	fstream file;
	string tmpRead;
	file.open(fileName, ios::binary | ios::in | ios::out);
	//If file does not exist, add trunc flag to set file to zero
	if (!file.is_open()) {
		file.close();
		return;
	}
	file.seekg(0, ios::beg); //seek to beginning of file

	while (!file.eof()) {

		file.read(reinterpret_cast<char *>(&tmpRead), sizeof(tmpRead));
		
		
		//file.seekg(sizeof(tmpProduct) * counter, ios::beg);
	}


}

void saveInv(vector<Inventory *> &inv, string fileName) {
	fstream file;
	
	file.open(fileName, ios::binary | ios::out | ios::trunc);
	//If file does not exist, add trunc flag to set file to zero
	if (!file.is_open()) {
		file.close();
		return;
	}
	

	for (int i = 0;i < inv.size(); i++) {
		Inventory a;
		
		file.write(reinterpret_cast<char *>(&a.iType), sizeof(a.iType));
		file.write(reinterpret_cast<char *>(&a.), sizeof(a.iType));


		//file.seekg(sizeof(tmpProduct) * counter, ios::beg);
	}
	file.close();

}

