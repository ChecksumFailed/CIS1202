#include "Media.h"



Media::Media()
{
}


Media::Media(string name, double price,  int yearPurchased, string genre, float rating, int year, string mediaType):Inventory(name, price,  yearPurchased) {
	this->genre = genre;
	this->rating = rating;
	this->year = year;
	this->mediaType = mediaType;
	iType = "Media";
}

Media::~Media()
{
	iType = "Media";
}

/*
Purpose : gets value of the property - genre
	Input Parameters :
I / O Parameters :
Output Parameters :
Function Return Value :
string - genre
*/
string Media::getGenre() { return this->genre; }
/*
Purpose : gets value of the property - rating
	Input Parameters :
I / O Parameters :
Output Parameters :
Function Return Value :
float - rating
*/
float Media::getRating() { return this->rating; }
/*
Purpose : gets value of the property - year
	Input Parameters :
I / O Parameters :
Output Parameters :
Function Return Value :
	int - year
*/
int Media::getYear() { return this->year; }
/*
Purpose : gets value of the property - mediaType
	Input Parameters :
I / O Parameters :
Output Parameters :
Function Return Value :
	string - mediaType
*/
string Media::getMediaType() { return this->mediaType; }

/*
Purpose : sets value of the property - genre
Input Parameters :
I/O Parameters :
Output Parameters :
string - genre
Function Return Value:

*/
void Media::setGenre(string genre) { this->genre = genre; }
/*
Purpose : sets value of the property - rating
Input Parameters :
I/O Parameters :
Output Parameters :
	int -rating
Function Return Value:

*/
void Media::setRating(float rating) { this->rating = rating; }
/*
Purpose : sets value of the property - year
Input Parameters :
I/O Parameters :
Output Parameters :
	int -year
Function Return Value:

*/
void Media::setYear(int year) { this->year = year; }
/*
Purpose : sets value of the property - mediaType
Input Parameters :
I/O Parameters :
Output Parameters :
	string - mediaType
Function Return Value:

*/
void Media::setMediaType(string mediaType) { this->mediaType = mediaType; }
/*
Purpose : Prints the contents of object
Input Parameters :
I/O Parameters : D
Output Parameters :
Function Return Value:
*/
void Media::print() {
	Inventory::print();
	cout << setw(20) << left << "Genre " << ": " << this->genre << endl;
	cout << setw(20) << left << "Rating " << ": " << fixed << setprecision(1) << this->rating << endl;
	cout << setw(20) << left << "Release Year " << ": " << this->year << endl;
	cout << setw(20) << left << "Media Type " << ": " << this->mediaType << endl;
	

}


//Serialize/Deserialize
/*
Purpose : Serializes object properties and writes to binary file
Input Parameters :
	ostream f- filestream object
I/O Parameters :
Output Parameters :

Function Return Value:
*/
void Media::write(ostream &f) {
	Inventory::write(f);

	//f.write(reinterpret_cast<char *>(&genre), sizeof(genre));
	writeString(f, genre);
	f.write(reinterpret_cast<char *>(&rating), sizeof(rating));
	f.write(reinterpret_cast<char *>(&year), sizeof(year));
	//f.write(reinterpret_cast<char *>(&mediaType), sizeof(mediaType));
	writeString(f, mediaType);
}	
/*
Purpose : Deserialized data from binary file and populates object values
Input Parameters :
	istream f- filestream object
I/O Parameters :
Output Parameters :

Function Return Value:
*/
void Media::read(istream &f) {
	Inventory::read(f);
	//f.read(reinterpret_cast<char *>(&genre), sizeof(genre));
	genre = readString(f);
	f.read(reinterpret_cast<char *>(&rating), sizeof(rating));
	f.read(reinterpret_cast<char *>(&year), sizeof(year));
//	f.read(reinterpret_cast<char *>(&mediaType), sizeof(mediaType));
	mediaType = readString(f);

}
/*
Purpose : Prompts user to for values needed to populate new object
Input Parameters :
I/O Parameters :
Output Parameters :
Function Return Value:
*/
void Media::populateProperties() {
	Inventory::populateProperties();
	cout << "Enter genre: ";
	this->genre = getString();
	cout << "Enter release year: ";
	this->year = getInput<int>();
	cout << "Enter rating(1.0-10.0): ";
	this->rating = getInput<float>(1.0, 10.0);
	cout << "Enter media type(cd/dvd/bluray/digital...): ";
	this->mediaType = getString();

}
/*
Purpose : Allows users to update any propety in class
Input Parameters :
I/O Parameters :
Output Parameters :
	int choice - placeholer for user choice
Function Return Value:
*/
void Media::updateItem() {
	int choice;
	int maxChoice = 6;
	do {
		cout << "1 - Name(" << this->getName() << ")\n";
		cout << "2 - Purchase Year(" << this->getYearPurchased() << ")\n";
		cout << "3 - Purchase Price(" << this->getPurchasePrice() << ")\n";
		cout << "4 - Genre(" << this->getGenre() << ")\n";
		cout << "5 - Rating(" << this->getRating() << ")\n";
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
			this->setRating(getInput<float>(1.0,10.0));
			break;

		}

	} while (choice != maxChoice);
}