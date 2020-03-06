#include "fileIO.h"

//read the file and insert people into bst
void fileIO::readFile(std::ifstream &dataFile, bst<Person>& nameTree, bst<Person>& bdayTree) {
	std::string nameLine, bdayLine;
	while (!dataFile.eof()) {
		//read 2 lines at a time
		std::getline(dataFile, nameLine);
		std::getline(dataFile, bdayLine);

		//if not valid, replace invalid with line to notify user
		if (!(valid(nameLine, bdayLine))) {
			nameLine = "NOT VALID";
			bdayLine = "";
		}

		Person temp(nameLine, bdayLine);
		
		//change pkey based on which tree it is being inserted
		temp.setPkey(0);
		nameTree.insert(temp);

		temp.setPkey(1);
		bdayTree.insert(temp);
		
	}
	dataFile.clear(); //clear the eof flag after using getline
	dataFile.seekg(0, dataFile.beg); //return to beginning of file (this sets read pointer to beg)
}

/*
Write to the file
*/
void fileIO::writeFiles(std::ofstream& nameFile, std::ofstream& bdayFile, bst<Person>& nameTree, bst<Person>& bdayTree) {
	nameFile << "Inorder traversal: \n";
	nameTree.writeInOrder(nameFile);

	nameFile << "\nPreorder traversal: \n";
	nameTree.writePreOrder(nameFile);

	nameFile << "\nPostorder traversal: \n";
	nameTree.writePostOrder(nameFile);

	bdayFile << "Inorder traversal: \n";
	bdayTree.writeInOrder(bdayFile);

	bdayFile << "\nPreorder traversal: \n";
	bdayTree.writePreOrder(bdayFile);

	bdayFile << "\nPostorder traversal: \n";
	bdayTree.writePostOrder(bdayFile);


}
//validate a given pair of lines, return bool
bool fileIO::valid(std::string nameLine, std::string bdayLine) {
	bool isValid = true;
	if (nameLine.length() == 0)
		isValid = false;

	if (bdayLine.length() != 10)
		isValid = false;

	if (bdayLine[4] != '-' || bdayLine[7] != '-')
		isValid = false;

	for (int i = 0; i < bdayLine.length(); i++) {
		if (i == 4 || i == 7)
			continue;

		if (!isNum(bdayLine[i]))
			isValid = false;
	}
	return isValid;
}

int fileIO::getNumLines(std::ifstream& dataFile) {
	int count = 0;
	std::string line;

	while (std::getline(dataFile, line)) {
		count++;
	}
	dataFile.clear(); //clear the eof flag after using getline
	dataFile.seekg(0, dataFile.beg); //return to beginning of file (this sets read pointer to beg)
	return count;
}

bool fileIO::isNum(char c) {
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}
