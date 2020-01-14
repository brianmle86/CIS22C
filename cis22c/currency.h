#pragma once
#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <iostream>
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
	void addWholeParts(int num);
	void addFractionParts(int num);
	void resetToBlankObj();

	//Currency operator + (Currency const &obj);
	friend ostream& operator<<(ostream& output, Currency& obj);
};


//children classes
class Dollar : public Currency {
public:
	Dollar(int wholeAmount, int fractionAmount);
};

class Euro : public Currency {
public:
	Euro(int wholeAmount, int fractionAmount);
};

class Yen : public Currency {
public:
	Yen(int wholeAmount, int fractionAmount);
};

class Rupee : public Currency {
public:
	Rupee(int wholeAmount, int fractionAmount);
};

class Yuan : public Currency {
public:
	Yuan(int wholeAmount, int fractionAmount);
};

#endif