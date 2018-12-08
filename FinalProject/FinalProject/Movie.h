#ifndef MOVIE_H
#define MOVIE_H

#pragma once
#include "Media.h"
class Movie :public Media
{
private:
	int runtime;
public:
	Movie();
	~Movie();
	virtual void print();

	////Seriallize/Deserialize
	virtual void write(ostream &f);
	virtual void read(istream &f);
};

#endif

Movie::Movie()
{
	iType = "Movie";
}


Movie::~Movie()
{
}

void Movie::print() {
	cout << "Runtime(Minutes): " << endl;
}

//Binary file functions
void Movie::write(ostream &f) {
	Media::write(f);
}

void Movie::read(istream &f) {
	Media::read(f);

}