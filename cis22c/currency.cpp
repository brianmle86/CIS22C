#include <string>
#include "currency.h"

Currency::Currency() { //default constructor
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

double Currency::getValue() {
	return wholeParts + (fractionParts / 100.0);
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

Currency Currency::operator + (const Currency& obj) {
	int sumWholeParts = getWholeParts() + obj.wholeParts;
	int sumFractionParts = getFractionParts() + obj.fractionParts;
	sumWholeParts += sumFractionParts / 100;
	sumFractionParts -= sumFractionParts * 100;

	if (obj.note == "Dollar") {
		return Dollar(sumWholeParts, sumFractionParts);
	}
	if (obj.note == "Euro") {
		return Euro(sumWholeParts, sumFractionParts);
	}
	if (obj.note == "Rupee") {
		return Rupee(sumWholeParts, sumFractionParts);
	}
	if (obj.note == "Yen") {
		return Yen(sumWholeParts, sumFractionParts);
	}
	if (obj.note == "Yuan") {
		return Yuan(sumWholeParts, sumFractionParts);
	}
	Currency newSum;

}

Currency Currency::operator - (Currency const& obj) {
	return obj;
}
Currency Currency::operator < (Currency const& obj) {
	return obj;
}
ostream& operator<<(ostream& output, const Currency& D) {

}

ostream& operator>>(ostream& output, const Currency& D) {

}

//derived class constructors
Currency::Dollar(int wholeAmount, int fractionAmount){ : Currency(wholeAmount, fractionAmount) {
	note = "Dollar";
	coin = "cent";
}

Currency::Euro(int wholeAmount, int fractionAmount) : Currency(wholeAmount, fractionAmount) {
	note = "Euro";
	coin = "cent";
}
Currency:Yen(int wholeAmount, int fractionAmount) : Currency(wholeAmount, fractionAmount) {
	note = "Yen";
	coin = "sen";
}
Currency::Rupee(int wholeAmount, int fractionAmount) : Currency(wholeAmount, fractionAmount) {
	note = "Rupee";
	coin = "paise";
}
Currency::Yuan(int wholeAmount, int fractionAmount) : Currency(wholeAmount, fractionAmount) {
	note = "Yuan";
	coin = "fen";
}
