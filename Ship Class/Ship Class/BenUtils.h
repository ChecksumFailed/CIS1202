#ifndef BENUTILS_H
#define BENUTILS_H
#include <iostream>
#include <iomanip>
#include <regex>

using namespace std;

#pragma once
class BenUtils
{
public:
	BenUtils();
	~BenUtils();
	static int getInt(); //get int user input and validate
	static double getDouble();//get double user input and validate
	static int getInt(int, int); //get int user input and validate based on range
	static string getString(); //Get string input and validate
	static string getString(string); //get string input and validate.  Pass string to match for validation

};

#endif // !BENUTILS_H