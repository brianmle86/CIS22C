#include <iostream>
#include "list.h"
#include "currency.h"
#include "stack.h"
#include "queue.h"

using namespace std;
/*
Brian Le, Luke Marshall-Wildgrube
De Anza College, CIS22C
Lab 3B
Stack ADT and Queue ADT demo
*/

int main() {
	bool menu;
	bool runAgain = true;
	string type, listType;
	int option;
	char yn; 

	//program ends if runAgain is false
	//everything here is fairly self-explanatory
	while (runAgain) {
		menu = true; //ends the individual menu session if false

		cout << "\nPlease enter the type you wish to use. (int, string, rupee): ";
		cin >> type;

		while (type != "int" && type != "string" && type != "rupee") {
			cout << "Please enter only int, string, or rupee. Try again. ";
			cin >> type;
		}

		cout << "\nPlease enter the type of list you want to create. (stack, queue); ";
		cin >> listType;

		while (listType != "stack" && listType != "queue") {
			cout << "Please enter only stack or queue. Try again. ";
			cin >> listType;
		}



		if (type == "int") {
			int toInsert;

			if (listType == "stack") {
				Stack<int> intStack;

				while (menu) {
					cout << "\nPlease select an option:\n"
						<< "1. Push\n"
						<< "2. Pop\n"
						<< "3. Peek\n"
						<< "4. Empty\n"
						<< "5. Exit\n";
					cin >> option;

					if (option < 1 || option > 5) {
						cout << "Please enter numbers 1 - 5 only. Try again. ";
						cin >> option;
					}

					if (option == 1) {
						cout << "Please enter the int you wish to push: ";
						cin >> toInsert;
						intStack.push(toInsert);
						intStack.displayStack();
					}

					else if (option == 2) {
						intStack.pop();
						intStack.displayStack();
					}

					else if (option == 3) {
						if (intStack.returnSize() == 0) {
							cout << "stack is empty\n";
						}
						else {
							cout << "top of stack: " << intStack.peek() << endl;
						}
					}

					else if (option == 4) {
						intStack.clear();
						intStack.displayStack();
					}

					else if (option == 5) {
						cout << "Do you wish to run again with a different type or list type? (y/n)\n";
						cin >> yn;
						if (yn == 'n' || yn == 'N') {
							menu = false;
							runAgain = false;
						}
						else {
							menu = false;
						}
					}

				}
			}

			else if (listType == "queue") {
				Queue<int> intQueue;

				while (menu) {
					cout << "\nPlease select an option:\n"
						<< "1. Enqueue\n"
						<< "2. Dequeue\n"
						<< "3. Front\n"
						<< "4. Rear\n"
						<< "5. Empty\n"
						<< "6. Exit\n";
					cin >> option;

					if (option < 1 || option > 6) {
						cout << "Please enter numbers 1 - 6 only. Try again. ";
						cin >> option;
					}

					if (option == 1) {
						cout << "Please enter the int you wish to enqueue: ";
						cin >> toInsert;
						intQueue.enqueue(toInsert);
						intQueue.displayQueue();
					}

					else if (option == 2) {
						intQueue.dequeue();
						intQueue.displayQueue();
					}

					else if (option == 3) {
						if (intQueue.returnSize() == 0) {
							cout << "queue is empty\n";
						}
						else {
							cout << "front of queue: " << intQueue.front() << endl;
						}
					}

					else if (option == 4) {
						if (intQueue.returnSize() == 0) {
							cout << "queue is empty\n";
						}
						else {
							cout << "rear of queue: " << intQueue.rear() << endl;
						}
					}

					else if (option == 5) {
						intQueue.clear();
						intQueue.displayQueue();
					}

					else if (option == 6) {
						cout << "Do you wish to run again with a different type or list type? (y/n)\n";
						cin >> yn;
						if (yn == 'n' || yn == 'N') {
							menu = false;
							runAgain = false;
						}
						else {
							menu = false;
						}
					}

				}
			}
		}

		else if (type == "string") {
			string toInsert;

			if (listType == "stack") {
				Stack<string> stringStack;

				while (menu) {
					cout << "\nPlease select an option:\n"
						<< "1. Push\n"
						<< "2. Pop\n"
						<< "3. Peek\n"
						<< "4. Empty\n"
						<< "5. Exit\n";
					cin >> option;

					if (option < 1 || option > 5) {
						cout << "Please enter numbers 1 - 5 only. Try again. ";
						cin >> option;
					}

					if (option == 1) {
						cout << "Please enter the string you wish to push: ";
						cin >> toInsert;
						stringStack.push(toInsert);
						stringStack.displayStack();
					}

					else if (option == 2) {
						stringStack.pop();
						stringStack.displayStack();
					}

					else if (option == 3) {
						if (stringStack.returnSize() == 0) {
							cout << "stack is empty\n";
						}
						else {
							cout << "top of stack: " << stringStack.peek() << endl;
						}
					}

					else if (option == 4) {
						stringStack.clear();
						stringStack.displayStack();
					}

					else if (option == 5) {
						cout << "Do you wish to run again with a different type or list type? (y/n)\n";
						cin >> yn;
						if (yn == 'n' || yn == 'N') {
							menu = false;
							runAgain = false;
						}
						else {
							menu = false;
						}
					}

				}
			}

			else if (listType == "queue") {
				Queue<string> stringQueue;

				while (menu) {
					cout << "\nPlease select an option:\n"
						<< "1. Enqueue\n"
						<< "2. Dequeue\n"
						<< "3. Front\n"
						<< "4. Rear\n"
						<< "5. Empty\n"
						<< "6. Exit\n";
					cin >> option;

					if (option < 1 || option > 6) {
						cout << "Please enter numbers 1 - 6 only. Try again. ";
						cin >> option;
					}

					if (option == 1) {
						cout << "Please enter the string you wish to enqueue: ";
						cin >> toInsert;
						stringQueue.enqueue(toInsert);
						stringQueue.displayQueue();
					}

					else if (option == 2) {
						stringQueue.dequeue();
						stringQueue.displayQueue();
					}

					else if (option == 3) {
						if (stringQueue.returnSize() == 0) {
							cout << "queue is empty\n";
						}
						else {
							cout << "front of queue: " << stringQueue.front() << endl;
						}
					}

					else if (option == 4) {
						if (stringQueue.returnSize() == 0) {
							cout << "queue is empty\n";
						}
						else {
							cout << "rear of queue: " << stringQueue.rear() << endl;
						}
					}

					else if (option == 5) {
						stringQueue.clear();
						stringQueue.displayQueue();
					}

					else if (option == 6) {
						cout << "Do you wish to run again with a different type or list type? (y/n)\n";
						cin >> yn;
						if (yn == 'n' || yn == 'N') {
							menu = false;
							runAgain = false;
						}
						else {
							menu = false;
						}
					}

				}
			}
		}

		else if (type == "rupee") {
			Rupee toInsert;

			if (listType == "stack") {
				Stack<Rupee> rupeeStack;

				while (menu) {
					cout << "\nPlease select an option:\n"
						<< "1. Push\n"
						<< "2. Pop\n"
						<< "3. Peek\n"
						<< "4. Empty\n"
						<< "5. Exit\n";
					cin >> option;

					if (option < 1 || option > 5) {
						cout << "Please enter numbers 1 - 5 only. Try again. ";
						cin >> option;
					}

					if (option == 1) {
						cout << "Please enter the rupee object you wish to push, in wholeAmount, fractionAmount: ";
						cin >> toInsert;
						rupeeStack.push(toInsert);
						rupeeStack.displayStack();
					}

					else if (option == 2) {
						rupeeStack.pop();
						rupeeStack.displayStack();
					}

					else if (option == 3) {
						Rupee top = rupeeStack.peek();
						if (rupeeStack.returnSize() == 0) {
							cout << "stack is empty\n";
						}
						else {
							cout << "top of stack: " << top << endl;
						}
					}

					else if (option == 4) {
						rupeeStack.clear();
						rupeeStack.displayStack();
					}

					else if (option == 5) {
						cout << "Do you wish to run again with a different type or list type? (y/n)\n";
						cin >> yn;
						if (yn == 'n' || yn == 'N') {
							menu = false;
							runAgain = false;
						}
						else {
							menu = false;
						}
					}

				}
			}

			else if (listType == "queue") {
				Queue<Rupee> rupeeQueue;

				while (menu) {
					cout << "\nPlease select an option:\n"
						<< "1. Enqueue\n"
						<< "2. Dequeue\n"
						<< "3. Front\n"
						<< "4. Rear\n"
						<< "5. Empty\n"
						<< "6. Exit\n";
					cin >> option;

					if (option < 1 || option > 6) {
						cout << "Please enter numbers 1 - 6 only. Try again. ";
						cin >> option;
					}

					if (option == 1) {
						cout << "Please enter the rupee object you wish to enqueue, in wholeAmount, fractionAmount: ";
						cin >> toInsert;
						rupeeQueue.enqueue(toInsert);
						rupeeQueue.displayQueue();
					}

					else if (option == 2) {
						rupeeQueue.dequeue();
						rupeeQueue.displayQueue();
					}

					else if (option == 3) {
						if (rupeeQueue.returnSize() == 0) {
							cout << "queue is empty\n";
						}
						else {
							Rupee front = rupeeQueue.front();
							cout << "front of queue: " << front << endl;
						}
					}

					else if (option == 4) {
						if (rupeeQueue.returnSize() == 0) {
							cout << "queue is empty\n";
						}
						else {
							Rupee rear = rupeeQueue.rear();
							cout << "rear of queue: " << rear << endl;
						}
					}

					else if (option == 5) {
						rupeeQueue.clear();
						rupeeQueue.displayQueue();
					}

					else if (option == 6) {
						cout << "Do you wish to run again with a different type or list type? (y/n)\n";
						cin >> yn;
						if (yn == 'n' || yn == 'N') {
							menu = false;
							runAgain = false;
						}
						else {
							menu = false;
						}
					}

				}
			}
		}
	}
	

	system("pause");
	return 0;
}