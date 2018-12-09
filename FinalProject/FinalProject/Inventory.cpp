#include "Inventory.h"



Inventory::Inventory()
{
	iType = "Inventory";
}
Inventory::Inventory(string name, double price, int yearPurchased) {
	this->name = name;
	this->purchasePrice = price;
	
	this->yearPurchased = yearPurchased;
	calculateDepreciation();
	iType = "Inventory";

	
}

Inventory::~Inventory()
{
}

//Getters
/*
Purpose : Returns value of the property - name
Input Parameters : 
I/O Parameters : 
Output Parameters : 
Function Return Value: 
	string - name property
*/
string Inventory::getName() {
	return this->name;
}
/*
Purpose : Returns value of the property - purchasePrice
Input Parameters :
I/O Parameters :
Output Parameters :
Function Return Value:
	double - purchase price property
*/
double Inventory::getPurchasePrice(){
	return this->purchasePrice;
}
/*
Purpose : Returns value of the property - iType
Input Parameters :
I/O Parameters :
Output Parameters :
Function Return Value:
	string - iType property
*/
string Inventory::getIType() {
	return this->iType;
}
/*
Purpose : Returns value of the property - yearPurchased
Input Parameters :
I/O Parameters :
Output Parameters :
Function Return Value:
	string - yearPurchased property
*/
int Inventory::getYearPurchased(){
	return this->yearPurchased;
}
/*
Purpose : Returns value of the property - depreciationyears
Input Parameters :
I/O Parameters :
Output Parameters :
Function Return Value:
	int - depreciationyears property
*/
int Inventory::getDepreciationYears(){
	return this->depreciationYears;
}
/*
Purpose : Returns value of the property - depreciatedPrice
Input Parameters :
I/O Parameters :
Output Parameters :
Function Return Value:
	double - depreciatedPrice property
*/
double Inventory::getDepreciatedPrice() {
	return this->depreciatedPrice;
}
//setters
/*
Purpose : Sets value of the property - name
Input Parameters :
I/O Parameters :
Output Parameters :
string - name Property
Function Return Value:
*/
void Inventory::setName(string name){
	this->name = name;

}
/*
Purpose : Sets value of the property - purchasePrice
Input Parameters :
I/O Parameters :
Output Parameters :
	double - purchasePrice property
Function Return Value:	
*/
void Inventory::setPurchasePrice(double price){
	this->purchasePrice = price;
}

/*
Purpose : Sets value of the property - yearPurchased
Input Parameters :
I/O Parameters :
Output Parameters :
	int - yearPurchased property
Function Return Value:
*/
void Inventory::setYearPurchased(int year){
	this->yearPurchased = year;
}
/*
Purpose : Sets value of the property - depreciationyears
Input Parameters :
I/O Parameters :
Output Parameters :
	int - depreciationyears property
Function Return Value:
*/
void Inventory::setDepreciationYears(int years){
	this->depreciationYears = years;
}

/*
Purpose : Calculates straight line deprecation for object
Input Parameters : 
I/O Parameters : Description of reference parameters that have one value upon entering the routine and different value upon leaving the routine
Output Parameters : 
	double salvagePrice - calculated salvage value
	double dAmount - calculated deprectation amount
	int yearsOwned - caluclated number of years owned
	double dValue - current calcualted value
Function Return Value: (for non-void functions) Description of any value returned by the function
*/
void Inventory::calculateDepreciation() {
	double salvagePrice = this->purchasePrice * this->depreciationRate;
	double dAmount = (this->purchasePrice - salvagePrice) / this->depreciationYears;
	int yearsOwned = getCurrentYear() - this->yearPurchased;
	double dValue = (this->purchasePrice - (dAmount * yearsOwned));
	if (dValue < 0)
		this->depreciatedPrice = dAmount;
	else
		this->depreciatedPrice= dValue;
	

}

/*
Purpose : returns the current year
Input Parameters : 
I/O Parameters : 
Output Parameters : 
	time_t t - time var
	timePtr - pointer to time oject
Function Return Value: 
	itn current year
*/
int Inventory::getCurrentYear() {
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);

	
	return timePtr->tm_year + 1900;

}

//output
/*
Purpose : Prints the contents of object
Input Parameters : 
I/O Parameters : D
Output Parameters :
Function Return Value: 
*/
void Inventory::print(){
	cout << endl;
	cout << setw(20) << left << "Type " << ": " << this->iType << endl;
	cout << setw(20) << left << "Name " << ": " << this->name << endl;
	cout << setw(20) << left << "Year Purchased " << ": " << this->yearPurchased << endl;
	cout << setw(20) << left << "Purchase Price" << ": $" << fixed <<  setprecision(2) << this->purchasePrice << endl;
	cout << setw(20) << left << "Current Value" << ": $" << fixed << setprecision(2)  << this->depreciatedPrice << endl;
	
	
}


