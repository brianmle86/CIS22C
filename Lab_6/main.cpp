#include <iostream>
#include <string>
#include "list.h"
#include "hashTable.h"
#include "person.h"

/*
Brian Le
Lab 6
De Anza College
CIS22C
*/
using namespace std;

int main() {
	cout << "lab 6 main\n";
	hashTable<string, Person> table(10);
	Person B("B", "2000-08-06");

	return 0;
}