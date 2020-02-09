#pragma once
#ifndef LIST_H
#define LIST_H
#include "node.h"
#include <iostream>

template<typename T>
class List {
protected:
	int numNodes;
	Node<T>* head;
	Node<T>* tail;
	bool isSorted = false;

public:
	List();
	virtual ~List();
	void pushNode(T value);
	void removeNode(int pos);
	int findValue(T value);
	int getSize();
	void deleteList();
	T getValue(int pos);
	void printList();
	void setSortStatus(bool status);
};

template <typename T>
List<T>::List() {
	numNodes = 0;
	head = nullptr;
	tail = nullptr;

}

template <typename T>
List<T>::~List() {
	deleteList();
}

template <typename T>
void List<T>::pushNode(T value) {
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

template <typename T>
void List<T>::removeNode(int pos) {
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
template <typename T>
int List<T>::findValue(T value) {
	Node<T>* temp = head;

	int count = 1; //position variable
	while (temp != nullptr) {
		if (temp->data == value)
			return count;
		temp = temp->next;
		count++;
	}
	return false; //value does not exist

}

template <typename T>
int List<T>::getSize() {
	return numNodes;
}

template <typename T>
void List<T>::deleteList() {
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

template <typename T>
T List<T>::getValue(int pos) {
	Node<T>* temp;
	Node<T>* toRemove;

	temp = head;
	if (pos == 1) {
		return head->data;
	}
	for (int i = 1; i < pos; i++)
		temp = temp->next;
	return temp->data;
	
}

template <typename T>
void List<T>::printList() {
	Node<T>* temp;

	while (temp->next != nullptr) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

template <typename T>
void List<T>::setSortStatus(bool status) {
	isSorted = status;
}
#endif