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
	//input validation - numElements

	cout << "Please enter the desired element type(int, string, Dollar): ";
	cin >> type;
	//input validation - type
	
	if (type == "int") {
		Array<int> dataArray(numElements);
		
		for (int i = 0; i < numElements; i++) {
			cout << "Please enter element #" << i << ": ";
			cin >> dataArray[i];
		}
		Sort<int>::RecurSelectionSort(dataArray, numElements);
		
	}

	else if (type == "string") {
		Array<string> dataArray(numElements);
		for (int i = 0; i < numElements; i++) {
			cout << "Please enter element #" << i << ": ";
			cin >> dataArray[i];
		}
	}

	else if (type == "Dollar") {
		Array<Dollar> dataArray(numElements);
		for (int i = 0; i < numElements; i++) {
			cout << "Please enter element #" << i << "in the form Currency, wholeParts, fractionParts: ";
			cin >> dataArray[i];
		}
	}






	return 0;
}