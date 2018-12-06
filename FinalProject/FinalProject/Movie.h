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