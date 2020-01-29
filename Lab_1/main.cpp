#include <iostream>
#include "currency.h"
#include "wallet.h"
#include <string>
#include <sstream> 
/**

*/
using namespace std;
int main() {
	Wallet wallet1;
	bool endProgram = false;
	bool valid = 1;
	char userInput;
	string currencyType;
	int wholeAmount, fractionAmount;
	cout << "WALLET 1.01\nLuke Marshall,Brian Le\n\n";

	//Main Loop to keep the program running. 
	while (endProgram == false) {
		cout << "Wallet opened. Please select an option.\n";

		cout << "a. Add money\n"
			<< "w. Withdraw money\n"
			<< "v. View balance\n"
			<< "e. Empty contents\n"
			<< "c. close wallet\n";

		cin >> userInput;
		while (userInput != 'a' && userInput != 'w' && userInput != 'v' && userInput != 'e' && userInput != 'c') { //Checks to make sure input is valid
			cout << "Enter a, w, v, e, or c only!\n";
			cin >> userInput;
		}
		if (userInput == 'a') {
			cout << "Please enter in the form [currencyType] [wholeAmount] [fractionAmount] ";
			cin >> currencyType >> wholeAmount >> fractionAmount;
			while (currencyType != "Dollar" && currencyType != "Euro" && currencyType != "Yen" && currencyType != "Yuan" && currencyType != "Rupee") {
				cout << "Currency not valid. Please enter a valid currency.\nValid currencies: Dollar, Euro, Yen, Yuan, Rupee\n";
				cout << "Please enter in the form [currencyType] [wholeAmount] [fractionAmount] ";
				cin >> currencyType >> wholeAmount >> fractionAmount;
			}

			while (valid == 1) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Wrong! Follow the correct format!" << endl;
					cin >> currencyType >> wholeAmount >> fractionAmount;
				}
				else
					valid = 0;
			}
			if (wallet1.doesCurrencyExist(currencyType)) {
				wallet1.add(currencyType, wholeAmount, fractionAmount);
			}
			else {
				wallet1.addCurrency(currencyType, wholeAmount, fractionAmount);
			}
			cout << "Success! " << wholeAmount << "." << fractionAmount << " " << currencyType << "(s) added!\n";

		}
		else if (userInput == 'w') {
			if (wallet1.isWalletEmpty()) {
				cout << "Nothing to withdraw!\n";
			}
			else {
				cout << "Please enter in the form [currencyType] [wholeAmount] [fractionAmount] ";
				cin >> currencyType >> wholeAmount >> fractionAmount;
				while (currencyType != "Dollar" && currencyType != "Euro" && currencyType != "Yen" && currencyType != "Yuan" && currencyType != "Rupee") {
					cout << "Currency not valid. Please enter a valid currency.\nValid currencies: Dollar, Euro, Yen, Yuan, Rupee\n";
					cout << "Please enter in the form [currencyType] [wholeAmount] [fractionAmount] ";
					cin >> currencyType >> wholeAmount >> fractionAmount;
				}
				while (valid == 1) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "Wrong! Follow the correct format!" << endl;
						cin >> currencyType >> wholeAmount >> fractionAmount;
					}
					else
						valid = 0;
				}
				if (wallet1.remove(currencyType, wholeAmount, fractionAmount)) {
					cout << "Success! " << wholeAmount << "." << fractionAmount << " " << currencyType << "(s) withdrawn!\n";
				}
				else
					cout << "Failure! " << wholeAmount << "." << fractionAmount << " " << currencyType << "(s) cannot be withdrawn!\n";
			}

		}
		else if (userInput == 'v') {
			cout << "There are " << wallet1.arraySize() << " currencies in the wallet. " << endl;
			if (wallet1.arraySize() != 0) {
				cout << wallet1.listWallet();

			}
		}
		else if (userInput == 'e') {
			cout << "Removing everything from wallet... \n";
			wallet1.resetCurrency();
		}
		else if (userInput == 'c') {
			endProgram = true;
		}

	}


	system("pause");
	return 0;
}