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
	Currency(string x);
	string getNoteName();
	double getValue();
	int getWholeParts();
	int getFractionParts();
	string getCoinName();
	void addWholeParts(int num);
	void addFractionParts(int num);
	void resetToBlankObj();

	friend ostream& operator<<(ostream& output, Currency& obj);
	friend istream& operator>>(istream& input, Currency& obj);
	friend bool operator> (Currency& obj1, Currency& obj2);
	friend bool operator< (Currency& obj1, Currency& obj2);
};


//children classes
class Dollar : public Currency {
public:
	Dollar();
	Dollar(int wholeAmount, int fractionAmount);
};

class Euro : public Currency {
public:
	Euro();
	Euro(int wholeAmount, int fractionAmount);
};

class Yen : public Currency {
public:
	Yen();
	Yen(int wholeAmount, int fractionAmount);
};

class Rupee : public Currency {
public:
	Rupee();
	Rupee(int wholeAmount, int fractionAmount);
};

class Yuan : public Currency {
public:
	Yuan();
	Yuan(int wholeAmount, int fractionAmount);
};

#endif