#ifndef MUSIC_H
#define MUSIC_H

#pragma once
#include "Media.h"
class Music :	public Media
{
private:
	string artist;
public:
	Music();
	~Music();
	virtual void print();
	string getArtist();
	void setArtist(string);

	////Seriallize/Deserialize
	virtual void write(ostream &f);
	virtual void read(istream &f);
	
	//input/update
	virtual void populateProperties(); //Propmpts user for input and populates properties.
	virtual void updateItem();

};

#endif //MUSIC_H

Music::Music()
{
	iType = "Music";
}


Music::~Music()
{
}


string Music::getArtist() { return this->artist; }
void Music::setArtist(string artist) { this->artist = artist; }

void Music::print() {
	Media::print();
	cout << setw(20) << left << "Artist " << ": " << this->artist << endl;
}

//Binary file functions
void Music::write(ostream &f) {
	Media::write(f);
	writeString(f, artist);
}

void Music::read(istream &f) {
	Media::read(f);
	artist = readString(f);

}

void Music::populateProperties() {
	Media::populateProperties();
	cout << "Enter Artist name: ";
	this->artist = getString();

}

void Music::updateItem() {
	int choice;
	int maxChoice = 7;
	do {
		cout << "1 - Name(" << this->getName() << ")\n";
		cout << "2 - Purchase Year(" << this->getYearPurchased() << ")\n";
		cout << "3 - Purchase Price(" << this->getPurchasePrice() << ")\n";
		cout << "4 - Genre(" << this->getGenre() << ")\n";
		cout << "5 - Rating(" << this->getRating() << ")\n";
		cout << "6 - Artist(" << this->getArtist() << ")\n";
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
			cout << "Enter new artist: ";
			this->setArtist(getString());
			break;

		}

	} while (choice != maxChoice);
}