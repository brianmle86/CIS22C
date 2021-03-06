#include <string>
#include "currency.h"

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



Dollar::Dollar(int wholeAmount, int fractionAmount) : Currency(wholeAmount, fractionAmount) {
	note = "Dollar";
	coin = "cent";
}

Euro::Euro(int wholeAmount, int fractionAmount) : Currency(wholeAmount, fractionAmount) {
	note = "Euro";
	coin = "cent";
}
Yen::Yen(int wholeAmount, int fractionAmount) : Currency(wholeAmount, fractionAmount) {
	note = "Yen";
	coin = "sen";
}
Rupee::Rupee(int wholeAmount, int fractionAmount) : Currency(wholeAmount, fractionAmount) {
	note = "Rupee";
	coin = "paise";
}
Yuan::Yuan(int wholeAmount, int fractionAmount) : Currency(wholeAmount, fractionAmount) {
	note = "Yuan";
	coin = "fen";
}