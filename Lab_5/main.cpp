#include <iostream>
#include <string>
#include <fstream>
#include "person.h"
#include "bst.h"
#include "fileIO.h"

using namespace std;

int main() {
	ifstream dataFile;
	ofstream nameFile, bdayFile;
	string fileName, name, bday;
	bst<Person> nameTree;
	bst<Person> bdayTree;

	nameFile.open("nameTree.txt");
	bdayFile.open("bdayTree.txt");

	//enter test.txt
	cout << "Please enter the path of the file: ";
	cin >> fileName;
	dataFile.open(fileName);
	
	if (!dataFile) {
		cout << "Error! Could not open file. ";
		return 1;
	}
	
	fileIO::readFile(dataFile, nameTree, bdayTree);
	fileIO::writeFiles(nameFile, bdayFile, nameTree, bdayTree);

	cout << "Inorder traversal:\n";
	nameTree.displayInOrder();

	cout << "\nPreorder traversal:\n";
	nameTree.displayPreOrder();

	cout << "\nPostorder traversal:\n";
	nameTree.displayPostOrder();



	Person temp("Brian", "2000-08-06");
	temp.setPkey(0);
	
	system("pause");
	return 0;
}