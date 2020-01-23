#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "node.h"
template<class T>
class LinkedList {
protected:
	int nodeCnt;
	Node<T>* head;
	Node<T>* tail;

public:
	LinkedList() {
		nodeCnt = 0;
		head = nullptr;
		tail = nullptr;

	}
	virtual ~LinkedList() {
		deleteList();
	}

	void pushNode(T value) {

		Node<T>* toPush = new Node<T>(value);
		Node<T>* temp = nullptr;
		if (nodeCnt == 0) {
			head = toPush;
			tail = head;
			nodeCnt++;
		}
		else {
			temp = head;
			head = toPush;
			toPush->next = temp;
			nodeCnt++;
		}
	}

	//removes node at position
	void removeNode(int pos) {
		Node<T>* temp;
		Node<T>* toRemove;
		temp = head;
		if (pos == 1) {
			delete head;
			nodeCnt--;
			return;
		}
		for (int i = 1; i < pos - 1; i++)
			temp = temp->next;
		toRemove = temp->next;
		temp->next = toRemove->next;
		delete toRemove;
		nodeCnt--;


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
		return nodeCnt;
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
		nodeCnt = 0;
		head = nullptr;
		tail = nullptr;
	}




};


#endif