
#include <iostream> //cout
#include <iomanip> // used to manipulate cout
#include <string> //needed for string variable
#include <fstream> //file handling
#include <sstream> //used for string bufffer
#include <vector>
#include <regex>



using namespace std;

//Global Constants
const int NUMFIELDS = 4; //Number of fields stored in 2d array
const int MAXMOVIES = 500; //Maximum size of database
/*
0 - Title
1 - Year
2 - Genre
3 - Rating
*/

//Functions
void deleteMovie(string[][NUMFIELDS], int, int &); //Delete movie from array
void loadDB(string arr[][NUMFIELDS], int &, string); //Read in file and load array
vector<string> parseString(string , char ); //Split delimted string
string getString(); //Get string input and validate
string getString(string); //get string input and validate.  Pass string to match for validation
int getInt(); //Get int input and validate
int getInt(int, int); //get int input and validate range.
void displayMenu(); //display main menu
void addMovie(string *, int&); //Add movie
void printMovies(string *,int); //print all movies in array
void searchMenu(string[][NUMFIELDS], int); //Generates menu for searching the 2d array
void updateDB(string*, string, int); //Writes changes to disk.
vector<string> searchMovies(string[][NUMFIELDS], int, int);

/*
Programmer Name: Ben Scherer
Program # : 3
Course: CIS 1202 Section 502
Date : 10/7/2018
Program Description : Mid Term prooject.  Movie database.  Supports CRUD operations and peristent changes.  Heavily leverages pointers and 2D arrays per requirements
*/
int main() {
	string movies[MAXMOVIES][NUMFIELDS]; //2d array to store movie details.  
	int size = 0; //current size of array
	int choice; //stores user input
	string dbFile = "movieDB.dat";
	 

	loadDB(movies, size, dbFile);
	//Load existing movies into array


	//Loop until user exits
	do {
		displayMenu();
		choice = getInt();
		switch (choice) {
		case 1:
			printMovies(&movies[0][0], size);
			break;
		case 2:
			
			break;
		case 3:
			addMovie(&movies[size][0], size);
			break;
		case 4:
			break;
		default:
			cout << "ERROR: Invalid Choice.  Try Again\n\n";
		}

		
	} while (choice != 4);

	cout << "Writing changes to disk....";
	updateDB(&movies[0][0], dbFile, size);

	//pauses program
	cout << "Press enter key to exit program\n";
	cin.get();
	return 0;
}


void searchMenu(string movies[][NUMFIELDS], int size) {
	int choice;
	cout << "\n 1 - Search by Title\n"
		<< "2 - Search by Year\n"
		<< "3 - Search by Genre\n"
		<< "4 - Search by Rating\n"
		<< "5 - Quit\n"
		<< "Enter Choice: ";

	do {
		choice = getInt();
		if (choice >= 1 && choice < 5)
			searchMovies(movies, size, choice);
		else if (choice == 5)
			return;
		else
			cout << "Invalid Choice.  Try again: ";


	} while (choice != 5);

}

vector<string> searchMovies(string movies[][NUMFIELDS],int size,int choice) {
	vector<string> searchResult;
	return searchResult;;
}
void printMovies(string *arr, int size) {
	int counter = 0;


	cout << left << setw(20) << "Title" << setw(20) << "Year" << setw(20) << "Genre" << setw(20) << "Rating" << endl;

	for (int i = 0; i < size; i++) {
		cout << left;
		for (int j = 0; j < NUMFIELDS; j++) {
			cout << setw(20) << *(arr+ (i*NUMFIELDS) + j);
		}
		cout << endl;
	}


	cout << endl;
	
	
}

void addMovie(string *arr, int &size) {
	if (size == MAXMOVIES) {
		cout << "The current release has a limitation of : " << MAXMOVIES << ".  Delete entries prior to adding more.";
		return;
	}

	cout << size << endl;
	cout << "Enter title of movie: ";
	*arr = getString();;
	cout << arr << "\t" << *arr <<endl;
	cout << "\nEnter 4 digit year of movie: ";
	*(arr + 1) = getString("^\\d{4}$");
	cout << "\nEnter genre of movie: ";
	*(arr + 2) = getString();
	cout << "\nEnter movie rating(1-10): ";
	*(arr + 3) = to_string(getInt(1, 10));
	cout << endl << endl;

	size++;


}

