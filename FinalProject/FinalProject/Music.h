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
	virtual void populateProperties(); //Propmpts user for input and populates properties.

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
