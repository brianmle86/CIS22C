#include <iostream>
#include "calculator.h"
using namespace std;
/*
Brian Le, Luke Marshall
De Anza College, CIS22C

This program allows the user to enter an infix expression and get the postfix and prefix expressions.
Both resulting expressions are then evaluated.
*/


int main() {
	string userExp;
	
	cout << "Remember to separate ALL operands and operators with a single space.\n"
		<< "Even parenthesis.\n"
		<< "Enter a mathematical expression in standard infix format: ";
	getline(cin, userExp);

	Calculator calc(userExp);

	while (!calc.valid()) {
		getline(cin, userExp);
	}

	calc.tokenize();

	calc.getPostfix();
	cout << "\nPostfix expression: ";
	calc.displayPostEx();

	double postResult = calc.evalPostfix();
	cout << "Postfix result: " << postResult << endl;

	calc.tokenize();

	calc.getPrefix();
	cout << "\nPrefix expression: ";
	calc.displayPreEx();

	double preResult = calc.evalPrefix();
	cout << "Prefix result: " << preResult << endl;

	system("pause");
	return 0;

}