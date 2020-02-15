#include <iostream>
#include "calculator.h"

Calculator::Calculator() {

    expression = "";
    postEx = "";
    preEx = "";
    result = 0.0;
}

Calculator::Calculator(string ex) {
    expression = ex;
}

Calculator::eval(double a, double b, char op) {


}

Calculator::getPrecedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}