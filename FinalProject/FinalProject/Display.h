#ifndef DISPLAY_H
#define DISPLAY_H



#pragma once
#include "Inventory.h"
class Display :public Inventory
{
private:
	int size;
	string resolution;
	string brand;

public:
	Display();
	Display(string, double, int, int,  string, string);
	~Display();
	string getResolution();
	string getBrand();
	int getSize();
	

	//setters
	void setSize(int);
	void setResolution(string);
	void setBrand(string);


	virtual void print();

	//Binary file functions
	virtual void write(fstream &f);
	virtual void read(fstream &f);
};
#endif // !DISPLAY_H