//Seriallize/Deserialize
/*
Purpose : Serializes object properties and writes to binary file
Input Parameters :
	ostream f- filestream object
I/O Parameters :
Output Parameters :

Function Return Value:
*/
void Inventory::write(ostream &f) { 
	//cout << purchasePrice << endl;

	

	//f.write(reinterpret_cast<char *>(&iType), sizeof(iType));
	writeString(f, iType);
	writeString(f, name);
	f.write(reinterpret_cast<char *>(&yearPurchased), sizeof(&yearPurchased));
	f.write(reinterpret_cast<char *>(&depreciationRate), sizeof(&depreciationRate));
	f.write(reinterpret_cast<char *>(&depreciationYears), sizeof(&depreciationYears));
	f.write(reinterpret_cast<char *>(&purchasePrice), sizeof(double));
	f.write(reinterpret_cast<char *>(&depreciatedPrice), sizeof(double));

	
}
/*
Purpose : Deserialized data from binary file and populates object values
Input Parameters : 
	istream f- filestream object
I/O Parameters : 
Output Parameters : 
	
Function Return Value:
*/
void Inventory::read(istream &f) {
	
	name = readString(f);
	
	f.read(reinterpret_cast<char *>(&yearPurchased), sizeof(&yearPurchased));
	f.read(reinterpret_cast<char *>(&depreciationRate), sizeof(&depreciationRate));
	f.read(reinterpret_cast<char *>(&depreciationYears), sizeof(&depreciationYears));
	f.read(reinterpret_cast<char *>(&purchasePrice), sizeof(double));
	f.read(reinterpret_cast<char *>(&depreciatedPrice), sizeof(double));

}
/*
Purpose : read char array from file and serialize into string
Input Parameters :
istream f - file sream object
I/O Parameters :	
Output Parameters :
	size_t stringSize - holds string sizeof value, needed to read char array from file
	vector<char> temp - stores char array from file
	string tempString - string created from char array
Function Return Value:
*/
string Inventory::readString(istream &f) {
	size_t stringSize;
	f.read(reinterpret_cast<char *>(&stringSize), sizeof(size_t));
	if (f.eof() || !f.good())
		return "";
	vector<char> temp(stringSize);
	f.read(reinterpret_cast<char *>(&temp[0]), stringSize * sizeof(char));
	string tempString(temp.begin(), temp.end());
	return tempString;

}

/*
Purpose : Serializing string and writes to file
Input Parameters : 
string s - string to serialize
I/O Parameters : 
	ostream f - file stream object
Output Parameters : 
	size_t stringSize - used calculate size of deserialized string
Function Return Value: 
*/
void Inventory::writeString(ostream &f, string &s) {
	size_t stringSize = s.size();
	f.write(reinterpret_cast<char *>(&stringSize), sizeof(size_t));
	f.write(s.c_str(), stringSize * sizeof(char));
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
string  Inventory::getString() {
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
Purpose : Prompts user to for values needed to populate new object
Input Parameters : 
I/O Parameters : 
Output Parameters :
Function Return Value: 
*/
void Inventory::populateProperties() {
	cout << "Enter name of item: ";
	this->name = getString();
	cout << "Enter year purchased: ";
	this->yearPurchased = getInput<int>();
	cout << "Enter purchase price: ";
	this->purchasePrice = getInput<double>();
	calculateDepreciation();
}


/*
Purpose : Allows users to update any propety in class
Input Parameters :
I/O Parameters : 
Output Parameters :
	int choice - placeholer for user choice
Function Return Value: 
*/
void Inventory::updateItem() {
	int choice;
	do {
		cout << "1 - Name(" << this->getName() << ")\n";
		cout << "2 - Purchase Year(" << this->getYearPurchased() << ")\n";
		cout << "3 - Purchase Price(" << this->getPurchasePrice() << ")\n";
		cout << "4 - Exit\n";
		choice = getInput<int>(1, 4);
		switch (choice) {
		case 1:
			cout << "Enter new name: ";
			this->setName(getString());
			break;
		case 2:
			cout << "Enter new purchase year: ";
			this->setYearPurchased(getInput<int>());
			break;
		case 3:
			cout << "Enter new purchase price: ";
			this->setPurchasePrice(getInput<double>());
			break;

		}

	} while (choice != 4);
}

//Comparators

/*
Purpose : Overload < operator for sort. Sort by name ascending
Input Parameters : 
I/O Parameters : 
Output Parameters : 
Function Return Value: 
	bool
*/
bool operator<(Inventory a, Inventory b)
{

	if (a.getName().compare(b.getName()) < 0)
		return true;
	return false;
}

/*
Purpose : Overload < operator for sort. Sort by name descending
Input Parameters :
I/O Parameters :
Output Parameters :
Function Return Value:
	bool
*/
bool operator>(Inventory a, Inventory b)
{

	if (a.getName().compare(b.getName()) > 0)
		return true;
	return false;
}
