#include "fileIO.h"

//read the file and insert people into bst
void fileIO::readFile(std::fstream &dataFile, bst<Person>*& nameTree, bst<Person>*& bdayTree) {
	//check if file is valid
	//read file while getline

	//insert name and bday to respective trees (reference)
	//use dynamic allocation
	//Person has constructors for name and bday

	//must have following lines after each use of getline:
	//dataFile.clear(); //clear the eof flag after using getline
	//dataFile.seekg(0, ios::beg); //return to beginning of file (this sets read pointer to beg)
}

//validate each pair of lines, return bool
bool fileIO::valid(std::fstream& dataFile) {
	//read file while getline
	//for each line, parse by char (strings can be indexed)

	//names are followed by bdays, so can't have "Brian" followed by "Ryan"

	//we assume a name is valid if there are no numbers

	//bdays appear yyyy-mm-dd, so check if line[4] and line[7] are '-' && mm <= 12 && dd <= 31

	//return bool
}
