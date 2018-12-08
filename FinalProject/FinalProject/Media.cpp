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
	cout << "Genre: " << this->genre << endl;
	cout << "Rating: " << fixed << setprecision(1) << this->rating << endl;
	cout << "Release Year: " << this->year << endl;
	

}


//Serialize/Deserialize
void Media::write(ostream &f) {
	Inventory::write(f);
	string genre;
	float rating;
	int year;
	string mediaType;
	f.write(reinterpret_cast<char *>(&genre), sizeof(genre));
	f.write(reinterpret_cast<char *>(&rating), sizeof(rating));
	f.write(reinterpret_cast<char *>(&genre), sizeof(genre));
	f.write(reinterpret_cast<char *>(&genre), sizeof(genre));
}	

void Media::read(istream &f) {
	Inventory::read(f);

}