void displayMenu() {
	cout << "\n1 - Print Movie Database\n";
	cout << "2 - Search Movie Database\n";
	cout << "3 - Add Movie\n";
	cout << "4 - Quit\n";
	cout << "Enter choice: ";
}


int getInt() {
	cin.clear();
	int intHolder; //temporary variable for getlne
	bool isValid = false;

	do {
		cin >> intHolder;
		if (cin.fail()) {
			cin.clear();
			cout << "\nYou have entered invalid input.  Try Again\n";
		}
		else
			isValid = true;
	} while (!isValid);
	cin.clear();
	cin.ignore();
	return intHolder;

}

int getInt(int low, int high) {
	cin.clear();
	int intHolder; //temporary variable for getlne
	bool isValid = false;

	do {
		cin >> intHolder;
		if (cin.fail() || intHolder < low || intHolder > high) {
			cin.clear();
			cout << "\nYou have entered invalid input.  Try Again\n";
		}
		else
			isValid = true;
	} while (!isValid);
	cin.clear();
	cin.ignore();
	return intHolder;

}

string getString() {
	cin.clear();
	string strHolder; //temporary variable for getlne
	bool isValid = false;

	do {
		getline(cin,strHolder);
		if (cin.fail()) {
			cin.clear();
			cout << "\nYou have entered invalid input.  Try Again\n";
		}
		else
			isValid = true;
	} while (!isValid);

	return strHolder;

}

string getString(string strToMatch) {
	cin.clear();
	string strHold; //temporary variable for getlne
	bool isValid = false;
	regex strRegEx(strToMatch, regex_constants::icase | regex_constants::ECMAScript); //Regex pattern to validate input

	do {
		getline(cin, strHold);
		if (cin.fail() || !regex_match(strHold,strRegEx)) {
			cin.clear();
			cout << "\nYou have entered invalid input.  Try Again\n";
		}
		else
			isValid = true;
	} while (!isValid);

	return strHold;

}

void deleteMovie(int arr[][NUMFIELDS], int index, int &size) {

	for (int i = index; i < size; i++) {
		for (int j = 0; j < NUMFIELDS; j++) {
			arr[i][j] = arr[i + 1][j];
		}
	}
	for (int i = 0; i < NUMFIELDS; i++) {
		arr[size - 1][i] = NULL;
	}
	size -= NUMFIELDS;


}

void loadDB (string arr[][NUMFIELDS], int &size, string filePath) {
	string strHold; //placeholder for getLine
	ifstream fileStream(filePath); //input stream for stats file
	


	//If loading statsFile fails, return.  No dat to laod
	if (fileStream.fail())
		return;

	cout << "Reading stats file....\n";

	//Read in line, parse data and populate arrays.  
	while (getline(fileStream, strHold)) {
		//cout << "Line: " << strHold << endl;
		vector<string> parsedData = parseString(strHold, '|');
		if (parsedData.size() > 0) {
			arr[size][0] = parsedData[0]; //Movie Title
			arr[size][1] = parsedData[1]; //Movie Year
			arr[size][2] = parsedData[2]; //Movie Genre
			arr[size][3] = parsedData[3]; //Movie Rating
			
			size++;
		}
		
	}


}

/*
Purpose : Splits a string into a vector, based on delimeter passed to function
Input Parameters :
	string strToSplit - String that needs split
	char delim - Delimeter to split string on


I/O Parameters :

Output Parameters :
	istringstream strStream - string stream var, needed to split
	string tempStr - temporary holder for splitting string
	vector<string> parsedItems - vector to hold the parsed data
*/
vector<string> parseString(string strToSplit, char delim) {
	istringstream strStream(strToSplit); //string stream var, needed to split
	string tempStr; //temporary holder for splitting string
	vector<string> parsedItems; //vector to hold the parsed data
	while (getline(strStream, tempStr, delim)) {
		parsedItems.push_back(tempStr);

	}

	return parsedItems;
}


//write changes to db file
void updateDB(string *arr, string file, int size) {
	ofstream outFile(file);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < NUMFIELDS; j++) {
			outFile << *(arr + (i*NUMFIELDS) + j);
			if (i != NUMFIELDS - 1)
				outFile << "|";
		}
		outFile << endl;
	}
	outFile.close();
}