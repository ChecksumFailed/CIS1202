#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>



std::vector<std::string> split(const std::string &); //Splits mathmatical expression into individual components



/*
Programmer Name: Ben Scherer
Program # : 13
Course: CIS 1202 Section 502
Date : 11/21/2018
Program Description : Splits mathmatical expression into individual strings and ouputs
*/
int main() {
	std::string expression; //holds expression user inputs
	std::vector<std::string> eVector; //holds expression split into individual strings

	//Get input
	std::cout << "Enter expression to split: ";
	std::getline(std::cin, expression);


	eVector = split(expression);//Split String

	//Output in normal order
	std::cout << std::endl << expression << " in split into individual entities: \n";
	for (std::string s : eVector) {
		std::cout << s << std::endl;
	}

	//Output in reverse order
	std::cout << std::endl << expression << " in split into individual entities(Reverse): \n";
		std::reverse(eVector.begin(), eVector.end());
	for (std::string s : eVector) {
		std::cout << s << std::endl;
	}

	//Wait for user input before exiting.
	std::cout << "Press any key to exit\n";
	getchar();
	return EXIT_SUCCESS;
}

/*
Purpose : Splits mathmatical expression into individual components
Input Parameters :
	string expression - mathmatical expression to split
I/O Parameters : n/a
Output Parameters : 
	string tmpStr - Temporary placeholder for split strings
	vector<string> tmpVector - Temporary vector to hold strings and return
Function Return Value: 
	vector<string> tmpVector - Contains individual strings from expression
*/
std::vector<std::string> split(const std::string &expression) {
	std::string tmpStr;
	std::vector<std::string> tmpVector;

	for (int i = 0; i < expression.length(); i++) { 
		if (std::isdigit(expression[i]) && !std::isspace(expression[i])) //Is a digit and is not a space
			tmpStr += expression[i];
		else if (!std::isdigit(expression[i])) { //Not a digit
			if (tmpStr.length() > 0) { //If string placeholder not empty, push to back of vector and erase placeholder
				tmpVector.push_back(tmpStr);
				tmpStr.erase();
			}
			if (std::isspace(expression[i])) //If a space,  increment counter
				i++;
			tmpVector.push_back(std::string(1,expression[i])); //Push char to back of vector

		}

	}
	if (tmpStr.length() > 0) //check for remaining numbers to push to vector
		tmpVector.push_back(tmpStr);

	return tmpVector;

}