#include <iostream> //cout
#include <iomanip> // used to manipulate cout
#include <string>

using namespace std;

//Structs
//Defines the attributes of an adddress
struct Address {
	string street;
	string city;
	string state;
	string zip;
};

//Defines the attributes of a Customer
struct Customer {
	string lastNm;
	string firstNm;
	Address homeAddr;
	Address busAddr;
};

//Functions
int displayMenu(); //Displays menu, recives and validates input
Customer getCustomer(); //Recives user input and creates new customer object
void showCustomer(Customer); //Prints out all information for customer object
Address getAddress(); // Get user input and create Address object
void findCust(Customer[], int);// searches array for customer and prints results
void expandArray(Customer[]);

/*
Programmer Name: Ben Scherer
Program # : 7
Course: CIS 1202 Section 502
Date : 9/24/2018
Program Description : Stores contact details for customers leveraging structs.
*/
int main() {
	Customer customerArr[1];
	int arrSize;
	int choice; //stores user input



//Loop until user exits
	choice = displayMenu();
	while (choice != 4) {

		switch (choice) {
		case 1:
			//enterRents(&rent[0], arrSize);
			break;
		case 2:
		//	displayRents(&rent[0], arrSize);
			break;
		case 3:
			//selectionSort(rent, arrSize);
			break;
		case 4:
		//	cout << "Total Rent: $" << sumRents(&rent[0], arrSize) << endl;
			break;
	
		default:
			cout << "ERROR: Invalid Choice.  Try Again\n\n";
		}

		choice = displayMenu();
	};


	//pauses program
	cout << "Press enter key to exit program\n";
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
int displayMenu() {
	int valToReturn;
	bool isValid = false;
	do {

		cout << "\nCustomer Contacts Menu\n\n";
		cout << "1: Enter new customer\n";
		cout << "2: Display all customers\n";
		cout << "3: Display a particular customer\n";
		cout << "4: Exit\n";
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


void expandArray(Customer customerArr[],int size) {

	Customer* tmpArr = new Customer[size * 2]; // double size of array
	//copy contents to tmp array
	for (int i = 0; i < size; i++) {
		tmpArr[i] = customerArr[i];
	}

	delete[] customerArr; //Delete old array from memory

	customerArr = tmpArr; //point to new array.
}