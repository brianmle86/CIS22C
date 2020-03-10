#pragma once
#include "fileIO.h"

void fileIO::readFile(std::ifstream& file, hashTable<std::string, Person>& table) {
	std::string nameLine, bdayLine;
	while (!file.eof()) {
		//read 2 lines at a time
		std::getline(file, nameLine);
		std::getline(file, bdayLine);

		//if not valid, replace invalid with line to notify user
		if (!(valid(nameLine, bdayLine))) {
			nameLine = "NOT VALID";
			bdayLine = "0000-00-00";
		}

		Person* temp = new Person;
		temp->setName(nameLine);
		temp->setBday(bdayLine);

		table.insert(*temp);
	}
	file.clear(); //clear the eof flag after using getline
	file.seekg(0, file.beg); //return to beginning of file (this sets read pointer to beg)
}

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

int fileIO::getNumLines(std::ifstream& file) {
	int count = 0;
	std::string line;

	while (std::getline(file, line)) {
		count++;
	}
	file.clear(); //clear the eof flag after using getline
	file.seekg(0, file.beg); //return to beginning of file (this sets read pointer to beg)
	return count;
}

bool fileIO::isNum(char c) {
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}