#include <iostream>
#include <string>
#include "hashTable.h"
#include "person.h"
#include <fstream>
#include "fileIO.h"

/*
Brian Le
Lab 6
De Anza College
CIS22C
*/
using namespace std;

int main() {
	string fileName;
	ifstream dataFile;

	cout << "Enter path of file: ";
	cin >> fileName;

	
	dataFile.open(fileName);
	if (!dataFile) {
		cout << "Error opening file. \n";
		return 1;
	}

	int numItems = fileIO::getNumLines(dataFile)/2;
	hashTable<string, Person> table(numItems);
	
	fileIO::readFile(dataFile, table);
	dataFile.close();
	
	table.displayTable();


	string day, result;
	int choice;
	bool check = true;
	while (check) {
		cout << "Enter a bday(yyyy-mm-dd) to search: ";
		cin >> day;

		if (table.search(day) == nullptr)
			result = "Invalid Data.";
		else
			result = table.search(day)->value.getName();

		cout << "Search result: " << result << endl;
		cout << "\n1. Search again\n"
			<< "2. Exit\n";
		cin >> choice;

		if (choice == 1)
			continue;
		else
			check = false;
	}

	system("pause");
	return 0;
}