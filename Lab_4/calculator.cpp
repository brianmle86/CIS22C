#include <iostream>
#include "calculator.h"

Calculator::Calculator() {

	expression = "";
	//postEx = "";
	//preEx = "";
	result = 0.0;
}

Calculator::Calculator(std::string ex) {
	expression = ex;
}

//Creates individual "tokens" from user inputted expression, which are then enqueued in infixEx
//we assume that user expression's tokens are separated by single space
void Calculator::tokenize() {
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


double Calculator::eval(double a, double b, char op) {
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else if (op == '*')
		return a * b;
	else if (op == '/')
		return a / b;
	else if (op == '%') {
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


void Calculator::getPostfix() {
	Stack<std::string> stack;
	std::cout << "size: " << infixEx.returnSize() << std::endl;
	int n = infixEx.returnSize();
	for (int i = 0; i < n; i++) {
		std::cout << "front: " << infixEx.front() << std::endl;
		
		if (i != 0)
			infixEx.dequeue();
		
		if (!isOperator(infixEx.front())) { //if operand (num)
			postEx.enqueue(infixEx.front());
			//infixEx.dequeue();
		}

		else if (stack.returnSize() == 0 || infixEx.front() == "(") {
			stack.push(infixEx.front());
			//infixEx.dequeue();
		}

		else if (infixEx.front() == ")") {
			while (stack.returnSize() != 0 && stack.peek() != "(") {
				postEx.enqueue(stack.peek());
				stack.pop();
			}
			stack.pop();
			//infixEx.dequeue();
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

std::string Calculator::getPrefix() {
	return "";
}

bool Calculator::isOperator(std::string x) {
	if (x == "+" || x == "-" || x == "*" || x == "/" || x == "(" || x == ")")
		return true;
	else
		return false;
}

void Calculator::displayInfixEx() {
	infixEx.displayQueue();
}

void Calculator::displayPostEx() {
	postEx.displayQueue();
}