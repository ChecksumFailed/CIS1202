#include <iostream> //cout
#include <iomanip> // used to manipulate cout
#include <string>
#include <istream>

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


/*
Programmer Name: Ben Scherer
Program # : 7
Course: CIS 1202 Section 502
Date : 9/24/2018
Program Description : Stores contact details for customers leveraging structs.
*/
int main() {
	Customer customerArr[20];
	int arrSize = 0;
	int maxSize = 1;
	int choice; //stores user input



//Loop until user exits
	choice = displayMenu();
	while (choice != 4) {

		switch (choice) {
		case 1:
			
			if (arrSize >= maxSize)
				expandArray(customerArr, arrSize,maxSize);
			customerArr[arrSize] = getCustomer();
			arrSize++;
			break;
		case 2:
			for (int i = 0; i < arrSize; i++) {
				showCustomer(customerArr[i]);
			}
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


/*
Purpose : Prompts and validates user input to add a customer
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : 
	Customer tmpCust - temporary customer object to store input values
Function Return Value: Customer object
*/
Customer getCustomer() {
	Customer tmpCust;
	cin.clear();
	cin.ignore();
	cout << "\nEnter customer first name: ";
	getline(cin,tmpCust.firstNm);

	cout << "\nEnter customer last name:";
	getline(cin, tmpCust.lastNm);

	cout << "\n\nEnter Business Address\n";
	cout << "Enter street address: ";
	getline(cin, tmpCust.busAddr.street);
	cout << "\nEnter city:";
	getline(cin, tmpCust.busAddr.city);
	cout << "\nEnter State:";
	getline(cin, tmpCust.busAddr.state);
	cout << "\nEnter zip code:";
	getline(cin, tmpCust.busAddr.zip);


	cout << "\n\nEnter Home Address\n";
	cout << "Enter street address: ";
	getline(cin, tmpCust.homeAddr.street);
	cout << "\nEnter city:";
	getline(cin, tmpCust.homeAddr.city);
	cout << "\nEnter State:";
	getline(cin, tmpCust.homeAddr.state);
	cout << "\nEnter zip code:";
	getline(cin, tmpCust.homeAddr.zip);


	return tmpCust;
}

/*
Purpose : Prints all attributes of customer object
Input Parameters : 
	custObj - Customer struct object
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: n/a
*/
void showCustomer(Customer custObj) {
	cout << "\nCustomer Name: " << custObj.firstNm << " " << custObj.lastNm << endl;
	
	cout << "Business Address: \n";
	cout << "\t" << custObj.busAddr.street << ", " << custObj.busAddr.city << ", " << custObj.busAddr.state << " " << custObj.busAddr.zip << endl;
	cout << "Home Address: \n";
	cout << "\t" << custObj.homeAddr.street << ", " << custObj.homeAddr.city << ", " << custObj.homeAddr.state << " " << custObj.homeAddr.zip << endl;
	
//out << "\t" << custObj.busAddr.street << " " << 

}

/*
Purpose : One sentence describing WHAT it does
Input Parameters : Description of value parameters; sent into the function, but not changed by the function
I/O Parameters : Description of reference parameters that have one value upon entering the routine and different value upon leaving the routine
Output Parameters : Description of reference parameters that receive their initial value inside the function
Function Return Value: (for non-void functions) Description of any value returned by the function
*/