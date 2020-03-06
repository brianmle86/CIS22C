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

	int choice, choice2;
	bool menu = true;
	string n, day;
	while (menu) {
		cout << "Enter a choice:\n"
			<< "1. insert to a tree\n"
			<< "2. remove from a tree\n"
			<< "3. search from tree\n"
			<< "4. exit\n";

		cin >> choice;
		if (choice == 1) {
			cout << "Insert to which tree?\n"
				<< "1. name\n"
				<< "2. bday\n";
			cin >> choice2;

			if (choice2 == 1) {
				cout << "Enter a name and birthday: ";
				cin >> n >> day;
				Person temp(n, day);
				nameTree.insert(temp);
				fileIO::writeFiles(nameFile, bdayFile, nameTree, bdayTree);
			}
			else if (choice2 == 2) {
				cout << "Enter a name and birthday: ";
				cin >> n >> day;
				Person temp(n, day);
				bdayTree.insert(temp);
				fileIO::writeFiles(nameFile, bdayFile, nameTree, bdayTree);
			}
		}
		else if (choice == 2) {
			cout << "Remove from which tree?\n"
				<< "1. name\n"
				<< "2. bday\n";
			cin >> choice2;

			if (choice2 == 1) {
				cout << "Enter a name and birthday: ";
				cin >> n >> day;
				Person temp(n, day);
				nameTree.remove(temp);
				fileIO::writeFiles(nameFile, bdayFile, nameTree, bdayTree);
			}
			else if (choice2 == 2) {
				cout << "Enter a name and birthday: ";
				cin >> n >> day;
				Person temp(n, day);
				bdayTree.remove(temp);
				fileIO::writeFiles(nameFile, bdayFile, nameTree, bdayTree);
			}
		}
		else if (choice == 3) {
			cout << "Search in which tree?\n"
				<< "1. name\n"
				<< "2. bday\n";
			cin >> choice2;

			if (choice2 == 1) {
				cout << "Enter a name and birthday: ";
				cin >> n >> day;
				Person temp(n, day);
				bstNode<Person>* node = nameTree.search(temp);
				cout << "Address is " << node << endl;
			}
			else if (choice2 == 2) {
				cout << "Enter a name and birthday: ";
				cin >> n >> day;
				Person temp(n, day);
				bstNode<Person>* node = bdayTree.search(temp);
				cout << "Address is " << node << endl;
			}
		}
		else if (choice == 4) {
			menu = false;
		}
	}

	
	return 0;
}