#include <iostream>
#include <string>
#include <fstream>
#include "person.h"
#include "hashTable.h"
#include "fileIO.h"

/*
Brian Le
Lab 6
De Anza College
CIS22C
To replace Lab 5.
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

	int numItems = fileIO::getNumLines(dataFile) / 2;
	hashTable<string, Person> table(numItems);

	fileIO::readFile(dataFile, table);
	dataFile.close();

	table.display();
	cout << "\n-->Table loaded with " << table.getNumCollisions()
		<< " collisions.\n";

	string day, result;
	int choice;
	bool menu = true;
	while (menu) {
		cout << "\n Select an option:\n"
			<< "1. Search\n"
			<< "2. remove\n"
			<< "3. Exit\n";
		cin >> choice;

		if (choice == 1) {
			cout << "Enter a bday(yyyy-mm-dd) to search: ";
			cin >> day;

			if (table.search(day) == nullptr)
				result = "Invalid Data.";
			else
				result = table.search(day)->value.getName();

			cout << "Search result: " << result << endl;
		}
		else if (choice == 2) {
			cout << "Enter a bday(yyyy-mm-dd) to remove: ";
			cin >> day;

			//remove function returns a bool to indicate success
			if (!table.remove(day))
				cout << "Invalid Data.\n";
			else {
				cout << "Remove sucessful.\n";
				table.display();
			}
			
		}
		else
			menu = false;
	}

	system("pause");
	return 0;
}