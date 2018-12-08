#ifndef MEDIA_H
#define MEDIA_H



#pragma once
#include "Inventory.h"
class Media :	public Inventory
{
private:
	string genre;
	float rating;
	int year;
	string mediaType;
public:
	Media();
	Media(std::string, double,  int, string, float, int, string);
	~Media();

	string getGenre();
	float getRating();
	int getYear();
	string getMediaType();


	void setGenre(string genre);
	void setRating(float rating);
	void setYear(int year);
	void setMediaType(string mediaType);

	virtual void print();

	//Binary file functions
	virtual void write(ostream &f);
	virtual void read(istream &f);
};

#endif // !MEDIA_H