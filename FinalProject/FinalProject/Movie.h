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
};

#endif

Movie::Movie()
{
	iType = "Movie";
}


Movie::~Movie()
{
}
