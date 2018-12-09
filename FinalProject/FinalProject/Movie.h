#ifndef MOVIE_H
#define MOVIE_H

#pragma once
#include "Media.h"
class Movie :public Media
{
private:
	int runtime;
public:
	Movie();
	~Movie();
	virtual void print();

	//getter and setters
	int getRuntime();
	void setRuntime(int);

	////Seriallize/Deserialize
	virtual void write(ostream &f);
	virtual void read(istream &f);
	//Input/outputs
	virtual void populateProperties(); //Propmpts user for input and populates properties.
	void updateItem();
};

#endif

Movie::Movie()
{
	iType = "Movie";
}


Movie::~Movie()
{
}

//getter/setters
int Movie::getRuntime() {
	return this->runtime;
}

void Movie::setRuntime(int runtime) {
	this->runtime = runtime;
}

void Movie::print() {
	Media::print();
	cout << setw(20) << left << "Runtime(Minutes) " << ": " << this->runtime << endl;
}

//Binary file functions
void Movie::write(ostream &f) {
	Media::write(f);
	f.write(reinterpret_cast<char *>(&runtime), sizeof(runtime));
}

void Movie::read(istream &f) {
	Media::read(f);
	f.read(reinterpret_cast<char *>(&runtime), sizeof(runtime));

}

void Movie::populateProperties() {
	Media::populateProperties();
	cout << "Enter runtime(minutes): ";
	this->runtime = getInput<int>();
}

void Movie::updateItem() {
	int choice;
	int maxChoice = 7;
	do {
		cout << "1 - Name(" << this->getName() << ")\n";
		cout << "2 - Purchase Year(" << this->getYearPurchased() << ")\n";
		cout << "3 - Purchase Price(" << this->getPurchasePrice() << ")\n";
		cout << "4 - Genre(" << this->getGenre() << ")\n";
		cout << "5 - Rating(" << this->getRating() << ")\n";
		cout << "6 - Runtime(" << this->getRuntime() << ")\n";
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
			this->setPurchasePrice(getInput<double>());
			break;
		case 4:
			cout << "Enter new genre: ";
			this->setGenre(getString());
			break;
		case 5:
			cout << "Enter new rating:  ";
			this->setRating(getInput<float>(1.0, 10.0));
			break;
		case 6:
			cout << "Enter new runtime: ";
			this->setRuntime(getInput<int>());
			break;

		}

	} while (choice != maxChoice);
}