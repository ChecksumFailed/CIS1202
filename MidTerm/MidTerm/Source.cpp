
#include <iostream> //cout
#include <iomanip> // used to manipulate cout
#include <string> //needed for string variable
#include <fstream> //file handling
#include <sstream> //used for string bufffer
#include <vector> //needed for vectors
#include <regex> //needed for regular expressions



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
void deleteMovie(string*, int &); //Delete movie from array
void loadDB(string arr[][NUMFIELDS], int &, string, int &, int &); //Read in file and load array
vector<string> parseString(string , char ); //Split delimted string
string getString(); //Get string input and validate
string getString(string); //get string input and validate.  Pass string to match for validation
int getInt(); //Get int input and validate
int getInt(int, int); //get int input and validate range.
void displayMenu(); //display main menu
void addMovie(string *, int&, int &, int &); //Add movie
void printMovies(string *,int,int &, int & ,int &); //print all movies in array
void printMovies(vector<string *>,  int &, int &, int &); //print all movies in vector
int searchMenu(); //Generates menu for searching the 2d array
void updateDB(string*, string, int); //Writes changes to disk.
void searchMovies(string[][NUMFIELDS], int &,int,int);
float getFloat(float, float);  // Get float input and validate.  Also checks range.
void printTableSeperator(int, char); //Prints out seperator for table
void movieActions(string *, int &,int&,int&);//Provides actions that can be taken against an individual movie
void updateMovie(string *, int &, int&); //Provides update functionality
void selectionSortFloat(string[][NUMFIELDS], int, int); //Peform selection sort on 2d array based on float values
void selectionSortString(string[][NUMFIELDS], int, int);//Peform selection sort on 2d array based on string values
void swap(string &, string &); //swap two reference values
void sortMovies(string[][NUMFIELDS], int); //Provides menu and input validation for sorting

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
	int maxTitle = 0, maxGenre = 0; //Max string length for title and genre.  Use for dynamic formatting, since these fields vary based on input

	loadDB(movies, size, dbFile, maxTitle, maxGenre);
	//Load existing movies into array


	//Loop until user exits
	do {
		displayMenu();
		choice = getInt();
		switch (choice) {
		case 1:
			printMovies(&movies[0][0], size,size,maxTitle,maxGenre);break;
		case 2:
			searchMovies(movies, size, maxTitle, maxGenre);	break;
		case 3:
			addMovie(&movies[size][0], size,maxTitle,maxGenre);	break;
		case 4:
			sortMovies(movies, size);
			break;
		default:
			cout << "ERROR: Invalid Choice.  Try Again\n\n";
		}

		
	} while (choice != 5);

	cout << "Writing changes to disk....\n";
	updateDB(&movies[0][0], dbFile, size);

	//pauses program
	cout << "Press enter key to exit program\n";
	cin.get();
	return 0;
}


int searchMenu() {
	cout << "\n1 - Search by Title\n"
		<< "2 - Search by Year\n"
		<< "3 - Search by Genre\n"
		<< "4 - Search by Rating\n"
		<< "5 - Quit\n"
		<< "Enter Choice: ";

	return getInt(1,5);

	   	   
}

