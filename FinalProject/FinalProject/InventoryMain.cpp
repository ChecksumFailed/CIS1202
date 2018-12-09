#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <map>
//Custom Class for inventory program
#include "Inventory.h"
#include "Media.h"
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

void addItem(vector<Inventory *> &);
void test(vector<Inventory *> &);
void loadDB(vector<Inventory *> &, string);
void saveInv(vector<Inventory *> &, string);
void printInv(const vector<Inventory *> &);
void printSummary(const vector<Inventory *> &);
template <class T> T sumMap(map<string,T>); //sums up values in map




int main() {
	vector<Inventory *> inventoryDB; //Inventory Vector to hold pointers to derived classes.
	int choice;
 	loadDB(inventoryDB, "inventory.dat");
	
	do {
		displayMainMenu();
		choice = Inventory::getInput<int>(1, 5);
		switch (choice)
		{
		case 1:
			printInv(inventoryDB);
			break;
		case 2:
			printSummary(inventoryDB);
			break;
		case 3:
			break;
		case 4:
			addItem(inventoryDB);
			break;
		
		}
	

	} while ( choice != 5);

	
	saveInv(inventoryDB, "inventory.dat");
	
	cout << "Press any key to exit";
	getchar();

	return EXIT_SUCCESS;
}

void displayMainMenu() {
	cout << "\nCIS 1202 Home Inventory Database\n\n";
	cout << "1 - Print Inventory\n";
	cout << "2 - Print Inventory Summary(Count/Cost/Depreciation)\n";
	cout << "3 - Search/Update/Delete Item\n";
	cout << "4 - Add inventory item\n";
	cout << "5 - Quit\n";
	cout << "Please enter choice: ";

}


void addItem(vector<Inventory *> &inv) {
	
	cout << "1 - Display\n"
		"2 - Movie\n"
		"3 - Music\n"
		"4 - Game\n"
		"5 - Misc\n"
		"6 - Exit\n";
	cout << "Select the type of item to add or 6 to exit: ";

	int choice = Inventory::getInput<int>(1, 6);
	if (choice == 6)
		return;
	

	//Create new object based on choice
	switch (choice) {
	case 1:
		inv.push_back(new Display);
		break;
	case 2:
		inv.push_back(new Movie);
		break;
	case 3:
		inv.push_back(new Music);
		break;
	case 4:
		inv.push_back(new Game);
		break;
	case 5:
		inv.push_back(new Inventory);
		break;
	}

	inv.back()->populateProperties();
	



}



void loadDB(vector<Inventory *> &inv,string fileName) {
	fstream file;
	string tmpRead;
	file.open(fileName, ios::binary | ios::in );
	//If file does not exist, add trunc flag to set file to zero
	if (!file.is_open()) {
		file.close();
		return;
	}
	file.seekg(0, ios::beg); //seek to beginning of file
	int counter = inv.size();
	
	tmpRead = Inventory::readString(file);
	while (!file.eof() && file.good()) {
		
		
		if (tmpRead == "Inventory")
			inv.push_back(new Inventory);
		else if (tmpRead == "Media")
			inv.push_back(new Media);
		else if (tmpRead == "Display")
			inv.push_back(new Display);
		else if (tmpRead == "Music")
			inv.push_back(new Music);
		else if (tmpRead == "Movie")
			inv.push_back(new Movie);
		else if (tmpRead == "Game")
			inv.push_back(new Game);
		
		if (inv[counter]) {
			inv[counter]->read(file);
			counter++;
		}
		if (file.eof() || !file.good()) {
			file.close();
			return;
		}
		tmpRead = "";
		tmpRead = Inventory::readString(file);
		
	
		
		//file.seekg(sizeof(tmpProduct) * counter, ios::beg);
	}

	file.close();

}



void saveInv(vector<Inventory *> &inv, string fileName) {
	fstream file;
	
	file.open(fileName, ios::binary | ios::out | ios::trunc);
	//If file does not exist, add trunc flag to set file to zero
	if (!file.is_open()) {
		file.close();
		return;
	}
	
	for (Inventory *a : inv) {
		a->write(file);
	}
			
	

	file.close();

}

void printInv(const vector<Inventory *> &inv) {

	for (Inventory *a : inv) {
		a->print();
	}
}

void printSummary(const vector<Inventory *> &inv) {
	int totalItem = 0;
	map<string, int> countMap;
	map<string, double> costMap;
	map<string, double> valueMap;

	for (Inventory *i : inv) {
		countMap[i->iType] ++;
		costMap[i->iType] += i->getPurchasePrice();
		valueMap[i->iType] += i->getDepreciatedPrice();
	}
	cout << endl;
	cout << setw(10) << "Type" << setw(10) << "Count" << setw(15) << "Total Cost" << setw(15) << "Total Value" << endl;

	map<string, int>::iterator it = countMap.begin();
	map<string, double>::iterator it2 = costMap.begin();
	map<string, double>::iterator it3 = valueMap.begin();
	while (it != countMap.end())
	{
		cout << setw(10) << it->first << setw(10) << it->second << setw(15) << it2->second << setw(15) << it3->second << endl;
		it++;
		it2++;
		it3++;
	}
	cout << setw(10) << "TOTAL: " << setw(10) << sumMap(countMap) << setw(15) << sumMap(costMap) << setw(15) << sumMap(valueMap) << endl;

}

template <class T> T sumMap(map<string, T> m) {
	T sumVar = 0;
	typename map<string, T>::iterator it = m.begin();
	while (it != m.end())
	{
		sumVar += it->second;
		it++;

	}
	return sumVar;
}


