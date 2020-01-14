#pragma once
#ifndef WALLET_H
#define WALLET_H
#include "currency.h"

using namespace std;

class Wallet {

private:
	Currency** currencies; //pointer magic
	int MAX_CURRENCIES = 5;
	int currenciesSize; //how many currencies there are currently in the array
public:
	Wallet();

	//number of individual currency types whose value is non-zero
	int arraySize();

	//check if a currency type exists with non-zero value in the wallet
	bool doesCurrencyExist(std::string);
	//add money by currency type
	void add(std::string, int, int);

	//remove money by currency type
	void remove(std::string currencyType, int wholeAmount, int fractionAmount);

	//zero out all currency types
	void resetCurrency();

	//check if wallet is empty
	bool isWalletEmpty();
};
#endif
