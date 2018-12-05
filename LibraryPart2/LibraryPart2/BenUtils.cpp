#include "BenUtils.h"



BenUtils::BenUtils()
{
}


BenUtils::~BenUtils()
{
}

/*
Purpose : Gets int input and validates
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value:
	int intHolder - float to validate input against
*/
int BenUtils::getInt() {
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
double BenUtils::getDouble() {
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
Purpose : Gets int input and validates against range
Input Parameters :
	int low - Low end of range
	int high - High end of range
I/O Parameters : n/a
Output Parameters :
Function Return Value:
	int intHolder - float to validate input against
*/
int BenUtils::getInt(int low, int high) {
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
Purpose : Gets string input and validates
	Input Parameters : n / a
	I / O Parameters : n / a
	Output Parameters :
bool isValid - Used to control loop until valid input is entered
Function Return Value :
string strHold - holds input from cin
*/
string  BenUtils::getString() {
	cin.clear();
	string strHolder; //temporary variable for getlne
	bool isValid = false;

	do {
		getline(cin, strHolder);
		if (cin.fail()) {
			cout << "\nYou have entered invalid input.  Try Again\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			isValid = true;
	} while (!isValid);

	return strHolder;

}

/*
Purpose : Gets string input and validates against parameter
Input Parameters :
	string strToMatch - string to validate input against
I/O Parameters : n/a
Output Parameters :
	bool isValid - Used to control loop until valid input is entered
Function Return Value:
	string strHold - holds input from cin
*/

string BenUtils::getString(string strToMatch) {
	cin.clear();
	string strHold; //temporary variable for getlne
	bool isValid = false;
	regex strRegEx(strToMatch, regex_constants::icase | regex_constants::ECMAScript); //Regex pattern to validate input

	do {
		getline(cin, strHold);
		if (cin.fail() || !regex_match(strHold, strRegEx)) {
			cout << "\nYou have entered invalid input.  Try Again\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			isValid = true;
	} while (!isValid);

	return strHold;

}