/*
Purpose : Allows user to update individual fields of movie
Input Parameters : n/a
I/O Parameters : 
	string *arr - ptr to individual movie
	int &maxTitle - max length of title string
	int maxGenre - max leng=th of genre string
Output Parameters : 
	int choice - user menu choice
Function Return Value: n/a
*/
void updateMovie(string *arr,int &maxTitle,int &maxGenre) {
	int choice;

	
	do {
		cout << "Movie Update Menu\n";
		cout << "1 - Update Title(" << *arr << ")\n"
			<< "2 - Update Year(" << *(arr +1) << ")\n"
			<< "3 - Update Genre(" << *(arr + 2) << ")\n"
			<< "4 - Update Rating(" << *(arr + 3) << ")\n"
			<< "5 - Quit\n";
		cout << "Enter Choice:";
		choice = getInt(1, 5);

		switch (choice) {
		case 1:
			cout << "Enter title of movie: ";
			*arr = getString();;
			if (arr->size() > maxTitle)
				maxTitle = (*arr).size();
			break;

		case 2:
			cout << "\nEnter 4 digit year of movie: ";
			*(arr + 1) = getString("^\\d{4}$");
			break;
		case 3:
			cout << "\nEnter genre of movie: ";
			*(arr + 2) = getString();
			if ((arr + 2)->size() > maxGenre)
				maxGenre = (*(arr + 2)).size();
			break;
		case 4:
			cout << "\nEnter movie rating(1.0-10.0): ";
			string rating = to_string(getFloat(1.0, 10.0)); //Get rating and convert to string
			rating.resize(3); //truncate to one decimal pint
			*(arr + 3) = rating;
			break;
		}
		
		
		cout << endl << endl;
	} while (choice != 5);
	

}

/*
Purpose : Prompts user to choose what field to search on, does input validation, then performs a linear search.  Results are  displayed and user can update from search results
Input Parameters : 
	string movies  - 2d Array of movies
	int size - size of array
	int maxTitle - max length of title string
	int maxGenre -max lenght of genre string
I/O Parameters :n/a
Output Parameters : 
	int choice - Type of search to perform
	int intToMatch - used for Int based comparison
	string strToMatch - used for String based comparison
Function Return Value: 
	vector<string *> - vector of pointers to search results
*/
void searchMovies(string movies[][NUMFIELDS],int &size,int maxTitle, int maxGenre) {
	int choice = searchMenu();
	int intToMatch;
	vector<string *> searchResult;
	string strToMatch; 
	

	switch (choice) {
	case 1 :
		cout << "Enter search string: ";
		strToMatch = getString();
		break;
	case 2:
		cout << "Enter Year to Search: ";
		intToMatch = stoi(getString("^\\d{4}$"));
		break;
	case 3:
		cout << "Enter Genre to Search: ";
		strToMatch = getString();
		break;
	case 4:
		cout << "Enter number from 1 - 10: ";
		 intToMatch = getInt(1,10);
		break;
	case 5:
		return;
	}

	regex strRegEx(".*" + strToMatch + ".*", regex_constants::icase | regex_constants::ECMAScript); //Regex pattern to validate input

	for (int i = 0; i < size; i++) {
			switch (choice) {
			case 1: 
				//cout << movies[i][0] << endl;
				if (regex_match(movies[i][0],strRegEx))
					searchResult.push_back(&movies[i][0]);
				break;
			case 2:
				if (stoi(movies[i][1]) == intToMatch)
					searchResult.push_back(&movies[i][0]);
				break;
			case 3:
				if (regex_match(movies[i][2], strRegEx))
					searchResult.push_back(&movies[i][0]);
				break;
			case 4:
				if (stoi(movies[i][3]) == intToMatch)
					searchResult.push_back(&movies[i][0]);
				break;
			}
		
	}
	cout << endl;
	if (searchResult.size() == 0) {
		cout << "\nNo matches found\n";
		return;
	}

	printMovies(searchResult, size,maxTitle, maxGenre);
	
}

