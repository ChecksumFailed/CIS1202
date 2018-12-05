#include "Media.h"



Media::Media()
{
}


Media::Media(string name, double price, string location, int yearPurchased, string genre, float rating, int year, string mediaType):Inventory(name, price, location, yearPurchased) {
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

}
