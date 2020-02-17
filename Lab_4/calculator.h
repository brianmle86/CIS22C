#pragma once

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "stack.h"
#include "queue.h"

class Calculator {
private:
	std::string expression;
	Stack<std::string> cStack;
	Queue<std::string> infixQueue;
	std::string postEx;
	std::string preEx;
	double result;

public:
	Calculator();
	Calculator(std::string ex);
	double eval(double a, double b, char op); //evaluate (a) (operator) (b)
	int getPrecedence(char op); //get operator precedence
	std::string getPostfix();
	std::string getPrefix();
	bool valid(); //verifies that expression is valid
	bool isOperator(char x); //return true if operator, false if operand

};



#endif