/*
Purpose : Print array of movies, validate input and take action on movie is selected
Input Parameters :
	int printSize - number of entries to print
I/O Parameters :
	string *arr - Vector of pointers
	int & maxTitle - Maximum lengh of title string
	int & maxGenre - Maximum lengh of genre string
	int & arrsize - Current size of array
Output Parameters :
	string *arr - placeholder pointer variable
	int numSeperator - the lengh of table seperator
Function Return Value: n/a
*/
void printMovies(string *arr, int printSize, int &arrSize,int &maxTitle, int &maxGenre) {
	int numSeperator =  3 + maxGenre + maxTitle + 4 + 6 + 5; //number of chars to use for table seperator. maxGenre + maxTitle + year + rating + number of seperators
	
	printTableSeperator(numSeperator, '-');
	cout << endl << left << "|" << setw(3) << "Id" << "|" << setw(maxTitle) << "Title" << "|" << setw(4) << "Year" << "|" <<  setw(maxGenre) << "Genre" << "|" << setw(6) << "Rating" << "|" << endl; //header for table
	printTableSeperator(numSeperator, '-');
	for (int i = 0; i < printSize; i++) {

		cout << "|" <<  left << setw(3) << i << "|" << setw(maxTitle) << *(arr + (i*NUMFIELDS)) << "|" << setw(4) << *(arr + (i*NUMFIELDS) + 1) << "|" << setw(maxGenre) << *(arr + (i*NUMFIELDS) + 2) << "|" << setw(6) << *(arr + (i*NUMFIELDS) + 3) << "|" << endl;
		printTableSeperator(numSeperator, '-');
		
	}
	
	cout << endl;
	if (printSize == 0)
		return;
	string choice;
	bool isValid = false;
	do {
		cout << "Enter Movie ID to update/delete(Q to quit):";
		choice = getString();
		
		try {
			if (choice == "q" || choice == "Q")
				return;
			else if (stoi(choice) >= 0 && stoi(choice) < printSize)
				isValid = true;
			else
				cout << "\nError - Invalid Input.  Try Again\n";
		}
		catch (exception e) {
			cout << "\nError - Invalid Input.  Try Again\n";
		}

	} while (!isValid);

	movieActions((arr + (stoi(choice) * NUMFIELDS)), arrSize,maxTitle,maxGenre);
	
}

/*
Purpose : Print array of movies, validate input and take action on movie is selected
Input Parameters :
I/O Parameters :
	vector<string**> - Vector of pointers 
	int & maxTitle - Maximum lengh of title string
	int & maxGenre - Maximum lengh of genre string
	int & arrsize - Current size of array
Output Parameters :
	string *arr - placeholder pointer variable
	int numSeperator - the lengh of table seperator
	int printSize - number of entries to print
Function Return Value: n/a
*/
void printMovies(vector<string*> searchResult,  int &arrSize, int &maxTitle, int &maxGenre) {

	string *arr; //temporary placeholder for pointer
	int numSeperator = 3 + maxGenre + maxTitle + 4 + 6 + 5; //number of chars to use for table seperator. maxGenre + maxTitle + year + rating + number of seperators
	int printSize = searchResult.size();

	printTableSeperator(numSeperator, '-');
	cout << endl << left << "|" << setw(3) << "Id" << "|" << setw(maxTitle) << "Title" << "|" << setw(4) << "Year" << "|" << setw(maxGenre) << "Genre" << "|" << setw(6) << "Rating" << "|" << endl; //header for table
	printTableSeperator(numSeperator, '-');
	for (int i = 0; i < printSize; i++) {
		arr = searchResult[i];
		cout << "|" << left << setw(3) << i << "|" << setw(maxTitle) << *(arr) << "|" << setw(4) << *(arr + 1) << "|" << setw(maxGenre) << *(arr + 2) << "|" << setw(6) << *(arr + 3) << "|" << endl;
		printTableSeperator(numSeperator, '-');

	}

	cout << endl;
	if (printSize == 0)
		return;
	string choice;
	bool isValid = false;
	do {
		cout << "Enter Movie ID to update/delete(Q to quit):";
		choice = getString();

		try {
			if (choice == "q" || choice == "Q")
				return;
			else if (stoi(choice) >= 0 && stoi(choice) < printSize)
				isValid = true;
			else
				cout << "\nError - Invalid Input.  Try Again\n";
		}
		catch (exception e) {
			cout << "\nError - Invalid Input.  Try Again\n";
		}

	} while (!isValid);

	movieActions(searchResult[stoi(choice)], arrSize,maxTitle,maxGenre);

}

