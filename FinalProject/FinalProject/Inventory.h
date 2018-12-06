#ifndef INVENTORY_H
#define INVENTORY_H
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

#pragma once
class Inventory
{

private: 
	std::string name; //name or descriptor of item
	double purchasePrice; //purchase price of item
	
	double depreciatedPrice; 
	int yearPurchased; //year item purchased
	//Assum 20% rate and 5 years of value. Calculates straight line depreciation for simplicity
	int depreciationYears = 5; //number of years in life of item.
	double depreciationRate = 0.2;
	double depreciationValue;
	

public:
	string iType;//inventory type
	Inventory();
	Inventory(std::string, double, int);
	~Inventory();

	//Getters
	std::string getName();
	double getPurchasePrice();
	int getYearPurchased();
	int getDepreciationYears();

	//setters
	void setName(std::string);
	void setPurchasePrice(double);
	void setYearPurchased(int);
	void setDepreciationYears(int);

	//math
	void calculateDepreciation();
	int getCurrentYear();
	virtual void print();



};

#endif