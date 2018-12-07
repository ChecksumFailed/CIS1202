#include "Display.h"



Display::Display()
{
}

Display::Display(string name, double price, int yearPurchased, int size, string res, string brand):Inventory(name,price,yearPurchased) {
	this->size = size;
	
	this->resolution = res;
	this->brand = brand;
	iType = "Display";
}
Display::~Display()
{
	iType = "Display";
}


//getters


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


void Display::setResolution(string res) {
	this->resolution = res;
}

void Display::setBrand(string brand) {
	this->brand = brand;
}

void Display::setSize(int size) {
	this->size = size;
}


void Display::print() {
	/*
		int size;
	string type;
	string resolution;
	string brand;*/

	cout << "Size(inches): " << this->size << endl;
	cout << "Resolution: " << this->resolution << endl;
	cout << "Brand: " << this->brand << endl;
}

//Serialize/Deserialize
void Display::write(fstream &f) {
	Inventory::write(f);
}

void Display::read(fstream &f) {
	Inventory::read(f);

}
