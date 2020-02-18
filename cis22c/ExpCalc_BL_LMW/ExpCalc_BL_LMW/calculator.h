#pragma once

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "stack.h"
#include "queue.h"
/*
Calculator class.
Uses stacks and queues to obtain and evaluate postfix and prefix expressions.
*/
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
	std::string getExpression();
	void tokenize();
	double eval(double a, double b, std::string op); //evaluate (a) (operator) (b)
	int getPrecedence(std::string op); //get operator precedence
	void getPostfix();
	void getPrefix();
	double evalPostfix();
	double evalPrefix();
	void replaceParen();
	bool valid(); //verifies that expression is valid
	bool isOperator(std::string x); //return true if operator, false if operand
	void reverseInfix();
	void displayInfixEx();
	void displayPostEx();
	void displayPreEx();
};



#endif