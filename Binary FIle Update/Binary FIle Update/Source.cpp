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
int getInt(); //Get int input and validate
void addRecord(fstream&); //Add record to file.d
double getDouble(); // gets double input and validates


/*
Programmer Name: Ben Scherer
Program # : 9
Course: CIS 1202 Section 502
Date : 10/14/2018
Program Description : Binary file manipulation program. Peforms Read/Modify operations
*/
int main() {
	int choice; 
	//Create fstream
	string fileName = "inventory.dat";
	// To modify file use ios::in|ios::out.  TO append to ios::out|ios::app.  Ios:in|ios:app not compat

	fstream inventory("Inventory.dat",ios::in | ios::app | ios::binary);
if (!inventory.is_open()) {
		cout << "Error: Unable to open inventory.dat. Exiting program\n";
		cin.get();
		return 1;
	}
	

	do {
		choice = showMenu();
		switch (choice) {
		case 1: printFile(inventory); break;
		case 2: addRecord(inventory); break;
		case 3: displayRecord(inventory); break;
		case 4: modifyRecord(inventory); break;
		}
	} while (choice != 5);


	if (inventory.is_open())
		inventory.close();

	return 0;
}


/*
Purpose : Displays Menu and validates input
Input Parameters :n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: getInt() 
*/
int showMenu() {
	int choice;
		cout << "Binary File Operations Menu\n\n";
		cout << "1 - Print File\n"
			<< "2 - Add Product\n"
			<< "3 - Display a specific product\n"
			<< "4 - Modify a specific product\n"
			<< "5 - Quit\n";
		cout << "Enter Choice: ";
	

		choice = getInt(1,5);
		cout << endl;
		return choice;
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
	Product tmpProduct;
	int readSize = sizeof(tmpProduct);
	int counter = 0;
	file.clear();
	cout << left << setw(15) << "Product Number" << setw(40) << "Product Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
	file.seekg(sizeof(tmpProduct), ios::beg);
	while (!file.eof()) {

		file.seekg(readSize * counter,ios::beg);
		file.read(reinterpret_cast<char *>(&tmpProduct), readSize);
		cout << left << setw(15) << tmpProduct.prodNum << setw(40) << tmpProduct.prodName << setw(10) << tmpProduct.price << setw(10) << tmpProduct.qty << endl;
		counter++;
	}



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
Purpose : add single record to file
Input Parameters :
I/O Parameters :
		fstream file - File stream object
Output Parameters : Description of reference parameters that receive their initial value inside the function
Function Return Value: n/a
*/
void addRecord(fstream &file) {
	Product p;
	file.clear();

	cout << "Add Record\n";
	cout << "Enter Product Number: ";
	p.prodNum = getInt();
	cout << "\nEnter prduct name: ";
	cin.getline(p.prodName, DESC_SIZE);
	cout << "\nEnter Price: ";
	p.price = getDouble();
	cout << "\nEnter Quantity: ";
	p.qty = getInt();

	//file.seekg(ios::end); //Go to end of file
	file.write(reinterpret_cast<char *>(&p), sizeof(p));
	cout << "\nAdded " << p.prodName << endl;

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

/*
Purpose : Gets int input and validates
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value:
	int intHolder - float to validate input against
*/
int getInt() {
	cin.clear();
	int intHolder; //temporary variable for getlne
	bool isValid = false;

	do {
		cin >> intHolder;
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
	return intHolder;

}

/*
Purpose : Gets double input and validates
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value:
	int intHolder - float to validate input against
*/
double getDouble() {
	cin.clear();
	double tmpHolder; //temporary variable for getlne
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