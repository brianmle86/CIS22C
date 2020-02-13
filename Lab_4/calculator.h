#pragma once

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "stack.h"
#include "queue.h"

class Calculator {
private:
	std::string expression;
	Stack<char> cStack;
	Queue<char> cQueue;
	std::string postEx;
	std::string preEx;
	double result;

public:
	Calculator();
	Calculator(std::string ex);
	double eval(double a, double b, char op); //evaluate (a) (operator) (b)
	int getPrecedence(); //get operator precedence
	std::string getPostfix();
	std::string getPrefix();
	bool valid(); //verifies that expression is valid
	bool operandOrOperator(); //return true if operator, false if operand

};



#endif