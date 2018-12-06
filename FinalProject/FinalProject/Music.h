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
	cout << "Artist: " << this->artist << endl;
}
