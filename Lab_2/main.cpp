/*
Brian Le, Luke Marshall
De Anza College
CIS22C - Lab 2

*/

#include <iostream>
#include <string>
#include "array.h"
#include "sort.h"
#include "currency.h"
using namespace std;

const int MAX_SORT_SIZE = 16;

int main() {
	int numElements;
	string type;
	
	cout << "Please enter the number of elements you wish to sort: ";
	cin >> numElements;
	
	while (numElements > MAX_SORT_SIZE || numElements <= 1) {
		cout << "Invalid! Try again: ";
		cin >> numElements;
	}
	
	cout << "Please enter the desired element type(int, string, Dollar): ";
	cin >> type;
	while (type != "int" && type != "string" && type != "Dollar") {
		cout << "Invalid type! Try again: ";
		cin >> type;
	}
	
	if (type == "int") {
		Array<int> dataArray(numElements);
		
		for (int i = 0; i < numElements; i++) {
			cout << "Please enter element #" << i + 1 << ": ";
			cin >> dataArray[i];
		}
		Sort<int>::RecurSelectionSort(dataArray, numElements);
		
	}

	else if (type == "string") {
		Array<string> dataArray(numElements);
		for (int i = 0; i < numElements; i++) {
			cout << "Please enter element #" << i + 1 << ": ";
			cin >> dataArray[i];
		}
		Sort<string>::RecurSelectionSort(dataArray, numElements);
	}

	else if (type == "Dollar") {
		Array<Dollar> dataArray(numElements);
		for (int i = 0; i < numElements; i++) {
			cout << "Please enter element #" << i + 1 << " in the form wholeParts, fractionParts: ";
			cin >> dataArray[i];
		}
		Sort<Dollar>::RecurSelectionSort(dataArray, numElements);
	}


	system("pause");
	return 0;
}