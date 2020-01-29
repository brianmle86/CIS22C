#include <string>
#include "currency.h"
#include <iostream>
Currency::Currency() {
	note = "";
	wholeParts = 0;
	fractionParts = 0;
	coin = "";

}

Currency::Currency(int wholeAmount, int fractionAmount) {
	wholeParts = wholeAmount;
	fractionParts = fractionAmount;
}
Currency::Currency(string x) {
	note = x;
}
string Currency::getNoteName() {
	return note;
}
//gets value of a currency as a double i.e. x.xx
double Currency::getValue() {
	return double(wholeParts + (fractionParts * 0.01));
}

int Currency::getWholeParts() {
	return wholeParts;
}

int Currency::getFractionParts() {
	return fractionParts;
}

string Currency::getCoinName() {
	return coin;
}

void Currency::addWholeParts(int num) {
	wholeParts += num;
}

void Currency::addFractionParts(int num) {
	fractionParts += num;
}

void Currency::resetToBlankObj() {
	note = "";
	wholeParts = 0;
	fractionParts = 0;
	coin = "";
}
ostream& operator<<(ostream& output, Currency& obj) {
	output << ((double(obj.wholeParts) + (obj.fractionParts / 100.0)));
	return output;
}

istream& operator>>(istream& input, Currency& obj) { //friend function can access currency members directly
	input >> obj.wholeParts >> obj.fractionParts;
	return input;
	
}

bool operator> (Currency& obj1, Currency& obj2) {
	return ((double(obj1.wholeParts) + (obj1.fractionParts/100.0)) > (double(obj2.wholeParts) + (obj2.fractionParts / 100.0)));
}

bool operator< (Currency& obj1, Currency& obj2) {
	return ((double(obj1.wholeParts) + (obj1.fractionParts / 100.0)) > (double(obj2.wholeParts) + (obj2.fractionParts / 100.0)));
}





Dollar::Dollar() : Currency("Dollar") {};
Dollar::Dollar(int wholeAmount, int fractionAmount) : Currency(wholeAmount, fractionAmount) {
	note = "Dollar";
	coin = "cent";
}

Euro::Euro() : Currency() {};
Euro::Euro(int wholeAmount, int fractionAmount) : Currency(wholeAmount, fractionAmount) {
	note = "Euro";
	coin = "cent";
}

Yen::Yen() : Currency() {};
Yen::Yen(int wholeAmount, int fractionAmount) : Currency(wholeAmount, fractionAmount) {
	note = "Yen";
	coin = "sen";
}

Rupee::Rupee() : Currency() {};
Rupee::Rupee(int wholeAmount, int fractionAmount) : Currency(wholeAmount, fractionAmount) {
	note = "Rupee";
	coin = "paise";
}

Yuan::Yuan() : Currency() {};
Yuan::Yuan(int wholeAmount, int fractionAmount) : Currency(wholeAmount, fractionAmount) {
	note = "Yuan";
	coin = "fen";
}