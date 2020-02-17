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

double Calculator::eval(double a, double b, char op) {
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else if (op == '/')
        return a / b;

}

//Gets precedence of operator. 3 highest, 1 lowest
int Calculator::getPrecedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}


std::string Calculator::getPostfix() {
    for (int i = 0; i < expression.size(); i++) {
        if (!isOperator(expression[i])) {//if operand
            postEx.push_back(expression[i]); //store operand
            continue;
        }

        if (cStack.returnSize() == 0 || cStack.peek() == "(") {

        }
    }
}

std::string Calculator::getPrefix() {

}

bool Calculator::isOperator(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')')
        return true;
    return false;
}