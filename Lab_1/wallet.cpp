#include <iostream>
#include "wallet.h"
#include <iomanip>
#include <sstream>


Wallet::Wallet() {
    currencies = new Currency * [MAX_CURRENCIES];
    for (int i = 0; i < 5; i++) {
        currencies[i] = nullptr;
    }
    currenciesSize = 0;
}

//returns number of currency types
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

//add money by currency type using dynamic memory allocation
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
int Wallet::remove(std::string currencyType, int wholeAmount, int fractionAmount) {
    if (doesCurrencyExist(currencyType) == false) {
        return 0;
    }
    int index;
    for (int i = 0; i < arraySize(); i++) {
        if (currencies[i]->getNoteName() == currencyType)
            index = i;
    }
    add(currencyType, (wholeAmount * -1), (fractionAmount * -1));
    if ((currencies[index]->getWholeParts() + (currencies[index]->getFractionParts() * 0.01)) < 0) {
        //currency has negative value, reverse remove
        add(currencyType, wholeAmount, fractionAmount);
        return 0;
    }
    if (checkIfZero(currencyType)) {
        currencies[index] = nullptr;
        currenciesSize--;
    }
    return 1;


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


//clear currency types in wallet
void Wallet::resetCurrency() {
    for (int i = 0; i < MAX_CURRENCIES; i++)
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
string Wallet::listWallet() {

    string list;

    for (int i = 0; i < arraySize(); i++) {
        ostringstream valueObj;

        string type = currencies[i]->getNoteName();
        double dbleVal = currencies[i]->getValue();
        valueObj << fixed;
        valueObj << setprecision(2);
        valueObj << dbleVal;
        string value = valueObj.str();
        list += (type + ": " + value + "\n");

    }
    return list;




}
