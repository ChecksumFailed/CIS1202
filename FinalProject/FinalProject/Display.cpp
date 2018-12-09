#include "Display.h"



Display::Display()
{
	iType = "Display";
}

Display::Display(string name, double price, int yearPurchased, int size, string res, string brand):Inventory(name,price,yearPurchased) {
	this->size = size;
	
	this->resolution = res;
	this->brand = brand;
	iType = "Display";
}
Display::~Display()
{
	
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


void Display::populateProperties() {
	Inventory::populateProperties();
	cout << "Enter size of display(inches): ";
	this->size = getInput<int>();
	cout << "Enter resolution(1080p,4k...): ";
	this->resolution = getString();
	cout << "Enter brand/manufacturer: ";
	this->brand = getString();

}


void Display::updateItem() {
	int choice;
	int maxChoice = 7;
	do {
		cout << "1 - Name(" << this->getName() << ")\n";
		cout << "2 - Purchase Year(" << this->getYearPurchased() << ")\n";
		cout << "3 - Purchase Price(" << this->getPurchasePrice() << ")\n";
		cout << "4 - Resolution(" << this->getResolution() << ")\n";
		cout << "5 - Brand(" << this->getBrand() << ")\n";
		cout << "6 - Size(" << this->getSize() << ")\n";
		cout << maxChoice << " - Exit\n";
		cout << "Enter Choice: ";
		choice = getInput<int>(1, maxChoice);
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
			this->setYearPurchased(getInput<double>());
			break;
		case 4:
			cout << "Enter new resolution: ";
			this->setResolution(getString());
			break;
		case 5:
			cout << "Enter new brand:  ";
			this->setBrand(getString());
			break;
		case 6:
			cout << "Enter new Size(inches): ";
			this->setYearPurchased(getInput<int>());
			break;

		}

	} while (choice != maxChoice);
}