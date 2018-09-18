#include <iostream> //cout
#include <iomanip> // used to manipulate cout
#include <string> //needed for string variable
#include <math.h> //used for basic arithmatic
#include <fstream> //file handling
#include <sstream> //used for string bufffer




using namespace std;

//Functions
void loadArrays(string[], double[], int &);
void showArrays(string[], double[], int);
void lookUpTaxes(string[], double[], int);
void sortTaxes(string[], double[], int);
void biggestTaxes(string[], double[], int);
int showMenu(); //Display's the menu and inputs and retursn the user's menu choice
void swap(string &, string &); //Swaps string values, used by sortTaxes function
void swap(double &, double &); //Swaps double values, used by sortTaxes function


/*
Programmer Name: Ben Scherer
Program # : 2
Course: CIS 1202 Section 502
Date : 9/1/2018
Program Description : Uses parallel arrays to input,print,search and find the largest amount due and sort tax data for county auditor
*/
int main() {
	int numElements = 0; //number of elements in parallel arrays
	string address[20] = {}; //store adddresses
	double amtDue[20] = {}; //stores amount due
	int choice; //stores user input

	loadArrays(address, amtDue, numElements); //load parallel arrays from file

	//Loop until user exits
	choice = showMenu();
	while(choice != 5) {
		
		if (choice == 1)
			showArrays(address, amtDue, numElements);
		else if (choice == 2)
			lookUpTaxes(address, amtDue, numElements);
		else if (choice == 3)
			sortTaxes(address, amtDue, numElements);
		else if (choice == 4)
			biggestTaxes(address, amtDue, numElements);
		else 
			cout << "ERROR: Invalid Choice.  Try Again\n\n";
		choice = showMenu();
	} ;


	//pauses program
	cout << "Press enter key to exit program\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}



/*
Purpose : Display's the menu and inputs and retursn the user's menu choice
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: n/a
*/
int showMenu() {
	int valToReturn;
	cin.clear();
	cout << "\nCounty Auditors Property Tax Sort and Search\n\n";
	cout << "1: Display the Property Tax Data\n";
	cout << "2: Look up taxes for a particular address\n";
	cout << "3: Sort tax amounts in ascending order\n";
	cout << "4: Display Property with largest tax due\n";
	cout << "5: Exit\n";
	cout << "Please enter your selection: ";
	
	cin >> valToReturn;
	
	return valToReturn;

}

/*
Purpose : Reads in text file and loads data into parallel arrays
Input Parameters : n/a
I/O Parameters :
	string address[] - addresses in the county
	int amtDue - taxes due at address
	int numElements - number of entries read in from file
Output Parameters :
	string strHold -placeholder for getLine
	ifstream fileInput - input stream for stats file
	string fileToOpen - File to read in
Function Return Value: n/a
*/
void loadArrays(string address[], double amtDue[], int &numElements) {
	string strHold; //placeholder for getLine
	string fileToOpen = "Prog3Input.txt";
	ifstream fileInput(fileToOpen); //input stream for stats file
	int counter = 0;
	


	//If loading statsFile fails, display error message and exit
	if (fileInput.fail()) {
		cout << "ERROR: Unable to open database file: " << fileToOpen << endl;
		exit(1);
	}

	cout << "Loading tax database....\n";

	//Read in line, parse data and populate arrays.  
	while (getline(fileInput, strHold)) {
	//	cout << "Line: " << strHold << endl;
		
		if (counter % 2 == 0) {
			address[numElements] = strHold;
			
			
		}
		else {
			amtDue[numElements] = stod(strHold);
			numElements++;
		}
		counter++;
	}


}


/*
Purpose : Prints out contents of arrays
Input Parameters : 
	string address[] - addresses in the county
	int amtDue - taxes due at address
	int numElements - number of elements in arrays
I/O Parameters :
Output Parameters :
Function Return Value: n/a
*/
void showArrays(string address[], double amtDue[], int numElements) {

	cout << "count Auditors Records\n\n";

	for (int i = 0; i < numElements; i++) {
		cout << address[i] << " = " << amtDue[i] << endl;
	}


}

/*
Purpose : Searches array for address
Input Parameters :
	string address[] - addresses in the county
	int amtDue - taxes due at address
	int numElements - number of elements in arrays
I/O Parameters :
Output Parameters : 
	string strHold - Placeholder for cin
Function Return Value: n/a
*/
void lookUpTaxes(string address[], double amtDue[], int numElements) {
	
	string  strHold;//placeholder for cin
	cin.ignore();
	cout << "Please enter the address to look up:";
	getline(cin, strHold);

	for (int i = 0; i < numElements; i++) {
		if (address[i] == strHold) {
			cout << "\nThe taxes for " << address[i] << " = " << amtDue[i] << endl;
			return;
		}
	}
	cout << "\nUnable to find address, " << strHold << " ,in tax records\n";
}



/*
Purpose : Performs selection sort based on amtdue array, ascending
Input Parameters :
	int numElements - number of elements in arrays
I/O Parameters :
	string address[] - addresses in the county
	int amtDue - taxes due at address
Output Parameters :
	
Function Return Value: n/a
*/
void sortTaxes(string address[], double amtDue[], int size) {

	int minIndex;
	int minValue;

	for (int start = 0; start < (size - 1); start++) {
		minIndex = start;
		minValue = amtDue[start];

		for (int index = start + 1; index < size; index++) {

			if (amtDue[index] < minValue) {
				minValue = amtDue[index];
				minIndex = index;

			}
		}
		swap(amtDue[minIndex], amtDue[start]);
		swap(address[minIndex], address[start]);
	}


}
/*
Purpose :swaps string values
Input Parameters :
	
I/O Parameters :
	string a - first string value to swap
	string b - second string value to swap
Output Parameters :

Function Return Value: n/a
*/
void swap(string &a, string &b) {
	string temp = a;
	a = b;
	b = temp;
}

/*
Purpose : Swaps double values
Input Parameters :

I/O Parameters :
	string a - first double value to swap
	string b - second double value to swap
Output Parameters :

Function Return Value: n/a
*/
void swap(double &a, double &b) {
	double temp = a;
	a = b;
	b = temp;
}

/*
Purpose : Find the largest value in the amtDue array
Input Parameters :
	string address[] - addresses in the county
	int amtDue - taxes due at address
	int numElements - number of elements in arrays
I/O Parameters :
	
Output Parameters :

Function Return Value: n/a
*/
void biggestTaxes(string address[], double amtDue[], int size) {
	int maxIndex = 0;

	for (int i = 0; i < size; i++) {
		if (amtDue[i] > amtDue[maxIndex])
			maxIndex = i;

	}

	cout << "The largest tax amount = " << amtDue[maxIndex] << " at " << address[maxIndex] << endl;

}