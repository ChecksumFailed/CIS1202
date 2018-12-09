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
string Inventory::getName() {
	return this->name;
}
double Inventory::getPurchasePrice(){
	return this->purchasePrice;
}

string Inventory::getIType() {
	return this->iType;
}

int Inventory::getYearPurchased(){
	return this->yearPurchased;
}
int Inventory::getDepreciationYears(){
	return this->depreciationYears;
}

double Inventory::getDepreciatedPrice() {
	return this->depreciatedPrice;
}
//setters
void Inventory::setName(string name){
	this->name = name;

}
void Inventory::setPurchasePrice(double price){
	this->purchasePrice = price;
}



void Inventory::setYearPurchased(int year){
	this->yearPurchased = year;
}
void Inventory::setDepreciationYears(int years){
	this->depreciationYears = years;
}




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

int Inventory::getCurrentYear() {
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);

	
	return timePtr->tm_year + 1900;

}

//output
void Inventory::print(){
	cout << endl;
	cout << setw(20) << left << "Type " << ": " << this->iType << endl;
	cout << setw(20) << left << "Name " << ": " << this->name << endl;
	cout << setw(20) << left << "Year Purchased " << ": " << this->yearPurchased << endl;
	cout << setw(20) << left << "Purchase Price" << ": $" << fixed <<  setprecision(2) << this->purchasePrice << endl;
	cout << setw(20) << left << "Current Value" << ": $" << fixed << setprecision(2)  << this->depreciatedPrice << endl;
	
	
}


//Seriallize/Deserialize
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

void Inventory::read(istream &f) {
	
	name = readString(f);
	
	f.read(reinterpret_cast<char *>(&yearPurchased), sizeof(&yearPurchased));
	f.read(reinterpret_cast<char *>(&depreciationRate), sizeof(&depreciationRate));
	f.read(reinterpret_cast<char *>(&depreciationYears), sizeof(&depreciationYears));
	f.read(reinterpret_cast<char *>(&purchasePrice), sizeof(double));
	f.read(reinterpret_cast<char *>(&depreciatedPrice), sizeof(double));

}

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

void Inventory::populateProperties() {
	cout << "Enter name of item: ";
	this->name = getString();
	cout << "Enter year purchased: ";
	this->yearPurchased = getInput<int>();
	cout << "Enter purchase price: ";
	this->purchasePrice = getInput<double>();
	calculateDepreciation();
}

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

//Overload < operator for sort. Sort by name by default.
bool operator<(Inventory a, Inventory b)
{

	if (a.getName().compare(b.getName()) < 0)
		return true;
	return false;
}

//Overload > operator for sort. Sort by name by default.
bool operator>(Inventory a, Inventory b)
{

	if (a.getName().compare(b.getName()) > 0)
		return true;
	return false;
}
