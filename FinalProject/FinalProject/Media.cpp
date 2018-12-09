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


string Media::getGenre() { return this->genre; }
float Media::getRating() { return this->rating; }
int Media::getYear() { return this->year; }
string Media::getMediaType() { return this->mediaType; }


void Media::setGenre(string genre) { this->genre = genre; }
void Media::setRating(float rating) { this->rating = rating; }
void Media::setYear(int year) { this->year = year; }
void Media::setMediaType(string mediaType) { this->mediaType = mediaType; }

void Media::print() {
	Inventory::print();
	cout << setw(20) << left << "Genre " << ": " << this->genre << endl;
	cout << setw(20) << left << "Rating " << ": " << fixed << setprecision(1) << this->rating << endl;
	cout << setw(20) << left << "Release Year " << ": " << this->year << endl;
	

}


//Serialize/Deserialize
void Media::write(ostream &f) {
	Inventory::write(f);

	//f.write(reinterpret_cast<char *>(&genre), sizeof(genre));
	writeString(f, genre);
	f.write(reinterpret_cast<char *>(&rating), sizeof(rating));
	f.write(reinterpret_cast<char *>(&year), sizeof(year));
	//f.write(reinterpret_cast<char *>(&mediaType), sizeof(mediaType));
	writeString(f, mediaType);
}	

void Media::read(istream &f) {
	Inventory::read(f);
	//f.read(reinterpret_cast<char *>(&genre), sizeof(genre));
	genre = readString(f);
	f.read(reinterpret_cast<char *>(&rating), sizeof(rating));
	f.read(reinterpret_cast<char *>(&year), sizeof(year));
//	f.read(reinterpret_cast<char *>(&mediaType), sizeof(mediaType));
	mediaType = readString(f);

}

void Media::populateProperties() {
	Inventory::populateProperties();
	cout << "Enter genre: ";
	this->genre = getString();
	cout << "Enter release year: ";
	this->year = getInput<int>();
	cout << "Enter rating(1.0-10.0): ";
	this->rating = getInput<double>(1.0, 10.0);
	cout << "Enter media type(cd/dvd/bluray/digital...): ";
	this->mediaType = getString();

}