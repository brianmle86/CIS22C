#include <iostream>
#include "node.h"
#include "list.h"
#include "currency.h"
#include "sort.h"


using namespace std;
int main() {
	int data;
	string dataString;

	List <int> intList;
	List <string> stringList;
	List <Rupee> rupeeList;



	for (int i = 0; i < 12; i++) {
		cout << "Please enter integer element #" << i + 1 << ": ";
		cin >> data;
		intList.pushNode(data);
	}
	Sort<int>::RecurSelectionSort(intList, 12);


	for (int i = 0; i < 20; i++) {
		cout << "Please enter string element #" << i + 1 << ": ";
		cin >> dataString;
		stringList.pushNode(dataString);
	}
	Sort<string>::RecurSelectionSort(stringList, 12);

	for (int i = 0; i < 11; i++) {
		cout << "Please enter Dollar element #" << i + 1 << " in the form wholeParts, fractionParts: ";
		cin >> data;
		rupeeList.pushNode(data);
	}
	

	cout << "this is lab 3a main\n";
	return 0;
}