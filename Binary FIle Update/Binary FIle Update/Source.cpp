//headers
#include <iostream> //cout
#include <iomanip> // used to manipulate cout
#include <fstream> //file handling
#include <string> //strings and getline

using namespace std;

const int DESC_SIZE = 40;
struct Product {
	long prodNum;
	char prodName[DESC_SIZE];
	double price;
	int qty;
};

//functions
int showMenu(); // Display menu and validate user input
void printFile(fstream&); //Print file contents
void displayRecord(fstream&);//display specific record in file
void modifyRecord(fstream&);//modify specific record in file
int getInt(int, int); //Get int input and validate based on range


/*
Programmer Name: Ben Scherer
Program # : 9
Course: CIS 1202 Section 502
Date : 10/14/2018
Program Description : Binary file manipulation program. Peforms Read/Modify operations
*/
int main() {


	return 0;
}

/*
Purpose : One sentence describing WHAT it does
Input Parameters :n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: int choice - Users choice
*/
int showMenu() {

	return 0;
}

/*
Purpose : Print contents of file
Input Parameters : 
	fstream file - File stream object
I/O Parameters : Description of reference parameters that have one value upon entering the routine and different value upon leaving the routine
Output Parameters : Description of reference parameters that receive their initial value inside the function
Function Return Value: n/a
*/
void printFile(fstream &file) {

}

/*
Purpose :  Print single record from file
Input Parameters :
	fstream file - File stream object
I/O Parameters : Description of reference parameters that have one value upon entering the routine and different value upon leaving the routine
Output Parameters : Description of reference parameters that receive their initial value inside the function
Function Return Value: n/a
*/
void displayRecord(fstream &file) {

}

/*
Purpose : Modify single record in file
Input Parameters :
I/O Parameters : 
		fstream file - File stream object
Output Parameters : Description of reference parameters that receive their initial value inside the function
Function Return Value: n/a
*/
void modifyRecord(fstream &file) {

}


/*
Purpose : Gets int input and validates against range
Input Parameters :
	int low - Low end of range
	int high - High end of range
I/O Parameters : n/a
Output Parameters :
Function Return Value:
	int intHolder - float to validate input against
*/
int getInt(int low, int high) {
	cin.clear();
	int intHolder; //temporary variable for getlne
	bool isValid = false;

	do {
		cin >> intHolder;
		if (cin.fail() || intHolder < low || intHolder > high) {
			cout << "\nYou have entered invalid input.  Try Again\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
		else
			isValid = true;
	} while (!isValid);
	cin.clear();
	cin.ignore();
	return intHolder;

}