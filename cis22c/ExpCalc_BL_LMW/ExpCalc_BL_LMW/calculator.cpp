#include <iostream>
#include "calculator.h"
/*
Calculator class function definitions.
*/
Calculator::Calculator() {

	expression = "";
	result = 0.0;
}

Calculator::Calculator(std::string ex) {
	expression = ex;
}

std::string Calculator::getExpression() {
	return expression;
}

//Creates individual "tokens" from user inputted expression, which are then enqueued in infixEx
//we assume that user expression's tokens are separated by single space
void Calculator::tokenize() {
	infixEx.clear();
	std::string token = "";
	std::string ex = "";
	for (int i = 0; i < expression.size(); i++) {
		ex.erase();
		ex.push_back(expression[i]);
		if (isOperator(ex)) {
			token.push_back(expression[i]);
			infixEx.enqueue(token);
			token = "";
			i++; //skip next iteration because we know it to be space
			continue;
		}

		if (expression[i] != ' ') {
			token.push_back(expression[i]);
			continue;
		}

		else {
			infixEx.enqueue(token);
			token = "";
			continue;
		}
	}
	infixEx.enqueue(token); //take care of the last token

}

/*
Evaluates for any given a, b, and operator.
*/
double Calculator::eval(double a, double b, std::string op) {
	if (op == "+")
		return a + b;
	else if (op == "-")
		return a - b;
	else if (op == "*")
		return a * b;
	else if (op == "/")
		return a / b;
	else if (op == "%") {
		return (int(a) % int(b)); //c++ does not support modulus with doubles
	}

}

//Gets precedence of operator. 3 highest, 1 lowest
int Calculator::getPrecedence(std::string op) {
	if (op == "^")
		return 3;
	else if (op == "*" || op == "/")
		return 2;
	else if (op == "+" || op == "-")
		return 1;
	else
		return -1;
}

/*
Uses the infix expression queue to get a postfix expression.
*/
void Calculator::getPostfix() {
	Stack<std::string> stack;
	int n = infixEx.returnSize();
	for (int i = 0; i < n; i++) {

		if (i != 0)
			infixEx.dequeue();

		if (!isOperator(infixEx.front())) { //if operand (num)
			postEx.enqueue(infixEx.front());

		}

		else if (stack.returnSize() == 0 || infixEx.front() == "(") {
			stack.push(infixEx.front());

		}

		else if (infixEx.front() == ")") {
			while (stack.returnSize() != 0 && stack.peek() != "(") {
				postEx.enqueue(stack.peek());
				stack.pop();
			}
			stack.pop();

		}

		else { //if operator
			while (stack.returnSize() != 0 && getPrecedence(infixEx.front()) <= getPrecedence(stack.peek())) {
				postEx.enqueue(stack.peek());
				stack.pop();


			}
			stack.push(infixEx.front());
		}


	}
	while (stack.returnSize() != 0) {
		postEx.enqueue(stack.peek());
		stack.pop();
	}
}

/*
Evaluates a postfix expression using stacks.
*/
double Calculator::evalPostfix() {
	double a, b;
	Stack<double> stack;

	int n = postEx.returnSize();
	for (int i = 0; i < n; i++) {
		if (isOperator(postEx.front())) {
			a = stack.peek();
			stack.pop();
			b = stack.peek();
			stack.pop();

			stack.push(eval(b, a, postEx.front()));
			postEx.dequeue();
		}
		else { //if num
			//after hours of endless googling, brian could not find a better solution
			//to this, so the forbidden use of this function had to be done
			stack.push(std::stoi(postEx.front()));
			postEx.dequeue();
		}
	}
	return stack.peek();
}

/*
Uses the infix expression queue to get a prefix expression.
*/
void Calculator::getPrefix() {
	//expression's parenthesis have been changed in main

	//tokenized into infixEx

	infixEx.reverseQueue();

	Stack<std::string> stack;

	int n = infixEx.returnSize();
	for (int i = 0; i < n; i++) {
		if (i != 0)
			infixEx.dequeue();

		if (!isOperator(infixEx.front())) { //if operand (num)
			preEx.enqueue(infixEx.front());

		}

		else if (stack.returnSize() == 0 || infixEx.front() == ")") {
			stack.push(infixEx.front());

		}

		else if (infixEx.front() == "(") {
			while (stack.returnSize() != 0 && stack.peek() != ")") {
				preEx.enqueue(stack.peek());
				stack.pop();
			}
			stack.pop();

		}

		else { //if operator
			while (stack.returnSize() != 0 && getPrecedence(infixEx.front()) <= getPrecedence(stack.peek())) {
				preEx.enqueue(stack.peek());
				stack.pop();
			}
			stack.push(infixEx.front());
		}


	}
	while (stack.returnSize() != 0) {
		preEx.enqueue(stack.peek());
		stack.pop();
	}

	preEx.reverseQueue();

}

/*
Evaluates a prefix expression using stacks.
*/
double Calculator::evalPrefix() {
	Stack<double> stack;
	double a, b;
	preEx.reverseQueue();
	int n = preEx.returnSize();
	for (int i = 0; i < n; i++) {
		if (isOperator(preEx.front())) {
			a = stack.peek();
			stack.pop();
			b = stack.peek();
			stack.pop();

			stack.push(eval(a, b, preEx.front()));
			preEx.dequeue();
		}
		else { //if num
			//after hours of endless googling, there does not seem to be a good
			//option to convert strings to ints or doubles :(
			stack.push(std::stoi(preEx.front()));
			preEx.dequeue();
		}
	}

	return stack.peek();
}

//returns true if x is operator, false otherwise.
bool Calculator::isOperator(std::string x) {
	if (x == "+" || x == "-" || x == "*" || x == "/" || x == "(" || x == ")")
		return true;
	else
		return false;
}

//helps the getPrefix(), because we need to switch out the parenthesis.
void Calculator::replaceParen() {
	int n = expression.size();
	for (int i = 0; i < n; i++) {
		if (expression[i] == '(')
			expression[i] = ')';
		else if (expression[i] == ')')
			expression[i] = '(';

	}

}

//reverse the infix expression queue
void Calculator::reverseInfix() {
	infixEx.reverseQueue();
}


/*
Display functions.
*/
void Calculator::displayInfixEx() {
	infixEx.displayQueue();
}

void Calculator::displayPostEx() {
	postEx.displayQueue();
}

void Calculator::displayPreEx() {
	preEx.displayQueue();
}

/*
Checks if user inputted expression is a valid infix expression.
*/
bool Calculator::valid() {
	std::string ex = "";
	std::string nextAfterOp = "";
	int parenthesis = 0; //count of parenthesis
	for (int i = 0; i < expression.size(); i++) {
		ex.erase();
		ex.push_back(expression[i]);

		if (ex == "(" || ex == ")")
			parenthesis++;

		if ((i + 1) != expression.size() && isOperator(ex))
			nextAfterOp.push_back(expression[i + 2]); //we can assume that succesive operands and operaters are separated by sapces
		if (isOperator(nextAfterOp)) //there is an operator after an operator, invalid
			return false;

	}

	//parenthesis come in pairs, so we check if the count is even
	if (parenthesis % 2 != 0)
		return false;

	return true;
}