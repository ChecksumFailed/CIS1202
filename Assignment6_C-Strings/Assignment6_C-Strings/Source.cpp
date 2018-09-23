#include <iostream>
#include <cstring>
#include <iomanip> // used to manipulate cout

using namespace std;
int findW(char[], int);
long getCustNum(char[], int);
int getYear(char[], int);
long getOrderNum(char[], int, int);
void getWorkOrder(char[],int);


int main() {
	//Variables
	const int SIZE = 20; //Char Array Size
	char custNumber[6], year[2], workOrderNumber[5]; //Data to be parse from workOrder string
	char workOrder[SIZE] ; //String to parse
	int orderLen;  //Number of char in work order
	int wPosition; //Position of w char in string
	

	getWorkOrder();

	//Get length of string and find position of 'W'.  Critical for all other fucntions
	orderLen = strlen(workOrder);
	wPosition = findW(workOrder, orderLen);
	if (wPosition == -1 ) { //if w not found or custnumber > 6 , invalid work order
		cout << "Invalid work order. Exiting program" << endl;
		return 1;
	}
	


	//Print Output
	cout << "Order Length: " << orderLen << endl;
	cout  << "W Position: " << wPosition << endl;
	cout << "Customer Number: " << getCustNum(workOrder, wPosition); << endl;;
	cout << "Year: " << getYear(workOrder,wPosition) << endl;;
	cout << "Order Number: " << getOrderNum(workOrder, wPosition,orderLen) << endl;;
		   	 	


	//pauses program
	cout << "Press enter key to exit program\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}


int findW(char workOrder[], int size) {

	for (int i = 0; i < size; i++) {
		if (workOrder[i] == 'W' || workOrder[i] == 'w')
			return i;
	}
	
	return -1; //return -1 if W char not found


}

long getCustNum(char workOrder[],int wPosition) {
	
	//Set array size to wPosition.  Allow for any size customer number
	//char custNumber[6];
	char* custNumber;
	custNumber = new char[wPosition];

	for (int i = 0; i < wPosition; i++) {
		custNumber[i] = workOrder[i];

	}

	long numToReturn =  atol(custNumber); // convert char array to long 
	delete custNumber; // delete from memory

	return numToReturn;
	}


int getYear(char workOrder[], int wPosition) {

	char year[2];
	int start = wPosition + 1;
	for (int i = 0; i < 2; i++) {
		year[i] = workOrder[i + start];
	}
	
	return atoi(year); //convert char array to int and return
}


long getOrderNum(char workOrder[], int wPosition,int orderLen) {
	
	int start = wPosition + 3; // Start position is wPostion + 1 + 2(year length)
	int charSize = orderLen - start ; //Calculate size of char array.   Lenth of work order - starting position
		
	//Set array size to wPosition.  Allow for any size order number
	char* orderNum;
	orderNum = new char[charSize];
	
	for (int i = 0; i < charSize; i++) {
		orderNum[i] = workOrder[i + start];
	
	}

	long numToReturn = atol(orderNum); // convert char array to long 
	delete orderNum; // delete from memory

	return numToReturn;
}


void getWorkOrder(char workOrder[],int size) {

	bool isValid = false;
	do {

		cout << "Enter a three part work order in the format: <CustomerNumber>W<Year><Order Number>\n\n";
		cout << "The first 5-6 digits before the W contain the work order number\n";
		cout << "The first 2 digits after the W rrepresent the year\n";
		cout << "The remaining digits represent the work order number\n";
		cout << "Example: 123456w991234\n\n";



		cin.getline(workOrder, size);
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "You have entered invalid input.  Try again" << endl;

		}
		else
			isValid = true;
	} while (!isValid);
}