/*
Purpose : Displays actions that can be taken against individual movie, validates input and then call appropriate function
Input Parameters :
I/O Parameters :
	string *movie - pointer to first element of movie to modify
	int & maxTitle - Maximum lengh of title string
	int & maxGenre - Maximum lengh of genre string
	int & arrsize - Current size of array
Output Parameters : n/a
Function Return Value: n/a
*/
void movieActions(string *movie,int &arrSize, int &maxTitle,int &maxGenre) {
	cout << "1 - Update Movie\n"
		<< "2 - Delete Movie\n"
		<< "3 - Quit\n";
	cout << "Enter Choice: ";
	int choice = getInt(1, 3);
	

	switch (choice) {
	case 1: 
		updateMovie(movie, maxTitle, maxGenre);
		break;
	case 2: 
		deleteMovie(movie, arrSize);
	}
	cout << endl;



}

/*
Purpose : Prints table seperator
Input Parameters :
	int numDash - Length of seperator
	char charToPrint - character to use a seperator
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: n/a
*/
void printTableSeperator(int numDash, char charToPrint) {

	for (int k = 0; k < numDash; k++)
		cout << charToPrint;

	cout << endl;
}

/*
Purpose : Adds Movie to 2d array
Input Parameters :
I/O Parameters : 
	string *arr - pointer to next empty element in array
	int & maxTitle - Maximum lengh of title string
	int & maxGenre - Maximum lengh of genre string
	int & size - Current size of array
Output Parameters : n/a
Function Return Value: n/a
*/
void addMovie(string *arr, int &size, int &maxTitle, int &maxGenre) {
	if (size == MAXMOVIES) {
		cout << "The current release has a limitation of : " << MAXMOVIES << ".  Delete entries prior to adding more.";
		return;
	}

	
	cout << "Enter title of movie: ";
	*arr = getString();;
	cout << "\nEnter 4 digit year of movie: ";
	*(arr + 1) = getString("^\\d{4}$");
	cout << "\nEnter genre of movie: ";
	*(arr + 2) = getString(); 
	cout << "\nEnter movie rating(1.0-10.0): ";
	string rating = to_string(getFloat(1.0, 10.0)); //Get rating and convert to string
	rating.resize(3); //truncate to one decimal pint
	*(arr + 3) = rating;
	cout << endl << endl;

	if (arr->size() > maxTitle)
		maxTitle = (*arr).size();
	if ((arr + 2)->size() > maxGenre)
		maxGenre = (*(arr + 2)).size();

	size++;


}
/*
Purpose : Displays main menu
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: n/a
*/
void displayMenu() {
	cout << "\n1 - Print Movie Database\n";
	cout << "2 - Search Movie Database\n";
	cout << "3 - Add Movie\n";
	cout << "4 - Sort Database\n";
	cout << "5 - Quit\n";
	cout << "Enter choice: ";
}

