#include <iostream> //cout
#include <iomanip> // used to manipulate cout
#include <string> //needed for string variable
#include <math.h> //used for basic arithmatic
#include <fstream> //file handling
#include <sstream> //used for string bufffer




using namespace std;

//Functions
int showMenu(); //Display's the menu and inputs and retursn the user's menu choice
void enterRents(int[], int); //prompts for int input until maxsize is reached
void displayRents(int *, int); //loops through memory pointers to display results instead of array
void displayMemoryLocations(int[], int); //loops through array and displays memory location of each element
void selectionSort(int[], int); //sorts array ascending
void swap(int &, int &); //used to swap values. Leveraged by selection sort



/*
Programmer Name: Ben Scherer
Program # : 3
Course: CIS 1202 Section 502
Date : 9/2/2018
Program Description : Property management program.  Leverages arrays and pointers to display and minipulate data.
*/
int main() {
	const int arrSize = 5; //Size of property array
	int rent[arrSize] = {};

	int choice; //stores user input

	

	//Loop until user exits
	choice = showMenu();
	while (choice != 5) {

		switch (choice) {
			case 1:
				enterRents(rent, arrSize);
				break;
			case 2:
				displayRents(&rent[0], arrSize);
				break;
			case 3:
				displayMemoryLocations(rent, arrSize);
				break;
			case 4:
				selectionSort(rent, arrSize);
				break;
			default:
				cout << "ERROR: Invalid Choice.  Try Again\n\n";
		}

		choice = showMenu();
	};


	//pauses program
	cout << "Press enter key to exit program\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}
/*
Purpose: Get user input and populate rent array
Input Parameters : 
	int size - Size of array
I/O Parameters : 
	int rent[] - Array of integers used to store rent values
Output Parameters 
	int i - simple counter for loops
Function Return Value: (for non-void functions) Description of any value returned by the function
*/
void enterRents(int rent[], int size) {
	cin.ignore();
	
	for (int i = 0; i < size; i++) {
		cout << "Enter rent for property #" << i + 1 << ": ";
		cin >> rent[i];
	}


}

/*
Purpose: Get user input and populate rent array
Input Parameters :
	int size - Size of array
	int *rentPtr - Points to first element in array
I/O Parameters :
Output Parameters: n/a	
Function Return Value: n/a
*/
void displayRents(int *rentPtr, int size) {

	cout << "Rental amounts for " << size << " properties\n";
	for (int i = 0; i < size; i++) {
		cout << (i + 1) << ": " << *(rentPtr + i) << endl;
	}

}

/*
Purpose: Displays memory locations of array
Input Parameters :	
	int size - Size of array
	int arrp[] - interger array
I/O Parameters :

Output Parameters: n/a
Function Return Value: n/a
*/
void displayMemoryLocations(int arr[], int size) {

	cout << "Displaying memory locations of array\n";
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " : " << &arr[i] << endl;
	}

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
	cout << "\nChecksumFailed Propery Managment\n\n";
	cout << "1: Enter rent amounts\n";
	cout << "2: Display rents\n";
	cout << "3: Display memory locations \n";
	cout << "4: Sort rent from low to high\n";
	cout << "5: Exit\n";
	cout << "Please enter your selection: ";

	cin >> valToReturn;

	return valToReturn;

}




/*
Purpose : Performs selection sort based on int array, ascending
Input Parameters :
	int size - number of elements in arrays
I/O Parameters :
	string arr[] - array of integers
Output Parameters : n/a
Function Return Value: n/a
*/
void selectionSort(int arr[], int size) {

	int minIndex;
	int minValue;

	for (int start = 0; start < (size - 1); start++) {
		minIndex = start;
		minValue = arr[start];

		for (int index = start + 1; index < size; index++) {

			if (arr[index] < minValue) {
				minValue = arr[index];
				minIndex = index;

			}
		}
		swap(arr[minIndex], arr[start]);
		
	}


}

/*
Purpose : Swaps int values
Input Parameters :

I/O Parameters :
	int a - first  value to swap
	int b - second  value to swap
Output Parameters :

Function Return Value: n/a
*/
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}


