#include "Inventory.h"



Inventory::Inventory()
{
	iType = "Inventory";
}
Inventory::Inventory(string name, double price, string location, int yearPurchased) {
	this->name = name;
	this->purchasePrice = price;
	this->location = location;
	this->yearPurchased = yearPurchased;
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
string Inventory::getLocation(){
	return this->location;
}
double Inventory::getDepreciatedPrice(){
	return this->depreciatedPrice;
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
void Inventory::setLocation(string location){
	this->location = location;
}
void Inventory::setDepreciatedPrice(double price){
	this->depreciatedPrice = price;
}

void Inventory::setYearPurchased(int year){
	this->yearPurchased = year;
}
void Inventory::setDepreciationYears(int years){
	this->depreciationYears = years;
}



double Inventory::calculateDepreciation() {
	int salvagePrice = this->purchasePrice * this->depreciationRate;
	double dAmount = (this->purchasePrice - salvagePrice) / this->depreciationYears;
	double dValue = (this->purchasePrice - (dValue * (getCurrentYear() - this->yearPurchased)));
	if (dValue < 0)
		return 0;
	else
		return dValue;
	

}

int Inventory::getCurrentYear() {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	return 1970 + ltm->tm_year;

}

//output
void Inventory::print(){
}
