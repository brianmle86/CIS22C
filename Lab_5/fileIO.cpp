#include "fileIO.h"

//read the file and insert people into bst
void fileIO::readFile(std::fstream &dataFile, bst<Person>*& nameTree, bst<Person>*& bdayTree) {
	if (!(valid(dataFile)))
		return;

	int lineCount = getNumLines(dataFile);
	std::string* nameArr = new std::string[lineCount];
	std::string* bdayArr = new std::string[lineCount];

	//read file while getline

	//insert name and bday to respective trees (reference)
	//use dynamic allocation
	//Person has constructors for name and bday
	dataFile.clear(); //clear the eof flag after using getline
	dataFile.seekg(0, dataFile.beg); //return to beginning of file (this sets read pointer to beg)
	std::string line;
	int i = 0;
	while (getline(dataFile, line)) {
		if (isNum(line[0]))
			bdayArr[i] = line;
		else
			nameArr[i] = line;
		i++;
	}
	
	int n = nameArr->length();
	
	for (int i = 0; i < n; i++) {
		Person temp(0, nameArr[i]);
		temp.setBday(bdayArr[i]);

		nameTree->insert(temp);
		temp.switchPkey();
		bdayTree->insert(temp);
	}
	
	dataFile.clear(); //clear the eof flag after using getline
	dataFile.seekg(0, dataFile.beg); //return to beginning of file (this sets read pointer to beg)
}

//validate each pair of lines, return bool
bool fileIO::valid(std::fstream& dataFile) {
	bool isValid = true;
	std::string line;

	int lineCount = getNumLines(dataFile);

	if (lineCount % 2 != 0)
		return false;

	while (std::getline(dataFile, line)) {
		if (isNum(line[0])) { //if line is birthday
			if (!(line[4] == '-' && line[7] == '-'))
				isValid = false;
		}
		else {
			if (line.length() == 0) //a name needs at least one char
				isValid = false;
		}
	}
	dataFile.clear(); //clear the eof flag after using getline
	dataFile.seekg(0, dataFile.beg); //return to beginning of file (this sets read pointer to beg)
	return isValid;
}

int fileIO::getNumLines(std::fstream& file) {
	int count = 0;
	std::string line;

	while (std::getline(file, line)) {
		count++;
	}
	
	return count;
}

bool fileIO::isNum(char c) {
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}
