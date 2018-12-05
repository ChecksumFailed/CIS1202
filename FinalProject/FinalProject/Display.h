#ifndef DISPLAY_H
#define DISPLAY_H



#pragma once
#include "Inventory.h"
class Display :public Inventory
{
private:
	int size;
	string type;
	string resolution;
	string brand;

public:
	Display();
	Display(string, double, string, int, int, string, string, string);
	~Display();
	string getType();
	string getResolution();
	string getBrand();
	int getSize();
	

	//setters
	void setSize(int);
	void setType(string);
	void setResolution(string);
	void setBrand(string);


	virtual void print();
};
#endif // !DISPLAY_H