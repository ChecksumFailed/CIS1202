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
	virtual void write(ostream &f); //seriallizes data and writes to file
	virtual void read(istream &f); //deserializes data nd writes to fiel

	virtual void populateProperties(); //Propmpts user for input and populates properties.
};

#endif // !MEDIA_H