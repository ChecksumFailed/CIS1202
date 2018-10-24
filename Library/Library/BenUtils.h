#ifndef BENUTILS_H
#define BENUTILS_H
#include <iostream>
#include <iomanip>

using namespace std;

#pragma once
class BenUtils
{
public:
	BenUtils();
	~BenUtils();
	int getInt(); //get int user input and validate
	double getDouble();//get double user input and validate
	int getInt(int, int); //get int user input and validate based on range

};

#endif // !BENUTILS_H