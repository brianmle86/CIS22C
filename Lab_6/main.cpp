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
	hashTable<string, Person> table(100);
	Person B("Brian", "2000-08-06");
	table.insert(B);
	cout << table.search("2000-08-06")->value.getName() << endl;
	return 0;
}