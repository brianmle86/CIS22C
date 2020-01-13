#pragma once
#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>

using namespace std;

class Currency {
protected:
	string note;
	int wholeParts;
	int fractionParts;
	string coin;
public:
	Currency();
	Currency(int wholeAmount, int fractionAmount);
	string getNoteName();
	double getValue();
	int getWholeParts();
	int getFractionParts();
	string getCoinName();

	Currency operator + (Currency const& obj);
	Currency operator - (Currency const& obj);
	Currency operator < (Currency const& obj);

	friend ostream& operator<<(ostream& output, const Currency& D);
	friend ostream& operator>>(ostream& output, const Currency& D);
};
#endif

