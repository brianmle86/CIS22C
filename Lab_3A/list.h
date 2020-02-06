#pragma once
#ifndef LIST_H
#define LIST_H
#include "node.h"
template<typename T>
class List {
protected:
	int numNodes;
	Node<T>* head;
	Node<T>* tail;
	int sortStatus;

public:
	List() {
		numNodes = 0;
		head = nullptr;
		tail = nullptr;

	}
	virtual ~List() {
		deleteList();
	}

	void pushNode(T value) {

		Node<T>* toPush = new Node<T>(value);
		Node<T>* temp = nullptr;
		if (numNodes == 0) {
			head = toPush;
			tail = head;
			numNodes++;
		}
		else {
			temp = head;
			head = toPush;
			toPush->next = temp;
			numNodes++;
		}
	}

	//removes node at position
	void removeNode(int pos) {
		Node<T>* temp;
		Node<T>* toRemove;
		temp = head;
		if (pos == 1) {
			delete head;
			numNodes--;
			return;
		}
		for (int i = 1; i < pos - 1; i++)
			temp = temp->next;
		toRemove = temp->next;
		temp->next = toRemove->next;
		delete toRemove;
		numNodes--;


	}

	//checks if the given value is contained in the linked list
	bool doesValueExist(T value) {
		Node<T>* temp;

		while (temp != nullptr) {
			if (temp->data == value)
				return true; //value exists

		}
		return false; //value does not exist

	}

	int getSize() {
		return numNodes;
	}

	void deleteList() {
		Node<T>* nodePtr;
		Node<T>* temp;
		nodePtr = head;

		while (nodePtr != nullptr) {
			temp = nodePtr->next;
			delete nodePtr;
			nodePtr = temp;
		}
		numNodes = 0;
		head = nullptr;
		tail = nullptr;
	}




};


#endif