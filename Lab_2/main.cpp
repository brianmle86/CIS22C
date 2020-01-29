#include <iostream>
#include <string>
#include "array.h"
#include "sort.h"
#include "currency.h"
using namespace std;

const int MAX_SORT_SIZE = 16;
/*
TODO:
-find a way to have cout only in main
-finish up input validation in main
-file I/O
-documentation
*/
int main() {
	int numElements;
	string type;
	bool flag = true;
	cout << "Please enter the number of elements you wish to sort: ";
	cin >> numElements;
	
	while (numElements > MAX_SORT_SIZE || numElements <= 1) {
		cout << "Invalid! Try again: ";
		cin >> numElements;
	}
	
	
	
	
	
	
	
	cout << "Please enter the desired element type(int, string, Dollar): ";
	cin >> type;
	//input validation - type
	
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






	return 0;
}