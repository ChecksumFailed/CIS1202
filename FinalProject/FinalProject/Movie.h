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

	//Binary file functions
	virtual void write(fstream &f);
	virtual void read(fstream &f);
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
void Movie::write(fstream &f) {
	Media::write(f);
}

void Movie::read(fstream &f) {
	Media::read(f);

}