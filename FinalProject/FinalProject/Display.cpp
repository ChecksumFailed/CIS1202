#include "Display.h"



Display::Display()
{
}

Display::Display(string name, double price, string location, int yearPurchased, int size, string type, string res, string brand):Inventory(name,price,location,yearPurchased) {
	this->size = size;
	this->type = type;
	this->resolution = res;
	this->brand = brand;
	iType = "Display";
}
Display::~Display()
{
	iType = "Display";
}


//getters
string Display::getType() {
	return this->type;
}

string Display::getResolution() {
	return this->resolution;
}

string Display::getBrand() {
	return this->brand;
}

int Display::getSize() {
	return this->size;
}



//setters
void Display::setType(string type) {
	this->type = type;
}

void Display::setResolution(string res) {
	this->resolution = res;
}

void Display::setBrand(string brand) {
	this->brand = brand;
}

void Display::setSize(int size) {
	this->size = size;
}


void print() {

}
 
