#pragma once

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "stack.h"
#include "queue.h"

class Calculator {
private:
	std::string expression;
	Queue<std::string> infixEx;
	Queue<std::string> postEx;
	Queue<std::string> preEx;
	double result;

public:
	Calculator();
	Calculator(std::string ex);
	void tokenize();
	double eval(double a, double b, char op); //evaluate (a) (operator) (b)
	int getPrecedence(std::string op); //get operator precedence
	void getPostfix();
	std::string getPrefix();
	bool valid(); //verifies that expression is valid
	bool isOperator(std::string x); //return true if operator, false if operand

	void displayInfixEx();
	void displayPostEx();
};



#endif