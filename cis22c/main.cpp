#include <iostream>
#include "currency.h"
#include "wallet.h"
#include <string>

using namespace std;

int main() {

	string currentType, userInput, quit;
	Wallet wallet1;
	bool endProgram = false;

	cout << "\t\tWALLET 1.01\t\t\n";


	//Main Loop to keep the program running. 
	while (endProgram == false) {
		cout << "Would you like to check your wallet? Enter Yes or No. ";
		cin >> userInput;

		//Changes user input to upercase. Probably would work better as a seperate function. I'll change that tomorrow.  
		for (string::size_type i = 0; i < userInput.length(); i++){

			userInput = toupper(userInput[i]);
			
		}
		if (userInput == "Y" || userInput == "YES") {
			cout << "Okay. ";

			/*****
			
			Testing the wallet class goes here. Needed to get sleep.
			
			
			
			
			
			
			
			
			
			
			
			*****/
		}



		//If user enters no ask if they would like to end the program.
		else if (userInput == "N" || userInput == "NO") {
			cout << "Ok, would you like to end the program? ";
			cin >> quit;
			//Changes user input to upercase.
			for (string::size_type i = 0; i < quit.length(); i++) {

				quit = toupper(quit[i]);

			}
			if (quit == "Y" || quit == "YES") {
				return 0;

			}
			else if (quit == "N" || quit == "NO") {
				cout << "That is all this program can do. \n";
			}

		}


	}
	
	

	

	
	return 0;

}
