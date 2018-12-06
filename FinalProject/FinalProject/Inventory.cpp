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


int Inventory::getYearPurchased(){
	return this->yearPurchased;
}
int Inventory::getDepreciationYears(){
	return this->depreciationYears;
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
	cout << "Type: " << this->iType << endl;
	cout << "Name: " << this->name << endl;
	cout << "Year Purchased: " << this->yearPurchased << endl;
	cout << "Purchase Price: $" << fixed <<  setprecision(2) << this->purchasePrice << endl;
	cout << "Current Value: $" << fixed << setprecision(2)  << this->depreciatedPrice << endl;
	
	
}
