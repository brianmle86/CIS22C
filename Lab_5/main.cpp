#include <iostream>
#include <string>
#include <fstream>
#include "person.h"
#include "bst.h"


using namespace std;

int main() {
	fstream dataFile;
	string fileName, name, bday;
	bst<Person>* nameTree;
	bst<Person>* bdayTree;

	cout << "Please enter the name of the file with its path: ";
	cin >> fileName;
	dataFile.open(fileName);
	if (!dataFile) {
		cout << "Error! Could not open file. ";
		return 1;
	}

	return 0;
}