#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <map>
#include <regex>
#include <algorithm>
//Custom Classes for inventory program
#include "Inventory.h"
#include "Media.h"
#include "Display.h"
#include "Game.h"
#include "Movie.h"
#include "Music.h"



using namespace std;


void displayMainMenu(); //Main Menu of program
void addItem(vector<Inventory *> &);
void test(vector<Inventory *> &);
void loadDB(vector<Inventory *> &, string);
void saveInv(vector<Inventory *> &, string);
void printInv(const vector<Inventory *> &);
void printSummary(const vector<Inventory *> &);
template <class T> T sumMap(map<string,T>); //sums up values in map
void search(vector<Inventory *> &,string); //searches vector by name
template <class T> int itemMenu(T &); //display menu for search result
void sortInv(vector<Inventory *> &);





/*
Programmer Name: Ben Scherer
Program # : FINAL PROJECT
Course: CIS 1202 Section 502
Date : 12/09/2018
Program Description :Final Project	- Home inventory system.  
					uses Class inheritance, virtual functions, template functions and custom serialization/deserialztion for persitent data storage
*/
int main() {
	vector<Inventory *> inventoryDB; //Inventory Vector to hold pointers to derived classes.
	int choice;
	try {
		loadDB(inventoryDB, "inventory.dat"); //load binary file into vector
	}
	catch (exception e) {
		cout << "ERROR reading data from file.  Please fix error or delete file\n";
		cout << "Press any key to exit";
		getchar();
		exit(EXIT_FAILURE);
	}
	
	do {
		displayMainMenu();
		choice = Inventory::getInput<int>(1, 6);
		switch (choice)
		{
		case 1: //print vector
			printInv(inventoryDB);
			break;
		case 2://print summary of items
			printSummary(inventoryDB);
			break;
		case 3: //search for item
			cout << "Enter name to search for: ";
			search(inventoryDB, Inventory::getString());
			break;
		case 4: //add item
			addItem(inventoryDB);
			break;
		case 5: //sort vector
			sortInv(inventoryDB);
			break;
		
		}
	

	} while ( choice != 6);

	
	saveInv(inventoryDB, "inventory.dat"); //save vector to file
	
	//Wait for user to exit
	cout << "Press any key to exit";
	getchar();

	return EXIT_SUCCESS;
}



/*
Purpose :Displays main menu of program
Input Parameters :n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: n/a
*/
void displayMainMenu() {
	cout << "\nCIS 1202 Home Inventory Database\n\n";
	cout << "1 - Print Inventory\n";
	cout << "2 - Print Inventory Summary(Count/Cost/Depreciation)\n";
	cout << "3 - Search/Update/Delete Item\n";
	cout << "4 - Add inventory item\n";
	cout << "5 - Sort inventory\n";
	cout << "6 - Quit\n";
	cout << "Please enter choice: ";

}

/*
Purpose : Sorts Inventory based on multiple criteria
Input Parameters :
	inv - vector of inventory pointers
I/O Parameters : 
	inv - vector of inventory pointers
Output Parameters : 
Function Return Value: 
*/
void sortInv(vector<Inventory *> &inv) {
	cout << "\nSort Menu\n";
	cout << "1 - Sort by Name(ASC)\n";
	cout << "2 - Sort by Name(Desc)\n";
	cout << "3 - Sort by Purchase Year(ASC)\n";
	cout << "4 - Sort by Purchase Year(DESC)\n";
	cout << "5 - Sort by Purchase Price(ASC)\n";
	cout << "6 - Sort by Purchase Price(DESC)\n";
	cout << "7 - Exit\n";
	cout << "Please enter choice: ";
	int choice = Inventory::getInput<int>(1, 7);

	switch (choice) {
	case 1://use overloaded operator
		sort(inv.begin(), inv.end(), [](Inventory *a, Inventory *b) {
			if (a < b)
				return true;
			else
				return false;
		});
		break;
	case 2://use overloaded operator
		sort(inv.begin(), inv.end(), [](Inventory *a, Inventory *b) {
			if (a > b)
				return true;
			else
				return false;
		});
		break;
	case 3:
		sort(inv.begin(), inv.end(), [](Inventory *a, Inventory *b) {
			return a->getYearPurchased() < b->getYearPurchased();
		});
		break;
	case 4:
		sort(inv.begin(), inv.end(), [](Inventory *a, Inventory *b) {
			return a->getYearPurchased() > b->getYearPurchased();
		});
	case 5:
		sort(inv.begin(), inv.end(), [](Inventory *a, Inventory *b) {
			return a->getPurchasePrice() < b->getPurchasePrice();
		});
		break;
	case 6:
		sort(inv.begin(), inv.end(), [](Inventory *a, Inventory *b) {
			return a->getPurchasePrice() > b->getPurchasePrice();
		});
		break;
	}

}

/*
Purpose : Adds new item to inventory
Input Parameters : 
	inv - vector of Inventory pointers
I/O Parameters : 
	inv - vector of inventory pointers
Output Parameters : 
Function Return Value: (for non-void functions) Description of any value returned by the function
*/
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

