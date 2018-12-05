#include <iostream>
#include <iomanip>
#include <string>
#include "Inventory.h"
#include "Media.h"
#include "Display.h"
#include "Game.h"
#include "Movie.h"
#include "Music.h"
#include <cmath>


using namespace std;

void displayMainMenu(); //Main Menu of program
template <class T> T getInput();
template <class T> T getInput(T,T);//checks against range

int main() {

	do {
		displayMainMenu();
		
	} while (getInput(1, 6) != 6);


	cout << "Press any key to exit";
	getchar();
	return EXIT_SUCCESS;
}



void displayMainMenu() {
	cout << "CIS 1202 Home Inventory Database\n\n";
	cout << "1 - Print Inventory\n";
	cout << "2 - Add Item\n";
	cout << "3 - Modify Item\n";
	cout << "4 - Delete Item\n";
	cout << "5 - Search for Item\n";
	cout << "6 - Quit\n";
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