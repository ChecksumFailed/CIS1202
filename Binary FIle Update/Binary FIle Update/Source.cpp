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
long getLong(); //get long input and validate
void openFile(fstream&,string); //open file. checks to see if file exists first.


/*
Programmer Name: Ben Scherer
Program # : 9
Course: CIS 1202 Section 502
Date : 10/14/2018
Program Description : Binary file manipulation program. Peforms Read/Modify operations
*/
int main() {
	int choice; //int for choice menu
	string fileName = "inventory.dat"; //filename to use
	fstream inventory; ////file stream object for program

	openFile(inventory, fileName); //open file
	if (!inventory.is_open()) { // if error, exit program
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


	if (inventory.is_open()) //if file is open, close
		inventory.close();

	return 0;
}

/*
Purpose : Opens and validates file stream
Input Parameters : 
	string fileame - name of file to open
I/O Parameters : 
	fstream file - fstream object leveraged by all functions
Output Parameters : n/a	
Function Return Value: n/a
*/
void openFile(fstream &file, string fileName) {
	file.open(fileName, ios::binary | ios::in | ios::out);
	//If file does not exist, add trunc flag to set file to zero
	if (!file.is_open()) {
		file.close();
		file.open(fileName, ios::binary | ios::in | ios::out | ios::trunc);
	}
	
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
	Product tmpProduct; //temporary variable to store data from read
	int counter = 0; //counter to display record number
	file.clear();
	
	cout << left << setw(15) << "Record Number" <<  setw(15) << "Product Number" << setw(DESC_SIZE) << "Product Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
	file.seekg(0, ios::beg); //seek to beginning of file
	file.read(reinterpret_cast<char *>(&tmpProduct), sizeof(tmpProduct)); //read in first line to check if at eof
	while (!file.eof()) {
		
		cout << left << setw(15) << counter << setw(15) << tmpProduct.prodNum << setw(DESC_SIZE) << tmpProduct.prodName << setw(10) << tmpProduct.price << setw(10) << tmpProduct.qty << endl;
		file.read(reinterpret_cast<char *>(&tmpProduct), sizeof(tmpProduct));
		counter++;
		//file.seekg(sizeof(tmpProduct) * counter, ios::beg);
	}



}

/*
Purpose :  Print single record from file
Input Parameters :
	int recordNum - stores input from user
I/O Parameters : 
	fstream file - File stream object
Output Parameters : Description of reference parameters that receive their initial value inside the function
Function Return Value: n/a
*/
void displayRecord(fstream &file) {

	Product tmpProduct;//temporary variable to store data from read
	
	file.clear();
	file.seekg(ios::beg);
	
	cout << "Enter the record number to display: ";
	int recordNum = getInt();
	cout << endl;

	file.seekg(recordNum * sizeof(tmpProduct), ios::beg);

	file.read(reinterpret_cast<char *>(&tmpProduct), sizeof(tmpProduct));

	if (file.fail()) {
		cerr <<"Error: Not a valid record number\n";
		return;
	}

	cout << left << setw(15) << "Product Num: " << tmpProduct.prodNum << endl;
	cout << left << setw(15) << "Product Name: " << tmpProduct.prodName << endl;
	cout << left << setw(15) << "Price: " << tmpProduct.price << endl;
	cout << left << setw(15) << "Quantity: " << tmpProduct.qty << endl;


}

/* 
Purpose : Modify single record in file
Input Parameters :
	int choice - used for menu loop
	int recordNum - stores record number inputed by user
I/O Parameters : 
		fstream file - File stream object
Output Parameters : Description of reference parameters that receive their initial value inside the function
Function Return Value: n/a
*/
void modifyRecord(fstream &file) {
	Product tmpProduct;
	int choice; 

	file.clear(); //clear eof flag
	file.seekg(ios::beg); //seek to beginning of file

	cout << "Enter the record number to modify: ";
	int recordNum = getInt();
	cout << endl;

	file.seekg(recordNum * sizeof(tmpProduct), ios::beg); //seek to record
	file.read(reinterpret_cast<char *>(&tmpProduct), sizeof(tmpProduct)); //attempt to read
	if (file.fail()) { //exit if read failure
		cerr << "Error: Not a valid record number\n";
		return;
	}

	//loop until user quits
	do {
		cout << endl;
		cout <<  "1 - Product Num(" << tmpProduct.prodNum  << ")" << endl;
		cout <<  "2 - Product Name(" << tmpProduct.prodName << ")" << endl;
		cout  <<  "3 - Price:(" << tmpProduct.price << ")" << endl;
		cout  <<  "4 - Quantity:(" << tmpProduct.qty << ")" << endl;
		cout  <<  "5 - Quit\n";
		cout  <<   "Enter field to modify or 5 to quit: ";
		choice = getInt(1, 5);

		switch (choice) {
		case 1:
			cout << "Enter new Product Number: ";
			tmpProduct.prodNum = getLong();
			break;
		case 2:
			cout << "Enter new Product Name: ";
			cin.getline(tmpProduct.prodName, DESC_SIZE);
			break;
		case 3:
			cout << "Enter new Price: ";
			tmpProduct.price = getDouble();
			break;
		case 4:
			cout << "Enter new Quantity: ";
			tmpProduct.qty = getInt();
			break;
		}
	} while (choice != 5);

	file.seekg(recordNum * sizeof(tmpProduct), ios::beg); //seek to record
	file.write(reinterpret_cast<char *>(&tmpProduct), sizeof(tmpProduct)); //write updated record to file
	if (file.fail()) {
		cerr << "Error: Unable to write data to file\n";
		return;
	}
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
	Product tmpProduct;
	file.clear();

	cout << "Add Record\n";
	cout << "Enter Product Number: ";
	tmpProduct.prodNum = getLong();
	cout << "\nEnter prduct name: ";
	cin.getline(tmpProduct.prodName, DESC_SIZE);
	cout << "\nEnter Price: ";
	tmpProduct.price = getDouble();
	cout << "\nEnter Quantity: ";
	tmpProduct.qty = getInt();

	//file.seekg(ios::end); //Go to end of file
	file.write(reinterpret_cast<char *>(&tmpProduct), sizeof(tmpProduct));
	if (file.fail()) {
		cerr << "Error: Unable to write data to file\n";
		return;
	}
	cout << "\nAdded " << tmpProduct.prodName << endl;

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
/*
Purpose : Gets long input and validates
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value:
	int tnoHolder - float to validate input against
*/
long getLong() {
	cin.clear();
	long tmpHolder; //temporary variable for getlne
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