/*
Purpose : Reads in binary file and deserializes into a vector of pointers
Input Parameters : 
	inv - vector of inventory pointers
	fileName - name of file to open
I/O Parameters :
	inv - vector of inventory pointers
Output Parameters : 
	fstream file - binary file to read in
	string tmpRead - placeholder to read in class type
Function Return Value: 
*/

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
	
	tmpRead = Inventory::readString(file); //Make sure file is not empty
	while (!file.eof() && file.good()) {
		
		// add new object to vector, based on type
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
		
		if (inv[counter]) { //If item was added, populate with data
			inv[counter]->read(file); //calls class deserialization function
			counter++;
		}
		if (file.eof() || !file.good()) { //if we hit end of file, exit function
			file.close();
			return;
		}
		tmpRead = "";
		tmpRead = Inventory::readString(file);
		
	}

	file.close(); //close our file

}


/*
Purpose : Write vector to binary file
Input Parameters : 
	inv - vector of pointers
	string filename - naem of file to write to
I/O Parameters : Description of reference parameters that have one value upon entering the routine and different value upon leaving the routine
Output Parameters : Description of reference parameters that receive their initial value inside the function
Function Return Value: (for non-void functions) Description of any value returned by the function
*/
void saveInv(vector<Inventory *> &inv, string fileName) {
	fstream file;
	
	file.open(fileName, ios::binary | ios::out | ios::trunc);
	//If file does not exist, add trunc flag to set file to zero
	if (!file.is_open()) {
		file.close();
		return;
	}
	
	for (Inventory *a : inv) {
		a->write(file); //call class serialization function and write to file
	}
	
	file.close(); //close file

}

/*
Purpose : Print contents of inventory vector
Input Parameters :
		inv - vector of inventory pointers
I/O Parameters : 
Output Parameters : 
Function Return Value: 
*/
void printInv(const vector<Inventory *> &inv) {

	for (Inventory *a : inv) {
		a->print(); //call class print function
	}
}

/*
Purpose : Prints summary of all items in inventory
Input Parameters : 
	inv - vector of Inventory pointers
I/O Parameters : Description of reference parameters that have one value upon entering the routine and different value upon leaving the routine
Output Parameters : Description of reference parameters that receive their initial value inside the function
Function Return Value: (for non-void functions) Description of any value returned by the function
*/
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

/*
Purpose : Summarizes numeric values of map and returns value
Input Parameters : 
	map<string, T> m - map to perform operation on
I/O Parameters : 
Output Parameters : 
	T sumVar = temporary var to increment
Function Return Value: 
	T sumVar - summarized value
*/
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

/*
Purpose : Searches vector for tiem based on name
Input Parameters :
	string searchString - String to search vector for
I/O Parameters : 
	vector<Inventory *> &inv -  vector of inventory objects
Output Parameters :
	vector<Inventory *> results - Temporary vector to hold search results
	int choice - holds user input
	int curSize - current size of search results
Function Return Value:
*/
void search(vector<Inventory *> &inv, string searchString) {
	vector<Inventory *> results; //temporary vector to hold search results
	regex strRegEx(".*" + searchString + ".*", regex_constants::icase | regex_constants::ECMAScript); //Regex pattern to validate input
	int choice = -1;
	int curSize; //current size of result set
	for (Inventory *i : inv) {
		if (regex_match(i->getName(), strRegEx))
			results.push_back(i);
	}
	do {
		curSize = results.size();
		int counter = 0;
		cout << "Search Results\n";
		for (Inventory *i : results) {
			cout << counter << " - " << i->getName() << endl;
			counter++;
		}
		if (results.size() == 0) {
			cout << "No match found\n";
			return;
		}
		cout << results.size()  << " - Exit\n";
		cout << "Enter number of item to modify or " << results.size()  << " to exit: ";
		choice = Inventory::getInput<int>(0, results.size() );
		if (choice == results.size())
			return;

		//Take action on search result
		int action = itemMenu(results[choice]);
		switch (action) {
		case 1:
			results[choice]->print();
			break;
		case 3:
			results[choice]->updateItem();
			break;
		case 2:
			std::vector<Inventory *>::iterator position = find(inv.begin(), inv.end(), results[choice]);
			if (position != inv.end()) // == myVector.end() means the element was not found
				inv.erase(position); //remove from main vector
			delete results[choice]; //deallocate pointer
			results.erase(results.begin() + choice); //remove from search results
			break;
	
		}
	} while (choice != curSize);

	
}
/*
Purpose : Displays menu of actions that can be performed on an object
Input Parameters : 
	T Item - pointer to individual Inventory class
I/O Parameters : 	
Output Parameters : 
Function Return Value: 
	returns integer chosen by user
*/
template <class T>
int itemMenu(T &item) {
	
	
	cout << item->getName() << " Menu" << endl;
	cout << "1 - Print\n";
	cout << "2 - Delete\n";
	cout << "3 - Update\n";
	cout << "4 - Exit\n";
	cout << "Enter choice: ";
	return Inventory::getInput<int>(1, 4);
	

}




