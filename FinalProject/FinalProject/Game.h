#ifndef GAME_H
#define GAME_H




#pragma once
#include "Media.h"
class Game :public Media
{
private:
	string platform;
public:
	Game();
	~Game();
	string getPlatform();
	void setPlatform(string);
	virtual void print();

	////Seriallize/Deserialize
	virtual void write(ostream &f);
	virtual void read(istream &f);

	//Input/update
	virtual void populateProperties(); //Propmpts user for input and populates properties.
	virtual void updateItem();
};
#endif // !GAME_H


Game::Game()
{
	iType = "Game";
}


Game::~Game()
{
}
/*
Purpose : gets value of the property - platform
Input Parameters :
I/O Parameters :
Output Parameters :
Function Return Value:
	string - platform
*/
string Game::getPlatform() { return this->platform; }
/*
Purpose : sets value of the property - platform
Input Parameters :
I/O Parameters :
Output Parameters :
string - platform
Function Return Value:
	
*/
void Game::setPlatform(string platform) {this->platform = platform; }

/*
Purpose : Prints the contents of object
Input Parameters :
I/O Parameters : D
Output Parameters :
Function Return Value:
*/
void Game::print() {
	cout << setw(20) << left << "Platform " << ": " << this->platform << endl;
}


//Binary file functions
/*
Purpose : Serializes object properties and writes to binary file
Input Parameters :
	ostream f- filestream object
I/O Parameters :
Output Parameters :

Function Return Value:
*/
void Game::write(ostream &f) {
	Media::write(f);
	//f.write(reinterpret_cast<char *>(&platform), sizeof(platform));
	writeString(f, platform);
}
/*
Purpose : Deserialized data from binary file and populates object values
Input Parameters :
	istream f- filestream object
I/O Parameters :
Output Parameters :

Function Return Value:
*/
void Game::read(istream &f) {
	Media::read(f);
	//f.read(reinterpret_cast<char *>(&platform), sizeof(platform));
	platform = readString(f);


}
/*
Purpose : Prompts user to for values needed to populate new object
Input Parameters :
I/O Parameters :
Output Parameters :
Function Return Value:
*/
void Game::populateProperties(){
	Media::populateProperties();
	cout << "Enter platform(Xbox,pc,etc): ";
	this->platform = getString();
}

/*
Purpose : Allows users to update any propety in class
Input Parameters :
I/O Parameters :
Output Parameters :
	int choice - placeholer for user choice
Function Return Value:
*/
void Game::updateItem() {
	int choice;
	int maxChoice = 7;
	do {
		cout << "1 - Name(" << this->getName() << ")\n";
		cout << "2 - Purchase Year(" << this->getYearPurchased() << ")\n";
		cout << "3 - Purchase Price(" << this->getPurchasePrice() << ")\n";
		cout << "4 - Genre(" << this->getGenre() << ")\n";
		cout << "5 - Rating(" << this->getRating() << ")\n";
		cout << "6 - Platform(" << this->getPlatform() << ")\n";
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
			cout << "Enter new platform: ";
			this->setPlatform(getString());
			break;

		}

	} while (choice != maxChoice);
}