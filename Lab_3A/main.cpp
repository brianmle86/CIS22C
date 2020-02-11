#include <iostream>

#include "list.h"
#include "currency.h"

using namespace std;




int main() {
	int intInput;
	string stringInput;
	Rupee rupeeInput;
	bool menu = true;
	int option, option2;

	// 0 - unsorted, 1 - ascending, 2 - descending
	List <int> intList(1);
	List <string> stringList(2);
	List <Rupee> rupeeList(0);

	cout << "First, please enter all the ints, strings, and rupee objects so the lists can be created.\n\n";
	
	cout << "Please enter 10 ints.\n";
	for (int i = 0; i < 10; i++) {
		cout << "int #" << i + 1 << ": ";
		cin >> intInput;
		while (!cin){
			cout << "Not a valid input. Try again. ";
			cin.clear();
			cin.ignore();
			cin >> intInput;
		}
		intList.insertNode(intInput);
	}
	
	cout << "Please enter 10 strings. ";
	for (int i = 0; i < 10; i++) {
		cout << "string #" << i + 1 << ": ";
		cin >> stringInput;
		stringList.insertNode(stringInput);

	}
	

	
	cout << "Please enter 10 rupee values. Enter in form wholeAmount, fractionAmount. ";
	for (int i = 0; i < 10; i++) {
		cout << "rupee amount #" << i + 1 << ": ";
		cin >> rupeeInput;
		while (!cin) {
			cout << "Not a valid input. Try again. ";
			cin.clear();
			cin.ignore();
			cin >> rupeeInput;
		}
		rupeeList.insertNode(rupeeInput);
	}
	
	
	
	intList.printList();
	stringList.printList();
	rupeeList.printList();
	
	while (menu) {
		cout << "\nChoose an option:\n"
			<< "1 - Add to a list\n"
			<< "2 - remove from a list\n"
			<< "3 - clear a list\n"
			<< "4 - get position of value\n"
			<< "5 - exit\n";
		cin >> option;
		while (option > 5 || option < 1) {
			cout << "Not a valid input. Try again. ";
			cin >> option;
		}

		if (option == 1) {
			cout << "\nWhat would you like to add to?\n"
				<< "1 - int list\n"
				<< "2 - string list\n"
				<< "3 - rupee object list\n";
			cin >> option2;
			while (option2 > 3 || option2 < 1) {
				cout << "Not a valid input. Try again. ";
				cin >> option2;
			}
			if (option2 == 1) {
				cout << "\nint to add: ";
				cin >> intInput;
				intList.insertNode(intInput);
				intList.printList();
			}
			else if (option2 == 2) {
				cout << "\nstring to add: ";
				cin >> stringInput;
				stringList.insertNode(stringInput);
				stringList.printList();
			}
			else if (option2 == 3) {
				cout << "\nrupee object to add: ";
				cin >> rupeeInput;
				rupeeList.insertNode(rupeeInput);
				rupeeList.printList();
			}
		}
		
		else if (option == 2) {
			cout << "\nWhat would you like to remove from?\n"
				<< "1 - int list\n"
				<< "2 - string list\n"
				<< "3 - rupee object list\n";
			cin >> option2;
			while (option2 > 3 || option2 < 1) {
				cout << "Not a valid input. Try again. ";
				cin >> option2;
			}
			if (option2 == 1) {
				cout << "\nposition of int to remove: ";
				cin >> intInput;
				intList.removeNode(intInput);
				intList.printList();
			}
			else if (option2 == 2) {
				cout << "\nposition of string to remove: ";
				cin >> intInput;
				stringList.removeNode(intInput);
				stringList.printList();
			}
			else if (option2 == 3) {
				cout << "\nposition of rupee object to remove: ";
				cin >> intInput;
				rupeeList.removeNode(intInput);
				rupeeList.printList();
			}
		}

		else if (option == 3) {
			cout << "\nWhat would you like to clear?\n"
				<< "1 - int list\n"
				<< "2 - string list\n"
				<< "3 - rupee object list\n";
			cin >> option2;
			while (option2 > 3 || option2 < 1) {
				cout << "Not a valid input. Try again. ";
				cin >> option2;
			}
			if (option2 == 1) {
				intList.deleteList();
				intList.printList();
			}
			else if (option2 == 2) {
				stringList.deleteList();
				stringList.printList();
			}
			else if (option2 == 3) {
				rupeeList.deleteList();
				rupeeList.printList();
			}
		}
		
		else if (option == 4) {
			cout << "where would you like to find a value?\n"
				<< "1 - int list\n"
				<< "2 - string list\n"
				<< "3 - rupee object list\n";
			cin >> option2;
			while (option2 > 3 || option2 < 1) {
				cout << "Not a valid input. Try again. ";
				cin >> option2;
			}
			if (option2 == 1) {
				cout << "value: ";
				cin >> intInput;
				cout << "position: " << intList.findValue(intInput) << endl;
			}
			else if (option2 == 2) {
				cout << "value: ";
				cin >> stringInput;
				cout << "position: " << stringList.findValue(stringInput) << endl;
			}
			else if (option2 == 3) {
				cout << "value: ";
				cin >> rupeeInput;
				cout << "position: " << rupeeList.findValue(rupeeInput) << endl;
			}
		}
		
		else if (option == 5) {
			menu = false;
		}
	}

	system("pause");
	return 0;
}