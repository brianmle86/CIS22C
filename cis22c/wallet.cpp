#include <iostream>
#include "wallet.h"


Wallet::Wallet() {
    currencies = new Currency * [MAX_CURRENCIES];
    currenciesSize = 0;
}

//number of individual currency types whose value is non-zero
int Wallet::arraySize() {
    int count = 0;
    for (int i = 0; i < MAX_CURRENCIES; i++) {
        if (currencies[i]->getValue() > 0) {
            count++;
        }
    }
    return count;
}

//check if a currency type exists with non-zero value in the wallet
bool Wallet::doesCurrencyExist(std::string currencyType) {
    for (int i = 0; i < arraySize(); i++) {
        if (currencies[i]->getNoteName() == currencyType)
            return true;
        else
            return false;
    }
}

//add money by currency type
void Wallet::add(std::string currencyType, int wholeAmount, int fractionAmount) {
    if (arraySize() < MAX_CURRENCIES) {   //while size of array does not exeed max 
        if (currencyType == "Dollar")
            currencies[arraySize()] = new Dollar(wholeAmount, fractionAmount); //this should create a new object in the array by calling constructor
        else if (currencyType == "Euro")
            currencies[arraySize()] = new Euro(wholeAmount, fractionAmount);
        else if (currencyType == "Rupee")
            currencies[arraySize()] = new Rupee(wholeAmount, fractionAmount);
        else if (currencyType == "Yen")
            currencies[arraySize()] = new Yen(wholeAmount, fractionAmount);
        else if (currencyType == "Yuan")
            currencies[arraySize()] = new Yuan(wholeAmount, fractionAmount);
    }
}

//remove money by currency type
//so this function is the OPPOSITE of the add function
//adding negative value will subtract money
void Wallet::remove(std::string currencyType, int wholeAmount, int fractionAmount) {
    wholeAmount *= -1;
    fractionAmount *= -1;
    add(currencyType, wholeAmount, fractionAmount);
}


//zero out all currency types
void Wallet::resetCurrency() {
    for (int i = 0; i < arraySize(); i++)
        currencies[i] = 0;
}

//check if wallet is empty
bool Wallet::isWalletEmpty() {
    if (currenciesSize = 0)
        return true;
    else
        return false;
}
