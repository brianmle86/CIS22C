#include <iostream>
#include "currency.h"
#include "wallet.h"
#include <string>
#include <sstream> 

using namespace std;


//Changes the user's input to all uppercase to allow more values to be entered while still being correct. 
string upperCase(string input) {
	for (string::size_type i = 0; i < input.length(); i++) {

		input = toupper(input[i]);
		return input;

	}
	
}

//Checks if user's input is yes or no
bool yesNo(string input) {

	if (upperCase(input) == "Y" || upperCase(input) == "YES") {
		return true;
	}
	else if (upperCase(input) == "N" || upperCase(input) == "NO") {
		return false;
	}
		
}


//Let's the user enter different inputs and converts them to wallet1.add compatable.
string typeOfMoney(string input) {

	if (upperCase(input) == "D" || upperCase(input) == "DOLLARS" || upperCase(input) == "DOLLAR") {
		return "Dollar";
	}
	else if (upperCase(input) == "E" || upperCase(input) == "EURO" || upperCase(input) == "EUROS") {
		return "Euro";
	}
	else if (upperCase(input) == "R" || upperCase(input) == "RUPEE" || upperCase(input) == "RUPEES") {
		return "Rupee";
	}
	else if (upperCase(input) == "Y" || upperCase(input) == "YEN" || upperCase(input) == "YENS") {
		return "Yen";
	}
	else if (upperCase(input) == "YUAN" || upperCase(input) == "YUANS") {
		return "Yuan";
	}
}







int main() {

	string currentType, userInput;
	
	Wallet wallet1;
	bool endProgram = false;

	cout << "\t\tWALLET 1.01\t\t\n";


	//Main Loop to keep the program running. 
	while (endProgram == false) {
		cout << "Would you like to open your wallet? Enter Yes or No. ";
		cin >> userInput;

		//Checks the user's input.
		if (yesNo(userInput) == true) {
			cout << "Enter 'A' to add money to wallet. \n'W' to remove money from wallet. \n'V' to view your current wallet's balance. \n'E' to empty your wallet completely. ";
			cin >> userInput;
			if (upperCase(userInput) == "A") {
				cout << "What kind of money would you like to add? Dollars, Pounds, Yen, Rupee, or Yuan? ";
				cin >> userInput;
				currentType = typeOfMoney(userInput);

				cout << "How much would you like to add? ";
				
				cin >> userInput;

				//Converts user's input to double
				stringstream s(userInput);
				double amount = 0;
				s >> amount;
				

				//Splits the double into two integers. 
				long intPart = (long)amount;
				double fractionalPart = amount - intPart;

				wallet1.add(currentType, intPart, fractionalPart);
				

				

				//wallet1.add("Dollar", wholeAmount, fractionAmount);
				
			}
			else if (upperCase(userInput) == "W") {
				cout << "What kind of money would you like to withdraw? Dollars, Pounds, Yen, Rupee, or Yuan?";
				cin >> userInput;
				currentType = typeOfMoney(userInput);

				cout << "How much would you like to withdraw? ";

				cin >> userInput;

				//Converts user's input to double
				stringstream s(userInput);
				double amount = 0;
				s >> amount;


				//Splits the double into two integers. 
				long intPart = (long)amount;
				double fractionalPart = amount - intPart;

				wallet1.remove(currentType, intPart, fractionalPart);
			}
			else if (upperCase(userInput) == "V") {
				if (wallet1.doesCurrencyExist("Dollars") == true) {
					cout << "You have dollars: ";
				}
			}
			else if (upperCase(userInput) == "E") {
				cout << "Removing everything from wallet... ";
				wallet1.resetCurrency();
			}
			
		}



		//If user enters no ask if they would like to end the program.
		else if (yesNo(userInput) == false) {
			cout << "Ok, would you like to end the program? ";
			cin >> userInput;
			//Checks the user's input to see if they want to quit. 
			if (yesNo(userInput) == true) {
				return 0;

			}
			else if (yesNo(userInput) == false) {
				cout << "That is all this program can do. \n";
			}

		}


	}
	
	

	

	
	return 0;

}
