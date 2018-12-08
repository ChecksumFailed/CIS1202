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
	Inventory::print();
	cout << setw(20) << left << "Size(inches) " << ": " << this->size << endl;
	cout << setw(20) << left << "Resolution " << ": " << this->resolution << endl;
	cout << setw(20) << left << "Brand " << ": " << this->brand << endl;
}

//Serialize/Deserialize
void Display::write(ostream &f) {
	Inventory::write(f);
	f.write(reinterpret_cast<char *>(&size), sizeof(size));
//	f.write(reinterpret_cast<char *>(&resolution), sizeof(resolution));
	writeString(f, resolution);
	//f.write(reinterpret_cast<char *>(&brand), sizeof(brand));
	writeString(f, brand);
}

void Display::read(istream &f) {
	Inventory::read(f);
	f.read(reinterpret_cast<char *>(&size), sizeof(size));
	//f.read(reinterpret_cast<char *>(&resolution), sizeof(resolution));
	//f.read(reinterpret_cast<char *>(&brand), sizeof(brand));
	resolution = readString(f);
	brand = readString(f);

}
