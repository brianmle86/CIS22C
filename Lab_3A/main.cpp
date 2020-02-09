#include <iostream>

#include "list.h"
#include "currency.h"
//   !!! NOTE !!!
//sorting linked lists is just stupid. too much pointer fuckery
//assignment is asking for sorted and unsorted lists, simply creating the lists here will suffice in demonstrating our List ADT
//despite warnings in assignment, slight modification to currency.cpp is necessary to ensure Rupee objects are functional. 
//operator overloads do not work with inheritance, so "$" was changed to "INR"
//we assume that the assignment means sorted (ascending or descending) or not sorted at all, where (ascending or descending) means the state of being sorted
using namespace std;
int main() {
	int data;
	string dataString;

	List <int> intList;
	List <string> stringList;
	List <Rupee> rupeeList;

	for (int i = 0; i < 20; i++) {
		intList.pushNode(i + 1); //nums 1-20
		intList.setSortStatus(true);
	}

	for (int i = 0; i < 20; i++) {
		//assignment wants strings in descending order.
		//pull 20 strings from a txt file and push to list
		stringList.setSortStatus(true);
	}

	for (int i = 0; i < 10; i++) {
		//assignment calls for unordered list. ask for user input and push to list
		//isSorted is false by default
	}

	
	

	cout << "this is lab 3a main\n";
	return 0;
}