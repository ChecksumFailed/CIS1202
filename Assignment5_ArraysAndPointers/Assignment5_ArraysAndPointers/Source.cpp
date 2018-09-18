#include <iostream> //cout
#include <iomanip> // used to manipulate cout
#include <string> //needed for string variable
#include <math.h> //used for basic arithmatic
#include <fstream> //file handling
#include <sstream> //used for string bufffer




using namespace std;

//Functions
int getMenuItem(); // Display's the menu and inputs and retursn the user's menu choice
void enterRents(int * ,int); //prompts for int input until maxsize is reached
void displayRents(int *, int); //loops through memory pointers to display results instead of array
void displayMemoryLocations(int *, int); //loops through array and displays memory location of each element
void selectionSort(int *, int); //sorts array ascending
void swap(int *, int *); //used to swap values. Leveraged by selection sort
int sumRents(int *, int); // summarizes rents array and returns int



/*
Programmer Name: Ben Scherer
Program # : 3
Course: CIS 1202 Section 502
Date : 9/2/2018
Program Description : Property management program.  Leverages arrays and pointers to display and minipulate data.
*/
int main() {
	const int arrSize = 7; //Size of property array
	int rent[arrSize] = {};

	int choice; //stores user input



	//Loop until user exits
	choice = getMenuItem();
	while (choice != 6) {

		switch (choice) {
		case 1:
			enterRents(&rent[0], arrSize);
			break;
		case 2:
			displayRents(&rent[0], arrSize);
			break;
		case 3:
			selectionSort(rent, arrSize);
			break;
		case 4:
			cout << "Total Rent: $" << sumRents(&rent[0], arrSize) << endl;
			break;
		case 5:
			displayMemoryLocations(rent, arrSize);
			break;
		default:
			cout << "ERROR: Invalid Choice.  Try Again\n\n";
		}

		choice = getMenuItem();
	};


	//pauses program
	cout << "Press enter key to exit program\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}



/*
Purpose: Get user input and populate rent array, using pointers
Input Parameters :
	int size - Size of array
I/O Parameters :
	int rent[] - Array of integers used to store rent values
Output Parameters
	int i - simple counter for loops
Function Return Value: (for non-void functions) Description of any value returned by the function
*/
void enterRents(int *rentPtr , int size) {
	cin.ignore();

	for (int i = 0; i < size; i++) {
		cout << "Enter rent for property #" << i + 1 << ": ";
		cin >> *(rentPtr + i);
		if (cin.fail() )
		{
			cin.clear();
			cin.ignore();
			cout << "You have entered invalid input.  Try again" << endl;
			i--;
		}
	}


}

/*
Purpose: Received pointer from rents array and summarizes all values.
Input Parameters :
	int size - Size of array
	int *rentPtr - Points to first element in array
I/O Parameters :
Output Parameters: n/a
Function Return Value: 
	totalRent - summarized value of all values in rents array.
*/
int sumRents(int *rentPtr, int size) {
	int totalRent = 0;//used to total rent due
	cout << "Summarizing rental amounts for " << size << " properties\n";
	for (int i = 0; i < size; i++) {
		totalRent += *(rentPtr + i);
	}
	return totalRent;
}

/*
Purpose: Get user input and populate rent array, using pointers
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
Purpose: Displays memory locations of array, using pointers
Input Parameters :
	int size - Size of array
	int arrPointer[] - Pointer to first element in rent array
I/O Parameters :

Output Parameters: n/a
Function Return Value: n/a
*/
void displayMemoryLocations(int *rentPtr, int size) {

	cout << "Displaying memory locations of array\n";
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " : " << rentPtr + i << endl;
	}

}
/*
Purpose : Display's the menu and inputs and retursn the user's menu choice
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: n/a
*/
int getMenuItem() {
	int valToReturn;
	bool isValid = false;
	do {
		
		cout << "\nChecksumFailed Propery Managment\n\n";
		cout << "1: Enter rent amounts\n";
		cout << "2: Display rents\n";
		cout << "3: Sort rent from low to high\n";
		cout << "4: Total rents\n";
		cout << "5: Display memory locations \n";
		cout << "6: Exit\n";
		cout << "Please enter your selection: ";

		cin >> valToReturn;
		if (cin.fail() || valToReturn < 1 || valToReturn > 6)
		{
			cin.clear();
			cin.ignore();
			cout << "You have entered invalid input.  Try again" << endl;

		}
		else
			isValid = true;
	} while (!isValid);

	return valToReturn;

}




/*
Purpose : Performs selection sort based on int array, ascending
Input Parameters :
	int size - number of elements in arrays
I/O Parameters :
	int arrPointer[] - Pointer to first element in rent array
Output Parameters : n/a
Function Return Value: n/a
*/
void selectionSort(int *arrPointer, int size) {

	int minIndex;
	int minValue;
	

	for (int start = 0; start < (size - 1); start++) {
		minIndex = start;
		minValue = *(arrPointer + start);

		for (int index = start + 1; index < size; index++) {

			if (*(arrPointer + index) < minValue) {
				minValue = *(arrPointer + index);
				minIndex = index;

			}
		}
		swap((arrPointer + minIndex), (arrPointer + start));

	}

	

}

/*
Purpose : Swaps int values
Input Parameters :

I/O Parameters :
	int a* - first  value to swap
	int b* - second  value to swap
Output Parameters :

Function Return Value: n/a
*/
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