/*
Purpose : Gets int input and validates
Input Parameters : n/a
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value:
	int intHolder - float to validate input against
*/
int getInt() {
	cin.clear();
	int intHolder; //temporary variable for getlne
	bool isValid = false;

	do {
		cin >> intHolder;
		if (cin.fail()) {
			cout << "\nYou have entered invalid input.  Try Again\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			isValid = true;
	} while (!isValid);
	cin.clear();
	cin.ignore();
	return intHolder;

}


/*
Purpose : Gets int input and validates against range
Input Parameters :
	int low - Low end of range
	int high - High end of range
I/O Parameters : n/a
Output Parameters :
Function Return Value:
	int intHolder - float to validate input against
*/
int getInt(int low, int high) {
	cin.clear();
	int intHolder; //temporary variable for getlne
	bool isValid = false;

	do {
		cin >> intHolder;
		if (cin.fail() || intHolder < low || intHolder > high) {
			cout << "\nYou have entered invalid input.  Try Again\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
		}
		else
			isValid = true;
	} while (!isValid);
	cin.clear();
	cin.ignore();
	return intHolder;

}


/*
Purpose : Gets float input and validates against range
Input Parameters :
	float low - Low end of range
	float high - High end of range
I/O Parameters : n/a
Output Parameters :	
Function Return Value:
	float tmpHolder - float to validate input against
*/
float getFloat(float low, float high) {
	cin.clear();
	float tmpHolder; //temporary variable for getlne
	bool isValid = false;

	do {
		cin >> tmpHolder;
		if (cin.fail() || tmpHolder < low || tmpHolder > high) {
			cout << "\nYou have entered invalid input.  Try Again\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			isValid = true;
	} while (!isValid);
	cin.clear();
	cin.ignore();
	return tmpHolder;

}


/*
Purpose : Gets string input and validates 
Input Parameters : n/a	
I/O Parameters : n/a
Output Parameters :
	bool isValid - Used to control loop until valid input is entered
Function Return Value:
	string strHold - holds input from cin
*/
string getString() {
	cin.clear();
	string strHolder; //temporary variable for getlne
	bool isValid = false;

	do {
		getline(cin,strHolder);
		if (cin.fail()) {
			cout << "\nYou have entered invalid input.  Try Again\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			isValid = true;
	} while (!isValid);

	return strHolder;

}

/*
Purpose : Gets string input and validates against parameter
Input Parameters : 
	string strToMatch - string to validate input against
I/O Parameters : n/a
Output Parameters : 
	bool isValid - Used to control loop until valid input is entered
Function Return Value: 
	string strHold - holds input from cin
*/

string getString(string strToMatch) {
	cin.clear();
	string strHold; //temporary variable for getlne
	bool isValid = false;
	regex strRegEx(strToMatch, regex_constants::icase | regex_constants::ECMAScript); //Regex pattern to validate input

	do {
		getline(cin, strHold);
		if (cin.fail() || !regex_match(strHold,strRegEx)) {
			cout << "\nYou have entered invalid input.  Try Again\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			isValid = true;
	} while (!isValid);

	return strHold;

}


/*
Purpose : Delete movie and assoicated fields from 2D array
Input Parameters : n/a
I/O Parameters : 
	string *arr - pointer to first field in movie to delete
	int &size - reference to array size.  Will be decreased by one
Output Parameters : 
	string *lastElement - pointer to last element in array
Function Return Value: n/a
*/

void deleteMovie(string *arr, int &size) {
	size--;
	string *lastElement = arr + (size * NUMFIELDS - 1); //Last ptr in array
	cout << "Deleting: " << *arr << endl;
	for (int i = 0; i < NUMFIELDS; i++) {//clear out values to "Delete" Them.  Memory is already allocated, so this is more a psuedo delete
		*(arr + i) = "";
	}
	
	//Shift all element of array.
	for (arr; (lastElement - arr) >= 0; arr += NUMFIELDS)
	{
		for (int i = 0; i < NUMFIELDS; i++) {
			*(arr + i) = *(arr + (NUMFIELDS + i));
		}
	}
	
}


/*
Purpose : Loads file into 2D array
Input Parameters : 
	string filePath - Path to input file
I/O Parameters : 
	string arr[][NUMFIELDS] - 2D array of movies
	int &size - size of array
	int &maxTitle - Length of longest title string
	int &maxGenre - length of longest genre string
Output Parameters : 
	string strHold - temporary paceholder for input
	ifstrem fileSTream - used to read in file
Function Return Value: n/a
*/
void loadDB (string arr[][NUMFIELDS], int &size, string filePath, int &maxTitle, int &maxGenre) {
	string strHold; //placeholder for getLine
	ifstream fileStream(filePath); //input stream for stats file
	
	//If loading statsFile fails, return.  No dat to laod
	if (fileStream.fail())
		return;

	cout << "Reading in database....\n";

	//Read in line, parse data and populate arrays.  
	while (getline(fileStream, strHold)) {
		
		vector<string> parsedData = parseString(strHold, '|');
		
		if (parsedData.size() == 4) {
	
			try {
				arr[size][0] = parsedData[0]; //Movie Title
				arr[size][1] = parsedData[1]; //Movie Year
				arr[size][2] = parsedData[2]; //Movie Genre
				arr[size][3] = parsedData[3]; //Movie Rating
				if (parsedData[0].size() > maxTitle)
					maxTitle = parsedData[0].length();
				if (parsedData[2].size() > maxGenre)
					maxGenre = parsedData[2].length();
				size++;
			}
			catch (exception e) {
				cout << "Malformed data, unable to load: " << parsedData[0];
			}
			
		}
		
	}


}

/*
Purpose : Splits a string into a vector, based on delimeter passed to function
Input Parameters :
	string strToSplit - String that needs split
	char delim - Delimeter to split string on
I/O Parameters : N/A
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



/*
Purpose : Writes 2d array to file
Input Parameters :
	string *arr: pointer to first element of 2d array
	string file: filename to write changes to
	int size: size of array
I/O Parameters : n/a
Output Parameters : n/a
Function Return Value: n/a
*/
void updateDB(string *arr, string file, int size) {
	ofstream outFile(file);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < NUMFIELDS; j++) {
			outFile << *(arr + (i*NUMFIELDS) + j);
			if (j != NUMFIELDS - 1)
				outFile << "|";
		}
		outFile << endl;
	}
	outFile.close();
}


/*
Purpose : Provides menu and user input validation, then calls the appropriate sort function
Input Parameters :
	int size - number of elements in arrays
	string arr[][NUMFIELDS] - 2D string array
I/O Parameters : n/a	
Output Parameters : n/a
Function Return Value: n/a
*/
void sortMovies(string movies[][NUMFIELDS], int size) {

	cout << "Select value by which to sort on: \n"
		<< " 1 - Title\n"
		<< " 2 - Year\n"
		<< " 3 - Genre\n"
		<< " 4 - Rating\n"
		<< " 5 - Quit\n";
	cout << "Enter Choice: ";
	int choice = getInt(1, 5);

	switch (choice) {
	case 1: 
		selectionSortString(movies, size, choice); break;
	case 2: 
		selectionSortFloat(movies, size, choice); break;
	case 3: 
		selectionSortString(movies, size, choice); break;
	case 4:
		selectionSortFloat(movies, size, choice); break;
	}
}

/*
Purpose : Performs selection sort based on 2d array String values, ascending
Input Parameters :
	int size - number of elements in arrays
I/O Parameters :
	string arr[][NUMFIELDS] - 2D string array
Output Parameters : n/a
Function Return Value: n/a
*/
void selectionSortString(string arr[][NUMFIELDS], int size,int choice) {

	int minIndex;
	string minValue;
	choice--;
	for (int start = 0; start < (size - 1); start++) {
		minIndex = start;
		minValue = arr[start][choice];

		for (int index = start + 1; index < size; index++) {

			if (arr[index][choice].compare(minValue) < 0) {
				minValue = arr[index][choice];
				minIndex = index;

			}
		}
		swap(arr[minIndex][choice], arr[start][choice]);

	}

	cout << endl;
}

/*
Purpose : Swaps string values
Input Parameters : n/a
I/O Parameters :
	int a - first  value to swap
	int b - second  value to swap
Output Parameters : n/a
Function Return Value: n/a
*/
void swap(string &a, string &b) {
	string temp = a;
	a = b;
	b = temp;
}

/*
Purpose : Performs selection sort based on 2d array float values, ascending
Input Parameters :
	int size - number of elements in arrays
I/O Parameters :
	string arr[][NUMFIELDS] - 2D string array
Output Parameters : n/a
Function Return Value: n/a
*/
void selectionSortFloat(string arr[][NUMFIELDS], int size, int choice) {
	choice--;
	int minIndex;
	float minValue;

	for (int start = 0; start < (size - 1); start++) {
		minIndex = start;
		minValue = stof(arr[start][choice]);

		for (int index = start + 1; index < size; index++) {

			if (stof(arr[index][choice]) < minValue) {
				minValue = stof(arr[index][choice]);
				minIndex = index;

			}
		}
		swap(arr[minIndex][choice], arr[start][choice]);

	}

	cout << endl;
}

