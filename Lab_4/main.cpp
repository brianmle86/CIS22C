#include <iostream>
#include "calculator.h"
using namespace std;



int main() {
	string userExp;



	cout << "main for lab 4.\n";
	cout << "Enter a mathematical expression in standard infix format. ";
	getline(cin, userExp);

	Calculator calc(userExp);

	calc.tokenize();

	calc.displayInfixEx();

	calc.getPostfix();

	calc.displayPostEx();


	
	system("pause");
	return 0;

}