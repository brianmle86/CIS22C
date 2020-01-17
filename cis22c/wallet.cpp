#include <iostream>
#include "wallet.h"


Wallet::Wallet() {
    currencies = new Currency *[MAX_CURRENCIES];
    for (int i = 0; i < 5; i++) {
        currencies[i] = nullptr;
    }
    currenciesSize = 0;
}

//number of individual currency types whose value is non-zero
int Wallet::arraySize() {
    int count = 0;
    for (int i = 0; i < MAX_CURRENCIES; i++) {
        if (currencies[i] != nullptr) {
            count++;
        }
    }
    return count;
}

//check if a currency type exists
bool Wallet::doesCurrencyExist(std::string currencyType) {
    for (int i = 0; i < arraySize(); i++) {
        if (currencies[i]->getNoteName() == currencyType)
            return true;
        else
            return false;
    }
    return false; //if arraySize() returns 0
}

//add money by currency type
void Wallet::addCurrency(std::string currencyType, int wholeAmount, int fractionAmount) {
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
    currenciesSize++;
}
//add money to existing currency type
void Wallet::add(std::string currencyType, int wholeAmount, int fractionAmount) {
    for (int i = 0; i < arraySize(); i++) {
        if (currencyType == currencies[i]->getNoteName()) {
            currencies[i]->addWholeParts(wholeAmount);
            currencies[i]->addFractionParts(fractionAmount);
        }
    }
}
//remove money by currency type
void Wallet::remove(std::string currencyType, int wholeAmount, int fractionAmount) {
    if (doesCurrencyExist(currencyType) == false) {
        cout << "Cannot withdraw!\n";
        return;
    }
    int index;
    for (int i = 0; i < arraySize(); i++) {
        if (currencies[i]->getNoteName() == currencyType)
            index = i;
    }
    add(currencyType, (wholeAmount * -1), (fractionAmount * -1));
    if ((currencies[index]->getWholeParts() + (currencies[index]->getFractionParts() * 0.01)) < 0) {
        //currency has negative value, reverse remove and notify user
        add(currencyType, wholeAmount, fractionAmount);
        cout << "Cannot withdraw more than you have!\n";
    }
    if (checkIfZero(currencyType)) {
        currencies[index] = nullptr;
        currenciesSize--;
    }

    
}
//checks if given currency type has zero value in wallet
bool Wallet::checkIfZero(std::string currencyType) {
    if (currenciesSize == 0)
        return false; //nothing in wallet
    int index;
    for (int i = 0; i < arraySize(); i++) {
        if (currencies[i]->getNoteName() == currencyType)
            index = i;
    }
    //first check if currency type actually exists in wallet
    if (doesCurrencyExist(currencyType)) {
        if ((currencies[index]->getWholeParts() + (currencies[index]->getFractionParts() * 0.01)) == 0) {
            return true;
        }
        else
            return false; //not zero
    }
}


//zero out all currency types
void Wallet::resetCurrency() {
    for (int i = 0; i < arraySize(); i++)
        currencies[i] = nullptr;
}

//check if wallet is empty
bool Wallet::isWalletEmpty() {
    if (currenciesSize == 0)
        return true;
    else
        return false;
}

//list items in wallet
void Wallet::listWallet() {
    for (int i = 0; i < arraySize(); i++) {
        cout << currencies[i]->getNoteName() << ": " << currencies[i]->getValue() << endl;
        //cout << *currencies[i] << endl;
    }
}
